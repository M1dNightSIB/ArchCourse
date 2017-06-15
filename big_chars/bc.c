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

int setcharpos(int *big, int x, int y, int value)
{
	int pos = 0;

	if((x < 0) || (y < 0) || (x > 7) || (y > 7) || (value > 1) || (value < 0))
		return -1;

	if(y <= 3)
		pos = 0;
	else
		pos = 1;

	y = y % 4;

	if(value == 0)
		big[pos] &= ~(1 << (y * 8 + x));
	else
		big[pos] |= (1 << (y * 8 + x)); 

	return 0;
}

int getcharpos(int *big, int x, int y, int *value)
{
	int pos = 0;

	if((x < 0) || (y < 0) || (x > 7) || (y > 7))
		return -1;

	if(y <= 3)
		pos = 0;
	else
		pos = 1;

	y = y % 4;
	*value = (big[pos] >> (y * 8)) & 1;

	return 0;
}

int charwrite(int fd, int *big, int count)
{
	int err = 0;

  	err = write(fd, &count, sizeof(count));
  	
  	if (err == -1)
    	return -1;

 	err = write(fd, big, count * sizeof(int) * 2);
  	
  	if (err == -1) 
    	return -1;

 	return 0;
}

int charread(int fd, int *big, int nd_count, int *count)
{
	int n, cnt, err;

  	err = read(fd, &n, sizeof(n));
  	
  	if ((err == -1) || (err != sizeof(n)))
	    return -1;


  	cnt = read(fd, big, nd_count * sizeof(int) * 2);
  
  	if (cnt == -1)
    	return -1;

  	*count = cnt / (sizeof(int) * 2);

  	return 0;
}