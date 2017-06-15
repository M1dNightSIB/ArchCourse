#include "rk.h"



int read_key(enum keys *key)
{

	struct termios def_options; //default options from termios
	char buf[16];
	int readNum;
	
	if(tcgetattr(STDIN_FILENO, &def_options) != 0) //tcgetattr(fd, termios *)
	  return -1;
	
	readNum = read(STDIN_FILENO, buf, 15); //IN stream
	
	if(readNum < 0)
	  return -1;
	
	buf[readNum] = '\0';
	
	if(strcmp(buf, "\E[15~") == 0)
		*key = f5_key;
	else if(strcmp(buf, "\E[17~") == 0)
		*key = f6_key;
	else if(strcmp(buf, "\E[A") == 0)
		*key = up_key;
	else if(strcmp(buf, "\E[B") == 0)
		*key = down_key;
	else if(strcmp(buf, "\E[C") == 0)
	  *key = right_key;
	else if(strcmp(buf, "\E[D") == 0)
	  *key = left_key;
	else if(strcmp(buf, "\n") == 0)
		*key = enter_key;
	else if(strcmp(buf, "\E") == 0)
		*key = esc_key;
	else if(strcmp(buf, "l") == 0)
		*key = l_key;
	else if(strcmp(buf, "r") == 0)
		*key = r_key;
	else if(strcmp(buf, "q") == 0)
		*key = q_key;
	else if(strcmp(buf, "x") == 0)
	 	*key = x_key;
	else if(strcmp(buf, "s") == 0)
		*key = s_key;
	else if(strcmp(buf, "i") == 0)
		*key = i_key;
	else if(strcmp(buf, "t") == 0)
		*key = t_key;
	else if(strcmp(buf, "d") == 0)
		*key = d_key;
	
	if(tcsetattr(STDIN_FILENO, TCSANOW, &def_options)  != 0) //tcsetattr(fd, optional_actions, termios *)
	  return -1;
	
	return 0;
}

int term_save(void)
{
	struct termios options;
	FILE *save;
	
	if(tcgetattr(STDIN_FILENO, &options) != 0)
		return -1;
	
	if((save = fopen("termsettings.con","wb" )) == NULL)
		return -1;
	  
	fwrite(&options, sizeof(options), 1, save);
	fclose(save);
	return 0;
}

int term_restore(void)
{
	struct termios options;
	FILE *data;
	
	if((data = fopen("termsettings.con", "rb")) == NULL)
		return -1;
	else
	{
		if(fread(&options, sizeof(options), 1, data) > 0)
		{
			if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &options) !=  0)
			{
				fclose(data);
				return -1;
			}
			else
			{
				fclose(data);
				return -1;
			}
			
		}
		fclose(data);
	}
	
	return 0;
}

int set_term_regime(int regime, int vtime, int vmin, int echo, int sigint)
{
	struct termios options;
	
	
	if(tcgetattr(STDIN_FILENO, &options) != 0)
		return -1;
	
	if(regime == 1)
		options.c_lflag |= ICANON;
	else if(regime == 0)
		options.c_lflag &= ~ICANON;
	else
		return -1;
	
	if(regime == 0)
	{
		options.c_cc[VTIME] = vtime;
		options.c_cc[VMIN] = vmin;
	
		if(echo == 1)
			options.c_lflag |= ECHO;
		else if(echo == 0)
			options.c_lflag &= ~ECHO;
		else
			return -1;
	
		if(sigint == 1)
			options.c_lflag |= ISIG;
		else if(sigint == 0)
			options.c_lflag &= ~ISIG;
		else
			return -1;
	}
	
	if(tcsetattr(STDIN_FILENO, TCSANOW, &options) != 0)
		return -1;
	
	return 0;
}
