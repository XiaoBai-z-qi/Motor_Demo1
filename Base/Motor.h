#ifndef __MOTOR_H__
#define __MOTOR_H__
#include "main.h"
#include "gpio.h"
#include "tim.h"

#define PERIOD 2100

#define PWM_TIM &htim2
#define ENCODER1_TIM &htim3
#define ENCODER2_TIM &htim4
#define TIM_10MS &htim6

#define PWMA TIM_CHANNEL_1
#define PWMB TIM_CHANNEL_2
#define E1A TIM_CHANNEL_1
#define E1B TIM_CHANNEL_2
#define E2A TIM_CHANNEL_1
#define E2B TIM_CHANNEL_2



void Motor_Init(void);
void Motor_Forward(uint8_t duty1, uint8_t duty2);
void Get_Encoder_Count(int16_t *count1, int16_t *count2);
void Clear_Encoder_Count(void);
void Set_Motor_Duty(uint8_t duty1, uint8_t duty2);



#endif
