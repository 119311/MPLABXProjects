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
// LED_LEFT_1, LED_LEFT_2, LED_RIGHT_1, LED_RIGHT_2 の順で配置
#define MOTOR_LEFT 0
#define MOTOR_RIGHT 1
#define CRANK_POSSIBLY 3
#define LANE_CHANGE_POSSIBLY 3
#define LANE_CHANGE_POSTPONEMENT 6
#define CRANK_POSTPONEMENT 6

#define LINE_CROSSED(x, i) (x[i] < LED_THRESHOLD)
#define SUB(x) ((x == 0) ? (0) : (x - 1))
#define MAP(x) ((x > INT8_MAX) ? (INT8_MAX) : ((x < INT8_MIN) ? (INT8_MIN) : (x)))

void ReadLedBar(uint8_t x[LED_NUM]);
void SetMotorValue(const uint8_t x[LED_NUM], int8_t y[MOTOR_NUM]);
void MotorOut(const int8_t y[MOTOR_NUM]);
// void TMR0_Interrupt(void);
void MOTOR_WRITE_PWM(const int8_t y[MOTOR_NUM], const uint8_t i, const uint8_t port);

void main(void)
{
	SYSTEM_Initialize();
	INTERRUPT_PeripheralInterruptEnable();
	// TMR0_SetInterruptHandler(TMR0_Interrupt);
	INTERRUPT_GlobalInterruptEnable();
	uint8_t ledBar[LED_NUM] = {0};
	int16_t motorOrder[MOTOR_NUM] = {64, 64};
	//-128 ~ -17 で後退,-16 ~ 15でブレーキ(0は空転), 16 ~ 127で前進
	while (1)
	{
		if (flag == 1)
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
void SetMotorValue(const uint8_t x[LED_NUM], int16_t y[MOTOR_NUM])
{
	bool left_line_crossed = LINE_CROSSED(x, LED_LEFT_2), right_line_crossed = LINE_CROSSED(x, LED_RIGHT_1), right_double_line = LINE_CROSSED(x, LED_RIGHT_1) && LINE_CROSSED(x, LED_RIGHT_2), left_double_line = LINE_CROSSED(x, LED_LEFT_1) && LINE_CROSSED(x, LED_LEFT_2);
	static bool crank_coming = false, lane_change_coming = false;
	static uint8_t crank_possibly = 0, lane_change_possibly = 0, crank_postponement = 0, lane_change_postponement = 0;
	crank_possibly = SUB(crank_possibly);
	lane_change_possibly = SUB(lane_change_possibly);
	if (left_double_line)
	{
		if (right_double_line)
			if (lane_change_possibly < LANE_CHANGE_POSSIBLY)
				lane_change_possibly += LANE_CHANGE_POSSIBLY;
			else
				lane_change_coming = true;
		else
		{
			if (crank_possibly < CRANK_POSSIBLY)
				crank_possibly += CRANK_POSSIBLY;
			else
				crank_coming = true;
		}
	}
	if (lane_change_coming)
		lane_change_postponement++;
	if (crank_coming)
		crank_postponement++;
	if (lane_change_postponement > LANE_CHANGE_POSTPONEMENT)
	{
		lane_change_coming = false;
		y[MOTOR_LEFT] += 32;
		// y[MOTOR_RIGHT] -= 30;
		return;
	}
	if (crank_postponement > CRANK_POSTPONEMENT)
	{
		crank_coming = false;
		y[MOTOR_LEFT] = -32;
		y[MOTOR_RIGHT] = 30;
		return;
	}
	if (left_line_crossed)
	{
		y[MOTOR_LEFT] -= 10;
		y[MOTOR_RIGHT] += 10;
		return;
	}
	if (right_line_crossed)
	{
		y[MOTOR_LEFT] += 10;
		y[MOTOR_RIGHT] -= 10;
		return;
	}
	y[MOTOR_LEFT] += 10;
	y[MOTOR_RIGHT] += 10;
}
void MotorOut(const int8_t y[MOTOR_NUM])
{
	//-128 ~ -17 で後退,-16 ~ 15でブレーキ(0は空転), 16 ~ 127で前進
	//ここ未完成なので回路と相談
	int8_t motor_left = MAP(y[MOTOR_LEFT]), motor_right = MAP(y[MOTOR_RIGHT]);
	for (size_t i = 0; i < MOTOR_RIGHT; i++)
		MOTOR_WRITE_PWM(y[i], i);
	return;
}
// void TMR0_Interrupt(void)
// {
// 	flag *= -1;
// }
void MOTOR_WRITE_PWM(const int8_t y[MOTOR_NUM], const uint8_t i, const uint8_t port)
{
	switch (port)
	{
	case 3:
		PWM3_LoadDutyValue(y[i]);
		break;
	default:
		break;
	}
}
