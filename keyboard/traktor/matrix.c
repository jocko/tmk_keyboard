/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "timer.h"
#include "matrix.h"


#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif
static bool debouncing = false;
static uint16_t debouncing_time = 0;


/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);


void matrix_init(void)
{
    // initialize row and col
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        _delay_us(1);  // delay for settling
        matrix_row_t cols = read_cols();
        if (matrix_debouncing[i] != cols) {
            if (debouncing) {
                dprintf("bounce: %d %d@%02X\n", timer_elapsed(debouncing_time), i, matrix_debouncing[i]^cols);
            }
            matrix_debouncing[i] = cols;
            debouncing = true;
            debouncing_time = timer_read();
        }
        unselect_rows();
    }

    if (debouncing && timer_elapsed(debouncing_time) >= DEBOUNCE) {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        debouncing = false;
    }

    return 1;
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

/* Column pin configuration
 * col: 0   1   2   3   4   5   6   7   8   9   10  11  12  13
 * pin: F0  F1  F4  F5  F6  F7  B6  D0  B7  B3  B2  B1  B0  D1
 */
static void  init_cols(void)
{
    // Input with pull-up(DDR:0, PORT:1)
    DDRF  &= ~(1<<0 | 1<<1 | 1<<4 | 1<<5 | 1<<6 | 1<<7);
    PORTF |=  (1<<0 | 1<<1 | 1<<4 | 1<<5 | 1<<6 | 1<<7);
    DDRD  &= ~(1<<0 | 1<<1);
    PORTD |=  (1<<0 | 1<<1);
    DDRB  &= ~(1<<6 | 1<<7 | 1<< 3 | 1<<2 | 1<<1 | 1<<0);
    PORTB |=  (1<<6 | 1<<7 | 1<< 3 | 1<<2 | 1<<1 | 1<<0);
}

static matrix_row_t read_cols(void)
{
    return (PINF&(1<<0) ? 0 : (1<<0)) |
           (PINF&(1<<1) ? 0 : (1<<1)) |
           (PINF&(1<<4) ? 0 : (1<<2)) |
           (PINF&(1<<5) ? 0 : (1<<3)) |
           (PINF&(1<<6) ? 0 : (1<<4)) |
           (PINF&(1<<7) ? 0 : (1<<5)) |
           (PINB&(1<<6) ? 0 : (1<<6)) |
           (PIND&(1<<0) ? 0 : (1<<7)) |
           (PINB&(1<<7) ? 0 : (1<<8)) |
           (PINB&(1<<3) ? 0 : (1<<9)) |
           (PINB&(1<<2) ? 0 : (1<<10)) |
           (PINB&(1<<1) ? 0 : (1<<11)) |
           (PINB&(1<<0) ? 0 : (1<<12)) |
           (PIND&(1<<1) ? 0 : (1<<13));
}

/* Row pin configuration
 * row: 0   1   2   3
 * pin: D2  D3  C6  C7 
 */
static void unselect_rows(void)
{
    // Hi-Z(DDR:0, PORT:0) to unselect
    DDRD  &= ~0b00001100;
    PORTD &= ~0b00001100;
    DDRC  &= ~0b11000000;
    PORTC &= ~0b11000000;
}

static void select_row(uint8_t row)
{
    // Output low(DDR:1, PORT:0) to select
    switch (row) {
        case 0:
            DDRD  |= (1<<2);
            PORTD &= ~(1<<2);
            break;
        case 1:
            DDRD  |= (1<<3);
            PORTD &= ~(1<<3);
            break;
        case 2:
            DDRC  |= (1<<6);
            PORTC &= ~(1<<6);
            break;
        case 3:
            DDRC  |= (1<<7);
            PORTC &= ~(1<<7);
            break;
    }
}
