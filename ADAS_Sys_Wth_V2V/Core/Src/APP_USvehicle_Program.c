/*
 *      @file USvehicle_Program.c
 *
 *      Created on: Feb 5, 2024
 *      @author: Abdelrahman Ramadan
 *      @brief The USvehicle source file ,including functions' definitions for each ultrasonic in the vehicle
 *            there are 6 ultrasonics 2 in the forward & 2 in the backward & two in the middle of the vehicle (right-left)
 *
 */


/***********************************************************************************************************************
 ____________________________________Includes___________________________________________________________________________

 ***********************************************************************************************************************/

#include "stm32f4xx.h"
#include "APP_USvehicle_Confg.h"
#include "APP_USvehicle_Interface.h"
#include "ECU_Sensors_Interface.h"
/**____________________________________________________________________________________________________________________**/







/***********************************************************************************************************************
 ____________________________________functions' definitions_____________________________________________________________

 ***********************************************************************************************************************/


/**
 * @fn     get_Distance_From_ForwardRight_US
 * @brief  Get the distance measured by the ultrasonic sensor positioned forward-right.
 * This    function retrieves the distance measured by the ultrasonic sensor located in the forward-right position.
 * @param  ForwardRight_Dist Pointer to a variable where the measured distance will be stored.
 * @retval ErrorStatus Status indicating the success or failure of the operation.
 *                     - SUCCESS: The distance measurement was successful.
 *                     - ERROR: An error occurred during the measurement process.
 */
void APP_Get_Distance_Init(void)
{
	Ultrasonics_Init();
}
ErrorStatus APP_get_Distance_From_ForwardRight_US (uint16_t *ForwardRight_Dist)
{
	ErrorStatus Error_St=SUCCESS;
	if (Get_HCSR04_Distance(FORWARD_RIGHT,ForwardRight_Dist)==ERROR)
	{
		Error_St=ERROR;
	}
	return Error_St;
}



/**
 * @fn     get_Distance_From_ForwardLeft_US
 * @brief  Get the distance measured by the ultrasonic sensor positioned forward-left.
 * This    function retrieves the distance measured by the ultrasonic sensor located in the forward-left position.
 * @param  ForwardLeft_Dist Pointer to a variable where the measured distance will be stored.
 * @retval ErrorStatus Status indicating the success or failure of the operation.
 *                     - SUCCESS: The distance measurement was successful.
 *                     - ERROR: An error occurred during the measurement process.
 */
ErrorStatus APP_get_Distance_From_ForwardLeft_US (uint16_t *ForwardLeft_Dist)
{
	ErrorStatus Error_St=SUCCESS;
	if (Get_HCSR04_Distance(FORWARD_LIFT,ForwardLeft_Dist)==ERROR)
	{
		Error_St=ERROR;
	}
	return Error_St;
}



/**
 * @fn     get_Distance_From_ForwardMid_US
 * @brief  Get the distance measured by the ultrasonic sensor positioned midd-right.
 * This    function retrieves the distance measured by the ultrasonic sensor located in the midd-right position.
 * @param  MidRight_Dist Pointer to a variable where the measured distance will be stored.
 * @retval ErrorStatus Status indicating the success or failure of the operation.
 *                     - SUCCESS: The distance measurement was successful.
 *                     - ERROR: An error occurred during the measurement process.
 */
ErrorStatus APP_get_Distance_From_ForwardMid_US (uint16_t *ForwardMid_Dist)
{
	ErrorStatus Error_St=SUCCESS;
	if (Get_HCSR04_Distance(FORWARD_MIDDLE,ForwardMid_Dist)==ERROR)
	{
		Error_St=ERROR;
	}
	return Error_St;
}







/**
 * @fn     get_Distance_From_BackRight_US
 * @brief  Get the distance measured by the ultrasonic sensor positioned backward-right.
 * This    function retrieves the distance measured by the ultrasonic sensor located in the back-right position.
 * @param  BackRight_Dist Pointer to a variable where the measured distance will be stored.
 * @retval ErrorStatus Status indicating the success or failure of the operation.
 *                     - SUCCESS: The distance measurement was successful.
 *                     - ERROR: An error occurred during the measurement process.
 */
ErrorStatus APP_get_Distance_From_BackRight_US (uint16_t *BackRight_Dist)
{
	ErrorStatus Error_St=SUCCESS;
	if (Get_HCSR04_Distance(BACKWARD_RIGHT,BackRight_Dist)==ERROR)
	{
		Error_St=ERROR;
	}
	return Error_St;
}




/**
 * @fn     get_Distance_From_BackLeft_US
 * @brief  Get the distance measured by the ultrasonic sensor positioned backward-left.
 * This    function retrieves the distance measured by the ultrasonic sensor located in the back-left position.
 * @param  BackLeft_Dist Pointer to a variable where the measured distance will be stored.
 * @retval ErrorStatus Status indicating the success or failure of the operation.
 *                     - SUCCESS: The distance measurement was successful.
 *                     - ERROR: An error occurred during the measurement process.
 */
ErrorStatus APP_get_Distance_From_BackLeft_US (uint16_t *BackLeft_Dist)
{
	ErrorStatus Error_St=SUCCESS;
	if (Get_HCSR04_Distance(BACKWARD_LIFT,BackLeft_Dist)==ERROR)
	{
		Error_St=ERROR;
	}
	return Error_St;
}



/**
 * @fn     get_Distance_From_BackMid_US
 * @brief  Get the distance measured by the ultrasonic sensor positioned midd-left.
 * This    function retrieves the distance measured by the ultrasonic sensor located in the midd-left position.
 * @param  MidLeft_Dist Pointer to a variable where the measured distance will be stored.
 * @retval ErrorStatus Status indicating the success or failure of the operation.
 *                     - SUCCESS: The distance measurement was successful.
 *                     - ERROR: An error occurred during the measurement process.
 */
ErrorStatus APP_get_Distance_From_BackMid_US (uint16_t *BackMid_Dist)
{
	ErrorStatus Error_St=SUCCESS;
	if (Get_HCSR04_Distance(BACKWARD_MIDDLE,BackMid_Dist)==ERROR)
	{
		Error_St=ERROR;
	}
	return Error_St;
}

