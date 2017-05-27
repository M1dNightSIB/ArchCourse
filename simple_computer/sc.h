#ifndef SC_H
#define SC_H

#define memory_size 100
#define FLAG_OVERFLOW 0
#define FLAG_DIVISION 1
#define FLAG_OUTMEM 2
#define FLAG_INTERRUPT 3
#define FLAG_COMMAND 4
#define BIT_ON(A, B) (A = ((A) | (1 << (B))))
#define BIT_OFF(A, B) (A = ((A) & ~(1 << (B))))
#define BITCHECK(A,B) (((A) >> B) & 1)

int memInit();
int memSet(int address, int value);
int memGet(int address, int *value);
int memSave(char *filename);
int memLoad(char *filename);
int regInit(void);
int regSet(int reg, int value);
int regGet(int reg, int *value);
int comEnc(int command, int operand, int *value);
int comDec(int value, int *command, int *operand);


#endif
