#include "pwm_output.h"
#include "bldc_config.h"
motor_struct motor;




void pwm_duty_update(uint16 duty)
{

    if (BLDC_MAX_DUTY < duty)
    {
        duty = BLDC_MAX_DUTY;
    }

    TIM1->ATRLR = BLDC_MAX_DUTY - 1;
    TIM1->CH1CVR = duty;
    TIM1->CH2CVR = duty;
    TIM1->CH3CVR = duty;
}


void pwm_a_bn_output()
{
    // A相上桥PWM
    GPIOA->CFGHR &= ~(0xf<<0);
    GPIOA->CFGHR |= (0xb<<0);


    // A相下桥关
    GPIOA->CFGLR  &= ~(0xf<<28);
    GPIOA->CFGLR|= (0x3<<28);
    GPIOA->BCR = PHASE_A_GPIO_LOW;

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
    GPIOA->BCR = PHASE_C_GPIO_HIGH;//high close
    // C相下桥关
    GPIOB->CFGLR &= ~(0xf<<4);
    GPIOB->CFGLR |= (0x3<<4);
    GPIOB->BCR = PHASE_C_GPIO_LOW;  //low close
}

void pwm_a_cn_output()
{
    // A相上桥PWM
    GPIOA->CFGHR &= ~(0xf<<0);
    GPIOA->CFGHR |= (0xb<<0);
    // A相下桥关
    GPIOA->CFGLR  &= ~(0xf<<28);
    GPIOA->CFGLR|= (0x3<<28);
    GPIOA->BCR = PHASE_A_GPIO_LOW;

    // C相上桥关
    GPIOA->CFGHR &= ~(0xf<<8);
    GPIOA->CFGHR |= (0x3<<8);
    GPIOA->BCR = PHASE_C_GPIO_HIGH;
    // C相下桥开
    GPIOB->CFGLR  &= ~(0xf<<4);
    GPIOB->CFGLR |= (0x3<<4);
    GPIOB->BSHR = PHASE_C_GPIO_LOW;
    // B相上桥关
    GPIOA->CFGHR &= ~(0xf<<4);
    GPIOA->CFGHR |= (0x3<<4);
    GPIOA->BCR = PHASE_B_GPIO_HIGH; //high close
    // B相下桥关
    GPIOB->CFGLR  &= ~(0xf<<0);
    GPIOB->CFGLR|= (0x3<<0);
    GPIOB->BCR = PHASE_B_GPIO_LOW;  //low close
}

void pwm_b_cn_output()
{
    // B相上桥PWM
    GPIOA->CFGHR &= ~(0xf<<4);
    GPIOA->CFGHR |= (0xb<<4);

    // B相下桥关
    GPIOB->CFGLR  &= ~(0xf<<0);
    GPIOB->CFGLR|= (0x3<<0);
    GPIOB->BCR = PHASE_B_GPIO_LOW;  //low close

    // C相上桥关
    GPIOA->CFGHR &= ~(0xf<<8);
    GPIOA->CFGHR |= (0x3<<8);
    GPIOA->BCR = PHASE_C_GPIO_HIGH;
    // C相下桥开
    GPIOB->CFGLR  &= ~(0xf<<4);
    GPIOB->CFGLR |= (0x3<<4);
    GPIOB->BSHR = PHASE_C_GPIO_LOW;
    // A相上桥关
    GPIOA->CFGHR &= ~(0xf<<0);
    GPIOA->CFGHR |= (0x3<<0);
    GPIOA->BCR = PHASE_A_GPIO_HIGH;
    // A相下桥关
    GPIOA->CFGLR  &= ~(0xf<<28);
    GPIOA->CFGLR|= (0x3<<28);
    GPIOA->BCR = PHASE_A_GPIO_LOW;
}


