/*
 * HAL_Interface.h
 *
 *  Created on: Feb 29, 2024
 *      Author: hp
 */

#ifndef INC_HAL_INTERFACE_H_
#define INC_HAL_INTERFACE_H_

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim10;

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);;
 void MX_TIM3_Init(void);
 void MX_TIM4_Init(void);
 void MX_TIM10_Init(void);

#endif /* INC_HAL_INTERFACE_H_ */
