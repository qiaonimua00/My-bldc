#ifndef _led_h_
#define _led_h_

#include "ch32v20x.h"

typedef enum
{
    LED_ON,
    LED_OFF,
}LED_STATUS_enum;


#define LED_RUN_PIN   GPIO_Pin_9
#define LED_ERR_PIN   GPIO_Pin_8


void led_init(void);

void led_run_control(LED_STATUS_enum state);
void led_err_control(LED_STATUS_enum state);

#endif
