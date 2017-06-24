#include <stdio.h>
#include <string.h>
#include "../simple_computer/sc.h"

FILE *fl_open(const char *filename)
{
	FILE *input = fopen(filename, "r");
	
	return input;
}

void translate(FILE *input ,const char *filename)
{
	int flag = 0, i = 0;
	for(i = 0; !feof(input); i++)
	{
		int line, cmd, operand, value;
		char command[10] = "\0";
		
		if(!fscanf(input, "%d", &line))
		{
			flag = 1;
			break;
		}

		fscanf(input, "%s", command);

		if(!strcmp(command, "READ"))
			cmd = 0x10;

		else if(!strcmp(command, "WRITE"))
			cmd = 0x11;

		else if(!strcmp(command, "LOAD"))
			cmd = 0x20;

		else if(!strcmp(command, "STORE"))
			cmd = 0x21;

		else if(!strcmp(command, "ADD"))
			cmd = 0x30;

		else if(!strcmp(command, "SUB"))
			cmd = 0x31;

		else if(!strcmp(command, "DIVIDE"))
			cmd = 0x32;

		else if(!strcmp(command, "MUL"))
			cmd = 0x33;

		else if(!strcmp(command, "JUMP"))
			cmd = 0x40;

		else if(!strcmp(command, "JNEG"))
			cmd = 0x41;

		else if(!strcmp(command, "JZ"))
			cmd = 0x42;

		else if(!strcmp(command, "HALT"))
			cmd = 0x43;

		else if(!strcmp(command, "NOT"))
			cmd = 0x51;

		else if(!strcmp(command, "AND"))
			cmd = 0x52;

		else if(!strcmp(command, "XOR"))
			cmd = 0x54;

		else if(!strcmp(command, "JNS"))
			cmd = 0x55;

		else if(!strcmp(command, "JC"))
			cmd = 0x56;

		else if(!strcmp(command, "JNC"))
			cmd = 0x57;

		else if(!strcmp(command, "JP"))
			cmd = 0x58;

		else if(!strcmp(command, "JNP"))
			cmd = 0x59;

		else if(!strcmp(command, "CHL"))
			cmd = 0x60;

		else if(!strcmp(command, "SHR"))
			cmd = 0x61;

		else if(!strcmp(command, "RCL"))
			cmd = 0x62;

		else if(!strcmp(command, "RCR"))
			cmd = 0x63;

		else if(!strcmp(command, "NEG"))
			cmd = 0x64;

		else if(!strcmp(command, "ADDC"))
			cmd = 0x65;

		else if(!strcmp(command, "SUBC"))
			cmd = 0x66;

		else if(!strcmp(command, "LOGLC"))
			cmd = 0x67;

		else if(!strcmp(command, "LOGRC"))
			cmd = 0x68;

		else if(!strcmp(command, "RCCL"))
			cmd = 0x69;

		else if(!strcmp(command, "RCCR"))
			cmd = 0x70;

		else if(!strcmp(command, "MOVA"))
			cmd = 0x71;

		else if(!strcmp(command, "MOVR"))
			cmd = 0x72;

		else if(!strcmp(command, "MOVCA"))
			cmd = 0x73;

		else if(!strcmp(command, "MOVCR"))
			cmd = 0x74;

		else if(!strcmp(command, "ADDC"))
			cmd = 0x75;

		else if(!strcmp(command, "="))
			cmd = 0x0;

		else
		{
			flag = 2;
			break;
		}

		if(!fscanf(input, "%x", &operand))
		{
			flag = 3;
			break;
		}

		if(comEnc(cmd, operand, &value))
		{
			flag = 4;
			break;
		}

		memSet(i, value);
	}

	if(!flag)
		memSave(filename);

	if (flag == 1) 
        fprintf(stderr, "line %d: expected num of line\n", ++i);

    if (flag == 2)
        fprintf(stderr, "line %d: wrong command\n", ++i);

    if (flag == 3)
        fprintf(stderr, "line %d: wrong operand\n", ++i);

    if (flag == 4)
        fprintf(stderr, "line %d: wrong command or operand\n", ++i);
}

int main(int argc, const char **argv)
{
	if(argc < 3 || argc > 4)
	{
		fprintf(stderr, "Incorrect input.sa/output.o file\n");
		return -1;
	}

	FILE *input = fl_open(argv[1]);

	if(input == NULL)
	{
		fprintf(stderr, "Cannot open file\n");
		return -1;
	}

	memInit();
	translate(input, argv[2]);

	return 0;
}