void pwm_b_an_output()
{
    // B相上桥PWM
    GPIOA->CFGHR &= ~(0xf<<4);
    GPIOA->CFGHR |= (0xb<<4);

    // B相下桥关
    GPIOB->CFGLR  &= ~(0xf<<0);
    GPIOB->CFGLR|= (0x3<<0);
    GPIOB->BCR = PHASE_B_GPIO_LOW;  //low close


    // A相上桥关
    GPIOA->CFGHR &= ~(0xf<<0);
    GPIOA->CFGHR |= (0x3<<0);
    GPIOA->BCR = PHASE_A_GPIO_HIGH; //high close
    // A相下桥开
    GPIOA->CFGLR  &= ~(0xf<<28);
    GPIOA->CFGLR|= (0x3<<28);
    GPIOA->BSHR = PHASE_A_GPIO_LOW;   // low on
    // C相上桥关
    GPIOA->CFGHR &= ~(0xf<<8);
    GPIOA->CFGHR |= (0x3<<8);
    GPIOA->BCR = PHASE_C_GPIO_HIGH;//high close
    // C相下桥关
    GPIOB->CFGLR  &= ~(0xf<<4);
    GPIOB->CFGLR |= (0x3<<4);
    GPIOB->BCR = PHASE_C_GPIO_LOW;  //low close
}

void pwm_c_an_output()
{
    // C相上桥PWM
    GPIOA->CFGHR &= ~(0xf<<8);
    GPIOA->CFGHR |= (0xb<<8);

    // C相下桥关
    GPIOB->CFGLR  &= ~(0xf<<4);
    GPIOB->CFGLR |= (0x3<<4);
    GPIOB->BCR = PHASE_C_GPIO_LOW;  //low close
    // A相上桥关
    GPIOA->CFGHR &= ~(0xf<<0);
    GPIOA->CFGHR |= (0x3<<0);
    GPIOA->BCR = PHASE_A_GPIO_HIGH; //high close
    // A相下桥开
    GPIOA->CFGLR  &= ~(0xf<<28);
    GPIOA->CFGLR|= (0x3<<28);
    GPIOA->BSHR = PHASE_A_GPIO_LOW;   // low on
    // B相上桥关
    GPIOA->CFGHR &= ~(0xf<<4);
    GPIOA->CFGHR |= (0x3<<4);
    GPIOA->BCR = PHASE_B_GPIO_HIGH; //high close
    // B相下桥关
    GPIOB->CFGLR  &= ~(0xf<<0);
    GPIOB->CFGLR|= (0x3<<0);
    GPIOB->BCR = PHASE_B_GPIO_LOW;  //low close
}

void pwm_c_bn_output()
{
    // C相上桥PWM
    GPIOA->CFGHR &= ~(0xf<<8);
    GPIOA->CFGHR |= (0xb<<8);

    // C相下桥关
    GPIOB->CFGLR  &= ~(0xf<<4);
    GPIOB->CFGLR |= (0x3<<4);
    GPIOB->BCR = PHASE_C_GPIO_LOW;  //low close

    // B相上桥关
    GPIOA->CFGHR &= ~(0xf<<4);
    GPIOA->CFGHR |= (0x3<<4);
    GPIOA->BCR = PHASE_B_GPIO_HIGH;
    // B相下桥开
    GPIOB->CFGLR  &= ~(0xf<<0);
    GPIOB->CFGLR|= (0x3<<0);
    GPIOB->BSHR = PHASE_B_GPIO_LOW;
    // A相上桥关
    GPIOA->CFGHR &= ~(0xf<<0);
    GPIOA->CFGHR |= (0x3<<0);
    GPIOA->BCR = PHASE_A_GPIO_HIGH;
    // A相下桥关
    GPIOA->CFGLR  &= ~(0xf<<28);
    GPIOA->CFGLR|= (0x3<<28);
    GPIOA->BCR = PHASE_A_GPIO_LOW;
}

void pwm_an_bn_cn_off()
{
    // A相上桥关
    GPIOA->CFGHR &= ~(0xf<<0);
    GPIOA->CFGHR |= (0x3<<0);
    GPIOA->BCR = PHASE_A_GPIO_HIGH;
    // A相下桥关
    GPIOA->CFGLR  &= ~(0xf<<28);
    GPIOA->CFGLR|= (0x3<<28);
    GPIOA->BCR = PHASE_A_GPIO_LOW;
    // B相上桥关
    GPIOA->CFGHR &= ~(0xf<<4);
    GPIOA->CFGHR |= (0x3<<4);
    GPIOA->BCR = PHASE_B_GPIO_HIGH;
    // B相下桥关
    GPIOB->CFGLR  &= ~(0xf<<0);
    GPIOB->CFGLR|= (0x3<<0);
    GPIOB->BCR = PHASE_B_GPIO_LOW;
    // C相上桥关
    GPIOA->CFGHR &= ~(0xf<<8);
    GPIOA->CFGHR |= (0x3<<8);
    GPIOA->BCR = PHASE_C_GPIO_HIGH;
    // C相下桥关
    GPIOB->CFGLR  &= ~(0xf<<4);
    GPIOB->CFGLR |= (0x3<<4);
    GPIOB->BCR = PHASE_C_GPIO_LOW;
}


