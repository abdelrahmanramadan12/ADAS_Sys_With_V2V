/*
 * File: systick_private.c
 * Author: Abdelrahman Osama
 * Description: Configuration file for the SysTick timer.
 * Date created: June 7, 2023
 * Last modified: February 16, 2024
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_



		 #define STK_CTRL		*((volatile uint32_t*)0xE000E010)
		 #define STK_LOAD		*((volatile uint32_t*)0xE000E014)
		 #define STK_VAL		*((volatile uint32_t*)0xE000E018)
		 #define STK_CALIB 		*((volatile uint32_t*)0xE000E01C)


#endif /* SYSTICK_PRIVATE_H_ */
