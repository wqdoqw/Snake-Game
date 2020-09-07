/*
 * score.c
 *
 * Written by Peter Sutton
 */
#include <stdio.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "terminalio.h"

#include "score.h"

// Variable to keep track of the score. We declare it as static
// to ensure that it is only visible within this module - other
// modules should call the functions below to modify/access the
// variable.
static uint32_t score;

void init_score(void) {
	score = 0;
	
}

void add_to_score(uint16_t value) {
	score += value;
	move_cursor(0,0);
	printf_P(PSTR("Current Score: %3d"), get_score());

}

uint32_t get_score(void) {

	return score;
}
