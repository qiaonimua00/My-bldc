#ifndef _usart_h_
#define _usart_h_

#include "bldc_config.h"
#include "ch32v20x.h"


void usart_init(uint32 baudrate);
void uart_write_byte(const uint8 dat);
void uart_write_buffer(const uint8 *buff, uint32 len);



#endif
