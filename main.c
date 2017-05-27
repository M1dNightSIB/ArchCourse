#include <stdio.h>
#include "simple_computer/sc.h"

extern int reg;

int main()
{
	regInit();
	int val;
	regSet(FLAG_OVERFLOW, 1);
	printf("%d", reg);
	return 0;
}
