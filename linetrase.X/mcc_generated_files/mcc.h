#ifndef MCC_H
#define MCC_H
#include "device_config.h"
#include "interrupt_manager.h"
#include "pin_manager.h"
#include <conio.h>
#include <stdbool.h>
#include <stdint.h>
#include <xc.h>
#include "adc.h"
#include "tmr0.h"
        SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);
void WDT_Initialize(void);
#endif
