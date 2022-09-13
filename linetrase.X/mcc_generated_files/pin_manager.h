/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1778
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED8 aliases
#define LED8_TRIS                 TRISAbits.TRISA0
#define LED8_LAT                  LATAbits.LATA0
#define LED8_PORT                 PORTAbits.RA0
#define LED8_WPU                  WPUAbits.WPUA0
#define LED8_OD                   ODCONAbits.ODA0
#define LED8_ANS                  ANSELAbits.ANSA0
#define LED8_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LED8_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LED8_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LED8_GetValue()           PORTAbits.RA0
#define LED8_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LED8_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LED8_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define LED8_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define LED8_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define LED8_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define LED8_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define LED8_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set LED7 aliases
#define LED7_TRIS                 TRISAbits.TRISA1
#define LED7_LAT                  LATAbits.LATA1
#define LED7_PORT                 PORTAbits.RA1
#define LED7_WPU                  WPUAbits.WPUA1
#define LED7_OD                   ODCONAbits.ODA1
#define LED7_ANS                  ANSELAbits.ANSA1
#define LED7_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED7_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED7_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED7_GetValue()           PORTAbits.RA1
#define LED7_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED7_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED7_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LED7_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LED7_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define LED7_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define LED7_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define LED7_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LED6A aliases
#define LED6A_TRIS                 TRISAbits.TRISA2
#define LED6A_LAT                  LATAbits.LATA2
#define LED6A_PORT                 PORTAbits.RA2
#define LED6A_WPU                  WPUAbits.WPUA2
#define LED6A_OD                   ODCONAbits.ODA2
#define LED6A_ANS                  ANSELAbits.ANSA2
#define LED6A_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED6A_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED6A_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED6A_GetValue()           PORTAbits.RA2
#define LED6A_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED6A_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED6A_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED6A_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED6A_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define LED6A_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define LED6A_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED6A_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LED5 aliases
#define LED5_TRIS                 TRISAbits.TRISA3
#define LED5_LAT                  LATAbits.LATA3
#define LED5_PORT                 PORTAbits.RA3
#define LED5_WPU                  WPUAbits.WPUA3
#define LED5_OD                   ODCONAbits.ODA3
#define LED5_ANS                  ANSELAbits.ANSA3
#define LED5_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LED5_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LED5_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LED5_GetValue()           PORTAbits.RA3
#define LED5_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LED5_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LED5_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define LED5_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define LED5_SetPushPull()        do { ODCONAbits.ODA3 = 0; } while(0)
#define LED5_SetOpenDrain()       do { ODCONAbits.ODA3 = 1; } while(0)
#define LED5_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define LED5_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set LED4 aliases
#define LED4_TRIS                 TRISAbits.TRISA4
#define LED4_LAT                  LATAbits.LATA4
#define LED4_PORT                 PORTAbits.RA4
#define LED4_WPU                  WPUAbits.WPUA4
#define LED4_OD                   ODCONAbits.ODA4
#define LED4_ANS                  ANSELAbits.ANSA4
#define LED4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED4_GetValue()           PORTAbits.RA4
#define LED4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LED4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LED4_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define LED4_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define LED4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define LED4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set LED3A aliases
#define LED3A_TRIS                 TRISAbits.TRISA5
#define LED3A_LAT                  LATAbits.LATA5
#define LED3A_PORT                 PORTAbits.RA5
#define LED3A_WPU                  WPUAbits.WPUA5
#define LED3A_OD                   ODCONAbits.ODA5
#define LED3A_ANS                  ANSELAbits.ANSA5
#define LED3A_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED3A_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED3A_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED3A_GetValue()           PORTAbits.RA5
#define LED3A_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED3A_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED3A_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED3A_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED3A_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define LED3A_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)
#define LED3A_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define LED3A_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISAbits.TRISA6
#define LED2_LAT                  LATAbits.LATA6
#define LED2_PORT                 PORTAbits.RA6
#define LED2_WPU                  WPUAbits.WPUA6
#define LED2_OD                   ODCONAbits.ODA6
#define LED2_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define LED2_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define LED2_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define LED2_GetValue()           PORTAbits.RA6
#define LED2_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define LED2_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONAbits.ODA6 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONAbits.ODA6 = 1; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISAbits.TRISA7
#define LED1_LAT                  LATAbits.LATA7
#define LED1_PORT                 PORTAbits.RA7
#define LED1_WPU                  WPUAbits.WPUA7
#define LED1_OD                   ODCONAbits.ODA7
#define LED1_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define LED1_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define LED1_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define LED1_GetValue()           PORTAbits.RA7
#define LED1_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define LED1_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONAbits.ODA7 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONAbits.ODA7 = 1; } while(0)

