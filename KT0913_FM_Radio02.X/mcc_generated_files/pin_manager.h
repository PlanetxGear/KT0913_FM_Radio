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
        Device            :  PIC16F18326
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

// get/set IO_RA0_NC aliases
#define IO_RA0_NC_TRIS                 TRISAbits.TRISA0
#define IO_RA0_NC_LAT                  LATAbits.LATA0
#define IO_RA0_NC_PORT                 PORTAbits.RA0
#define IO_RA0_NC_WPU                  WPUAbits.WPUA0
#define IO_RA0_NC_OD                   ODCONAbits.ODCA0
#define IO_RA0_NC_ANS                  ANSELAbits.ANSA0
#define IO_RA0_NC_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define IO_RA0_NC_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define IO_RA0_NC_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define IO_RA0_NC_GetValue()           PORTAbits.RA0
#define IO_RA0_NC_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define IO_RA0_NC_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define IO_RA0_NC_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define IO_RA0_NC_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define IO_RA0_NC_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define IO_RA0_NC_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define IO_RA0_NC_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define IO_RA0_NC_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set IO_RA1_NC aliases
#define IO_RA1_NC_TRIS                 TRISAbits.TRISA1
#define IO_RA1_NC_LAT                  LATAbits.LATA1
#define IO_RA1_NC_PORT                 PORTAbits.RA1
#define IO_RA1_NC_WPU                  WPUAbits.WPUA1
#define IO_RA1_NC_OD                   ODCONAbits.ODCA1
#define IO_RA1_NC_ANS                  ANSELAbits.ANSA1
#define IO_RA1_NC_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_RA1_NC_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_RA1_NC_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_RA1_NC_GetValue()           PORTAbits.RA1
#define IO_RA1_NC_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_RA1_NC_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_RA1_NC_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define IO_RA1_NC_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define IO_RA1_NC_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define IO_RA1_NC_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define IO_RA1_NC_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define IO_RA1_NC_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set SW3_down aliases
#define SW3_down_TRIS                 TRISAbits.TRISA2
#define SW3_down_LAT                  LATAbits.LATA2
#define SW3_down_PORT                 PORTAbits.RA2
#define SW3_down_WPU                  WPUAbits.WPUA2
#define SW3_down_OD                   ODCONAbits.ODCA2
#define SW3_down_ANS                  ANSELAbits.ANSA2
#define SW3_down_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SW3_down_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SW3_down_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SW3_down_GetValue()           PORTAbits.RA2
#define SW3_down_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SW3_down_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SW3_down_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define SW3_down_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define SW3_down_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define SW3_down_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define SW3_down_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define SW3_down_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set POWER_AMP aliases
#define POWER_AMP_TRIS                 TRISAbits.TRISA4
#define POWER_AMP_LAT                  LATAbits.LATA4
#define POWER_AMP_PORT                 PORTAbits.RA4
#define POWER_AMP_WPU                  WPUAbits.WPUA4
#define POWER_AMP_OD                   ODCONAbits.ODCA4
#define POWER_AMP_ANS                  ANSELAbits.ANSA4
#define POWER_AMP_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define POWER_AMP_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define POWER_AMP_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define POWER_AMP_GetValue()           PORTAbits.RA4
#define POWER_AMP_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define POWER_AMP_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define POWER_AMP_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define POWER_AMP_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define POWER_AMP_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define POWER_AMP_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define POWER_AMP_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define POWER_AMP_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SW1_menu aliases
#define SW1_menu_TRIS                 TRISAbits.TRISA5
#define SW1_menu_LAT                  LATAbits.LATA5
#define SW1_menu_PORT                 PORTAbits.RA5
#define SW1_menu_WPU                  WPUAbits.WPUA5
#define SW1_menu_OD                   ODCONAbits.ODCA5
#define SW1_menu_ANS                  ANSELAbits.ANSA5
#define SW1_menu_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SW1_menu_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SW1_menu_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SW1_menu_GetValue()           PORTAbits.RA5
#define SW1_menu_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SW1_menu_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SW1_menu_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SW1_menu_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SW1_menu_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SW1_menu_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SW1_menu_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define SW1_menu_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set IO_RC0_NC aliases
#define IO_RC0_NC_TRIS                 TRISCbits.TRISC0
#define IO_RC0_NC_LAT                  LATCbits.LATC0
#define IO_RC0_NC_PORT                 PORTCbits.RC0
#define IO_RC0_NC_WPU                  WPUCbits.WPUC0
#define IO_RC0_NC_OD                   ODCONCbits.ODCC0
#define IO_RC0_NC_ANS                  ANSELCbits.ANSC0
#define IO_RC0_NC_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_NC_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_NC_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_NC_GetValue()           PORTCbits.RC0
#define IO_RC0_NC_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_NC_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_RC0_NC_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_RC0_NC_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_RC0_NC_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_RC0_NC_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define IO_RC0_NC_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define IO_RC0_NC_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set POWER_RADIO_LCD aliases
#define POWER_RADIO_LCD_TRIS                 TRISCbits.TRISC1
#define POWER_RADIO_LCD_LAT                  LATCbits.LATC1
#define POWER_RADIO_LCD_PORT                 PORTCbits.RC1
#define POWER_RADIO_LCD_WPU                  WPUCbits.WPUC1
#define POWER_RADIO_LCD_OD                   ODCONCbits.ODCC1
#define POWER_RADIO_LCD_ANS                  ANSELCbits.ANSC1
#define POWER_RADIO_LCD_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define POWER_RADIO_LCD_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define POWER_RADIO_LCD_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define POWER_RADIO_LCD_GetValue()           PORTCbits.RC1
#define POWER_RADIO_LCD_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define POWER_RADIO_LCD_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define POWER_RADIO_LCD_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define POWER_RADIO_LCD_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define POWER_RADIO_LCD_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define POWER_RADIO_LCD_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define POWER_RADIO_LCD_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define POWER_RADIO_LCD_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set POWER_BACKLIGHT aliases
#define POWER_BACKLIGHT_TRIS                 TRISCbits.TRISC2
#define POWER_BACKLIGHT_LAT                  LATCbits.LATC2
#define POWER_BACKLIGHT_PORT                 PORTCbits.RC2
#define POWER_BACKLIGHT_WPU                  WPUCbits.WPUC2
#define POWER_BACKLIGHT_OD                   ODCONCbits.ODCC2
#define POWER_BACKLIGHT_ANS                  ANSELCbits.ANSC2
#define POWER_BACKLIGHT_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define POWER_BACKLIGHT_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define POWER_BACKLIGHT_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define POWER_BACKLIGHT_GetValue()           PORTCbits.RC2
#define POWER_BACKLIGHT_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define POWER_BACKLIGHT_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define POWER_BACKLIGHT_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define POWER_BACKLIGHT_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define POWER_BACKLIGHT_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define POWER_BACKLIGHT_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define POWER_BACKLIGHT_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define POWER_BACKLIGHT_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SW2_up aliases
#define SW2_up_TRIS                 TRISCbits.TRISC5
#define SW2_up_LAT                  LATCbits.LATC5
#define SW2_up_PORT                 PORTCbits.RC5
#define SW2_up_WPU                  WPUCbits.WPUC5
#define SW2_up_OD                   ODCONCbits.ODCC5
#define SW2_up_ANS                  ANSELCbits.ANSC5
#define SW2_up_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SW2_up_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SW2_up_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SW2_up_GetValue()           PORTCbits.RC5
#define SW2_up_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SW2_up_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SW2_up_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SW2_up_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SW2_up_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SW2_up_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SW2_up_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define SW2_up_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

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


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF2 pin functionality
 * @Example
    IOCAF2_ISR();
 */
void IOCAF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF2_SetInterruptHandler() method.
    This handler is called every time the IOCAF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(IOCAF2_InterruptHandler);

*/
extern void (*IOCAF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF2_SetInterruptHandler() method.
    This handler is called every time the IOCAF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(IOCAF2_DefaultInterruptHandler);

*/
void IOCAF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF5 pin functionality
 * @Example
    IOCAF5_ISR();
 */
void IOCAF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_InterruptHandler);

*/
extern void (*IOCAF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_DefaultInterruptHandler);

*/
void IOCAF5_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF5 pin functionality
 * @Example
    IOCCF5_ISR();
 */
void IOCCF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF5_SetInterruptHandler() method.
    This handler is called every time the IOCCF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(IOCCF5_InterruptHandler);

*/
extern void (*IOCCF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF5_SetInterruptHandler() method.
    This handler is called every time the IOCCF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(IOCCF5_DefaultInterruptHandler);

*/
void IOCCF5_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/