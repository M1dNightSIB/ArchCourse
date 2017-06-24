#ifndef SC_H
#define SC_H

#define memory_size 100
#define FLAG_OVERFLOW 1
#define FLAG_DIVISION 2
#define FLAG_OUTMEM 3
#define FLAG_INTERRUPT 4
#define FLAG_COMMAND 5

int *RAM,
	registr_;

int memInit();
int memSet(int address, int value);
int memGet(int address, int *value);
int memSave(const char *filename);
int memLoad(const char *filename);
int regInit(void);
int regSet(int reg, int value);
int regGet(int reg, int *value);
int comEnc(int command, int operand, int *value);
int comDec(int value, int *command, int *operand);


#endif
