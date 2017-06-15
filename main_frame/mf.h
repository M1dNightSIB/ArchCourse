#ifndef MF_H
#define MF_H

#define RAM_X 2
#define RAM_Y 2
#define ACC_X 64
#define	ACC_Y 2
#define	INST_CNT_X 64
#define	INST_CNT_Y 5
#define	OPER_X 64
#define OPER_Y 8
#define FL_X 64
#define	FL_Y 11
#define KEY_X 54
#define KEY_Y 14
#define BC_X 2
#define BC_Y 14
#define FD 1
#define HIDE_CURSOR "\E[?25l"
#define SHOW_CURSOR "\E[?25h"
#include "../big_chars/bc.h"

void init_frame();
void init_ram_box();
void init_key_box();
void init_big_char_box();
void init_info_box();
void cursor(char *str);

#endif