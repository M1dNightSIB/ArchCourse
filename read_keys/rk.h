#ifndef RK_H
#define RK_H

#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*termios struct
 * tcflag_t  c_iflag  input mode
 * tcflag_t  c_oflag  output mode
 * tcflag_t  c_cflag  control mode
 * tcflag_t  c_lflag  local mode
 * cc_t c__cc[NCCS];  control sym
 *ECHO echo input characters
 * ICANON enable canonical mode
 * ISIG when any of the character INTR, QUIT, SUSP or DSUSP are received
 * VMIN minimum number of characters for noncanonical read
 * VTIME timeout in deciseconds for noncanonical read
 */

enum keys
{
	other_key = 0,
	up_key,
	down_key,
	right_key,
	left_key,
	enter_key,
	esc_key,
	f5_key,
	f6_key,
	l_key,
	r_key,
	i_key,
	t_key,
	s_key,
	x_key,
	d_key,
	q_key
};

int read_key(enum keys *key);
int term_save(void);
int term_restore(void);
int set_term_regime(int regime, int vtime, int vmin, int echo, int sigint);

#endif