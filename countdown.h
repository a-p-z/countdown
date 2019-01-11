#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>

#include "symbols.h"

#define N_DIGITS 5
#define CLOCK_W  N_DIGITS * (SYMBOL_W + 1)
#define CLOCK_H  SYMBOL_H
#define WHITE    1
#define RED      2
#define CONTINUE 0
#define EXIT     1
#define RESUME   2

int digits_to_seconds(char digits[N_DIGITS]);
void seconds_to_digits(long seconds, char digits[N_DIGITS]);
void push_digit(char digits[N_DIGITS], int i);
void countdown_read_digits(char string[N_DIGITS]);
void countdown_start(long seconds);
void set_color_by_remaining_time(long time);
void set_color(short seconds);
void print_digits(char digits[N_DIGITS]);
void print_seconds(long time);
short read_command();
short pause_read_command();
#endif
