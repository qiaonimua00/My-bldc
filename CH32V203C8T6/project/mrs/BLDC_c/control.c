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
//            // �����������
//            srand(battery.adc_reg_value);

            // �رն�ʱ��1�������ж�
            TIM1->DMAINTENR &= ~TIM_IT_Update;
            // �رն�ʱ��3�������ж�
            TIM3->DMAINTENR &= ~TIM_IT_Update;
            // �رն�ʱ��4�������ж�
            TIM4->DMAINTENR &= ~TIM_IT_Update;
            // �ر�PA2�ⲿ�����ж�
            disable_opama_interrupts();
            // ��ʼ�׶�
            // �ȴ�10ms + �����ʱ(0-50)ms��
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
                // ���һЩ������ֵ
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
                // ִ�л���
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
            // ����ǿ��
            static uint8 gpio_state = 0;
            uint8 motor_next_step_flag = 0;
            uint16 temp_commutation_time = TIM4->CNT;
            // ͨ��λ�Ƶķ�ʽ������ƽ���ݴ��������
            gpio_state = (gpio_state << 1) | ((GPIOA->INDR & GPIO_Pin_2) ? 1 : 0);
            if ((motor.step % 2))
            {

                 if(flag_fan == 0)
                 {
                     // ������
                     if(gpio_state == 0)
                     {
                         motor_next_step_flag = 1;
                         gpio_state = 0xFC;
                     }
                 }
                 else if(flag_fan ==1)
                 {
                     //�½���

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
                   //�½���

                    if(gpio_state == 0xFF)
                    {
                        motor_next_step_flag = 1;
                        gpio_state = 0x03;


                    }
               }
               else if(flag_fan ==1)
               {
                   // ������
                   if(gpio_state == 0)
                   {
                       motor_next_step_flag = 1;
                       gpio_state = 0xFC;
                   }
               }





            }
            if(motor_next_step_flag)
            {
                // ��ת�������
                stall_time_out_check = 0;
                // ��ʱ������ֵ���
                TIM4->CNT = 0;
                // ȥ�����������
                motor.commutation_time_sum -= motor.commutation_time[motor.step];
                // ���滻��ʱ��
                motor.commutation_time[motor.step] = temp_commutation_time;
                // �����µĻ���ʱ�䣬��6�λ�����ʱ��
                motor.commutation_time_sum += motor.commutation_time[motor.step];
                // �����������һ
                motor.commutation_num++;
                // һ�׵�ͨ�˲�
                motor.filter_commutation_time_sum = (motor.filter_commutation_time_sum * 3 + motor.commutation_time_sum * 1) >> 2;
                // �ȴ�15��
                while(TIM4->CNT < (motor.filter_commutation_time_sum / 24));
                // ִ�л���
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
                // ��ת���
                if((10 * BLDC_STALL_TIME_OUT) < stall_time_out_check++)
                {
                    stall_time_out_check = 0;
                    motor.commutation_num = 0;
                    motor.run_flag = MOTOR_STOP_STALL;
                }
            }
            // �ջ�״̬�л�
            if((motor.commutation_num > (BLDC_OPEN_LOOP_WRITE * BLDC_POLES)) && (motor.filter_commutation_time_sum < 40000))
            {
                // ���һЩ����
                motor.commutation_num = 0;
                // ��ת���������
                stall_time_out_check = 0;
                // �л�Ϊ�ջ�״̬
                motor.run_flag = MOTOR_CLOSE_LOOP;
                // ��PA2�ⲿ�����ж�
                enable_opama_interrupts();
                led_run_control(LED_ON);
                led_err_control(LED_OFF);
            }
//             ����20ms + �����ʱ(0-50)msû�м�⵽���䣬��ӽ�������ʼ״̬
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
            // ͨ��PA2���ŵĵ�ƽ״̬�����ж�ת���
            if(oled_pin_state != pin_state)
            {
                stall_time_out_check = 0;
                oled_pin_state = pin_state;
            }
            else
            {
                // �������һֱ��һ��״̬���ҳ����� BLDC_STALL_TIME_OUT ms ����Ϊ��ת��
                if(stall_time_out_check++ > (10 * BLDC_STALL_TIME_OUT))          // 10KHZ��0.1ms����һ��
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

            // �����Ӽ���
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
            // �رն�ʱ��1�������ж�
            TIM1->DMAINTENR &= ~TIM_IT_Update;
            // �رն�ʱ��3�������ж�
            TIM3->DMAINTENR &= ~TIM_IT_Update;
            // �رն�ʱ��4�������ж�
            TIM4->DMAINTENR &= ~TIM_IT_Update;
            // �ر�PA2�ⲿ�����ж�
            disable_opama_interrupts();
            motor_brake(100);
            led_run_control(LED_OFF);
            led_err_control(LED_ON);
        }
        break;
        case MOTOR_HX:
        {
            // �رն�ʱ��1�������ж�
            TIM1->DMAINTENR &= ~TIM_IT_Update;
            // �رն�ʱ��3�������ж�
            TIM3->DMAINTENR &= ~TIM_IT_Update;
            // �رն�ʱ��4�������ж�
            TIM4->DMAINTENR &= ~TIM_IT_Update;
            // �ر�PA2�ⲿ�����ж�
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
    // ��ȡ���λ���ʱ��
    temp_commutation_time = TIM4->CNT;

    // ȥ�����綯��ë��
    if(temp_commutation_time < (motor.filter_commutation_time_sum / 12) && (BLDC_CLOSE_LOOP_WRITE * BLDC_POLES) < motor.commutation_num)
    {
        return;
    }

    // ��ʱ�����
    TIM4->CNT = 0;
    TIM3->CNT = 0;
    TIM3->ATRLR = motor.filter_commutation_time_sum >> 4;     // 22.5�Ⱥ�ʼ����
    // ������ʱ��3�������¼��ж�
    TIM3->INTFR = 0x00;
    TIM3->DMAINTENR |= TIM_IT_Update;

    disable_opama_interrupts();
}


