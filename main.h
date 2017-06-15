#ifndef MAIN_H
#define MAIN_H

#include "simple_computer/sc.h"
#include "main_frame/mf.h"
#include "read_keys/rk.h"
#include <signal.h>

int acc = 0x0,
	inst_cnt = 0x0,
	operation = 0x0,
	cur_cell = 0x0,
	hand_exit = 0x1;

void key_handler(enum keys key);
void print_ram(int *cell); //write cells of memory
void print_acc();
void print_inst_cnt();
void print_operation();
void print_cur_cell();
void init_sig_handlers();
int set_non_canonical_regime(int vmin, int echo);

#endif
