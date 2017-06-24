#ifndef CMP_H
#define CMP_H

#include "simple_computer/sc.h"
#include "main_frame/mf.h"
#include "read_keys/rk.h"
#include "cpu/alu.h"
#include <signal.h>
#include <signal.h>
#include <sys/time.h>

extern int acc,
	inst_cnt,
	operation,
	cur_cell,
	hand_exit;

struct itimerval timer;
extern enum keys key;

void key_handler(enum keys key);
void cell_step(int sig); //for signal
void return_hand_manage(int sig);//for signal
void print_ram(int *cell); //write cells of memory
void print_acc();
void print_inst_cnt();
void print_operation();
void print_flags();
void print_cur_cell();
void init_sig_handlers();
void transform_bchar(char *sym, int *big);
int set_non_canonical_regime(int vmin, int echo);

extern const char flags[5]; //Overflow, Zero Div, Out of memoory, Interrupt, Incorrected commnand
extern char bigchar_0[64];
 
extern char bigchar_1[64];
 
extern char bigchar_2[64];
 
extern char bigchar_3[64];
 
extern char bigchar_4[64];
 
extern char bigchar_5[64];
 
extern char bigchar_6[64];
 
extern char bigchar_7[64];
 
extern char bigchar_8[64];
 
extern char bigchar_9[64];
 
extern char bigchar_A[64];
 
extern char bigchar_B[64];
 
extern char bigchar_C[64];
 
extern char bigchar_D[64];
 
extern char bigchar_E[64];
 
extern char bigchar_F[64];
 
extern char bigchar_PLUS[64];

extern char *ind[17];
#endif
