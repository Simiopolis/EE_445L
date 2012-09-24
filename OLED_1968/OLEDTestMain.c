// OLEDTestMain.c
// Runs on LM3S1968
// Test Output.c by sending various characters and strings to
// the OLED display and verifying that the output is correct.
// Daniel Valvano
// July 28, 2011

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to the Arm Cortex M3",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2011
   Section 3.4.5

 Copyright 2011 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

#include <stdio.h>
#include "Output.h"
#include "rit128x96x4.h"
#include "Graphics.h"

// delay function for testing from sysctl.c
// which delays 3*ulCount cycles
#ifdef __TI_COMPILER_VERSION__
	//Code Composer Studio Code
	void Delay(unsigned long ulCount){
	__asm (	"    subs    r0, #1\n"
			"    bne     Delay\n"
			"    bx      lr\n");
}

#else
	//Keil uVision Code
	__asm void
	Delay(unsigned long ulCount)
	{
    subs    r0, #1
    bne     Delay
    bx      lr
	}

#endif

int main(void){
	RIT128x96x4Init(1000000);
	DrawMenuSetTimer(87);
	Delay(8000000);
	DrawMenuSetAlarm(87);
	Delay(8000000);
	DrawMenuToggleAlarm(87);
	Delay(8000000);
	DrawMenuDisplayMode(87);
	Delay(8000000);

	/*RIT128x96x4_Line(10, 20, 50, 80, 'F');
	Delay(4000000);
	RIT128x96x4_Line(40, 20, 60, 80, 'F');
	Delay(4000000);
	RIT128x96x4_Line(50, 30, 20, 70, 'F');
	Delay(4000000);
	RIT128x96x4_Line(60, 40, 10, 30, 'F');
	Delay(4000000);*/
	RIT128x96x4Clear();
	
	while(1);
}
