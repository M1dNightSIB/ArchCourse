#ifndef MAIN_H
#define MAIN_H

#include "simple_computer/sc.h"
#include "main_frame/mf.h"
#include "read_keys/rk.h"
#include <signal.h>
#include <signal.h>
#include <sys/time.h>

int acc = 0x0,
	inst_cnt = 0x0,
	operation = 0x0,
	cur_cell = 0x0,
	hand_exit = 0x1;

struct itimerval timer;
enum keys key = other_key;

void key_handler(enum keys key);
void cell_step(int sig); //for signal
void return_hand_manage(int sig);//for signal
void print_ram(int *cell); //write cells of memory
void print_acc();
void print_inst_cnt();
void print_operation();
void print_cur_cell();
void init_sig_handlers();
int set_non_canonical_regime(int vmin, int echo);

#endif
