#include "usart.h"

//-------------------------------------------------------------------------------------------------------------------
//  @brief      调试u串口初始化
//  @param      baudrate     波特率
//  @return     void
//  @since
//-------------------------------------------------------------------------------------------------------------------
void usart_init(uint32 baudrate)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure = {0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_USART1,ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = baudrate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART_Init(USART1, &USART_InitStructure);

    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_Cmd(USART1, ENABLE);
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      串口发送数组
//  @param      buff        要发送的数组地址
//  @param      len         数据长度
//  @return     void
//  @note
//-------------------------------------------------------------------------------------------------------------------
void uart_write_buffer(const uint8 *buff, uint32 len)
{
    while(len--)
    {
        uart_write_byte(*buff++);
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      串口发送一个字节
//  @param      dat     传输的数据
//  @return     void
//  @note
//-------------------------------------------------------------------------------------------------------------------
void uart_write_byte(const uint8 dat)
{
    while((USART1->STATR & USART_FLAG_TXE)==0);
    USART1->DATAR = dat;
}

