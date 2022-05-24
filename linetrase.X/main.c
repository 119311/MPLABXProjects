#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "mcc_generated_files/mcc.h"

#define LED_NUM 4
#define MOTOR_NUM 2

void ReadLedBar(uint8_t x[LED_NUM]);
void SetMotorValue(const uint8_t x[LED_NUM], int8_t y[MOTOR_NUM]);
void MotorOut(const int8_t y[MOTOR_NUM]);

void main(void)
{
  SYSTEM_Initialize();
  INTERRUPT_PeripheralInterruptEnable();
  uint8_t ledBar[LED_NUM]; // LedBarStatus
  int8_t motorOrder[MOTOR_NUM];
  while (1)
  {
    ReadLedBar(ledBar);
    SetMotorValue(ledBar, motorOrder);
    MotorOut(motorOrder);
  }
}
void ReadLedBar(uint8_t x[LED_NUM])
{
  ADC_SelectChannel(1);
  for (uint8_t i = 0; i < LED_NUM; i++)
  {
    ;
  }
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
