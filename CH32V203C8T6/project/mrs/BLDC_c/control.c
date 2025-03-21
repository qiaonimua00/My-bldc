#include "control.h"
#include "bldc_config.h"
#include "pwm_output.h"
#include "stdlib.h"
#include "led.h"
#include "opma.h"

static uint16 temp_commutation_time;
volatile unsigned char flag_fan=0;


void pit_callback(void)
{


    static uint16 stall_time_out_check = 0;
//    static uint8  restart_count = 0;
    switch(motor.run_flag)
    {
        case MOTOR_START:
        {
//            // 置随机数种子
//            srand(battery.adc_reg_value);

            // 关闭定时器1，更新中断
            TIM1->DMAINTENR &= ~TIM_IT_Update;
            // 关闭定时器3，更新中断
            TIM3->DMAINTENR &= ~TIM_IT_Update;
            // 关闭定时器4，更新中断
            TIM4->DMAINTENR &= ~TIM_IT_Update;
            // 关闭PA2外部引脚中断
            disable_opama_interrupts();
            // 开始阶段
            // 等待10ms + 随机延时(0-50)ms，
            if(TIM4->CNT > (10 + 25))
            {
//                motor.duty_register = ((float)BLDC_START_VOLTAGE * BLDC_MAX_DUTY / (12.0/1000));
                motor.duty_register = 350;
                if(motor.duty_register < (BLDC_MAX_DUTY / 25))
                {
                    motor.duty_register = (BLDC_MAX_DUTY / 25);
                }
                pwm_duty_update(motor.duty_register);
                TIM4->CNT = 0;
                // 清除一些变量的值
                motor.commutation_time[0] = 6000;
                motor.commutation_time[1] = 6000;
                motor.commutation_time[2] = 6000;
                motor.commutation_time[3] = 6000;
                motor.commutation_time[4] = 6000;
                motor.commutation_time[5] = 6000;
                motor.commutation_time_sum = motor.commutation_time[0] + motor.commutation_time[1] + motor.commutation_time[2] + \
                                             motor.commutation_time[3] + motor.commutation_time[4] + motor.commutation_time[5] ;
                motor.filter_commutation_time_sum = motor.commutation_time_sum;
                motor.commutation_num   = 0;
                motor.commutation_faile_count = 0;
                // 执行换向
                if(flag_fan == 0)
                {
                    motor_next_step();
                }
                else if(flag_fan ==1)
                {
                    motor_next_step_fan();
                }

                motor.filter_commutation_time_sum = 0;
                stall_time_out_check = 0;
                motor.run_flag = MOTOR_OPEN_LOOP;
            }
        }
        break;
        case MOTOR_OPEN_LOOP:
        {
            // 开环强拉
            static uint8 gpio_state = 0;
            uint8 motor_next_step_flag = 0;
            uint16 temp_commutation_time = TIM4->CNT;
            // 通过位移的方式，将电平数据存入变量中
            gpio_state = (gpio_state << 1) | ((GPIOA->INDR & GPIO_Pin_2) ? 1 : 0);
            if ((motor.step % 2))
            {

                 if(flag_fan == 0)
                 {
                     // 上升沿
                     if(gpio_state == 0)
                     {
                         motor_next_step_flag = 1;
                         gpio_state = 0xFC;
                     }
                 }
                 else if(flag_fan ==1)
                 {
                     //下降沿

                      if(gpio_state == 0xFF)
                      {
                          motor_next_step_flag = 1;
                          gpio_state = 0x03;


                      }
                 }
           }
           else
            {
               if(flag_fan == 0)
               {
                   //下降沿

                    if(gpio_state == 0xFF)
                    {
                        motor_next_step_flag = 1;
                        gpio_state = 0x03;


                    }
               }
               else if(flag_fan ==1)
               {
                   // 上升沿
                   if(gpio_state == 0)
                   {
                       motor_next_step_flag = 1;
                       gpio_state = 0xFC;
                   }
               }





            }
            if(motor_next_step_flag)
            {
                // 堵转计数清空
                stall_time_out_check = 0;
                // 定时器计数值清空
                TIM4->CNT = 0;
                // 去掉最早的数据
                motor.commutation_time_sum -= motor.commutation_time[motor.step];
                // 保存换相时间
                motor.commutation_time[motor.step] = temp_commutation_time;
                // 叠加新的换相时间，求6次换相总时长
                motor.commutation_time_sum += motor.commutation_time[motor.step];
                // 换相次数增加一
                motor.commutation_num++;
                // 一阶低通滤波
                motor.filter_commutation_time_sum = (motor.filter_commutation_time_sum * 3 + motor.commutation_time_sum * 1) >> 2;
                // 等待15度
                while(TIM4->CNT < (motor.filter_commutation_time_sum / 24));
                // 执行换向
                if(flag_fan == 0)
                {
                    motor_next_step();
                }
                else if(flag_fan ==1)
                {
                    motor_next_step_fan();
                }
            }
            else
            {
                // 堵转检测
                if((10 * BLDC_STALL_TIME_OUT) < stall_time_out_check++)
                {
                    stall_time_out_check = 0;
                    motor.commutation_num = 0;
                    motor.run_flag = MOTOR_STOP_STALL;
                }
            }
            // 闭环状态切换
            if((motor.commutation_num > (BLDC_OPEN_LOOP_WRITE * BLDC_POLES)) && (motor.filter_commutation_time_sum < 40000))
            {
                // 清除一些变量
                motor.commutation_num = 0;
                // 堵转计数器清空
                stall_time_out_check = 0;
                // 切换为闭环状态
                motor.run_flag = MOTOR_CLOSE_LOOP;
                // 打开PA2外部引脚中断
                enable_opama_interrupts();
                led_run_control(LED_ON);
                led_err_control(LED_OFF);
            }
//             超过20ms + 随机延时(0-50)ms没有检测到跳变，则从进入电机开始状态
            if((TIM4->CNT > (20 + rand()%30)*2000) && (motor.run_flag == MOTOR_OPEN_LOOP))
            {
                TIM4->CNT = 0;
                if(flag_fan == 0)
                {
                    motor_next_step();
                }
                else if(flag_fan ==1)
                {
                    motor_next_step_fan();
                }
                motor.run_flag = MOTOR_START;
            }
        }
        break;
        case MOTOR_CLOSE_LOOP:
        {
            static uint8 oled_pin_state = 0;
            uint8 pin_state = (GPIOA->INDR & GPIO_Pin_2);
            // 通过PA2引脚的电平状态，进行堵转检测
            if(oled_pin_state != pin_state)
            {
                stall_time_out_check = 0;
                oled_pin_state = pin_state;
            }
            else
            {
                // 如果引脚一直是一个状态，且超过了 BLDC_STALL_TIME_OUT ms 则认为堵转了
                if(stall_time_out_check++ > (10 * BLDC_STALL_TIME_OUT))          // 10KHZ，0.1ms计数一次
                {
                    stall_time_out_check = 0;
                    motor.run_flag = MOTOR_STOP_STALL;
                }
            }

            if(motor.commutation_num < (BLDC_CLOSE_LOOP_WRITE * BLDC_POLES))
            {
                 if (motor.duty_register < BLDC_PWM_DEADTIME)
                 {
                     motor.duty_register = BLDC_PWM_DEADTIME;
                 }
                 if (motor.duty_register > (BLDC_MAX_DUTY / 5 + BLDC_PWM_DEADTIME))
                 {
                     motor.duty_register = BLDC_MAX_DUTY / 5 + BLDC_PWM_DEADTIME;
                 }
            }

            // 缓慢加减速
            if((motor.duty != motor.duty_register))
            {
                if(0 > motor.duty_register)
                {
                    motor.duty_register = 0;
                }

                if(motor.duty > motor.duty_register)
                {
                    motor.duty_register += BLDC_SPEED_INCREMENTAL;
                }
                else
                {
                    motor.duty_register = motor.duty;
                }

                pwm_duty_update(motor.duty_register);
            }
        }

        break;
        case MOTOR_IDLE:
        case BYTE_LOW_VOLTAGE:
        {
            pwm_an_bn_cn_off();
        }
        break;
        case MOTOR_STOP_STALL:
        {
//            if (restart_count < BLDC_RESTART_MAX)
//            {
//                motor.run_flag = MOTOR_RESTART;
//            }
//            motor_stop(BLDC_BRAKE_DUTY);

            pwm_an_bn_cn_off();
            led_run_control(LED_OFF);
            led_err_control(LED_ON);
        }
        break;
//        case MOTOR_RESTART:
//        {
//            static int16 restart_delay = BLDC_RESTART_DELAY*10;
//            if (restart_count < BLDC_RESTART_MAX)
//            {
//                if(restart_delay-- < 0)
//                {
//                    restart_delay = BLDC_RESTART_DELAY*10;
//                    restart_count++;
//                    motor.run_flag = MOTOR_IDLE;
//                }
//            }
//        }
//        break;
        case MOTOR_STOP:
        {
            // 关闭定时器1，更新中断
            TIM1->DMAINTENR &= ~TIM_IT_Update;
            // 关闭定时器3，更新中断
            TIM3->DMAINTENR &= ~TIM_IT_Update;
            // 关闭定时器4，更新中断
            TIM4->DMAINTENR &= ~TIM_IT_Update;
            // 关闭PA2外部引脚中断
            disable_opama_interrupts();
            motor_brake(100);
            led_run_control(LED_OFF);
            led_err_control(LED_ON);
        }
        break;
        case MOTOR_HX:
        {
            // 关闭定时器1，更新中断
            TIM1->DMAINTENR &= ~TIM_IT_Update;
            // 关闭定时器3，更新中断
            TIM3->DMAINTENR &= ~TIM_IT_Update;
            // 关闭定时器4，更新中断
            TIM4->DMAINTENR &= ~TIM_IT_Update;
            // 关闭PA2外部引脚中断
            disable_opama_interrupts();
            motor_brake(100);
            flag_fan = (~flag_fan & 0x01);
            motor.run_flag = MOTOR_START;
        }
        break;
    }
}

