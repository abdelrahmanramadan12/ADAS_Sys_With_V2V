


#ifndef SERVICE_CAR_DIRECTIONS_H_
#define SERVICE_CAR_DIRECTIONS_H_

#include "HAL_MOTOR_Interface.h"

/*********************  PROTO_TYPES   *************/

void CAR_Directions_Forword (void);
void CAR_Directions_Backward (void);
void CAR_Directions_Right (void);
void CAR_Directions_Left (void);
void CAR_Directions_Stop(void);
void CAR_Set_Speed(SpeedLevel speed);


#endif /* CAR_DIRECTIONS_H_ */
