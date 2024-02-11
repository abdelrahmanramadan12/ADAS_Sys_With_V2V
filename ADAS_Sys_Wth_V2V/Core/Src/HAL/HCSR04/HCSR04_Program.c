/*
 *      @file   HCSR04_Program.c
 *
 *      Created on: Dec 22, 2023
 *      @author: Abdelrahman Ramadan
 *      @brief The HCSR04 source file ,including functions' definitions
 *             function provides delay (in microseconds), function provides the distance in (cm)
 *
 */

/***********************************************************************************************************************
 ____________________________________Includes___________________________________________________________________________

 ***********************************************************************************************************************/
#include "stm32f4xx.h"
#include "HCSR04_Cfg.h"
#include "HCSR04_Interface.h"

/***********************************************************************************************************************
 ____________________________________Global variables___________________________________________________________________

 ***********************************************************************************************************************/
uint32_t IC_Val1 = 0;          /** first captured value (rising)                     **/
uint32_t IC_Val2 = 0;          /** second captured value (falling)                   **/
uint32_t Difference = 0;       /** difference between two values "IC_Val1","IC_Val2" **/
uint8_t  Is_FirstVal_Captured = 0; /** Flag for the value captured                       **/


/***********************************************************************************************************************
 ____________________________________functions' definitions_____________________________________________________________

 ***********************************************************************************************************************/

/**
  * @fn     delay_us
  * @brief  This function provides delay (in microseconds) based
  *         on variable incremented.
  * @param  delay_us specifies the delay time length, in microseconds, *htim for select the timer to generate the delay.
  * @retval None
  */
void delay_us (uint16_t delay_us,TIM_HandleTypeDef *htim )
{

	__HAL_TIM_SET_COUNTER(htim,0);
	while(__HAL_TIM_GET_COUNTER(htim)< delay_us);

}

/**
  * @fn          Get_HCSR04_Distance
  * @brief       Measure the distance using an HC-SR04 ultrasonic sensor.
  * @param[in]   htim: Pointer to a TIM_HandleTypeDef structure that contains the configuration information for the specified TIM module.
  * @param[in]   TIM_CHANNEL_Num_ : Specifies the TIM channel number "replace "num" with 1,2,3 or 4".
  * @param[in]   TRIG_Num: Specifies the TRIG pin number.
  * @param[out]  Distance: Pointer to a variable to store the measured distance.
  * @retval      ErrorStatus: Status indicating success or failure of the function.
  *                     - SUCCESS: The distance measurement was successful.
  *                     - ERROR: An error occurred during the measurement process.
  */
ErrorStatus  Get_HCSR04_Distance (TIM_HandleTypeDef *htim , TIM_CHANNEL_t TIM_CHANNEL_Num_, TRIG_PIN_t TRIG_Num, uint32_t *Distance)
{
	ErrorStatus  Error_Status =SUCCESS;    /** define error status as success **/
	uint32_t timeOut =0;                   /**var for timeout **/

	HAL_TIM_IC_Start_IT(htim, TIM_CHANNEL_Num_);


	switch (TRIG_Num) {
		case TRIG_1:
				HAL_GPIO_WritePin(TRIG_PORT, TRIG_1, GPIO_PIN_SET);    /** Set TRIG pin HIGH**/
				delay_us(10,htim);  /** wait for 10 us **/
				HAL_GPIO_WritePin(TRIG_PORT, TRIG_1, GPIO_PIN_RESET);  /**Set TRIG pin low  **/
			break;

		case TRIG_2:
				HAL_GPIO_WritePin(TRIG_PORT, TRIG_2, GPIO_PIN_SET);    /** Set TRIG pin HIGH**/
				delay_us(10,htim);  /** wait for 10 us **/
				HAL_GPIO_WritePin(TRIG_PORT, TRIG_2, GPIO_PIN_RESET);  /**Set TRIG pin low  **/
			break;

		case TRIG_3:
				HAL_GPIO_WritePin(TRIG_PORT, TRIG_3, GPIO_PIN_SET);    /** Set TRIG pin HIGH**/
				delay_us(10,htim);  /** wait for 10 us **/
				HAL_GPIO_WritePin(TRIG_PORT, TRIG_3, GPIO_PIN_RESET);  /**Set TRIG pin low  **/
			break;

		case TRIG_4:
				HAL_GPIO_WritePin(TRIG_PORT, TRIG_4, GPIO_PIN_SET);    /** Set TRIG pin HIGH**/
				delay_us(10,htim);  /** wait for 10 us **/
				HAL_GPIO_WritePin(TRIG_PORT, TRIG_4, GPIO_PIN_RESET);  /**Set TRIG pin low  **/
			break;

		case TRIG_5:
				HAL_GPIO_WritePin(TRIG_PORT, TRIG_5, GPIO_PIN_SET);    /** Set TRIG pin HIGH**/
				delay_us(10,htim);  /** wait for 10 us **/
				HAL_GPIO_WritePin(TRIG_PORT, TRIG_5, GPIO_PIN_RESET);  /**Set TRIG pin low  **/
			break;

		case TRIG_6:
				HAL_GPIO_WritePin(TRIG_PORT, TRIG_6, GPIO_PIN_SET);    /** Set TRIG pin HIGH**/
				delay_us(10,htim);  /** wait for 10 us **/
				HAL_GPIO_WritePin(TRIG_PORT, TRIG_6, GPIO_PIN_RESET);  /**Set TRIG pin low  **/
			break;
		default:
			break;
	}

	__HAL_TIM_ENABLE_IT(htim, TIM_IT_CC1);                   /**Enable timer      **/

/*___________________________________________________________________________________________________________________________*/

	/**After the callback function***/
	while (timeOut<TIMEOUT)
	{



		if (Is_FirstVal_Captured==2 )
			{
				if (IC_Val2 > IC_Val1)       /***if second value  captured > first value captured                       ****/
				{
					Difference = IC_Val2-IC_Val1;
				}

				else if (IC_Val1 > IC_Val2)  /***if second  value  captured < first value captured "overflow happened"  ****/
				{
					Difference = (0xffff - IC_Val1) + IC_Val2;
				}
                //Distance= Difference/58;

			    *Distance = (float)Difference*.034/2;

			    Is_FirstVal_Captured=0;
			    break;
			}
		else
			{
			   timeOut++;
			}

	}
	if (timeOut>=TIMEOUT)
	          {
					Error_Status=ERROR;
	          }

    return Error_Status;
}







