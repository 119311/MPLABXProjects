#include "mcc_generated_files/mcc.h"
#include <stdbool.h>
#include <stdio.h>
#define INCREMENTAL 16
#define LEFT_LINE2_CROSSED PORTAbits.RA0
#define LEFT_LINE_CROSSED PORTAbits.RA1
#define RIGHT_LINE_CROSSED PORTAbits.RA2
#define RIGHT_LINE2_CROSSED PORTAbits.RA3
#define IN1 PORTBbits.RB1
#define IN2 PORTBbits.RB0
#define IN3 PORTBbits.RB2
#define IN4 PORTBbits.RB3
#define MODE PORTBbits.RB4
#define LARGE PORTBbits.RB5
#define SUB(x) ((0 == x) ? (0) : (x - 1))
#define ABS(x) ((0 < x) ? (x) : (-x))
#define ROUNDtoINT8(x) ((INT8_MAX < x) ? (INT8_MAX) : ((x < INT8_MIN) ? (INT8_MIN) : (x)))
// void SetMotorOrder(int16_t motorOrder[2]);
// void RunMotor(const uint8_t motorNum, const int8_t value);
void main(void)
{
    SYSTEM_Initialize();
    MODE = LOW;
    LARGE = LOW;
    while (true) {
        if (LEFT_LINE_CRsOSSED)
            if (LEFT_LINE2_CROSSED) {
                IN1 = HIGH, IN2 = LOW;
                IN3 = HIGH, IN4 = LOW;
                __delay_ms(50);
                while (LEFT_LINE2_CROSSED == 0) {
                    IN1 = HIGH, IN2 = LOW;
                    IN3 = HIGH, IN4 = LOW;
                }
                IN1 = HIGH, IN2 = LOW;
                IN3 = HIGH, IN4 = LOW;
                __delay_ms(50);
                IN1 = HIGH, IN2 = LOW;
                IN3 = LOW, IN4 = HIGH;
                __delay_ms(50);
            } else {
                IN1 = HIGH, IN2 = LOW;
            }
        if (RIGHT_LINE_CROSSED)
            if (RIGHT_LINE2_CROSSED) {
                IN1 = HIGH, IN2 = LOW;
                IN3 = HIGH, IN4 = LOW;
                __delay_ms(25);
                IN1 = LOW, IN2 = HIGH;
                IN3 = HIGH, IN4 = LOW;
                __delay_ms(20);
                IN1 = HIGH, IN2 = LOW;
                IN3 = LOW, IN4 = HIGH;
                __delay_ms(25);
            } else {
                IN3 = HIGH, IN4 = LOW;
            }
        else {
            IN1 = HIGH, IN2 = LOW;
            IN3 = HIGH, IN4 = LOW;
        }
        __delay_ms(10);
    }
}
// void SetMotorOrder(int16_t motorOrder[2])
//{
/**
 * @brief get position from line sensor and set motorOrder
 * @param motorOrder[2]
 * @return void
 * @note	motorOrder[0] is left motor, motorOrder[1] is right motor
 * @note	motorOrder[0] is positive if forward, negative if backward
 * @note	motorOrder[1] is positive if forward, negative if backward
 */
//	if (LEFT_LINE_CROSSED){
//        if (LEFT_LINE2_CROSSED)
//            else motorOrder[0] -= INCREMENTAL, motorOrder[1] += INCREMENTAL;
//    }
//	else if (RIGHT_LINE_CROSSED){
//        if (RIGHT_LINE2_CROSSED)
//            else motorOrder[0] += INCREMENTAL, motorOrder[1] -= INCREMENTAL;
//    }
//	else
//		motorOrder[0] += INCREMENTAL, motorOrder[1] += INCREMENTAL;
//}
// void RunMotor(const uint8_t motorNum, const int8_t value)
//{
/**
 * @brief run motor with designated time
 * @param motorNum
 * @param value
 * @return void
 * @note	motorNum is 0 or 1
 * @note	value is positive if forward, negative if backward
 * @note	motorOrder[0] is left motor, motorOrder[1] is right motor
 * @note	motorOrder[0] is positive if forward, negative if backward
 * @note	motorOrder[1] is positive if forward, negative if backward
 */
//	static size_t timer = 0;
//	if (timer)
//	{
//		timer--;
//		if (!timer)
//			CCP1 = LOW, CCP2 = LOW;
//	}
//	else
//	{
//		timer = ABS(value);
//		switch (motorNum)
//		{
//		case 0:
//			PORTCbits.RC5 = HIGH;
//			if (0 < value)
//				SEL21 = HIGH, SEL22 = LOW;
//			else
//				SEL22 = HIGH, SEL21 = LOW;
//			break;
//		case 1:
//			PORTCbits.RC2 = HIGH;
//			if (0 < value)
//				SEL11 = LOW, SEL12 = HIGH;
//			else
//				SEL11 = HIGH, SEL12 = LOW;
//			break;
//		}
//	}
//}