// get/set IN2 aliases
#define IN2_TRIS                 TRISBbits.TRISB0
#define IN2_LAT                  LATBbits.LATB0
#define IN2_PORT                 PORTBbits.RB0
#define IN2_WPU                  WPUBbits.WPUB0
#define IN2_ANS                  ANSELBbits.ANSB0
#define IN2_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IN2_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IN2_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IN2_GetValue()           PORTBbits.RB0
#define IN2_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IN2_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IN2_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define IN2_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define IN2_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define IN2_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set IN1 aliases
#define IN1_TRIS                 TRISBbits.TRISB1
#define IN1_LAT                  LATBbits.LATB1
#define IN1_PORT                 PORTBbits.RB1
#define IN1_WPU                  WPUBbits.WPUB1
#define IN1_ANS                  ANSELBbits.ANSB1
#define IN1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IN1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IN1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IN1_GetValue()           PORTBbits.RB1
#define IN1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IN1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define IN1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define IN1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define IN1_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define IN1_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set IN3 aliases
#define IN3_TRIS                 TRISBbits.TRISB2
#define IN3_LAT                  LATBbits.LATB2
#define IN3_PORT                 PORTBbits.RB2
#define IN3_WPU                  WPUBbits.WPUB2
#define IN3_ANS                  ANSELBbits.ANSB2
#define IN3_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IN3_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IN3_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IN3_GetValue()           PORTBbits.RB2
#define IN3_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IN3_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IN3_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IN3_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IN3_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define IN3_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set IN4 aliases
#define IN4_TRIS                 TRISBbits.TRISB3
#define IN4_LAT                  LATBbits.LATB3
#define IN4_PORT                 PORTBbits.RB3
#define IN4_WPU                  WPUBbits.WPUB3
#define IN4_ANS                  ANSELBbits.ANSB3
#define IN4_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IN4_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IN4_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IN4_GetValue()           PORTBbits.RB3
#define IN4_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IN4_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define IN4_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define IN4_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define IN4_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define IN4_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set MODE aliases
#define MODE_TRIS                 TRISBbits.TRISB4
#define MODE_LAT                  LATBbits.LATB4
#define MODE_PORT                 PORTBbits.RB4
#define MODE_WPU                  WPUBbits.WPUB4
#define MODE_OD                   ODCONBbits.ODB4
#define MODE_ANS                  ANSELBbits.ANSB4
#define MODE_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define MODE_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define MODE_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define MODE_GetValue()           PORTBbits.RB4
#define MODE_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define MODE_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define MODE_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define MODE_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define MODE_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define MODE_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define MODE_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define MODE_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set LARGE aliases
#define LARGE_TRIS                 TRISBbits.TRISB5
#define LARGE_LAT                  LATBbits.LATB5
#define LARGE_PORT                 PORTBbits.RB5
#define LARGE_WPU                  WPUBbits.WPUB5
#define LARGE_OD                   ODCONBbits.ODB5
#define LARGE_ANS                  ANSELBbits.ANSB5
#define LARGE_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define LARGE_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define LARGE_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define LARGE_GetValue()           PORTBbits.RB5
#define LARGE_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define LARGE_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define LARGE_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define LARGE_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define LARGE_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define LARGE_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define LARGE_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define LARGE_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set SW_BLUE aliases
#define SW_BLUE_TRIS                 TRISCbits.TRISC2
#define SW_BLUE_LAT                  LATCbits.LATC2
#define SW_BLUE_PORT                 PORTCbits.RC2
#define SW_BLUE_WPU                  WPUCbits.WPUC2
#define SW_BLUE_OD                   ODCONCbits.ODC2
#define SW_BLUE_ANS                  ANSELCbits.ANSC2
#define SW_BLUE_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SW_BLUE_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SW_BLUE_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SW_BLUE_GetValue()           PORTCbits.RC2
#define SW_BLUE_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SW_BLUE_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SW_BLUE_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SW_BLUE_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SW_BLUE_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define SW_BLUE_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define SW_BLUE_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SW_BLUE_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set SW_RED aliases
#define SW_RED_TRIS                 TRISCbits.TRISC3
#define SW_RED_LAT                  LATCbits.LATC3
#define SW_RED_PORT                 PORTCbits.RC3
#define SW_RED_WPU                  WPUCbits.WPUC3
#define SW_RED_OD                   ODCONCbits.ODC3
#define SW_RED_ANS                  ANSELCbits.ANSC3
#define SW_RED_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SW_RED_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SW_RED_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SW_RED_GetValue()           PORTCbits.RC3
#define SW_RED_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SW_RED_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SW_RED_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SW_RED_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SW_RED_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define SW_RED_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define SW_RED_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define SW_RED_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/