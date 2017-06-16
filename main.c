#include <stdio.h>
#include "main.h"

int main()
{
	cursor(HIDE_CURSOR);// start initialization
	init_frame();
	memInit();
	regInit();
	init_sig_handlers();
	set_non_canonical_regime(0x1, 0x0);

	while(hand_exit)
	{
		print_ram(&cur_cell);
		print_acc();
		print_inst_cnt();
		print_operation();
		print_cur_cell();
		print_flags();
		key_handler(key);
	}

	clear();	//clearing 
	cursor(SHOW_CURSOR);
	set_non_canonical_regime(0x0, 0x1);

	return 0;
}

void init_sig_handlers()
{
	signal(SIGALRM, cell_step);
	signal(SIGUSR1, return_hand_manage);
	
	timer.it_value.tv_sec = 4;
	timer.it_value.tv_usec = 0;
	timer.it_interval.tv_sec = 1;
	timer.it_interval.tv_usec = 500;
	setitimer(ITIMER_REAL, &timer, NULL);
}

void return_hand_manage(int sig)
{
	regSet(FLAG_INTERRUPT, 1);
}

void cell_step(int sig)
{
	int val;
	regGet(FLAG_INTERRUPT, &val);
	if(val == 0)
	{
		cur_cell = inst_cnt;
		print_ram(&cur_cell);
		print_inst_cnt();
		print_operation();
		print_cur_cell();
		print_flags();
		inst_cnt++;
		
		if(inst_cnt > 0x63)
			inst_cnt = 0;
	}
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
		case up_key:		//
			cur_cell -= 0xA;
			break;
				
		case down_key:		//
			cur_cell += 0xA;
			break;
		
		case left_key:		//
			cur_cell -= 0x1;
			break;

		
		case right_key:		//change cells
			cur_cell += 0x1;
			break;
		
		case q_key:			//exit
			hand_exit = 0x0;
			break;

		case f5_key:		//set accumulator
			set_non_canonical_regime(0x4, 0x0);
			read(FD, buf, sizeof(buf));
			acc = atoi(buf);
			set_non_canonical_regime(0x1, 0x0);
			break;

		case f6_key:		//set instruction counter
			inst_cnt = cur_cell;
			break;

		case t_key:
			setitimer(ITIMER_REAL, &timer, NULL);
			regSet(FLAG_INTERRUPT, 0);
			break;	

		case enter_key:
			set_non_canonical_regime(0x4, 0x0);
			read(FD, buf, sizeof(buf));
			RAM[cur_cell] = atoi(buf);
			break;

		case i_key:
			raise(SIGUSR1);
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
	int start_x = 45;
	const int y = 16;
	int big[2] = {0, 0};
	int tmp = RAM[cur_cell];

	for(int i = 0; i < 4; i++)
	{
		transform_bchar(ind[tmp % 10], big);
		printchar(big, start_x, y, GREEN, DEFAULT);
		start_x -= 9;
		tmp /= 10;
	}
	transform_bchar(ind[16], big);
	printchar(big, start_x, y, GREEN, DEFAULT);
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

void print_flags()
{
	int start_x = 64 + 1;
	const int y = 11 + 1;

	fg_color(RED);

	for(int i = 0; i < 5; i++)
	{
		int val;
		regGet(i+1, &val);
		term_xy(start_x, y);

		if(val == 1)
		{
			char flag[4];
			sprintf(flag, "%c", flags[i]);
			write(FD, flag, strlen(flag));
		}
		else
			write(FD, " ", 1);
		
		start_x += 4;
	}

	fg_color(DEFAULT);
}

void transform_bchar(char *sym, int *big) //transform bigchar to int big[2]
{
	int x, y;
	for(int i = 0; i < 64; i++)
	{
		x = i % 8;
		y = i / 8;
		setcharpos(big, x, y, sym[i]);
	}
}