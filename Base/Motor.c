#include "Motor.h"

static void Set_AIN1(uint8_t x)
{
    HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, (GPIO_PinState)x);
}
static void Set_AIN2(uint8_t x)
{
    HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, (GPIO_PinState)x);
}
static void Set_BIN1(uint8_t x)
{
    HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, (GPIO_PinState)x);
}
static void Set_BIN2(uint8_t x)
{
    HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, (GPIO_PinState)x);
}



void Motor_Init(void)
{
    HAL_TIM_PWM_Start(PWM_TIM, PWMA);
    HAL_TIM_PWM_Start(PWM_TIM, PWMB);
    Set_Motor_Duty(0,0);
}





void Motor_Forward(uint8_t duty1, uint8_t duty2)
{
    Set_AIN1(0);
    Set_AIN2(1);
    Set_BIN1(1);
    Set_BIN2(0);
    Set_Motor_Duty(duty1, duty2);

}

void Set_Motor_Duty(uint8_t duty1, uint8_t duty2)
{
    uint16_t duty[2] = {duty1, duty2};
    duty[0] = duty1 * PERIOD / 100;
    duty[1] = duty2 * PERIOD / 100;
    __HAL_TIM_SET_COMPARE(PWM_TIM, PWMA, duty[0]);
    __HAL_TIM_SET_COMPARE(PWM_TIM, PWMB, duty[1]);
}

