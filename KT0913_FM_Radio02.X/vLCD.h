/*******************************************************************************
 *	I2C LCD control <AQM1602Y-RN-GBW>
 *	I2C1 use
 *	author  :hiroshi murakami
 *	created :20231122
 *	modified:-
 ******************************************************************************/

#ifndef _vLCD_H
#define _vLCD_H

#include <stdint.h>

/*****************************
 * DEFINES
 *****************************/
#define LCD_ADDRESS 0x3E
#define LCD_CMND 0x00
#define LCD_DATA 0x40

#define LCD_FUNCTION_SET_NORMAL 0x38    // 8bit 2line Normal mode
#define LCD_FUNCTION_SET_EXTEND 0x39    // 8bit 2line Extend mode
#define LCD_INTERNAL_OSC_FREQUENCY 0x14 // OSC 183Hz BIAS 1/5
#define LCD_CONTRAST_SET 0x70
#define LCD_POWER_ICON_CONTRAST 0x5F
#define LCD_FOLLOWER_CONTROL 0x6B       // Follwer for 3.3v
#define LCD_DISPLAY_ON 0x0C
#define LCD_CLEAR_DISPLAY 0x01

#define LCD_SET_LINE1_POSITION 0b10000000
#define LCD_SET_LINE2_POSITION 0b11000000

/*****************************
 * VARIABLES
 *****************************/
#if defined _vLCD_C

    int8_t LCD_Line1[17];
    int8_t LCD_Line2[17];


//	BYTE bKT0913_Lin1_buff[KT0913_BUFFER_SIZE + 1];			// LCD buffer
//	enum eModeL1 eModeLcdL1Status;

#else

    extern int8_t LCD_Line1[17];
    extern int8_t LCD_Line2[17];
    
//    extern BYTE bKT0913_Lin1_buff[];
//	extern enum eModeL1 eModeLcdL1Status;

#endif

/*****************************
 * PROTOTYPES
 *****************************/

void LCD_send_I2C(int8_t cmd, int8_t data);
void LCD_send_String(int8_t *disp);
void LCD_init(void);



#endif