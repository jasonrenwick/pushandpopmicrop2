#include <p18cxxx.h>
#include "xlcd_grpd.h"
#include <delays.h>

/* Set configuration bits for use with ICD2 / PICDEM2 PLUS Demo Board:
* - set HS oscillator
* - disable watchdog timer
* - disable low voltage programming
*/
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 20000000UL

void DelayFor18TCY(void)
 {
 Delay10TCYx(0x6); //delays 20 cycles
 return;
 }
 /*****/
 void DelayPORXLCD(void)   // minimum 15ms
 {
 Delay100TCYx(0xF0);   // 100TCY * 160
 return;
 }
 /*****/
 void DelayXLCD(void)     // minimum 5ms
 {
 Delay100TCYx(0xF6);      // 100TCY * 54
 return;
 }

void main(){

    PORTD = 0X00;
    TRISD = 0X00;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while( BusyXLCD() );
    SetDDRamAddr(0x00);
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    while( BusyXLCD() );
    WriteCmdXLCD( BLINK_ON );
    while( BusyXLCD() );
    putrsXLCD("Hello");
    while( BusyXLCD() );
       
    Sleep();
}   