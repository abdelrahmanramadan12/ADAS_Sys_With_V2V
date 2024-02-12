/*
 * communication_module.c
 *	SWC:
 *	Version:
 *  Created on: Dec 12, 2023
 *      Author: Mohamed Hussein
 */


/********************** includes ***********************************************/

#include <stdint.h>

#include "stm32f4xx_hal.h"

#include "communication_module.h"
#include "communication_module_cfg.h"

/*************************** externs ***************************************/


extern SPI_HandleTypeDef hspi1;
extern DMA_HandleTypeDef hdma_spi1_rx;
extern DMA_HandleTypeDef hdma_spi1_tx;



/*********************  Global Variable Definition *****************************/
HAL_StatusTypeDef HAL_STATUS_SPIDMA = HAL_ERROR ;

/*********************  APIs Definition ****************************************/


HAL_StatusTypeDef HAL_CommModule_SPIReceiveDMA(uint8_t* copy_u8DataArray) {



	// Initiates SPI data Receive using DMA
	HAL_STATUS_SPIDMA = HAL_SPI_Receive_DMA(&hspi1,copy_u8DataArray,BUFFER_RECEIVE_SIZE) ;

	// Returns the status of the operation

	return HAL_STATUS_SPIDMA ;
}


HAL_StatusTypeDef HAL_CommModule_SPISendDMA(uint8_t* copy_u8DataArray) {


	  // Initiates SPI data transmission using DMA

	HAL_STATUS_SPIDMA = HAL_SPI_Receive_DMA(&hspi1,copy_u8DataArray,BUFFER_RECEIVE_SIZE) ;

	// Returns the status of the operation
	return HAL_STATUS_SPIDMA ;

}



/********************** Helper Functions Declaration "prototype" ************/


/*********************  ISRs Definition ****************************************/

/*********************  Helper Function Definition ****************************/


