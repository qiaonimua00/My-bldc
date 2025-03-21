#ifndef _pwm_output_h_
#define _pwm_output_h_

#include "ch32v20x.h"
#include "bldc_config.h"

typedef struct
{
    volatile uint8  run_flag;                       // 电机正在运行标志位
    short   step;                           // 电机运行的步骤
    uint16  commutation_time[6];            // 最近6次换相时间
    int32   duty;                           // PWM占空比       用户改变电机速度时修改此变量
    int32   duty_register;                  // PWM占空比寄存器 用户不可操作
    uint32  commutation_faile_count;        // 换向失败计数
    uint32  filter_commutation_time_sum;    // 滤波后的换向总和
    uint32  commutation_time_sum;           // 最近6次换相时间总和
    uint32  commutation_num;                // 统计换相次数
}motor_struct;



#define PHASE_A_GPIO_LOW        GPIO_Pin_7
#define PHASE_A_GPIO_HIGH       GPIO_Pin_8

#define PHASE_B_GPIO_LOW        GPIO_Pin_0
#define PHASE_B_GPIO_HIGH       GPIO_Pin_9

#define PHASE_C_GPIO_LOW        GPIO_Pin_1
#define PHASE_C_GPIO_HIGH       GPIO_Pin_10





void pwm_complementary_init(void);
void motor_commutation_execute(uint8 step);
void motor_next_step();
void pwm_duty_update(uint16 duty);


void pwm_a_bn_output(void);
void pwm_a_cn_output(void);
void pwm_b_cn_output(void);
void pwm_b_an_output(void);
void pwm_c_an_output(void);
void pwm_c_bn_output(void);
void pwm_an_bn_cn_off(void);
void motor_next_step_fan();


#endif
