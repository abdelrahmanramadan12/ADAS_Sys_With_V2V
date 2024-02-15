/*
 * Speed_Module.h
 *
 *  Created on: Dec , 2023
 *      Author: Abdelrahman Osama
 */

#ifndef INC_SPEED_MODULE_H_
#define INC_SPEED_MODULE_H_






// Enum for different speed levels
typedef enum {
    SPEED_LEVEL_1 = 40,
    SPEED_LEVEL_2 = 55,
    SPEED_LEVEL_3 = 60,
    SPEED_LEVEL_4 = 85,
    SPEED_LEVEL_5 = 100,
} SpeedLevel;


/**
  * @brief  Set the desiredc speed to the motor.
  * @param  enum for the specific duty cycle.
  * @retval void.
  * @note  this function set the desired speed with the duty cycle to control the speed of motor
  */
void SetMotorSpeed(SpeedLevel speed);



#endif /* INC_SPEED_MODULE_H_ */
