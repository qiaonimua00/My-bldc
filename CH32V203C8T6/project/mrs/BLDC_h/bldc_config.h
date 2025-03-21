#ifndef _bldc_config_h_
#define _bldc_config_h_

#define uint16  unsigned short
#define uint8  unsigned char
typedef unsigned int        uint32;                                             // 无符号 32 bits
typedef signed int          int32;                                              // 有符号 32 bits


#define BLDC_MAX_DUTY               (3000)          // 输出频率为48kHZ，PWM的最大占空比，需要自行根据PWM初始化去计算
                                                    // 计算公式：SystemCoreClock / 48000 = 3000
                                                    // SystemCoreClock = 144000000

#define BLDC_PWM_DEADTIME           (30)            // PWM死区设置
#define BLDC_STALL_TIME_OUT         (200)           // 堵转超时检测，单位ms

#define BLDC_OPEN_LOOP_WRITE        (10 )           // 开环等待换向次数

#define BLDC_POLES                  (7  )           // 电机极对数
#define BLDC_CLOSE_LOOP_WRITE       (30 )           // 闭环等待换向次数

#define BLDC_SPEED_INCREMENTAL      (1 )            // 单次加速最大值 1-15，可修改这个提高加速响应，
                                                    // 设置1响应速度最慢，设置15响应速度最快。
                                                    // 响应速度越快，越容易出现换相错误，所以建议从1开始，一点一点增加。
#define BLDC_BRAKE_DUTY             (100)           // 刹车时的占空比.

#define BLDC_COMMUTATION_FAILED_MAX (200 )          // 换相错误最大次数 大于这个次数后认为电机堵转

#endif
