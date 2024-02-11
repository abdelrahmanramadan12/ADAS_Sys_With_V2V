/*
 *      @file   HCSR04_Interface.h
 *
 *      Created on: Dec 22, 2023
 *      @author: Abdelrahman Ramadan
 *      @brief The HCSR04 header file ,including functions' declarations
 *
 */
#ifndef SRC_ULTRASONIC_HCSR04_HCSR04_INTERFACE_H_
#define SRC_ULTRASONIC_HCSR04_HCSR04_INTERFACE_H_


#define TIMEOUT   1000


#define TRIG_PORT GPIOB



typedef enum{
	TIM_CHANNEL_1_     =                 TIM_CHANNEL_1 ,
	TIM_CHANNEL_2_     =                 TIM_CHANNEL_2 ,
	TIM_CHANNEL_3_     =                 TIM_CHANNEL_3 ,
	TIM_CHANNEL_4_     =                 TIM_CHANNEL_4
}TIM_CHANNEL_t;


typedef enum{
	TRIG_1 =GPIO_PIN_1,
	TRIG_2 =GPIO_PIN_2,
	TRIG_3 =GPIO_PIN_3,
	TRIG_4 =GPIO_PIN_4,
	TRIG_5 =GPIO_PIN_5,
	TRIG_6 =GPIO_PIN_6,
}TRIG_PIN_t;




void delay_us (uint16_t time, TIM_HandleTypeDef *htim );



ErrorStatus  Get_HCSR04_Distance (TIM_HandleTypeDef *htim , TIM_CHANNEL_t TIM_CHANNEL_Num_,TRIG_PIN_t TRIG_Num, uint32_t *distance);







#endif
