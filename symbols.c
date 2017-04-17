#include "symbols.h"

void print_string(int x, int y, char string[], int length)
{
	const bool (**symbols)[5][5] = malloc(sizeof(bool**) * length);
	string_to_symbols(string, symbols, length);
	print_symbols(x, y, symbols, length);
	free(symbols);
}

void print_symbol(int x, int y, const bool (*symbol)[SYMBOL_H][SYMBOL_W])
{
	int h;
	int w;

	for (h = SYMBOL_H - 1; h >= 0; h--)
	{
		for (w = 0; w < SYMBOL_W; w++)
		{
			if ((*symbol)[h][w])
			{	
				mvaddch(y + h, x + w, ' ' | A_REVERSE);
			}
		}
	}
}

void print_symbols(int x, int y, const bool (*symbols[])[SYMBOL_H][SYMBOL_W], int length)
{
	int i;

	for (i = 0; i < length; i++)
	{
		print_symbol(x, y, symbols[i]);
		x += SYMBOL_W + 1;
	}
}

void string_to_symbols(char string[], const bool (*symbols[])[SYMBOL_H][SYMBOL_W], int length)
{
	int i;
	const bool (*symbol)[SYMBOL_H][SYMBOL_W];

	for (i = 0; i < length; i++)
	{
		switch (string[i])
		{
			case ' ':
				symbol = &SPACE;
				break;

			case ':':
				symbol = &COLON;
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				symbol = &NUMBERS[string[i] - '0'];
				break;
			
			default:
				symbol = &SPACE;
				break;
		}
		symbols[i] = symbol;
	}
}

const bool NUMBERS[][SYMBOL_H][SYMBOL_W] =
{
	{
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1}
	},
	{
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1}
	},
	{
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1}
	},
	{
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1}
	},
	{
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1}
	},
	{
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1}
	},
	{
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1}
	},
	{
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1}
	},
	{
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1}
	},
	{
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1}
	}
};

const bool COLON[SYMBOL_H][SYMBOL_W] =
{
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0}
};

const bool SPACE[SYMBOL_H][SYMBOL_W] =
{
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0}
};

const bool MINUS[SYMBOL_H][SYMBOL_W] =
{
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 1, 1, 1, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0}
};
