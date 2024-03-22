/*
 * APP_CONTROL_SYSTEM.h
 *
 *  Created on: Feb 26, 2024
 *      Author: hp
 */

#ifndef INC_APP_CONTROL_SYSTEM_H_
#define INC_APP_CONTROL_SYSTEM_H_

#define BUFFER_SIZE   1


typedef enum
{
	IS_FORWARD,
	IS_BACKWARD,
	IS_RIGHT,
	IS_LIFT,
	IS_STOPED
}CarDirection_t;



void APP_CONTROL_SYSTEM_INIT(void);
void APP_CONTROL_SYSTEM_RUNNABLE(void);


#endif /* INC_APP_CONTROL_SYSTEM_H_ */
