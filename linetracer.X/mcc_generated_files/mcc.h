#ifndef MCC_H
#define	MCC_H
#include <xc.h>
#include "device_config.h"
#include "pin_manager.h"
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
void SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);
void WDT_Initialize(void);
#endif	
