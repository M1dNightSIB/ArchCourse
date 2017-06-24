#include "cmd_handler.h"


int READ(int operand)//input in cell
{
	return 0;
}

int WRITE(int operand)//output from cell
{
	return 0;
}

int LOAD(int operand)//load in accum from cell
{
	int value = 0;
	memGet(operand, &value);
	acc = value;

	return 0;
}

int STORE(int operand)
{
	memSet(operand, acc);

	return 0;
}

int ADD(int operand)
{
	int tmp;
	memGet(operand, &tmp);
	acc += tmp;

	return 0;
}

int SUB(int operand)
{
	int tmp;
	memGet(operand, &tmp);
	acc -= tmp;

	return 0;
}


int DIVIDE(int operand)
{
	int tmp;
	memGet(operand, &tmp);

	if(tmp == 0)
	{
		regSet(FLAG_DIVIDE, 0x1);
		return -1;
	}
	else
	{
		acc /= tmp;
	}

	return 0;
}

int MUL(int operand)
{
	int tmp;
	memGet(operand, &tmp);

	acc *= tmp;

	return 0;
}

int JUMP(int operand)
{
	inst_cnt = operand;

	return 0;
}

int JNEG(int operand)
{
	if(acc < 0x0)
		inst_cnt = operand;

	return 0;
}

int JZ(int operand)
{
	if(acc == 0x0)
		inst_cnt = operand;

	return 0;
}

int HALT(int operand)
{
	regSet(FLAG_INTERRUPT, 0x1);

	return 0;
}

int NOT(int operand)
{
	memSet(operand, ~acc);

	return 0;
}

int AND(int operand)
{
	int tmp;
	memGet(operand, &tmp);
	acc = acc & tmp;

	return 0;
}

int OR(int operand)
{
	int tmp;
	memGet(operand, &tmp);
	acc = acc | tmp;

	return 0;
}

int XOR(int operand)
{
	int tmp;
	memGet(operand, &tmp);
	acc = acc ^ tmp;

	return 0;
}

int JNS(int operand)
{
	if(acc > 0)
		inst_cnt = operand;

	return 0;
}

int JC(int operand)
{
	if(acc > 0x7f)
		inst_cnt = operand;

	return 0;
}

int JNC(int operand)
{
	if(acc < 0x7f)
		inst_cnt = operand;

	return 0;
}

int JP(int operand)
{
	if(acc % 2 == 0)
		inst_cnt = operand;

	return 0;
}

int JNP(int operand)
{
	if(acc % 2 != 0)
		inst_cnt = operand;

	return 0;
}

int CHL(int operand)
{
	int tmp;
	memGet(operand, &tmp);
	acc = tmp << 0x1;

	return 0;
}

int SHR(int operand)
{
	int tmp;
	memGet(operand, &tmp);
	acc = tmp >> 0x1;


	return 0;
}

int RCL(int operand)
{
	int tmp, buf = 0x40;
	memGet(operand, &tmp);
	buf = buf & tmp;
	buf = buf >> 6;
	tmp = tmp << 1;
	acc = tmp | buf;

	return 0;
}

int RCR(int operand)
{
	int tmp, buf = 0x1;
	memGet(operand, &tmp);
	buf = buf & tmp;
	tmp = tmp >> 1;
	buf = buf << 6;
	acc = buf | tmp;

	return 0;
}

int NEG(int operand)
{

	return 0;
}


int SUBC(int operand)
{
	int tmp, tmp1;
	memGet(operand, &tmp);
	memGet(acc, &tmp1);
	acc = tmp - tmp1;

	return 0;
}

int LOGLC(int operand)
{	
	return 0;
}

int LOGRC(int operand)
{
	return 0;
}

int RCCL(int operand)
{
	return 0;
}

int RCCR(int operand)
{
	return 0;
}

int MOVA(int operand)
{
	int tmp;
	memGet(operand, &tmp);
	memSet(acc, tmp);

	return 0;
}

int MOVR(int operand)
{
	int tmp;
	memGet(acc, &tmp);
	memSet(operand, tmp);
	
	return 0;
}

int MOVCA(int operand)
{
	
	return 0;
}

int MOVCR(int operand)
{
	return 0;
}

int ADDC(int operand)
{
	int tmp, tmp1;
	memGet(operand, &tmp);
	memGet(acc, &tmp1);
	acc = tmp + tmp1;
	return 0;
}