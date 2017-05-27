#ifndef MT_H
#define MT_H

#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

enum colors
{
	BLACK = 0,
	RED = 1,
	GREEN = 2,
	YELLOW = 3,
	BLUE = 4,
	PURPLE = 5,
	LBLUE = 6,
	WHITE = 7,
	DEFAULT = 9
};

int clear(void);
int term_xy(int x, int y);
int get_screen_size(int *rows, int *cols);
int fg_color(enum colors color);
int bg_color(enum colors color);


#endif
