/*
 * APP_TASKS.h
 *
 *  Created on: Mar 6, 2024
 *      Author: hp
 */

#ifndef INC_APP_TASKS_H_
#define INC_APP_TASKS_H_
typedef enum
{
	POS1,
	POS2,
	POS3,
	FORWARD_DISTANCE1,
	FORWARD_DISTANCE2,
	FORWARD_DISTANCE3,
	BACKWARD_DISTANCE1,
	BACKWARD_DISTANCE2,
	BACKWARD_DISTANCE3,
	CAR_DIRECTION,
	CAR_SPEED
}Another_Car_Data_Index;
typedef enum
{
	NOT_FORWARD,
	FORWARD_SAME_DIRECTION,
	FORWARD_OPPOSITE_DIRECTION

}Is_Forward_t;
void APP_Init_Task(void);
void Is_Car_Forward(void);
void Prepare_Data_Tasks(void);
void APP_Emergency_Braking_Task(void);
void APP_Adaptive_Cruise_Control_Task(void);


#endif /* INC_APP_TASKS_H_ */
