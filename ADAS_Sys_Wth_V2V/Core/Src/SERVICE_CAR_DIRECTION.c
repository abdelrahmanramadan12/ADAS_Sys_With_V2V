/*
 * SERVICE_CAR_DIRECTION.c
 *
 *  Created on: Feb 22, 2024
 *      Author: hp
 */


#include "SERVICE_CAR_DIRECTION.h"
#include "HAL_MOTOR_CFG.h"

void CAR_Directions_Forword (void)
{

	Motor_Select(RIGHT_MOTOR,MOTOR_CCW) ;
	Motor_Select(LIFT_MOTOR,MOTOR_CW) ;


}

void CAR_Directions_Backward (void)
{

	Motor_Select(RIGHT_MOTOR,MOTOR_CW) ;
	Motor_Select(LIFT_MOTOR,MOTOR_CCW) ;



}

void CAR_Directions_Right (void)
{

	Motor_Select(RIGHT_MOTOR,MOTOR_CW) ;
	Motor_Select(LIFT_MOTOR,MOTOR_CW) ;



}
void CAR_Directions_Left (void)
{


	Motor_Select(RIGHT_MOTOR,MOTOR_CCW) ;
	Motor_Select(LIFT_MOTOR,MOTOR_CCW) ;


}
void CAR_Directions_Stop (void)
{




	Motor_Select(RIGHT_MOTOR,MOTOR_STOP) ;
	Motor_Select(LIFT_MOTOR,MOTOR_STOP) ;

}


void CAR_Set_Speed(SpeedLevel speed)
{
	SetMotorSpeed(speed);
}
