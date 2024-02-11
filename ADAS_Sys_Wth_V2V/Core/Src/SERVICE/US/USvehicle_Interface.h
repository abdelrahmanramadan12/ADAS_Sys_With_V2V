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




ErrorStatus get_Distance_From_ForwardRight_US (uint32_t *ForwardRight_Dist);


ErrorStatus get_Distance_From_ForwardLeft_US (uint32_t *ForwardLeft_Dist);


ErrorStatus get_Distance_From_ForwardMid_US (uint32_t *ForwardMid_Dist);




ErrorStatus get_Distance_From_BackRight_US (uint32_t *BackRight_Dist);


ErrorStatus get_Distance_From_BackLeft_US (uint32_t *BackLeft_Dist);


ErrorStatus get_Distance_From_BackMid_US (uint32_t *BackMid_Dist);



#endif
