
#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_



typedef enum {
	SPEED_LEVEL_0=  0,
    SPEED_LEVEL_1 = 40,
    SPEED_LEVEL_2 = 55,
    SPEED_LEVEL_3 = 60,
    SPEED_LEVEL_4 = 85,
    SPEED_LEVEL_5 = 100
} SpeedLevel;

typedef enum{
	MOTOR_CW,
	MOTOR_CCW,
	MOTOR_STOP
}Motor_Mode;

typedef enum{
	RIGHT_MOTOR=1,  //==>> Motor at forward right
	LIFT_MOTOR   //==>> Motor at forward Left

}MOTOR_position;

#define NUM_OF_TICKS  1000Ul


void Motor_Init(void);

void Motor_Select(MOTOR_position motor,Motor_Mode mode);

void SetMotorSpeed(SpeedLevel speed);


#endif /*MOTOR_H_ */
