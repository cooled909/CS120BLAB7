/*	Author: Edward Segura
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab 7  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *  Demo Link: https://drive.google.com/file/d/1-69rr3-mdl9A3snO6I56JQ8uuHPiKBod/view?usp=sharing
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
    	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
    }


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    unsigned char B_out;
    unsigned short max = 128;
    ADC_init();
    while (1) {
    	ADC = PINA & 0x01;
    	//39 is lowest detected by photoresistor so my range will be 128-39
    	if(ADC >= max){
    		B_out = 0xFF;
    	}
    	else if(ADC >= 117){
    		B_out = 0x7F;
    	}
    	else if(ADC >= 106){
    		B_out = 0x3F;
    	}
    	else if(ADC >= 95){
    		B_out = 0x1F;
    	}
    	else if(ADC >= 84){
    		B_out = 0x0F;
    	}
    	else if(ADC >= 73){
    		B_out = 0x07;
    	}
    	else if(ADC >= 62){
    		B_out = 0x03;
    	}
    	else if (ADC >= 51){
    		B_out = 0x01;
    	}
    	else if(ADC >= 39){
    		B_out = 0x00;
    	}
    	PORTB = B_out;
    }
    return 1;
}
