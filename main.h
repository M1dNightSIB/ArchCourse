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
void print_flags();
void print_cur_cell();
void init_sig_handlers();
void transform_bchar(char *sym, int *big);
int set_non_canonical_regime(int vmin, int echo);

char flags[5] = {'O', 'D', 'M', 'I', 'C'}; //Overflow, Zero Div, Out of memoory, Interrupt, Incorrected commnand
char bigchar_0[64] = {
   0, 0, 1, 1, 1, 1, 0, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   1, 0, 0, 0, 0, 0, 0, 1,
   1, 0, 0, 0, 0, 0, 0, 1,
   1, 0, 0, 0, 0, 0, 0, 1,
   1, 0, 0, 0, 0, 0, 0, 1,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 0, 1, 1, 1, 1, 0, 0
 };
 
 char bigchar_1[64] = {
   0, 0, 0, 0, 0, 1, 1, 0,
   0, 0, 0, 0, 1, 0, 1, 0,
   0, 0, 0, 1, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0
 };
 
 char bigchar_2[64] = {
   0, 0, 0, 1, 1, 1, 0, 0,
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 1, 0, 0,
   0, 0, 0, 0, 1, 0, 0, 0,
   0, 0, 0, 1, 0, 0, 0, 0,
   0, 0, 1, 0, 0, 0, 0, 0,
   0, 1, 1, 1, 1, 1, 1, 0
 };
 
 char bigchar_3[64] = {
   0, 0, 1, 1, 1, 1, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 1, 1, 1, 0, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 1, 1, 1, 1, 1, 0
 };
 
 char bigchar_4[64] = {
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 0, 1, 1, 1, 1, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0
 };
 
 char bigchar_5[64] = {
   0, 0, 1, 1, 1, 1, 1, 0,
   0, 0, 1, 0, 0, 0, 0, 0,
   0, 0, 1, 0, 0, 0, 0, 0,
   0, 0, 1, 1, 1, 1, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 1, 1, 1, 1, 1, 0
 };
 
 char bigchar_6[64] = {
   0, 0, 1, 1, 1, 1, 1, 0,
   0, 0, 1, 0, 0, 0, 0, 0,
   0, 0, 1, 0, 0, 0, 0, 0,
   0, 0, 1, 1, 1, 1, 1, 0,
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 0, 1, 1, 1, 1, 1, 0
 };
 
 char bigchar_7[64] = {
   0, 0, 1, 1, 1, 1, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 1, 0, 0,
   0, 0, 0, 0, 0, 1, 0, 0,
   0, 0, 0, 0, 1, 0, 0, 0,
   0, 0, 0, 0, 1, 0, 0, 0,
   0, 0, 0, 1, 0, 0, 0, 0,
   0, 0, 0, 1, 0, 0, 0, 0
 };
 
 char bigchar_8[64] = {
   0, 0, 1, 1, 1, 1, 1, 0,
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 0, 1, 1, 1, 1, 1, 0,
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 0, 1, 1, 1, 1, 1, 0
 };
 
 char bigchar_9[64] = {
   0, 0, 1, 1, 1, 1, 1, 0,
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 0, 1, 0, 0, 0, 1, 0,
   0, 0, 1, 1, 1, 1, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 0, 0, 0, 0, 1, 0,
   0, 0, 1, 1, 1, 1, 1, 0
 };
 
 char bigchar_A[64] = {
   0, 0, 1, 1, 1, 1, 0, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 1, 1, 1, 1, 1, 1, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 1, 0, 0, 0, 0, 1, 0
 };
 
 char bigchar_B[64] = {
   0, 1, 1, 1, 1, 0, 0, 0,
   0, 1, 0, 0, 1, 0, 0, 0,
   0, 1, 0, 0, 1, 0, 0, 0,
   0, 1, 1, 1, 1, 1, 0, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 1, 1, 1, 1, 1, 0, 0
 };
 
 char bigchar_C[64] = {
   0, 0, 1, 1, 1, 1, 1, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 0, 1, 1, 1, 1, 1, 0
 };
 
 char bigchar_D[64] = {
   0, 1, 1, 1, 1, 0, 0, 0,
   0, 1, 0, 0, 0, 1, 0, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 1, 0, 0, 0, 0, 1, 0,
   0, 1, 0, 0, 0, 1, 0, 0,
   0, 1, 1, 1, 1, 0, 0, 0
 };
 
 char bigchar_E[64] = {
   0, 1, 1, 1, 1, 1, 1, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 1, 1, 1, 1, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 1, 1, 1, 1, 1, 0
 };
 
 char bigchar_F[64] = {
   0, 1, 1, 1, 1, 1, 1, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 1, 1, 1, 0, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0,
   0, 1, 0, 0, 0, 0, 0, 0
 };
 
 char bigchar_PLUS[64] = {
	 0, 0, 0, 1, 1, 0, 0, 0,
	 0, 0, 0, 1, 1, 0, 0, 0,
	 0, 0, 0, 1, 1, 0, 0, 0,
	 1, 1, 1, 1, 1, 1, 1, 1,
	 1, 1, 1, 1, 1, 1, 1, 1,
	 0, 0, 0, 1, 1, 0, 0, 0,
	 0, 0, 0, 1, 1, 0, 0, 0,
	 0, 0, 0, 1, 1, 0, 0, 0
 };

char *ind[17] = {bigchar_0, bigchar_1, bigchar_2, bigchar_3, bigchar_4, bigchar_5, bigchar_6, bigchar_7, bigchar_8, bigchar_9, bigchar_A, bigchar_B, bigchar_C, bigchar_D, bigchar_E, bigchar_F, bigchar_PLUS};

#endif