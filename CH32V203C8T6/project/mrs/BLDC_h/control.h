#ifndef _control_h_
#define _control_h_

#include "ch32v20x.h"
#include "pwm_output.h"
typedef enum
{
    MOTOR_IDLE = 0,
    MOTOR_START,
    MOTOR_OPEN_LOOP,
    MOTOR_CLOSE_LOOP ,
    MOTOR_STOP_STALL,
    MOTOR_RESTART,

    BYTE_LOW_VOLTAGE,
    MOTOR_STOP,
    MOTOR_HX,

}run_state_enum;


extern motor_struct motor;

void pit_init(void);
void pit_callback(void);
void commutation_time_count_init(void);
void advance_commutation_count_init(void);
void opama_callback();
void commutation_and_degauss_callback();
void motor_brake(uint16 duty);

#endif
