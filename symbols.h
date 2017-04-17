#ifndef SYMBOLS_H
#define SYMBOLS_H

#include <stdlib.h>
#include <curses.h>

#define SYMBOL_W 5
#define SYMBOL_H 5

const bool NUMBERS[10][SYMBOL_H][SYMBOL_W];
const bool COLON[SYMBOL_H][SYMBOL_W];
const bool SPACE[SYMBOL_H][SYMBOL_W];
const bool MINUS[SYMBOL_H][SYMBOL_W];

void print_string(int x, int y, char string[], int length);
void print_symbols(int x, int y, const bool (*symbols[])[SYMBOL_H][SYMBOL_W], int length);
void print_symbol(int x, int y, const bool (*symbol)[SYMBOL_H][SYMBOL_W]);
void string_to_symbols(char string[], const bool (*symbols[])[SYMBOL_H][SYMBOL_W], int length);

#endif
