/*
 * ECU_Sensors_CFG.h
 *
 *  Created on: Feb 29, 2024
 *      Author: hp
 */

#ifndef INC_ECU_SENSORS_CFG_H_
#define INC_ECU_SENSORS_CFG_H_


#include "stm32f4xx_hal.h"

#define TIMEOUT    146500Ul

typedef enum
{
	FORWARD_RIGHT=0,
	FORWARD_LIFT,
	FORWARD_MIDDLE,
	BACKWARD_RIGHT,
	BACKWARD_LIFT,
	BACKWARD_MIDDLE,
	NUM_OF_ULTRASONICS,

}Ultrasonics_Index;


typedef struct
{
	GPIO_TypeDef*	   ULTRASONIC_ECO_port;
	GPIO_TypeDef*	   ULTRASONIC_TRIG_port;
	TIM_HandleTypeDef* TIMER;
	uint32_t           TIM_CHANNEL;
	uint16_t           ULTRASONIC_ECO_PIN;
	uint16_t           ULTRASONIC_TRIG_PIN;
}Ultrasonic_HandleTypeDEf;
extern Ultrasonic_HandleTypeDEf Ultrasonics[];
/*
typedef enum
{
	ULTRASONIC1_ECO_port=GPIOB,
	ULTRASONIC2_ECO_port=GPIOB,
	ULTRASONIC3_ECO_port=GPIOB,
	ULTRASONIC4_ECO_port=GPIOB,
	ULTRASONIC5_ECO_port=GPIOB,
	ULTRASONIC6_ECO_port=GPIOB
}Ultrasonic_ECO_Port_t;

typedef enum
{
	ULTRASONIC1_TRIG_port=GPIOB,
	ULTRASONIC2_TRIG_port=GPIOB,
	ULTRASONIC3_TRIG_port=GPIOB,
	ULTRASONIC4_TRIG_port=GPIOB,
	ULTRASONIC5_TRIG_port=GPIOB,
	ULTRASONIC6_TRIG_port=GPIOB
}Ultrasonic_TRIG_Port_t;

typedef enum
{
	ULTRASONIC1_ECO_PIN=GPIO_PIN_4,
	ULTRASONIC2_ECO_PIN=GPIO_PIN_4,
	ULTRASONIC3_ECO_PIN=GPIO_PIN_4,
	ULTRASONIC4_ECO_PIN=GPIO_PIN_4,
	ULTRASONIC5_ECO_PIN=GPIO_PIN_4,
	ULTRASONIC6_ECO_PIN=GPIO_PIN_4
}Ultrasonic_ECO_PIN_t;

typedef enum
{
	ULTRASONIC1_TRIG_PIN=GPIO_PIN_4,
	ULTRASONIC2_TRIG_PIN=GPIO_PIN_4,
	ULTRASONIC3_TRIG_PIN=GPIO_PIN_4,
	ULTRASONIC4_TRIG_PIN=GPIO_PIN_4,
	ULTRASONIC5_TRIG_PIN=GPIO_PIN_4,
	ULTRASONIC6_TRIG_PIN=GPIO_PIN_4
}Ultrasonic_TRIG_Port_t;

typedef enum
{
	ULTRASONIC1_TRIG_PIN=GPIO_PIN_4,
	ULTRASONIC2_TRIG_PIN=GPIO_PIN_4,
	ULTRASONIC3_TRIG_PIN=GPIO_PIN_4,
	ULTRASONIC4_TRIG_PIN=GPIO_PIN_4,
	ULTRASONIC5_TRIG_PIN=GPIO_PIN_4,
	ULTRASONIC6_TRIG_PIN=GPIO_PIN_4
}Ultrasonic_TRIG_Port_t;

typedef enum
{
	ULTRASONIC1_TRIG_PIN=&htim3,
	ULTRASONIC2_TRIG_PIN=&htim3,
	ULTRASONIC3_TRIG_PIN=&htim3,
	ULTRASONIC4_TRIG_PIN=&htim3,
	ULTRASONIC5_TRIG_PIN=&htim4,
	ULTRASONIC6_TRIG_PIN=&htim4
}Ultrasonic_TIM_t;
*/
#endif /* INC_ECU_SENSORS_CFG_H_ */
