#ifndef MCC_H
#define MCC_H

#include "adc.h"
#include "device_config.h"
#include "interrupt_manager.h"
#include "pin_manager.h"
#include "tmr0.h"
#include <conio.h>
#include <stdbool.h>
#include <stdint.h>
#include <xc.h>

void SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);
void WDT_Initialize(void);

#endif
