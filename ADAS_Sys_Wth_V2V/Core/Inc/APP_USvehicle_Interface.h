/*
 *      @file USvehicle_Interface.h
 *
 *      Created on: Feb 5, 2024
 *      @author: Abdelrahman Ramadan
 *      @brief The USvehicle header file ,including functions' declarations
 *
 */

#ifndef SRC_ULTRASONIC_US_USVEHICLE_INTERFACE_H_
#define SRC_ULTRASONIC_US_USVEHICLE_INTERFACE_H_


void APP_Get_Distance_Init(void);


ErrorStatus APP_get_Distance_From_ForwardRight_US (uint16_t *ForwardRight_Dist);


ErrorStatus APP_get_Distance_From_ForwardLeft_US (uint16_t *ForwardLeft_Dist);


ErrorStatus APP_get_Distance_From_ForwardMid_US (uint16_t *ForwardMid_Dist);




ErrorStatus APP_get_Distance_From_BackRight_US (uint16_t *BackRight_Dist);


ErrorStatus APP_get_Distance_From_BackLeft_US (uint16_t *BackLeft_Dist);


ErrorStatus APP_get_Distance_From_BackMid_US (uint16_t *BackMid_Dist);



#endif
