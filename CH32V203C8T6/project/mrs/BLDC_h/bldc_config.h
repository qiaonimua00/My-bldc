#ifndef _bldc_config_h_
#define _bldc_config_h_

#define uint16  unsigned short
#define uint8  unsigned char
typedef unsigned int        uint32;                                             // �޷��� 32 bits
typedef signed int          int32;                                              // �з��� 32 bits


#define BLDC_MAX_DUTY               (3000)          // ���Ƶ��Ϊ48kHZ��PWM�����ռ�ձȣ���Ҫ���и���PWM��ʼ��ȥ����
                                                    // ���㹫ʽ��SystemCoreClock / 48000 = 3000
                                                    // SystemCoreClock = 144000000

#define BLDC_PWM_DEADTIME           (30)            // PWM��������
#define BLDC_STALL_TIME_OUT         (200)           // ��ת��ʱ��⣬��λms

#define BLDC_OPEN_LOOP_WRITE        (10 )           // �����ȴ��������

#define BLDC_POLES                  (7  )           // ���������
#define BLDC_CLOSE_LOOP_WRITE       (30 )           // �ջ��ȴ��������

#define BLDC_SPEED_INCREMENTAL      (1 )            // ���μ������ֵ 1-15�����޸������߼�����Ӧ��
                                                    // ����1��Ӧ�ٶ�����������15��Ӧ�ٶ���졣
                                                    // ��Ӧ�ٶ�Խ�죬Խ���׳��ֻ���������Խ����1��ʼ��һ��һ�����ӡ�
#define BLDC_BRAKE_DUTY             (100)           // ɲ��ʱ��ռ�ձ�.

#define BLDC_COMMUTATION_FAILED_MAX (200 )          // ������������� ���������������Ϊ�����ת

#endif
