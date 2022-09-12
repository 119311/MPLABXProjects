#ifndef PWM4_H
#define PWM4_H
#include <stdint.h>
#include <xc.h>
#ifdef __cplusplus #define PWM4_INITIALIZE_DUTY_VALUE 0
void PWM4_Initialize(void);
void PWM4_LoadDutyValue(uint16_t dutyValue);
#ifdef __cplusplus
