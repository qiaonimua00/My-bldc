#include "ch32v20x.h"
#include "control.h"
#include "opma.h"
#include  "led.h"
#include  "usart.h"


void NMI_Handler        (void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler  (void) __attribute__((interrupt("WCH-Interrupt-fast")));
void SysTick_Handler    (void) __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM2_IRQHandler    (void) __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM3_IRQHandler    (void) __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM4_IRQHandler    (void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI2_IRQHandler   (void) __attribute__((interrupt("WCH-Interrupt-fast")));
void USART1_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));


void SysTick_Handler(void)
{
//       static int count_hx=0;
//       static unsigned char pin_A2 =10;
//       // 关闭定时器1，更新中断
//       TIM1->DMAINTENR &= ~TIM_IT_Update;
//       // 关闭定时器3，更新中断
//       TIM3->DMAINTENR &= ~TIM_IT_Update;
//       // 关闭定时器4，更新中断
//       TIM4->DMAINTENR &= ~TIM_IT_Update;
//       // 关闭PA2外部引脚中断
//       disable_opama_interrupts();
//
//       motor.duty_register = 350;
//       pwm_duty_update(motor.duty_register);
//
//       count_hx++;
//       if(count_hx>=5000)
//       {
//           count_hx=0;
//           motor_next_step_fan();
//
//       }

    pit_callback();

//    if(count_hx<5000)
//    {
//        pwm_a_cn_output();
//        count_hx++;
//    }
//    else
//    {
//        led_run_control(LED_OFF);
//        led_err_control(LED_ON);
//        pwm_an_bn_cn_off();
//        enable_opama_interrupts();
//        EXTI->RTENR = 0;
//        EXTI->FTENR = (1<<2);       // 下降沿
//        pin_A2 = (GPIOA->INDR & GPIO_Pin_2);
//    }





    SysTick->SR = 0;
}


void TIM2_IRQHandler(void)
{
    TIM2->INTFR = ~TIM_FLAG_CC4;
}

void TIM3_IRQHandler(void)
{
    commutation_and_degauss_callback();
    TIM3->INTFR = 0;
}

void TIM4_IRQHandler(void)
{

    TIM4->INTFR = 0;
}

void EXTI2_IRQHandler(void)
{

    opama_callback();
    EXTI->INTFR = EXTI_Line2;

}

char rx_date;
volatile char buff[2];
unsigned char point=0;

void USART1_IRQHandler(void)
{

    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
    {
        rx_date = USART_ReceiveData(USART1);
        buff[point++] = rx_date;
        if(point>1)
        {

            if( buff[0]==1)
            {

                motor.duty = 10.9375 * buff[1]+200;
                if( motor.duty<200)motor.duty=200;
                else if(motor.duty>3000)motor.duty=3000;
                uart_write_byte(0x11);
            }
            if (buff[0]==0x02)
            {

                if(buff[1]==0x1)
                {
                    motor.run_flag = MOTOR_START;
                    uart_write_byte(0x44);
                }
                if (buff[1]==0x2)
                {
                    motor.run_flag = MOTOR_STOP;
                    uart_write_byte(0x55);
                }
                if (buff[1]==0x3)
                {
                    motor.run_flag = MOTOR_HX;
                    uart_write_byte(0x66);
                }

            }
            point=0;
            buff[0]=0;
            buff[1]=0;

        }


        uart_write_byte(rx_date);
        USART_ClearITPendingBit(USART1 , USART_IT_IDLE);

    }

}


/*********************************************************************
 * @fn      NMI_Handler
 *
 * @brief   This function handles NMI exception.
 *
 * @return  none
 */
void NMI_Handler(void)
{
}



/*********************************************************************
 * @fn      HardFault_Handler
 *
 * @brief   This function handles Hard Fault exception.
 *
 * @return  none
 */
void HardFault_Handler(void)
{


}


