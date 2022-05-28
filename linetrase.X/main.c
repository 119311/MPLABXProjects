#include <stdio.h>
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
	uint8_t ledBar[LED_NUM] = {0};
	int16_t motorOrder[MOTOR_NUM] = {64, 64};
	//-128~-17で後退,-16~15でブレーキ(0は空転)16~128で前進
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
