/*
 * communication_module.h
 * Description: Header file containing function prototypes and declarations for the Communication Module
 * SWC: Communication Module
 * Version:
 * Created on: Dec 12, 2023
 * Author: Mohamed Hussein
 */

#ifndef INC_COMMUNICATION_MODULE_H_
#define INC_COMMUNICATION_MODULE_H_

/********************** Macro Declarations ***************************************/

/* Macro Definitions for indicating pass or don't pass in different directions */
#define DON_T_PASS_R    0
#define DON_T_PASS_L    1
#define DON_T_PASS_RL   2
#define PASS            3

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
HAL_StatusTypeDef HAL_CommModule_SPIReceiveDMA(uint8_t* copy_u8DataArray);

/**
 * @brief  Sends data via SPI using DMA for the Communication Module.
 * @param  copy_u8DataArray: Pointer to an array containing data to be sent.
 * @retval HAL_StatusTypeDef: HAL status indicating success or failure.
 * @note   This function uses DMA to send data through the SPI interface of
 *         the Communication Module. It takes a pointer to an array containing
 *         the data to be transmitted. The function returns a status indicating
 *         whether the data transmission was successful or encountered any errors.
 */
HAL_StatusTypeDef HAL_CommModule_SPISendDMA(uint8_t* copy_u8DataArray);

/**
 * @brief  Task for receiving data via SPI.
 */
void HAL_ComMoudle_ReceiveTask(void);

/**
 * @brief  Task for sending data via SPI.
 */
void HAL_ComMoudle_SendTask(void);

/**
 * @brief  Tx Transfer completed callback.
 * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @retval None
 */
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi);

/**
 * @brief  Rx Transfer completed callback.
 * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @retval None
 */
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi);

#endif /* INC_COMMUNICATION_MODULE_H_ */
