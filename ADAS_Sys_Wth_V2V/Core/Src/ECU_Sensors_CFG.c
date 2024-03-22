/*
 * ECU_Sensors_CFG.c
 *
 *  Created on: Feb 29, 2024
 *      Author: hp
 */

#include "ECU_Sensors_CFG.h"
#include "stm32f4xx_hal.h"


#include "HAL_Interface.h"



Ultrasonic_HandleTypeDEf Ultrasonics[]=
{
		{GPIOA,GPIOB,&htim3,TIM_CHANNEL_1,GPIO_PIN_6,GPIO_PIN_13},
		{GPIOA,GPIOB,&htim3,TIM_CHANNEL_2,GPIO_PIN_7,GPIO_PIN_14},
		{GPIOA,GPIOB,&htim3,TIM_CHANNEL_1,GPIO_PIN_6,GPIO_PIN_13},
		{GPIOB,GPIOB,&htim3,TIM_CHANNEL_1,GPIO_PIN_0,GPIO_PIN_0},
		{GPIOB,GPIOB,&htim3,TIM_CHANNEL_1,GPIO_PIN_0,GPIO_PIN_0},
		{GPIOA,GPIOB,&htim3,TIM_CHANNEL_2,GPIO_PIN_7,GPIO_PIN_14},
};
