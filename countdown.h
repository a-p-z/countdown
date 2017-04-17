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

int string_to_seconds(char string[N_DIGITS]);
void seconds_to_string(long seconds, char string[N_DIGITS]);
void push_char(char string[N_DIGITS], int i);
void countdown_read_time(char string[N_DIGITS]);
void countdown_start(long seconds);

#endif
