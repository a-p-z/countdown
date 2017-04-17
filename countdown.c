#include "countdown.h"

int main()
{
	short *background = malloc(sizeof(short));
	short *foreground = malloc(sizeof(short));
	char string[N_DIGITS];
	long seconds;

	initscr();
	start_color();
	assume_default_colors(-1, -1);
	pair_content(0, foreground, background);
	init_pair(1, *foreground, *background);
	init_pair(2, COLOR_RED, *background);
	keypad(stdscr, TRUE);
	curs_set(0);

	countdown_read_time(string);
	seconds = string_to_seconds(string);
	countdown_start(time(NULL) + seconds);

	free(background);
	free(foreground);
	endwin();

	return 0;
}

int string_to_seconds(char string[N_DIGITS])
{
	short h = string[1] - '0';
	short m1 = string[3] - '0';
	short m0 = string[4] - '0';

	return 3600 * h + 600 * m1 + 60 * m0;
}

void seconds_to_string(long seconds, char string[N_DIGITS])
{
	string[0] = seconds >= 0 ? ' ' : '-';
	seconds = labs(seconds);
	string[1] = seconds / 3600 % 10 + '0';
	string[2] = ':';
	string[3] = seconds / 60 % 60 / 10 + '0';
	string[4] = seconds / 60 % 10  + '0';
}

void push_char(char string[N_DIGITS], int i)
{
	string[0] = ' ';
	string[1] = string[3];
	string[2] = ' ';
	string[3] = string[4];
	string[4] = (char) i;
}

void countdown_read_time(char string[N_DIGITS])
{
	bool flag = true;
	int x;
	int y;
	int c;

	string[0] = ' ';
	string[1] = '0';
	string[2] = ' ';
	string[3] = '0';
	string[4] = '0';
	
	while (flag)
	{
		clear();

		x = (COLS - CLOCK_W) / 2;
		y = (LINES - CLOCK_H) / 2;

		print_string(x, y, string, N_DIGITS);

		mvprintw(y + SYMBOL_H - 1, x + 2 * (SYMBOL_W + 1), "h");
		mvprintw(y + SYMBOL_H - 1, x + 5 * (SYMBOL_W + 1), "m");

		refresh();
		
		c = getch();

		switch (c)
		{
			case '\n':
				flag = false;
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
				push_char(string, c);
				break;

			case KEY_UP:
				string[N_DIGITS-1]++;
				break;

			case KEY_DOWN:
				string[N_DIGITS-1]--;
				break;
			
			default:
				break;
		}
	}
}

void countdown_start(const long seconds)
{
	int x;
	int y;
	long current;
	char string[N_DIGITS];

	while (true)
	{
		clear();
		
		x = (COLS - CLOCK_W) / 2;
		y = (LINES - CLOCK_H) / 2;

		current = seconds - time(NULL);
		
		if (current >= 0)
		{
			attron(COLOR_PAIR(1));
		}
		else
		{
			attron(COLOR_PAIR(2));
		}

		seconds_to_string(current, string);
		print_string(x, y, string, N_DIGITS);

		mvprintw(y + SYMBOL_H -1, x + CLOCK_W, "%02ld", labs(current) % 60);

		refresh();
		sleep(1);
	}
}