//void motor_brake(uint16 duty)
//{
//    // A相上桥关
//    GPIOA->CFGHR &= ~(0xf<<0);
//    GPIOA->CFGHR |= (0x3<<0);
//    GPIOA->BCR = PHASE_A_GPIO_HIGH;
//    // A相下桥开
//    GPIOA->CFGLR  &= ~(0xf<<28);
//    GPIOA->CFGLR|= (0x3<<28);
//    GPIOA->BSHR = PHASE_A_GPIO_LOW;
//    // B相上桥关
//    PHASE_B_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<4);
//    PHASE_B_GPIO_PORT_HIGH->CFGHR |= (0x3<<4);
//    PHASE_B_GPIO_PORT_HIGH->HIGH_BITREG_OFF = PHASE_B_GPIO_HIGH;
//    // B相下桥开
//    PHASE_B_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<0);
//    PHASE_B_GPIO_PORT_LOW->CFGLR|= (0x3<<0);
//    PHASE_B_GPIO_PORT_LOW->LOW_BITREG_ON = PHASE_B_GPIO_LOW;
//    // C相上桥关
//    PHASE_C_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<8);
//    PHASE_C_GPIO_PORT_HIGH->CFGHR |= (0x3<<8);
//    PHASE_C_GPIO_PORT_HIGH->HIGH_BITREG_OFF = PHASE_C_GPIO_HIGH;
//    // C相下桥开
//    PHASE_C_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<4);
//    PHASE_C_GPIO_PORT_LOW->CFGLR |= (0x3<<4);
//    PHASE_C_GPIO_PORT_LOW->LOW_BITREG_ON = PHASE_C_GPIO_LOW;
//
//    pwm_duty_update(duty);
//}




void motor_commutation_execute(uint8 step)
{
//    TIM1->CTLR1 &= ~TIM_CEN;
//    pwm_an_bn_cn_off();
    switch(step)
    {
        case 0:
        {
            pwm_a_bn_output();
        }
        break;
        case 1:
        {
            pwm_a_cn_output();
        }
        break;
        case 2:
        {
            pwm_b_cn_output();
        }
        break;
        case 3:
        {
            pwm_b_an_output();
        }
        break;
        case 4:
        {
            pwm_c_an_output();
        }
        break;
        case 5:
        {
            pwm_c_bn_output();
        }
        break;
    }
//    TIM1->CTLR1 |=  TIM_CEN;
}

void motor_next_step()
{
    motor.step++;
    if (motor.step > 5)
    {
        motor.step = 0;
    }
    // 换相
    motor_commutation_execute(motor.step);
    // 设置比较器通道
    if (motor.step == 0 || motor.step == 3)
    {
        OPA->CR = 0x70;  //C   out = 0
    }
    if (motor.step == 1 || motor.step == 4)
    {
        OPA->CR = 0x10;  //B   out=0
    }
    if (motor.step == 2 || motor.step == 5)
    {
        OPA->CR = 0x01;  //A   out = 0
    }
    // 开启对应的边沿检测
    if ((motor.step % 2))
    {
        EXTI->RTENR = 0;
        EXTI->FTENR = (1<<2);       // 下降沿
    }
    else
    {
        EXTI->FTENR = 0;
        EXTI->RTENR = (1<<2);       // 上升沿
    }
}


void motor_next_step_fan()
{
    motor.step--;
    if (motor.step <0)
    {
        motor.step = 5;
    }
    // 换相
    motor_commutation_execute(motor.step);
    // 设置比较器通道
    if (motor.step == 0 || motor.step == 3)
    {
        OPA->CR = 0x70;  //C   out = 0
    }
    if (motor.step == 1 || motor.step == 4)
    {
        OPA->CR = 0x10;  //B   out=0
    }
    if (motor.step == 2 || motor.step == 5)
    {
        OPA->CR = 0x01;  //A   out = 0
    }
    // 开启对应的边沿检测
    if ((motor.step % 2))
    {
        EXTI->FTENR = 0;
        EXTI->RTENR = (1<<2);       // 上升沿

    }
    else
    {
        EXTI->RTENR = 0;
        EXTI->FTENR = (1<<2);       // 下降沿


    }
}


