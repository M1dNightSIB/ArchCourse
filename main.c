#include <stdio.h>
#include "simple_computer/sc.h"

extern int reg;

int main()
{
	regInit();
	int val;
	regSet(FLAG_INTERRUPT, 1);
	regGet(FLAG_INTERRUPT, &val);
	printf("%d", val);
	return 0;
}
