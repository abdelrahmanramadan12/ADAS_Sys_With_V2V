/*
 * Kernel.c
 *
 *
 *      Author: Abdelrahman Osama
 */

//************* includes***************//
#include "Kernel_Interface.h"
#include "Kernel_Private.h"
#include "Kernel_Config.h"
#include "main.h"
#include "SYSTICK_INTERFACE.h"


Task_t SystemTasks[MAX_NUM_OF_TASK]={{NULL}};


static void Scedular();

void RTOS_voidStart(void){

	STK_voidSetIntervalPeriodic(1,&Scedular);

}





Kernel_Feedback RTOS_u8CreateTask(uint8_t Copy_u8Priority,void (*Copy_pvTaskFunc)(void),uint16_t Copy_u16Periodicity){

	Kernel_Feedback  Local_u8ErrorState=OKK;

	//check if the pointer isn't null
	if(Copy_pvTaskFunc!=NULL){

		/*check if the given priority is available or not*/
		if(SystemTasks[Copy_u8Priority].TaskFunc==NULL){

			SystemTasks[Copy_u8Priority].Periodicity= Copy_u16Periodicity;
			SystemTasks[Copy_u8Priority].TaskFunc= Copy_pvTaskFunc;
			SystemTasks[Copy_u8Priority].State= READY;



		}
		else{
			/*priority is not available*/
			Local_u8ErrorState=PIRIORTY_UNAVAILABLE;

		}


	}
	else{
		Local_u8ErrorState=NOK_NULLPOINTER;

	}

return Local_u8ErrorState;

}

void RTOS_voidSuspendTask(uint8_t Copy_u8Priority){

	SystemTasks[Copy_u8Priority].State=SUSPENDED;

}
void RTOS_voidResumeTask(uint8_t Copy_u8Priority){

	SystemTasks[Copy_u8Priority].State=READY;
}
void RTOS_voidDeleteTask(uint8_t Copy_u8Priority){

	SystemTasks[Copy_u8Priority].TaskFunc= NULL;
}

static void Scedular(void)
{

	volatile static uint16_t Local_u16SystickCounter=0;
	uint8_t Local_u8TaskCounter;
		Local_u16SystickCounter++;

		for(Local_u8TaskCounter=0;Local_u8TaskCounter<MAX_NUM_OF_TASK;Local_u8TaskCounter++)
		{
			if(SystemTasks[Local_u8TaskCounter].State==READY)
			{
				if(Local_u16SystickCounter % SystemTasks[Local_u8TaskCounter].Periodicity ==0)
				{
					/*Invoke the task function if it is not NULL*/
					if(SystemTasks[Local_u8TaskCounter].TaskFunc != NULL)
					{
						SystemTasks[Local_u8TaskCounter].TaskFunc();
					}
				}
				else
				{
					/*Do nothing*/
				}
			}
			else
			{
				/*Task is suspended, Do nothing*/
			}
		}


}






