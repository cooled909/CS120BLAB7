/*	Author: Edward Segura
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab 7  Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *  Demo Link: https://drive.google.com/file/d/12aTwfiKz2n4CNeVm-mGwwUo6K-dmYVup/view?usp=sharing
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
    	if(ADC >= max/2){
    		B_out = 0x01;
    	}
    	else{
    		B_out = 0x00;
    	}
    	PORTB = B_out;
    }
    return 1;
}
