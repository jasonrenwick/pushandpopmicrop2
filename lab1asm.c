#include <p18f452.h>
#include <delays.h>
#include "xlcd_grpd.h"
#include <string.h>
#include <stdio.h>

//#pragma config OSC = HS
//#pragma config WDT = OFF //Disable watchdog timer
//#pragma config LVP = OFF //Disable low voltage programming

unsigned int MapIndex;
extern void intMapName(void);
extern char getMapChar(void);
extern char MapName;

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

void main(void){
    char grpName[7];
    intMapName();
    for(MapIndex=0;MapIndex<=7;MapIndex++){
        grpName[MapIndex] = getMapChar();
    }
    
    PORTD = 0X00;
    TRISD = 0X00;
    
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while( BusyXLCD() );
    SetDDRamAddr(0x00);
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    while( BusyXLCD() );
    WriteCmdXLCD( BLINK_ON );
    while( BusyXLCD() );
    putsXLCD(grpName);
    while( BusyXLCD() );
       
    Sleep();
    

        
}


