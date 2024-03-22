
/*
 * ECU_Sensors_Interface.h
 *
 *  Created on: Feb 29, 2024
 *      Author: hp
 */

#ifndef INC_ECU_SENSORS_INTERFACE_H_
#define INC_ECU_SENSORS_INTERFACE_H_

#include "ECU_Sensors_CFG.h"



ErrorStatus  Get_HCSR04_Distance (Ultrasonics_Index ultrasonic,uint16_t* Distance);
void Ultrasonics_Init(void);

#endif /* INC_ECU_SENSORS_INTERFACE_H_ */
