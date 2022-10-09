#include "pin_manager.h"

void PIN_MANAGER_Initialize(void)
{
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;
    TRISE = 0x08;
    TRISA = 0xFF;
    TRISB = 0xC0;
    TRISC = 0xFF;
    ANSELC = 0x00;
    ANSELB = 0x00;
    ANSELA = 0x24;
    WPUE = 0x00;
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x0C;
    OPTION_REGbits.nWPUEN = 0;
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    INLVLA = 0x3F;
    INLVLB = 0xF0;
    INLVLC = 0xFF;
    return;
}
void PIN_MANAGER_IOC(void)
{
    return;
}

/**
 End of File
*/
