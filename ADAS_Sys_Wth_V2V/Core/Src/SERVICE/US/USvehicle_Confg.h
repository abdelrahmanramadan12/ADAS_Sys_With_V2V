/*
 *      @file USvehicle_Confg.h
 *
 *      Created on: Feb 5, 2024
 *      @author: Abdelrahman Ramadan
 *      @brief The USvehicle configuration file
 *
 */


#ifndef SRC_ULTRASONIC_US_USVEHICLE_CONFG_H_
#define SRC_ULTRASONIC_US_USVEHICLE_CONFG_H_





#define F_RIGHT_TIM             &htim1
#define F_LEFT_TIM              &htim1
#define F_MID_TIM               &htim1


#define B_RIGHT_TIM             &htim1
#define B_LEFT_TIM              &htim3
#define B_MID_TIM               &htim3


#define F_RIGHT_CHANNEL         TIM_CHANNEL_1
#define F_LEFT_CHANNEL          TIM_CHANNEL_2
#define F_MID_CHANNEL           TIM_CHANNEL_3


#define B_RIGHT_CHANNEL         TIM_CHANNEL_4
#define B_LEFT_CHANNEL          TIM_CHANNEL_1
#define B_MID_CHANNEL           TIM_CHANNEL_2





#endif
