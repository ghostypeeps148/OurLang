#include <termios.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	struct termios orig, new;
	tcgetattr(STDIN_FILENO, &orig);
	new = orig;
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_lflag &= (NOFLSH);
	new.c_iflag &= ~(IGNBRK | IGNCR | INPCK | PARMRK | IUTF8);
	new.c_iflag &= (ISTRIP | INLCR | IGNPAR | BRKINT | IUCLC | IXANY);
	new.c_cc[VTIME] = 99;
	new.c_cc[VMIN] = 99;
	new.c_cc[VINTR] = '\0';
	new.c_cc[VKILL] = '\0';
	new.c_cc[VQUIT] = '\0';
	new.c_cc[VSTOP] = '\0';
	new.c_cc[CREAD] = '\0';
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
}
