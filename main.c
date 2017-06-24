#include <stdio.h>
#include "cmp.h"

int main()
{
	cursor(HIDE_CURSOR);// start initialization
	init_frame();
	memInit();
	regInit();
	init_sig_handlers();
	set_non_canonical_regime(0x1, 0x0);

	while(hand_exit)
	{
		print_ram(&cur_cell);
		print_acc();
		print_inst_cnt();
		print_operation();
		print_cur_cell();
		print_flags();
		key_handler(key);
	}

	clear();	//clearing 
	cursor(SHOW_CURSOR);
	set_non_canonical_regime(0x0, 0x1);

	return 0;
}
