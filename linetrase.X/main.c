#include <stdio.h>
#include "mcc_generated_files/mcc.h"

#define LED_NUM 4
#define MOTOR_NUM 2

void ReadLedBar(uint8_t x[LED_NUM]);
void SetMotorValue(const uint8_t x[LED_NUM], int8_t y[MOTOR_NUM]);
void MotorOut(const int8_t y[MOTOR_NUM]);

typedef enum
{
  Led_Left_1,
  Led_Left_2,
  Led_Right_1,
  Led_Right_2,
  // Led_Left_1, Led_Left_2, Led_Right_1, Led_Right_2 の順で配置
} LedBar;

void main(void)
{
  SYSTEM_Initialize();
  INTERRUPT_PeripheralInterruptEnable();
  uint8_t ledBar[LED_NUM] = {0}; // LedBarStatus
  int8_t motorOrder[MOTOR_NUM] = {0};
  while (1)
  {
    //ここに割込み追記
    ReadLedBar(ledBar);
    SetMotorValue(ledBar, motorOrder);
    MotorOut(motorOrder);
  }
}
void ReadLedBar(uint8_t x[LED_NUM])
{
  for (uint8_t i = channel_AN0; i <= channel_AN3; i++)
    x[i] = ADC_GetConversion(i) >> 8;
  return;
}
void SetMotorValue(const uint8_t x[LED_NUM], int8_t y[MOTOR_NUM])
{
  return;
}
void MotorOut(const int8_t y[MOTOR_NUM])
{
  return;
}