void pwm_complementary_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
    GPIO_PinRemapConfig(GPIO_PartialRemap_TIM1, ENABLE);            // 重映射
    GPIO_InitTypeDef        GPIO_InitStruct = {0};
    GPIO_InitStruct.GPIO_Pin = PHASE_A_GPIO_LOW;
    GPIO_InitStruct.GPIO_Mode= GPIO_Mode_AF_PP ;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = PHASE_B_GPIO_LOW;
    GPIO_InitStruct.GPIO_Mode= GPIO_Mode_AF_PP ;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = PHASE_C_GPIO_LOW;
    GPIO_InitStruct.GPIO_Mode= GPIO_Mode_AF_PP ;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = PHASE_A_GPIO_HIGH;
    GPIO_InitStruct.GPIO_Mode= GPIO_Mode_AF_PP ;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = PHASE_B_GPIO_HIGH;
    GPIO_InitStruct.GPIO_Mode= GPIO_Mode_AF_PP ;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = PHASE_C_GPIO_HIGH;
    GPIO_InitStruct.GPIO_Mode= GPIO_Mode_AF_PP ;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    TIM_OCInitTypeDef       TIM_OCInitStructure = {0};
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure = {0};
    TIM_BDTRInitTypeDef     TIM_BDTRInitStructure = {0};
    TIM_DeInit(TIM1);
    TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
    TIM_TimeBaseInitStructure.TIM_Period = BLDC_MAX_DUTY - 1;                   // 设置定时器周期值
    TIM_TimeBaseInitStructure.TIM_Prescaler = 0;                                // 定时器时钟不分频
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;                 // 不分频
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;             // 中心对齐模式  PWM频率=定时器输入时钟频率/(2*周期值)
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;                        // 占空比的更新频率=定时器输入时钟频率/((TIM_RepetitionCounter+1)*周期值)
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);

    TIM_OCStructInit(&TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;                           // PWM模式1，定时器计数值小于比较值的时候，引脚输出有效电平
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Disable;               // CHx通道使能
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;             //
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;                   // CHx  有效电平为高电平 无效电平为低电平
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;                // CHx  空闲状态输出低电平
    TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;                 // CHxN 有效电平为高电平 无效电平为低电平
    TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;              // CHxN 空闲状态输出低电平
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OC1Init(TIM1, &TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OC2Init(TIM1, &TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OC3Init(TIM1, &TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OC4Init(TIM1, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
    TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
    TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
    TIM_OC1FastConfig(TIM1, TIM_OCFast_Disable);
    TIM_OC2FastConfig(TIM1, TIM_OCFast_Disable);
    TIM_OC3FastConfig(TIM1, TIM_OCFast_Disable);
    TIM_BDTRStructInit(&TIM_BDTRInitStructure);
    TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Disable;
    TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Disable;
    TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_OFF;
    TIM_BDTRInitStructure.TIM_DeadTime = BLDC_PWM_DEADTIME;                          // PWM死区时间
    TIM_BDTRInitStructure.TIM_Break = TIM_Break_Disable;                        // 刹车失能
    TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_High;           // 刹车极性为高，高电平的时候刹车
    TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Disable;    // 当刹车信号无效的时候自动开启输出
    TIM_BDTRConfig(TIM1, &TIM_BDTRInitStructure);
    TIM_ITConfig(TIM1, TIM_IT_Break,    DISABLE);                   // 关闭刹车中断
    TIM_ITConfig(TIM1, TIM_IT_Update,   DISABLE);                   // 关闭更新中断
    TIM_ITConfig(TIM1, TIM_IT_Trigger,  DISABLE);                   // 允许定时器更新中断
    TIM_ITConfig(TIM1, TIM_IT_COM,      DISABLE);
    TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Enable);
    TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Enable);
    TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Enable);
    TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Enable);
    TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Enable);
    TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Enable);
    TIM_Cmd(TIM1, ENABLE);
    TIM_CtrlPWMOutputs(TIM1, ENABLE);
    TIM_ARRPreloadConfig(TIM1, ENABLE);                             // 使能自动重装载预装载使能
    TIM_GenerateEvent(TIM1, TIM_EventSource_Update);

}
