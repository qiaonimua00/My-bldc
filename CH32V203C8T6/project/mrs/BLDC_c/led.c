#include "led.h"

void led_run_control(LED_STATUS_enum state)
{
    if(state == LED_ON)
    {
        GPIOB->BCR = LED_RUN_PIN;
    }
    else
    {
        GPIOB->BSHR = LED_RUN_PIN;
    }
}

void led_err_control(LED_STATUS_enum state)
{
    if(state == LED_ON)
    {
        GPIOB->BCR = LED_ERR_PIN;
    }
    else
    {
        GPIOB->BSHR = LED_ERR_PIN;
    }
}



void led_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitTypeDef        GPIO_InitStruct = {0};
    GPIO_InitStruct.GPIO_Pin = LED_RUN_PIN;
    GPIO_InitStruct.GPIO_Mode= GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = LED_ERR_PIN;
    GPIO_InitStruct.GPIO_Mode= GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    led_run_control(LED_OFF);
    led_err_control(LED_OFF);
}