void opama_callback()
{
    // 获取本次换相时间
    temp_commutation_time = TIM4->CNT;

    // 去除反电动势毛刺
    if(temp_commutation_time < (motor.filter_commutation_time_sum / 12) && (BLDC_CLOSE_LOOP_WRITE * BLDC_POLES) < motor.commutation_num)
    {
        return;
    }

    // 定时器清空
    TIM4->CNT = 0;
    TIM3->CNT = 0;
    TIM3->ATRLR = motor.filter_commutation_time_sum >> 4;     // 22.5度后开始换向
    // 开启定时器3，更新事件中断
    TIM3->INTFR = 0x00;
    TIM3->DMAINTENR |= TIM_IT_Update;

    disable_opama_interrupts();
}


void commutation_and_degauss_callback()
{
    if(motor.run_flag == MOTOR_CLOSE_LOOP)
    {
        // 换向
        if(flag_fan == 0)
        {
            motor_next_step();
        }
        else if(flag_fan ==1)
        {
            motor_next_step_fan();
        }

        // 使能比较器中断
        enable_opama_interrupts();

        // 去掉最早的数据
        motor.commutation_time_sum -= motor.commutation_time[motor.step];
        // 保存换相时间
        motor.commutation_time[motor.step] = temp_commutation_time;
        // 叠加新的换相时间，求6次换相总时长
        motor.commutation_time_sum += motor.commutation_time[motor.step];
        // 换相次数增加一
        motor.commutation_num++;
        // 一阶低通滤波
        motor.filter_commutation_time_sum = (motor.filter_commutation_time_sum * 7 + motor.commutation_time_sum * 1) >> 3;

        // 等待稳定，再开始换相错误判断
        if((BLDC_CLOSE_LOOP_WRITE * BLDC_POLES) < motor.commutation_num)
        {
            // 本次换向60度的时间，在上一次换向一圈时间的45度到75度，否则认为换相错误
            // (360.0f / 45) = 8
            // (360.0f / 75) = 4.8
            if((temp_commutation_time > ((motor.filter_commutation_time_sum >> 3))) && (temp_commutation_time < (motor.filter_commutation_time_sum / 4.8f)))
            {
                // 延时减去换向失败计数器
                if((motor.commutation_faile_count))
                {
                    motor.commutation_faile_count--;
                }
            }
            else
            {
                if(BLDC_COMMUTATION_FAILED_MAX < motor.commutation_faile_count++)
                {
                    motor.run_flag = MOTOR_STOP_STALL;
                }
            }
        }
    }
    TIM3->DMAINTENR &= ~TIM_IT_Update;  // 关闭定时器3更新中断
}








