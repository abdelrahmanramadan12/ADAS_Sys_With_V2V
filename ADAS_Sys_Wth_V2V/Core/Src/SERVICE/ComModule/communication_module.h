/*
 * communication_module.h
 *	SWC:
 *	Version:
 *  Created on: Dec 12, 2023
 *      Author: Mohamed Hussein
 */


#ifndef INC_COMMUNICATION_MODULE_H_
#define INC_COMMUNICATION_MODULE_H_


/********************** Macro Declarations ***************************************/

/*********************  Macro Function Declarations *****************************/

/*********************  Data Type Declarations ***********************************/

/*********************  Software Interfaces Declarations "APIs" *****************/


/**
  * @brief  Receives data via SPI using DMA for the Communication Module.
  * @param  copy_u8DataArray: Pointer to an array to store received data.
  * @retval HAL_StatusTypeDef: HAL status indicating success or failure.
  * @note   This function uses DMA to receive data from the SPI interface of
  *         the Communication Module. It takes a pointer to an array where the
  *         received data will be stored. The function returns a status
  *         indicating whether the data reception was successful or encountered
  *         any errors.
  */
HAL_StatusTypeDef HAL_CommModule_SPIReceiveDMA(uint8_t* copy_u8DataArray) ;



/**
  * @brief  Sends data via SPI using DMA for the Communication Module.
  * @param  copy_u8DataArray: Pointer to an array containing data to be sent.
  * @retval HAL_StatusTypeDef: HAL status indicating success or failure.
  * @note   This function uses DMA to send data through the SPI interface of
  *         the Communication Module. It takes a pointer to an array containing
  *         the data to be transmitted. The function returns a status indicating
  *         whether the data transmission was successful or encountered any errors.
  */

HAL_StatusTypeDef HAL_CommModule_SPISendDMA(uint8_t* copy_u8DataArray) ;


#endif /* INC_COMMUNICATION_MODULE_H_ */
