#include <p18f452.h>
#include <delays.h>
#include <xlcd.h>
#include <string.h>
#include <stdio.h>

//#pragma config OSC = HS
//#pragma config WDT = OFF //Disable watchdog timer
//#pragma config LVP = OFF //Disable low voltage programming

unsigned int MapIndex;
extern void intMapName(void);
extern char getMapChar(void);
extern char MapName;

void main(void){
    char grpName[7];
    intMapName();
    for(MapIndex=0;MapIndex<=7;MapIndex++){
        grpName[MapIndex] = getMapChar();
    }
    
    grpName[0] = 'N';//this is just to get a break-point
        
}


