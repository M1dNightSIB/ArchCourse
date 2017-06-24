#include <stdlib.h>
#include <stdio.h>
#include "sc.h"

int	commands[38] = {0x10, 0x11, 0x20, 0x21, 0x30, 0x31, 0x32,
					0x33, 0x40, 0x41, 0x42, 0x43, 0x51, 0x52,
					0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
					0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
					0x67, 0x68, 0x69, 0x70, 0x71, 0x72, 0x73,
					0x74, 0x75, 0x76
				   };


int memInit()
{
	free(RAM);
	RAM = (int*)malloc(memory_size * sizeof(int));
	if(RAM == NULL)
		return -1;
	for(int i = 0; i < memory_size; i++)
		RAM[i] = 0x0;
	
	return 0;
}

int memSet(int address, int value)
{
	if(address < memory_size && address >= 0x0)
	{
		RAM[address] = value;
	}
	else
	{
		regSet(FLAG_OUTMEM, 0x1);
		
		return -1;
	}
	return 0x0;
}

int memGet(int address, int *value)
{
	if(address < memory_size && address >= 0 && value != NULL)
	{
		*value = RAM[address];
		return 0;
	}
	else
	{
		regSet(FLAG_OUTMEM, 1);
		return -1;
	}
}

int memSave(const char *filename)
{
	FILE *MEMORYDUMP;
	
	MEMORYDUMP = fopen(filename, "wb");
	
	if(MEMORYDUMP == NULL)
		return -1;
	else
	{
		if(fwrite(RAM, sizeof(*RAM)* memory_size, 1, MEMORYDUMP));
		{
			fclose(MEMORYDUMP);
		}
	}
	return 0;
}

int memLoad(const char *filename)
{
	FILE *MEMORYDUMP;
	
	MEMORYDUMP = fopen(filename, "rb");
	
	if(MEMORYDUMP == NULL)
		return -1;
	else
	{
		if(fread(RAM, sizeof(*RAM) * memory_size, 1, MEMORYDUMP))
		{
			for(int i = 0; i < memory_size; i++)
				RAM[i] &= 0x7FFF;
				
			fclose(MEMORYDUMP);
		}
	}
	return 0;
}

int regInit()
{
	registr_ = 0x0;
	
	return 0;
}

int regSet(int reg, int value)
{
	if((reg > 0) && (reg <= 5))
	{
		if(value == 1)
		{
			registr_ = registr_ | (1 << (reg - 1));
		}
		else if(value == 0)
			registr_ = registr_ & (~(1 << (reg - 1)));
		else
			return -1;
	}
	else
		return -1;
		
	return 0;
}

int regGet(int reg, int *value)
{
	if((reg > 0) && (reg <= 5))
	{
		*value = (registr_ >> (reg - 1)) & 1;
	}
	else
		return -1;
	
	return 0;
}

int comEnc(int command, int operand, int *value)
{
	int *comptr;
	for(int i = 0; i < 38; i++) //count of correct commands
		if(command == commands[i])
			comptr = &commands[i];
			
	if(comptr == NULL)
	{
		regSet(FLAG_COMMAND, 1);
		return -1;
	}
	if(comptr != NULL)
	{
		if(operand > 0x7F)
		{
			operand &= 0x7F;
			regSet(FLAG_OVERFLOW, 1);
		}
		if(value != NULL)
		{
			*value = (command << 7) | operand;
			regSet(FLAG_COMMAND, 0);
		}
	}
	
	return 0;
}

int comDec(int value, int *command, int *operand)
{
	int *comptr,
		attr = (value >> 14) & 1,
		comtmp,
		optmp;
		
	if(command != NULL && operand != NULL)
	{
		if(attr == 0)
		{
			comtmp = (value >> 7) & 0x7F;
			optmp = value & 0x7F;
			for(int i = 0; i < 38; i++)
				if(comtmp == commands[i])
					comptr = &commands[i];
		}
		if(comptr != NULL)
		{
			*command = comtmp;
			*operand = optmp;
		}
		else
		{
			regSet(FLAG_COMMAND, 1);
			return -1;
		}
		
		
	}
	
	return 0;
}
