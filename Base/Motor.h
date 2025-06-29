#ifndef __MOTOR_H__
#define __MOTOR_H__
#include "main.h"
#include "gpio.h"
#include "tim.h"

#define PERIOD 2100

#define PWM_TIM &htim2
#define PWMA TIM_CHANNEL_1
#define PWMB TIM_CHANNEL_2



void Motor_Init(void);
void Motor_Forward(uint8_t duty1, uint8_t duty2);

void Set_Motor_Duty(uint8_t duty1, uint8_t duty2);



#endif
