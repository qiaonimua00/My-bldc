#ifndef _pwm_output_h_
#define _pwm_output_h_

#include "ch32v20x.h"
#include "bldc_config.h"

typedef struct
{
    volatile uint8  run_flag;                       // ����������б�־λ
    short   step;                           // ������еĲ���
    uint16  commutation_time[6];            // ���6�λ���ʱ��
    int32   duty;                           // PWMռ�ձ�       �û��ı����ٶ�ʱ�޸Ĵ˱���
    int32   duty_register;                  // PWMռ�ձȼĴ��� �û����ɲ���
    uint32  commutation_faile_count;        // ����ʧ�ܼ���
    uint32  filter_commutation_time_sum;    // �˲���Ļ����ܺ�
    uint32  commutation_time_sum;           // ���6�λ���ʱ���ܺ�
    uint32  commutation_num;                // ͳ�ƻ������
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
