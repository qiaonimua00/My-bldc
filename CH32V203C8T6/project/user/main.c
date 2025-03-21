#include "led.h"
#include "control.h"
#include "opma.h"
#include "usart.h"

// 电机未运行			RUN闪烁，ERR熄灭
// 正常运行           	RUN常亮, ERR熄灭
// 电池电压过低       	RUN熄灭，ERR常亮
// 电机堵转        		RUN熄灭，ERR闪烁

int main(void)
{
    motor.run_flag=MOTOR_START;
    motor.duty = 450;
    motor.step=2;
    led_init();

    extern void SysTick_Handler(void);
    extern void EXTI2_IRQHandler(void);
    SetVTFIRQ((uint32)EXTI2_IRQHandler,   EXTI2_IRQn,     0, ENABLE);
    SetVTFIRQ((uint32)SysTick_Handler,    SysTicK_IRQn,   3, ENABLE);

    // debug串口初始化
    usart_init(921600);

    //运放初始化
    opama_init();

    //初始化TIM1输出互补PWM
    pwm_complementary_init();


    //TIM3
    advance_commutation_count_init();

    //TIM4
    commutation_time_count_init();


    pa2_exit_init();


    led_run_control(LED_ON);
    led_err_control(LED_OFF);

    //滴答定时器
    pit_init();
    while(1)
    {

    }
}