void pit_init(void)
{
    // 10Khz
    // 100us 进一次中断
    SysTick->CTLR = 0;
    SysTick->SR   = 0;
    SysTick->CNT  = 0;
    SysTick->CMP  = SystemCoreClock / 10000;
    SysTick->CTLR = 0xF;
    NVIC_SetPriority(SysTicK_IRQn, 0xE0);
    NVIC_EnableIRQ(SysTicK_IRQn);
}



//TIM3
void advance_commutation_count_init(void)
{
    // 1 us计数一次
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE );
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};
    TIM_TimeBaseStructure.TIM_Period = 0xFFFF;
    TIM_TimeBaseStructure.TIM_Prescaler = (SystemCoreClock / 2 /1000000) - 1;                    // 分频值
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                     // 设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;                 // TIM向上计数模式
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
    TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
    TIM_ITConfig(TIM3,TIM_IT_Update, ENABLE);
    NVIC_SetPriority(TIM3_IRQn, 0x00);
    NVIC_EnableIRQ(TIM3_IRQn);
    TIM_Cmd(TIM3, ENABLE);
}



//TIM4
void commutation_time_count_init(void)
{
    // 1 us计数一次
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE );
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};
    TIM_TimeBaseStructure.TIM_Period = 0xFFFF;
    TIM_TimeBaseStructure.TIM_Prescaler = (SystemCoreClock / 2 / 1000000) - 1;                 // 分频值
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                     // 设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;                 // TIM向上计数模式
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;                            // 重复计数器设置为0
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
    TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
    NVIC_SetPriority(TIM4_IRQn, 0x02);
    NVIC_EnableIRQ(TIM4_IRQn);
    TIM_Cmd(TIM4, ENABLE);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      刹车
