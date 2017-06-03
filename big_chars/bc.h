#ifndef BC_H
#define BC_H

#include "../my_term/mt.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BOXCHAR_REC 'a'
#define BOXCHAR_BR 'j'
#define BOXCHAR_BL 'm'
#define BOXCHAR_TR 'k'
#define BOXCHAR_TL 'l'
#define BOXCHAR_VERT 'x'
#define BOXCHAR_HOR 'q'

void printA(char str);
int box(int x1, int y1, int x2, int y2);


#endif