void commutation_and_degauss_callback()
{
    if(motor.run_flag == MOTOR_CLOSE_LOOP)
    {
        // ����
        if(flag_fan == 0)
        {
            motor_next_step();
        }
        else if(flag_fan ==1)
        {
            motor_next_step_fan();
        }

        // ʹ�ܱȽ����ж�
        enable_opama_interrupts();

        // ȥ�����������
        motor.commutation_time_sum -= motor.commutation_time[motor.step];
        // ���滻��ʱ��
        motor.commutation_time[motor.step] = temp_commutation_time;
        // �����µĻ���ʱ�䣬��6�λ�����ʱ��
        motor.commutation_time_sum += motor.commutation_time[motor.step];
        // �����������һ
        motor.commutation_num++;
        // һ�׵�ͨ�˲�
        motor.filter_commutation_time_sum = (motor.filter_commutation_time_sum * 7 + motor.commutation_time_sum * 1) >> 3;

        // �ȴ��ȶ����ٿ�ʼ��������ж�
        if((BLDC_CLOSE_LOOP_WRITE * BLDC_POLES) < motor.commutation_num)
        {
            // ���λ���60�ȵ�ʱ�䣬����һ�λ���һȦʱ���45�ȵ�75�ȣ�������Ϊ�������
            // (360.0f / 45) = 8
            // (360.0f / 75) = 4.8
            if((temp_commutation_time > ((motor.filter_commutation_time_sum >> 3))) && (temp_commutation_time < (motor.filter_commutation_time_sum / 4.8f)))
            {
                // ��ʱ��ȥ����ʧ�ܼ�����
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
    TIM3->DMAINTENR &= ~TIM_IT_Update;  // �رն�ʱ��3�����ж�
}








void pit_init(void)
{
    // 10Khz
    // 100us ��һ���ж�
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
    // 1 us����һ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE );
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};
    TIM_TimeBaseStructure.TIM_Period = 0xFFFF;
    TIM_TimeBaseStructure.TIM_Prescaler = (SystemCoreClock / 2 /1000000) - 1;                    // ��Ƶֵ
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                     // ����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;                 // TIM���ϼ���ģʽ
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
    // 1 us����һ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE );
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};
    TIM_TimeBaseStructure.TIM_Period = 0xFFFF;
    TIM_TimeBaseStructure.TIM_Prescaler = (SystemCoreClock / 2 / 1000000) - 1;                 // ��Ƶֵ
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                     // ����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;                 // TIM���ϼ���ģʽ
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;                            // �ظ�����������Ϊ0
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
    TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
    NVIC_SetPriority(TIM4_IRQn, 0x02);
    NVIC_EnableIRQ(TIM4_IRQn);
    TIM_Cmd(TIM4, ENABLE);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ɲ��
//  @param      duty    ɲ��ռ�ձ�
//  @return     void
//  @since      v1.0
//  Sample usage:   ����ȫ��,��������PWM,����ɲ��
//-------------------------------------------------------------------------------------------------------------------
void motor_brake(uint16 duty)
{
    // A�����Ź�
    GPIOA->CFGHR &= ~(0xf<<0);
    GPIOA->CFGHR |= (0x3<<0);
    GPIOA->BCR = PHASE_A_GPIO_HIGH;
    // A�����ſ�
    GPIOA->CFGLR  &= ~(0xf<<28);
    GPIOA->CFGLR|= (0x3<<28);
    GPIOA->BSHR = PHASE_A_GPIO_LOW;
    // B�����Ź�
    GPIOA->CFGHR &= ~(0xf<<4);
    GPIOA->CFGHR |= (0x3<<4);
    GPIOA->BCR = PHASE_B_GPIO_HIGH;
    // B�����ſ�
    GPIOB->CFGLR  &= ~(0xf<<0);
    GPIOB->CFGLR|= (0x3<<0);
    GPIOB->BSHR = PHASE_B_GPIO_LOW;
    // C�����Ź�
    GPIOA->CFGHR &= ~(0xf<<8);
    GPIOA->CFGHR |= (0x3<<8);
    GPIOA->BCR = PHASE_C_GPIO_HIGH;
    // C�����ſ�
    GPIOB->CFGLR  &= ~(0xf<<4);
    GPIOB->CFGLR |= (0x3<<4);
    GPIOB->BSHR = PHASE_C_GPIO_LOW;

    pwm_duty_update(duty);
}
