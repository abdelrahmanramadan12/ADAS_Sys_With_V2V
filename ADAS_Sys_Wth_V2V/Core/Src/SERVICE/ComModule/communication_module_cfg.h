/*
 * communication_module_cfg.h
 * Description: Header file containing configuration parameters for the communication module
 * SWC: Communication Module
 * Version:
 * Created on: Dec 12, 2023
 * Author: Mohamed Hussein
 */

#ifndef INC_COMMUNICATION_MODULE_CFG_H_
#define INC_COMMUNICATION_MODULE_CFG_H_

/* Address of Array that will send data */
#define SENDER_ARRAY_ADDRESS    0xFFFFFFFF

/* Address of Array that will receive data */
#define RECEIVER_ARRAY_ADDRESS    0xFFFFFFFF

/* Size of array used for sending data via SPI */
#define BUFFER_SEND_SIZE    8

/* Size of array used for receiving data via SPI */
#define BUFFER_RECEIVE_SIZE    8

/* Define safe distances for different directions */
#define SAFE_DISTANCE_R    100
#define SAFE_DISTANCE_L    100

/* Define receiving and sending patterns */
#define RECEIVING_PATTERN   0b01010101
#define SENDING_PATTERN     0b10101010

/* Define the amount of data in bytes from the beginning until the last byte in the data */
#define RECEIVE_DATA_SIZE    10

/* Define the pattern of the last data that was sent */
#define LAST_RECEIVING_PATTERN 0b11001101

#endif /* INC_COMMUNICATION_MODULE_CFG_H_ */
