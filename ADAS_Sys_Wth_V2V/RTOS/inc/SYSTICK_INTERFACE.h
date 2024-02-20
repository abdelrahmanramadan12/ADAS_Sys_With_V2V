/*
 * File: systick_interface.c
 * Author: Abdelrahman Osama
 * Description: Configuration file for the SysTick timer.
 * Date created: June 7, 2023
 * Last modified: February 16, 2024
 */


#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_
#include"main.h"
void STK_void_Init();

void STK_voidSetBusyWait(uint32_t Copyu32NoCounts);

void STK_voidSetIntervalSingle(uint32_t Copyu32NoCounts,void (*Lpf)(void));
void STK_voidSetIntervalPeriodic(uint32_t Copyu32NoCounts,void (*Lpf)(void));
void STK_voidGetRemainingTime(uint32_t* Remaining_u32Time);
void STK_voidGetElapsedTime(uint32_t* Elapsed_u32Time);



#endif /* SYSTICK_INTERFACE_H_ */
