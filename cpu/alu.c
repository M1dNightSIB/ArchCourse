#include "alu.h"

int ALU(int command, int operand)
{
	switch(command)
	{
		case 0x10:
			return READ(operand);

		case 0x11:
			return WRITE(operand);

		case 0x20:
			return LOAD(operand);

		case 0x21:
			return STORE(operand);

		case 0x30:
			return ADD(operand);

		case 0x31:
			return SUB(operand);

		case 0x32:
			return DIVIDE(operand);

		case 0x33:
			return MUL(operand);

		case 0x40:
			return JUMP(operand);

		case 0x41:
			return JNEG(operand);

		case 0x42:
			return JZ(operand);

		case 0x43:
			return HALT(operand);

		case 0x51:
			return NOT(operand);

		case 0x52:
			return AND(operand);

		case 0x53:
			return OR(operand);

		case 0x54:
			return XOR(operand);

		case 0x55:
			return JNS(operand);

		case 0x56:
			return JC(operand);

		case 0x57:
			return JNC(operand);

		case 0x58:
			return JP(operand);

		case 0x59:
			return JNP(operand);

		case 0x60:
			return CHL(operand);

		case 0x61:
			return SHR(operand);

		case 0x62:
			return RCL(operand);

		case 0x63:
			return RCR(operand);

		case 0x64:
			return NEG(operand);

		case 0x65:
			return ADDC(operand);

		case 0x66:
			return SUBC(operand);

		case 0x67:
			return LOGLC(operand);

		case 0x68:
			return LOGRC(operand);

		case 0x69:
			return RCCL(operand);

		case 0x70:
			return RCCR(operand);

		case 0x71:
			return MOVA(operand);

		case 0x72:
			return MOVR(operand);

		case 0x73:
			return MOVCA(operand);	

		case 0x74:
			return MOVCR(operand);
		
		default:
			regSet(FLAG_COMMAND, 0x1);
			return -1;				
	}
}