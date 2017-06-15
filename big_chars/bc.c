#include "bc.h"

void printA(char str)
{
	int len = 1 + strlen("\E(0\E(B");
	char *_str = (char*)malloc(len * sizeof(char));

	sprintf(_str, "\E(0%c\E(B", str);
	write(1, _str, strlen(_str));
}

int box(int x1, int y1, int x2, int y2)
{
	int xmax, ymax;
	get_screen_size(&ymax, &xmax);

	if(x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || 
		x1 > xmax || x2 > xmax || y1 > ymax || y2 > ymax)
		return -1;

	term_xy(x1, y1);
	printA(BOXCHAR_TL);
	term_xy(x1,y2);
	printA(BOXCHAR_BL);

	term_xy(x2, y1);
	printA(BOXCHAR_TR);
	term_xy(x2,y2);
	printA(BOXCHAR_BR);

	for(int i = x1 + 1; i < x2; i++)
	{
		term_xy(i, y1);
		printA(BOXCHAR_HOR);
		term_xy(i, y2);
		printA(BOXCHAR_HOR);
	}

	for(int i = y1 + 1; i < y2; i++)
	{
		term_xy(x1,i);
		printA(BOXCHAR_VERT);
		term_xy(x2,i);
		printA(BOXCHAR_VERT);
	}

	return 0;
}

int printchar(int *big, int x, int y, enum colors fg, enum colors bg)
{
	int xmax, ymax, pos, bit;
	char row[9];
	
	get_screen_size(&ymax, &xmax);
	
	if(x < 0 || y < 0 || x + 8 > xmax|| y + 8 > ymax)
		return -1;
	
	row[8] = '\0';
	
	fg_color(fg);
	bg_color(bg);
	
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0;  j < 8; j++)
		{
			pos = i >> 2;
			bit = (big[pos] >> ((i % 4) * 8 + j)) & 1;
			
			if(bit == 0)
				row[j] = ' ';
			else
				row[j] = BOXCHAR_REC;
			
		}
		term_xy(x, y + i);
		
		for(int i = 0; i < strlen(row); i++)
			printA(row[i]);
	}
	fg_color(DEFAULT);
	bg_color(DEFAULT);
		
	return 0;
}