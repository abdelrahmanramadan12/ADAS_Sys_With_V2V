/*
 * File: systick_program.c
 * Author: Abdelrahman Osama
 * Description: Configuration file for the SysTick timer.
 * Date created: June 7, 2023
 * Last modified: February 16, 2024
 */

#include "main.h"
#include "BIT_MATHS.h"
#include "SYSTICK_CONFIG.h"
#include "SYSTICK_PRIVATE.h"
#include "SYSTICK_INTERFACE.h"


uint8_t STK_u8SingleIntFlag=0;

void(*STK_pToFunction)(void);

void STK_void_Init(){
	CLEAR_BIT(STK_CTRL,0);
	CLEAR_BIT(STK_CTRL,1);
	STK_LOAD=0;
	STK_VAL=0;



#if(STK_CLK==STK_AHB_CLK)
	CLEAR_BIT(STK_CTRL,2);
#elif(STK_CLK==STK_AHB_CLK_DIV_BY_8)
	SET_BIT(STK_CTRL,2);
#else
#error("ERROR SYSTICK CLK")



#endif
}

void STK_voidSetBusyWait(uint32_t Copyu32NoCounts){
	CLEAR_BIT(STK_CTRL,0);
	CLEAR_BIT(STK_CTRL,1);
	STK_LOAD=0;
	STK_VAL=0;

	STK_LOAD=Copyu32NoCounts;
	SET_BIT(STK_CTRL,0);
	while(GET_BIT(STK_CTRL,16)==0);
	CLEAR_BIT(STK_CTRL,1);



}

void STK_voidSetIntervalSingle(uint32_t Copyu32NoCounts,void (*Lpf)(void)){
	STK_pToFunction=Lpf;
	STK_LOAD=Copyu32NoCounts;
	SET_BIT(STK_CTRL,0);
	SET_BIT(STK_CTRL,1);
	STK_u8SingleIntFlag=1;


}
void STK_voidSetIntervalPeriodic(uint32_t Copyu32NoCounts,void (*Lpf)(void)){


	STK_pToFunction=Lpf;
	STK_LOAD=Copyu32NoCounts;
	SET_BIT(STK_CTRL,0);
	SET_BIT(STK_CTRL,1);
	STK_u8SingleIntFlag=0;

}



void Private_voidDisableSTK(void){
	CLEAR_BIT(STK_CTRL,0);
	STK_LOAD=0;
	STK_VAL=0;

}
void SysTick_Handler(void){

	if(STK_u8SingleIntFlag==1){
		Private_voidDisableSTK();
		CLEAR_BIT(STK_CTRL,1);
	}
	if(STK_pToFunction!=NULL){
		STK_pToFunction();
	}
	uint8_t Local_u8TempVariable=GET_BIT(STK_CTRL,16);
}