//  @param      duty    刹车占空比
//  @return     void
//  @since      v1.0
//  Sample usage:   上桥全关,下桥输入PWM,进行刹车
//-------------------------------------------------------------------------------------------------------------------
void motor_brake(uint16 duty)
{
    // A相上桥关
    GPIOA->CFGHR &= ~(0xf<<0);
    GPIOA->CFGHR |= (0x3<<0);
    GPIOA->BCR = PHASE_A_GPIO_HIGH;
    // A相下桥开
    GPIOA->CFGLR  &= ~(0xf<<28);
    GPIOA->CFGLR|= (0x3<<28);
    GPIOA->BSHR = PHASE_A_GPIO_LOW;
    // B相上桥关
    GPIOA->CFGHR &= ~(0xf<<4);
    GPIOA->CFGHR |= (0x3<<4);
    GPIOA->BCR = PHASE_B_GPIO_HIGH;
    // B相下桥开
    GPIOB->CFGLR  &= ~(0xf<<0);
    GPIOB->CFGLR|= (0x3<<0);
    GPIOB->BSHR = PHASE_B_GPIO_LOW;
    // C相上桥关
    GPIOA->CFGHR &= ~(0xf<<8);
    GPIOA->CFGHR |= (0x3<<8);
    GPIOA->BCR = PHASE_C_GPIO_HIGH;
    // C相下桥开
    GPIOB->CFGLR  &= ~(0xf<<4);
    GPIOB->CFGLR |= (0x3<<4);
    GPIOB->BSHR = PHASE_C_GPIO_LOW;

    pwm_duty_update(duty);
}
