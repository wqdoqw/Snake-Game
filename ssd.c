/*
 * ssd.c
 *
 * Created: 6/1/2017 4:16:48 PM
 *  Author: wqdoq
 */ 
/*
 * FILE: lab14-2.c
 * A seven segment display is connected to port A, with the CC
 * (digit select) pin connected to port D, pin 0.
 * A push button will be connected to pin T0.
 * We will count the number of times that the push button 
 * is pressed using timer/counter 0. We will display this value on 
 * the seven segment display as a two digit number 00 -> 99. We
 * will alternate the digit display 1000 times per second so that
 * we can see both digits together.
 */
#include "snake.h"
#include <avr/io.h>
#include "ssd.h"
#include "timer0.h"

	uint8_t snb;
	uint8_t seven_seg_data[10] = {63,6,91,79,102,109,125,7,127,111};
	uint8_t seven_seg_cc = 0;
	
void init_ssd(void) {
	DDRC=0xff;
	DDRD=0x04; //D2
}

 void update_ssd(void) {
 	
	snb = get_snake_length();
	seven_seg_cc = 4 ^ seven_seg_cc;
	
		if(seven_seg_cc==0){
			PORTC = seven_seg_data[(snb%10)];
			PORTD = seven_seg_cc;
		}
		else if(snb>9){	
			
			PORTC = seven_seg_data[(snb/10)] ;	
			PORTD = seven_seg_cc;
		}
		

}
