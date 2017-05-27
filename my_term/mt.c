#include "mt.h"
#include <stdio.h>
#include <string.h>

int clear(void)
{
	write(1, "\E[2J\E[0;0H",strlen("\E[2J\E[0;0H"));
	return 0;	
}
int term_xy(int x, int y)
{
	char str[20];
	int rows, cols;
	
	get_screen_size(&rows, &cols);
	
	if((x >= 0 && x <= cols) && (y >= 0 && y <= rows))
	{
		if(sprintf(str, "\E[%d;%dH", y, x))
			write(1, str, strlen(str));
		else
			return -1;
	}
	
		return 0;
}
int get_screen_size(int *rows, int *cols)
{
	struct winsize size;
	
	if(!ioctl(0, TIOCGWINSZ, &size))
	{
		*rows = size.ws_row;
		*cols = size.ws_col;
		return 0;
	}
	else
		return -1;
}
int fg_color(enum colors color)
{
	char str[20];
	if(!sprintf(str, "\E[%dm", (color+30)))
		return -1;
	else
		write(1, str, strlen(str));
	return 0;
}
int bg_color(enum colors color)
{
	char str[20];
	if(!sprintf(str, "\E[%dm", (color+40)))
		return -1;
	else
		write(1, str, strlen(str));
	
	return 0;
}
