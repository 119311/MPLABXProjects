#ifndef TMR0_H
#define TMR0_H
#include <stdbool.h>
#include <stdint.h>
#ifdef __cplusplus
void TMR0_Initialize(void);
uint8_t TMR0_ReadTimer(void);
void TMR0_WriteTimer(uint8_t timerVal);
void TMR0_Reload(void);
void TMR0_ISR(void);
void TMR0_SetInterruptHandler(void (*InterruptHandler)(void));
extern void (*TMR0_InterruptHandler)(void);
void TMR0_DefaultInterruptHandler(void);
#ifdef __cplusplus
