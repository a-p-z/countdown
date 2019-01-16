#include "countdown.h"

int main()
{
	short *background = malloc(sizeof(short));
	short *foreground = malloc(sizeof(short));
	char digits[N_DIGITS];
	long seconds;

	initscr();
	start_color();
	assume_default_colors(-1, -1);
	pair_content(0, foreground, background);
	init_pair(WHITE, *foreground, *background);
	init_pair(RED, COLOR_RED, *background);
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();

	countdown_read_digits(digits);
	seconds = digits_to_seconds(digits);
	countdown_start(seconds);

	free(background);
	free(foreground);
	endwin();

	return 0;
}

int digits_to_seconds(char digits[N_DIGITS])
{
	short h = digits[1] - '0';
	short m1 = digits[3] - '0';
	short m0 = digits[4] - '0';

	return 3600 * h + 600 * m1 + 60 * m0;
}

void seconds_to_digits(long seconds, char digits[N_DIGITS])
{
	digits[0] = ' ';
	seconds = labs(seconds);
	digits[1] = seconds / 3600 % 10 + '0';
	digits[2] = ':';
	digits[3] = seconds / 60 % 60 / 10 + '0';
	digits[4] = seconds / 60 % 10  + '0';
}

void push_digit(char digits[N_DIGITS], int i)
{
	digits[0] = ' ';
	digits[1] = digits[3];
	digits[2] = ' ';
	digits[3] = digits[4];
	digits[4] = (char) i;
}

void countdown_read_digits(char digits[N_DIGITS])
{
	int x;
	int y;
	int c;

	digits[0] = ' ';
	digits[1] = '0';
	digits[2] = ' ';
	digits[3] = '0';
	digits[4] = '0';
	
	while (true)
	{
		clear();

		x = (COLS - CLOCK_W) / 2;
		y = (LINES - CLOCK_H) / 2;

		print_digits(digits);

		mvprintw(y + SYMBOL_H - 1, x + 2 * (SYMBOL_W + 1), "h");
		mvprintw(y + SYMBOL_H - 1, x + 5 * (SYMBOL_W + 1), "m");

		refresh();
		
		c = getch();

		switch(c)
		{
			case '\n':
				return;

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
				push_digit(digits, c);
				break;

			default:
				break;
		}
	}
}

void countdown_start(long seconds)
{
	long remaining_time;
	char digits[N_DIGITS];
	short command;

	seconds += time(NULL);

	while (true)
	{
		command = read_command();
		if (command == EXIT) {
			break;
		
		} else if (command == RESUME) {
			seconds = remaining_time + time(NULL);
		}

		remaining_time = seconds - time(NULL);
		seconds_to_digits(remaining_time, digits);

		clear();
		set_color_by_remaining_time(remaining_time);
		beep_on_timeout(remaining_time);
		print_digits(digits);
		print_seconds(remaining_time);
		refresh();

		sleep(1);
	}
}

void set_color_by_remaining_time(const long time)
{
	if (time >= 0)
	{
		set_color(WHITE);
	}
	else
	{
		set_color(RED);
	}
}

void beep_on_timeout(const long time)
{
	if (-10 <= time && time <= 0)
	{
		beep();
	}
}

void set_color(const short color)
{
	attron(COLOR_PAIR(color));
}

void print_digits(char digits[N_DIGITS])
{
	int x = (COLS - CLOCK_W) / 2;
	int y = (LINES - CLOCK_H) / 2;

	print_string(x, y, digits, N_DIGITS);
}

void print_seconds(const long seconds)
{
	int x = (COLS - CLOCK_W) / 2;
	int y = (LINES - CLOCK_H) / 2;

	mvprintw(y + SYMBOL_H -1, x + CLOCK_W, "%02ld", labs(seconds) % 60);
}

short read_command()
{
	nodelay(stdscr, TRUE);
	noecho();

	switch(getch())
	{
		case 'P':
			return pause_read_command();

		case 'Q':
			return EXIT;

		default:
			return CONTINUE;
	}

	return CONTINUE;
}

short pause_read_command()
{
	nodelay(stdscr, FALSE);
	noecho();

	while(true)
	{
		switch(getch())
		{
			case 'P':
				return RESUME;

			case 'Q':
				return EXIT;

			default:
				break;
		}
	}

	return CONTINUE;
}
