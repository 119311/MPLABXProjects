#ifndef TMR2_H
#define TMR2_H
#include <stdbool.h>
#include <stdint.h>
#ifdef __cplusplus typedef enum {
            TMR2_ROP_STARTS_TMRON,
        TMR2_ROP_STARTS_TMRON_ERSHIGH,
        TMR2_ROP_STARTS_TMRON_ERSLOW,
        TMR2_ROP_RESETS_ERSBOTHEDGE,
        TMR2_ROP_RESETS_ERSRISINGEDGE,
        TMR2_ROP_RESETS_ERSFALLINGEDGE,
        TMR2_ROP_RESETS_ERSLOW,
        TMR2_ROP_RESETS_ERSHIGH,
            TMR2_OS_STARTS_TMRON,
        TMR2_OS_STARTS_ERSRISINGEDGE,
        TMR2_OS_STARTS_ERSFALLINGEDGE,
        TMR2_OS_STARTS_ERSBOTHEDGE,
        TMR2_OS_STARTS_ERSFIRSTRISINGEDGE,
        TMR2_OS_STARTS_ERSFIRSTFALLINGEDGE,
        TMR2_OS_STARTS_ERSRISINGEDGEDETECT,
        TMR2_OS_STARTS_ERSFALLINGEDGEDETECT,
        TMR2_OS_STARTS_TMRON_ERSHIGH = 0x16,
        TMR2_OS_STARTS_TMRON_ERSLOW = 0x17,
            TMR2_MS_STARTS_TMRON_ERSRISINGEDGEDETECT = 0x11,
        TMR2_MS_STARTS_TMRON_ERSFALLINGEDGEDETECT = 0x12,
        TMR2_MS_STARTS_TMRON_ERSBOTHEDGE = 0x13
} TMR2_HLT_MODE;
typedef enum {
        TMR2_T2INPPS,
        TMR2_RESERVED,
        TMR2_T4POSTSCALED,
        TMR2_T6POSTSCALED,
        TMR2_T8POSTSCALED,
        TMR2_CCP1_OUT,
        TMR2_CCP2_OUT,
        TMR2_CCP7_OUT,
        TMR2_RESERVED_1,
        TMR2_PWM3_OUT,
        TMR2_PWM4_OUT,
        TMR2_PWM9_OUT,
        TMR2_RESERVED_2,
        TMR2_PWM5_OUT,
        TMR2_PWM6_OUT,
        TMR2_PWM11_OUT,
        TMR2_RESERVED_3,
        TMR2_C1_OUT_SYNC,
        TMR2_C2_OUT_SYNC,
        TMR2_C3_OUT_SYNC,
        TMR2_C4_OUT_SYNC,
        TMR2_C5_OUT_SYNC,
        TMR2_C6_OUT_SYNC,
        TMR2_RESERVED_4,
        TMR2_RESERVED_5,
        TMR2_ZCD_OUTPUT,
        TMR2_CLC1_OUT,
        TMR2_CLC2_OUT,
        TMR2_CLC3_OUT,
        TMR2_CLC4_OUT
} TMR2_HLT_EXT_RESET_SOURCE;
#define TMR2_INTERRUPT_TICKER_FACTOR 20
void TMR2_Initialize(void);
void TMR2_ModeSet(TMR2_HLT_MODE mode);
void TMR2_ExtResetSourceSet(TMR2_HLT_EXT_RESET_SOURCE reset);
void TMR2_Start(void);
void TMR2_StartTimer(void);
void TMR2_Stop(void);
void TMR2_StopTimer(void);
uint8_t TMR2_Counter8BitGet(void);
uint8_t TMR2_ReadTimer(void);
void TMR2_Counter8BitSet(uint8_t timerVal);
void TMR2_WriteTimer(uint8_t timerVal);
void TMR2_Period8BitSet(uint8_t periodVal);
void TMR2_LoadPeriodRegister(uint8_t periodVal);
void TMR2_ISR(void);
void TMR2_CallBack(void);
void TMR2_SetInterruptHandler(void (*InterruptHandler)(void));
extern void (*TMR2_InterruptHandler)(void);
void TMR2_DefaultInterruptHandler(void);
#ifdef __cplusplus 
