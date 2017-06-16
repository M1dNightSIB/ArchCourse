#include "mf.h"


void init_frame()//print main frame
{

	clear();
	init_ram_box();
	init_info_box();
	init_big_char_box();
	init_key_box();

}

void init_ram_box() //window with cells of memory
{
	box(RAM_X, RAM_Y, RAM_X + 61, RAM_Y + 11);
	term_xy((RAM_X + 60) / 2 - 3, RAM_Y);
	write(FD, "MEMORY", strlen("MEMORY"));
}

void init_big_char_box() //window with current cell of memory which 
{						//is storage  in instruction counter
	box(BC_X, BC_Y, BC_X + 51, BC_Y + 11);
}

void init_key_box()  //window with manage keys
{						 
	box(KEY_X, KEY_Y, KEY_X + 32, KEY_Y + 11);
	term_xy(KEY_X + 32 / 2 - 9, KEY_Y);
	write(FD, "KEYS", strlen("KEYS"));

	term_xy(KEY_X + 1, KEY_Y + 1);
	write(FD, "L - load", strlen("L - load"));

	term_xy(KEY_X + 1, KEY_Y + 2);
	write(FD, "S - save", strlen("S - save"));

	term_xy(KEY_X + 1, KEY_Y + 3);
	write(FD, "R - run", strlen("R - run"));

	term_xy(KEY_X + 1, KEY_Y + 4);
	write(FD, "T - step", strlen("T - step"));

	term_xy(KEY_X + 1, KEY_Y + 5);
	write(FD, "I - reset", strlen("I - reset"));

	term_xy(KEY_X + 1, KEY_Y + 6);
	write(FD, "F5 - accumulator", strlen("F5 - accumulator"));

	term_xy(KEY_X + 1, KEY_Y + 7);
	write(FD, "F6 - instruction counter", strlen("F6 - instruction counter"));
}						


void init_info_box() //window with current statuses of
{					 //accumulator, instruction counter, operarion, flags
	box(ACC_X, ACC_Y, ACC_X + 22, ACC_Y + 2);    //accumulator box
	term_xy(ACC_X + 22 / 2 - 5, ACC_Y);
	write(FD, "ACCUMULATOR", strlen("ACCUMULATOR"));
	
	box(INST_CNT_X, INST_CNT_Y, INST_CNT_X + 22, INST_CNT_Y + 2); //instcounter box
	term_xy(INST_CNT_X + 22 / 2 - 9, INST_CNT_Y);
	write(FD, "INSTRUCTIONCOUNTER", strlen("INSTRUCTIONCOUNTER"));
	
	box(OPER_X, OPER_Y, OPER_X + 22, OPER_Y + 2); //operatin box
	term_xy(OPER_X + 22 / 2 - 4, OPER_Y);
	write(FD, "OPERATION", strlen("OPERATION"));
	
	box(FL_X, FL_Y, FL_X + 22, FL_Y + 2); //flags box
	term_xy(FL_X + 22 / 2 - 2, FL_Y);
	write(FD, "FLAGS", strlen("FLAGS"));
}

void cursor(char *str)
{
	write(FD, str, strlen(str));
}