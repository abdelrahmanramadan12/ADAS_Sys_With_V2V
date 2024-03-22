/*
 * APP_TASKS.c
 *
 *  Created on: Mar 6, 2024
 *      Author: hp
 */
#include "stdint.h"
#include "stm32f4xx.h"
#include "ECU_Sensors_Interface.h"
#include "SERVICE_CAR_DIRECTION.h"
#include "APP_CONTROL_SYSTEM.h"
#include "APP_TASKS.h"
#include "V2V_Communication.h"
extern CarDirection_t Current_My_Car_Direction;
extern SpeedLevel Current_My_Car_speed;
extern uint8_t New_Data_Flag;
extern uint8_t Another_Car_Data[CAR_DATA_SIZE];
extern uint8_t Flag_New_Car;

uint16_t Last_Back_Distance;
uint16_t Last_ahead_Distance;
uint16_t my_Position=0;
uint8_t Car_Forward_Status=NOT_FORWARD;

void APP_Init_Task(void)
{
	Ultrasonics_Init();

}

void Prepare_Data_Tasks(void)
{
	 if( Get_HCSR04_Distance(BACKWARD_MIDDLE, &Last_Back_Distance)==ERROR)
	 {
		 Last_Back_Distance=0;
	 }

	 if( Get_HCSR04_Distance(FORWARD_MIDDLE, &Last_ahead_Distance)==ERROR)
	 	 {
		 Last_ahead_Distance=0;
	 	 }


}

void APP_Emergency_Braking_Task(void)
{

	if(Current_My_Car_Direction==IS_BACKWARD)
	{
       if( Last_Back_Distance!=0)
       {

             if(Last_Back_Distance>100 )
             {
               /*nothing*/

             }
             else if(Last_Back_Distance>50)
             {
                  if(Current_My_Car_speed>SPEED_LEVEL_4)
                  {
                	  Current_My_Car_speed=SPEED_LEVEL_4;
                	  CAR_Set_Speed(Current_My_Car_speed);
                  }
             }
             else if(Last_Back_Distance>30)
             {
                 if(Current_My_Car_speed>SPEED_LEVEL_3)
                 {
               	  Current_My_Car_speed=SPEED_LEVEL_3;
               	  CAR_Set_Speed(Current_My_Car_speed);
                 }

             }
             else if(Last_Back_Distance>20)
             {
                 if(Current_My_Car_speed>SPEED_LEVEL_2)
                 {
               	  Current_My_Car_speed=SPEED_LEVEL_2;
               	  CAR_Set_Speed(Current_My_Car_speed);
                 }

             }
             else if(Last_Back_Distance>10)
             {
                 if(Current_My_Car_speed>SPEED_LEVEL_1)
                 {
               	  Current_My_Car_speed=SPEED_LEVEL_1;
               	  CAR_Set_Speed(Current_My_Car_speed);
                 }

             }
             else
             {

               	  Current_My_Car_speed=SPEED_LEVEL_0;
               	  CAR_Set_Speed(Current_My_Car_speed);
             }
       }

	}
	else if(Current_My_Car_Direction==IS_FORWARD)
	{

		 if( Last_ahead_Distance!=0)
		       {

		             if(Last_ahead_Distance>100 )
		             {
		               /*nothing*/

		             }
		             else if(Last_ahead_Distance>50)
		             {
		                  if(Current_My_Car_speed>SPEED_LEVEL_4)
		                  {
		                	  Current_My_Car_speed=SPEED_LEVEL_4;
		                	  CAR_Set_Speed(Current_My_Car_speed);
		                  }
		             }
		             else if(Last_ahead_Distance>30)
		             {
		                 if(Current_My_Car_speed>SPEED_LEVEL_3)
		                 {
		               	  Current_My_Car_speed=SPEED_LEVEL_3;
		               	  CAR_Set_Speed(Current_My_Car_speed);
		                 }

		             }
		             else if(Last_ahead_Distance>20)
		             {
		                 if(Current_My_Car_speed>SPEED_LEVEL_2)
		                 {
		               	  Current_My_Car_speed=SPEED_LEVEL_2;
		               	  CAR_Set_Speed(Current_My_Car_speed);
		                 }

		             }
		             else if(Last_ahead_Distance>10)
		             {
		                 if(Current_My_Car_speed>SPEED_LEVEL_1)
		                 {
		               	  Current_My_Car_speed=SPEED_LEVEL_1;
		               	  CAR_Set_Speed(Current_My_Car_speed);
		                 }

		             }
		             else
		             {

		               	  Current_My_Car_speed=SPEED_LEVEL_0;
		               	  CAR_Set_Speed(Current_My_Car_speed);
		             }
		       }


	}


}

void Is_Car_Forward(void)
{
	uint16_t local_pos=0;
	uint16_t local_Back_Dis=0;

 if(Flag_New_Car==1)
 {
	 Flag_New_Car=0;


	local_Back_Dis+=Another_Car_Data[BACKWARD_DISTANCE1]*100;
	local_Back_Dis+=Another_Car_Data[BACKWARD_DISTANCE2]*10;
	local_Back_Dis+=Another_Car_Data[BACKWARD_DISTANCE3];


	local_pos+=Another_Car_Data[POS1]*100;
	local_pos+=Another_Car_Data[POS2]*10;
	local_pos+=Another_Car_Data[POS3];


	if(Last_ahead_Distance!=0)
	{

		if(Last_ahead_Distance==local_Back_Dis)
		{

			if(local_pos==my_Position)
			{
				Car_Forward_Status=FORWARD_SAME_DIRECTION;

			}
			else if((int16_t)((int16_t)local_pos-(int16_t)my_Position)==-90 || (int16_t)((int16_t)local_pos-(int16_t)my_Position)==90)
			{
				Car_Forward_Status=FORWARD_OPPOSITE_DIRECTION;
			}
		}
		else
		{
			Car_Forward_Status=NOT_FORWARD;

		}



	}
	else
	{
		Car_Forward_Status=NOT_FORWARD;
	}


 }
 else
 {
	 Car_Forward_Status=NOT_FORWARD;
 }
}

void APP_Adaptive_Cruise_Control_Task(void)
{

if(Car_Forward_Status==FORWARD_SAME_DIRECTION)
{

	 if(Last_ahead_Distance<100)
	 {
		 if(Current_My_Car_speed>Another_Car_Data[CAR_SPEED])
		 {
			 Current_My_Car_speed=Another_Car_Data[CAR_SPEED];
			 CAR_Set_Speed(Current_My_Car_speed);

		 }
	 }

}

}
