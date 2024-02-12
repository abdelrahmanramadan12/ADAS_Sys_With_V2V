/*
 * Speed_Module.c
 *
 *  Created on: Dec , 2023
 *      Author: Abdelrahman Osama
 */



//

#include "stm32f4xx_hal.h"
#include "Speed_Module.h"



extern TIM_HandleTypeDef htim9;




void SetMotorSpeed(SpeedLevel speed) {

   void SetMotorSpeed(SpeedLevel speed) {
    // Create a structure to hold PWM configuration settings
    TIM_OC_InitTypeDef sConfigOC;
    
    // Configure PWM mode
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    
    // Set the pulse width (duty cycle) based on the provided speed level
    sConfigOC.Pulse = speed;
    
    // Configure the output polarity (whether the output is active high or low)
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    
    // Disable fast mode for PWM output
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    
    // Configure PWM channel on Timer 9 with the provided settings
    HAL_TIM_PWM_ConfigChannel(&htim9, &sConfigOC, TIM_CHANNEL_1);
    
    // Start PWM generation on Timer 9, Channel 1
    HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_1);
}

}
}
}