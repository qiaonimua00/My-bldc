#include  "opma.h"
#include "bldc_config.h"



void enable_opama_interrupts(void)
{
//    EXTI->INTFR = EXTI_Line2;           // 清除中断标志位
    EXTI->INTENR |= (1 << 2);           // 打开PA2外部引脚中断
}


void disable_opama_interrupts(void)
{
    EXTI->INTENR &= ~(1 << 2);          // 关闭PA2外部引脚中断
    EXTI->INTFR = EXTI_Line2;           // 清除中断标志位
}



void opama_init(void)
{
    GPIO_InitTypeDef        GPIO_InitStruct = {0};
    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_5;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_14|GPIO_Pin_15;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_4 | GPIO_Pin_3 | GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    OPA->CR = 0x01;
}



void pa2_exit_init()
{
    EXTI_InitTypeDef        EXTI_InitStructure = {0};
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource2);
    EXTI_InitStructure.EXTI_Line = EXTI_Line2;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
    EXTI_ClearITPendingBit(EXTI_Line2);
    NVIC_SetPriority(EXTI2_IRQn, 0x00);
    NVIC_EnableIRQ(EXTI2_IRQn);
}
