#include <stdio.h>
#include "simple_computer/sc.h"
#include "main.h"
#include "main_frame/mf.h"

int main()
{
	cursor(HIDE_CURSOR);// start initialization
	init_frame();
	memInit();
	regInit();
	while(1)
	{
		print_ram(0);
		print_acc();
		print_inst_cnt();
		print_operation();
	}	
	cursor(SHOW_CURSOR);
	return 0;
}

void print_ram(int cell)
{
	for(int i = 0; i < memory_size / 10; i++)
	{
		term_xy(RAM_X + 1, RAM_Y + i + 1);

		for(int j = 0; j < memory_size / 10; j++)
		{
			char buf[6];
			sprintf(buf, "+%04d ", RAM[i * 10 + j]);
			
			if(cell == i * 10 + j)
				bg_color(GREEN);
			else
				bg_color(DEFAULT);
			
			write(FD, buf, strlen(buf));
		}
	}
}

void print_acc()
{
	term_xy(ACC_X + 9, ACC_Y + 1);
	
	char buf[5];
	sprintf(buf, "+%04d", acc);

	write(FD, buf, strlen(buf));
}

void print_inst_cnt()
{
	term_xy(INST_CNT_X + 9, INST_CNT_Y + 1);
	
	char buf[5];
	sprintf(buf, "+%04d", inst_cnt);

	write(FD, buf, strlen(buf));
}

void print_operation()
{
	term_xy(OPER_X + 7, OPER_Y + 1);
	
	char buf[8];
	sprintf(buf, "+%02d : %02d", operation / 100, operation % 100);

	write(FD, buf, strlen(buf));
}