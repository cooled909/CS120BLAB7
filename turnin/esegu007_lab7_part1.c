/*	Author: Edward Segura
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab 7  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *  Demo Link: https://drive.google.com/file/d/1-4vqNr1k9EVjBqJf3BOVaEsvLDtsta6G/view?usp=sharing
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
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
    unsigned short ADC_in;
    unsigned char B_out;
    unsigned char D_out;
    ADC_init();
    while (1) {
    	ADC = PINA & 0x01;
    	ADC_in = ADC;
    	B_out = (char)ADC_in;
    	D_out = (char)(ADC_in >> 8);
    	PORTB = B_out;
    	PORTD = D_out;
    }
    return 1;
}
