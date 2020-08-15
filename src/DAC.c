// DAC.c
// Runs on LM4F120 or TM4C123, 
// edX lab 13 
// Implementation of the 4-bit digital to analog converter
// Daniel Valvano, Jonathan Valvano
// December 29, 2014
// Port B bits 3-0 have the 4-bit DAC

#include "DAC.h"
#include "..//tm4c123gh6pm.h"

// **************DAC_Init*********************
// Initialize 4-bit DAC 
// Input: none
// Output: none
void DAC_Init(void){ volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x2; //initialize Port B
	delay = SYSCTL_RCGC2_R;
	GPIO_PORTB_DIR_R = 0xf; //initialize Port B bits 3-0 as outputs
	GPIO_PORTB_DR8R_R  = 0xf; //8 mA drive
	GPIO_PORTB_PCTL_R = 0; //configure as GPIO
	GPIO_PORTB_DEN_R = 0xf; //enable digital pins

}


// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Output: none
void DAC_Out(unsigned long data){
  GPIO_PORTB_DATA_R = data;
}
