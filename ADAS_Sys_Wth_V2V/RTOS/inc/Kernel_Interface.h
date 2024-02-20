/*
 * Kernel_Interface.h
 *
 *
 *      Author: Abdelrahman Osama
 *
 */

#ifndef SCEDULAR_KERNEL_INTERFACE_H_
#define SCEDULAR_KERNEL_INTERFACE_H_

#include"main.h"

/******************************************************
 * Enumerations
 ******************************************************/

typedef enum {
    BLOCKED,       // Task is blocked and not ready to execute
    READY,         // Task is ready to execute
    SUSPENDED      // Task is suspended and temporarily paused
} Task_State_t;

typedef enum {
    OKK,                    // Operation successful
    NOK_NULLPOINTER,        // Null pointer passed as argument
    NOK_PRIODICITY_LIMIT,   // Periodicity exceeds limits
    NOK_UNKOWN,             // Unknown error occurred
    PIRIORTY_UNAVAILABLE,   // Priority value is unavailable
    FAILED                  // Operation failed
} Kernel_Feedback;

/******************************************************
 * Structures
 ******************************************************/

typedef struct {
    uint16_t Periodicity;   // Periodicity of the task in milliseconds
    void (*TaskFunc)(void); // Pointer to the task function
    Task_State_t State;     // Current state of the task (BLOCKED, READY, SUSPENDED)
} Task_t;

/******************************************************
 * Function Prototypes
 ******************************************************/

/*
 * Function: RTOS_voidStart
 * Description: Starts the RTOS scheduler.
 * Parameters: None
 * Returns: None
 */
void RTOS_voidStart(void);

/*
 * Function: RTOS_u8CreateTask
 * Description: Creates a new task with the specified priority, task function, and periodicity.
 * Parameters:
 *   - Copy_u8Priority: Priority of the task (0 = highest priority)
 *   - Copy_pvTaskFunc: Pointer to the task function
 *   - Copy_u16Periodicity: Periodicity of the task in milliseconds
 * Returns:
 *   - Kernel_Feedback: Feedback indicating the success or failure of the operation
 */
Kernel_Feedback RTOS_u8CreateTask(uint8_t Copy_u8Priority, void (*Copy_pvTaskFunc)(void), uint16_t Copy_u16Periodicity);

/*
 * Function: RTOS_voidSuspendTask
 * Description: Suspends the task with the specified priority.
 * Parameters:
 *   - Copy_u8Priority: Priority of the task to suspend
 * Returns: None
 */
void RTOS_voidSuspendTask(uint8_t Copy_u8Priority);

/*
 * Function: RTOS_voidResumeTask
 * Description: Resumes the task with the specified priority.
 * Parameters:
 *   - Copy_u8Priority: Priority of the task to resume
 * Returns: None
 */
void RTOS_voidResumeTask(uint8_t Copy_u8Priority);

/*
 * Function: RTOS_voidDeleteTask
 * Description: Deletes the task with the specified priority.
 * Parameters:
 *   - Copy_u8Priority: Priority of the task to delete
 * Returns: None
 */
void RTOS_voidDeleteTask(uint8_t Copy_u8Priority);



#endif /* SCEDULAR_KERNEL_INTERFACE_H_ */
