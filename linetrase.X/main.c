#include <stdio.h>
#include "mcc_generated_files/mcc.h"

#define LED_NUM 4
#define JUDGMENT_NUM 4
#define MOTOR_NUM 2
#define LED_THRESHOLD 71
#define LED_LEFT_1 0
#define LED_LEFT_2 1
#define LED_RIGHT_1 2
#define LED_RIGHT_2 3

#define MOTOR_LEFT 0
#define MOTOR_RIGHT 1
#define CRANK_POSSIBLY 3
#define LANE_CHANGE_POSSIBLY 3
#define LANE_CHANGE_POSTPONEMENT 6
#define CRANK_POSTPONEMENT 6

#define LINE_CROSSED(x, i) (x[i] < LED_THRESHOLD)
#define SUB(x) ((x == 0) ? (0) : (x - 1))
#define MAP(x) ((x > (INT8_MAX)) ? (INT8_MAX) : ((x < (INT8_MIN)) ? (INT8_MIN) : (x)))

void main(void)
{
  SYSTEM_Initialize();

  int16_t motorOrder[MOTOR_NUM] = {64, 64};
  bool left_line_crossed = PORTAbits.RA2, right_line_crossed = PORTAbits.RA3;

  if (left_line_crossed)
    motorOrder[MOTOR_LEFT] -= 32, motorOrder[MOTOR_RIGHT] += 32;
  else if (right_line_crossed)
    motorOrder[MOTOR_LEFT] += 32, motorOrder[MOTOR_RIGHT] -= 32;
  else
    motorOrder[MOTOR_LEFT] += 64, motorOrder[MOTOR_RIGHT] += 64;

  int8_t motor[2] = {MAP(motorOrder[MOTOR_LEFT]), MAP(motorOrder[MOTOR_RIGHT])};

  size_t j = 0;
  while (HIGH)
  {
    if (16.0 < motor[MOTOR_RIGHT])
    {
      PORTCbits.RC4 = LOW;
      PORTCbits.RC6 = HIGH;
      PORTCbits.RC5 = HIGH;
      if (j > UINT8_MAX / 2.0 * abs(motor[MOTOR_RIGHT]))
        PORTCbits.RC5 = LOW;
    }
    else if (-16.0 > motor[MOTOR_RIGHT])
    {
      PORTCbits.RC4 = HIGH;
      PORTCbits.RC6 = LOW;
      PORTCbits.RC5 = HIGH;
      if (j > UINT8_MAX / 2.0 * abs(motor[MOTOR_RIGHT]))
        PORTCbits.RC5 = LOW;
    }
    if (16.0 < motor[MOTOR_LEFT])
    {
      PORTCbits.RC3 = HIGH;
      PORTCbits.RC1 = LOW;
      PORTCbits.RC2 = HIGH;
      if (j > UINT8_MAX / 2.0 * abs(motor[MOTOR_LEFT]))
        PORTCbits.RC2 = LOW;
    }
    else if (-16.0 > motor[MOTOR_LEFT])
    {
      PORTCbits.RC3 = LOW;
      PORTCbits.RC1 = HIGH;
      PORTCbits.RC2 = HIGH;
      if (j > UINT8_MAX / 2.0 * abs(motor[MOTOR_LEFT]))
        PORTCbits.RC2 = LOW;
    }
    j++;
    __delay_us(1);
  }
}