/***********************************************************************************************************************
 ___________________________________  callback function _______________________________________________________________

 ***********************************************************************************************************************/

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
//    if (htim->Instance==TIM1)
//      {
			if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)  /** if the interrupt source is channel1 **/
			{
				if (Is_FirstVal_Captured==0)                   /** if the first value is not captured ***/
				{
					IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); /* read the first value*/
					Is_FirstVal_Captured = 1;                            /* set the first captured flag =1 ***/

					/** change the polarity to falling edge**/
					__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
				}

				else if (Is_FirstVal_Captured==1)   /** if the first is already captured now capture the falling edge **/
				{
					IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);  /** read second value **/
					__HAL_TIM_SET_COUNTER(htim, 0);                            /** reset the counter **/



					Is_FirstVal_Captured = 2;                         /**set the flag =2 to clac the distance "synch" **/

					/*** set polarity to rising edge ****/
					__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
					__HAL_TIM_DISABLE_IT(htim, TIM_IT_CC1);
				}
			}

			else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)  /** if the interrupt source is channel 2 **/
			{
				if (Is_FirstVal_Captured==0)                   /** if the first value is not captured ***/
				{
					IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2); /* read the first value*/
					Is_FirstVal_Captured = 1;                                 /* set the first captured flag =1 ***/

					/** change the polarity to falling edge**/
					__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_FALLING);
				}

				else if (Is_FirstVal_Captured==1)   /** if the first is already captured now capture the falling edge **/
				{
					IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);  /** read second value **/
					__HAL_TIM_SET_COUNTER(htim, 0);                            /** reset the counter **/



					Is_FirstVal_Captured = 2;                         /**set the flag =2 to clac the distance "synch" **/

					/*** set polarity to rising edge ****/
					__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_RISING);
					__HAL_TIM_DISABLE_IT(htim, TIM_IT_CC1);
				}
			}

			else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)  /** if the interrupt source is channel3 **/
			{
				if (Is_FirstVal_Captured==0)                   /** if the first value is not captured ***/
				{
					IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3); /* read the first value*/
					Is_FirstVal_Captured = 1;                                 /* set the first captured flag =1 ***/

					/** change the polarity to falling edge**/
					__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_FALLING);
				}

				else if (Is_FirstVal_Captured==1)   /** if the first is already captured now capture the falling edge **/
				{
					IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);  /** read second value **/
					__HAL_TIM_SET_COUNTER(htim, 0);                            /** reset the counter **/



					Is_FirstVal_Captured = 2;                         /**set the flag =2 to clac the distance "synch" **/

					/*** set polarity to rising edge ****/
					__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_RISING);
					__HAL_TIM_DISABLE_IT(htim, TIM_IT_CC1);
				}
			}

			else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4)  /** if the interrupt source is channel1 **/
			{
				if (Is_FirstVal_Captured==0)                   /** if the first value is not captured ***/
				{
					IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4); /* read the first value*/
					Is_FirstVal_Captured = 1;                                 /* set the first captured flag =1 ***/

					/** change the polarity to falling edge**/
					__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_4, TIM_INPUTCHANNELPOLARITY_FALLING);
				}

				else if (Is_FirstVal_Captured==1)   /** if the first is already captured now capture the falling edge **/
				{
					IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);  /** read second value **/
					__HAL_TIM_SET_COUNTER(htim, 0);                            /** reset the counter **/



					Is_FirstVal_Captured = 2;                         /**set the flag =2 to clac the distance "synch" **/

					/*** set polarity to rising edge ****/
					__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_4, TIM_INPUTCHANNELPOLARITY_RISING);
					__HAL_TIM_DISABLE_IT(htim, TIM_IT_CC1);
				}
			}

     // }
}






/*
 * HCSR04_Program.c
 *
 *  Created on: Feb 10, 2024
 *      Author: abdel
 */


