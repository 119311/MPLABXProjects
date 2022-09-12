#ifndef PWM3_H
#define PWM3_H
#include <stdint.h>
#include <xc.h>
#ifdef __cplusplus #define PWM3_INITIALIZE_DUTY_VALUE 0
void PWM3_Initialize(void);
void PWM3_LoadDutyValue(uint16_t dutyValue);
#ifdef __cplusplus 
