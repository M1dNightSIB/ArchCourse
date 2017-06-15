#include <stdio.h>
#include "main.h"

int main()
{
	cursor(HIDE_CURSOR);// start initialization
	init_frame();
	memInit();
	regInit();
	set_non_canonical_regime(0x1, 0x0);
	enum keys key = other_key;

	while(hand_exit)
	{
		print_ram(&cur_cell);
		print_acc();
		print_inst_cnt();
		print_operation();
		key_handler(key);
	}

	clear();	//clearing 
	cursor(SHOW_CURSOR);
	set_non_canonical_regime(0x0, 0x1);

	return 0;
}

void init_sig_handlers()
{
	
}

int set_non_canonical_regime(int vmin, int echo)
{
	if(set_term_regime(0, 0, vmin, echo, 1))
		return 0;
	else
		return -1;
}

void key_handler(enum keys key)
{
	char buf[4];
	read_key(&key);

	switch(key)
	{
		case up_key:
			cur_cell -= 0xA;
			break;
		
		
		case down_key:
			cur_cell += 0xA;
			break;

		
		case left_key:
			cur_cell -= 0x1;
			break;

		
		case right_key:
			cur_cell += 0x1;
			break;
		
		case q_key:
			hand_exit = 0x0;
			break;

		case f5_key:
			set_non_canonical_regime(0x4, 0x0);
			read(FD, buf, sizeof(buf));
			acc = atoi(buf);
			set_non_canonical_regime(0x1, 0x0);
			break;

		case f6_key:
			inst_cnt = cur_cell;
			break;

		case enter_key:
			set_non_canonical_regime(0x4, 0x0);
			read(FD, buf, sizeof(buf));
			RAM[cur_cell] = atoi(buf);
			break;
		
		default: 
			key = other_key;
			break;
	}

	if(cur_cell > 0x63)// 0x63 = 99
		cur_cell = 0x0;
	if(cur_cell < 0x0)
		cur_cell = 0x63;

	operation = RAM[cur_cell];
}

void print_cur_cell()
{

}

void print_ram(int *cell)
{
	for(int i = 0; i < memory_size / 10; i++)
	{
		term_xy(RAM_X + 1, RAM_Y + i + 1);

		for(int j = 0; j < memory_size / 10; j++)
		{
			char buf[6];
			sprintf(buf, "+%04d ", RAM[i * 10 + j]);
			
			if(*cell == i * 10 + j)
				bg_color(GREEN);
			
			write(FD, buf, strlen(buf));
			bg_color(DEFAULT);
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