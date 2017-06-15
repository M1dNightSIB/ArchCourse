#ifndef MAIN_H
#define MAIN_H

int acc = 0x0,
	inst_cnt = 0x0,
	operation = 0x0;

void print_ram(int cell); //write cells of memory
void print_acc();
void print_inst_cnt();
void print_operation();

#endif
