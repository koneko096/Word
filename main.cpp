#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <time.h>
#include <queue>

using namespace std;

static struct termios old_termios, new_termios;

/* restore new terminal i/o settings */
void resetTermios(){
	tcsetattr(0,TCSANOW,&old_termios);
}

/* initialize new terminal i/o settings */
void initTermios(){
	tcgetattr(0,&old_termios); // store old terminal
	new_termios = old_termios; // assign to new setting
	new_termios.c_lflag &= ~ICANON; // disable buffer i/o
	new_termios.c_lflag &= ~ECHO; // disable echo mode
	tcsetattr(0,TCSANOW,&new_termios); // use new terminal setting
}

/* detect keyboard press */
int kbhit(){
	struct timeval tv = {0L,0L};
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0,&fds);
	return select(1,&fds,NULL,NULL,&tv);
}

/* read 1 character */
char getch(){
	char ch;
	ch = getchar();
	return ch;
}

void output(queue<char> q) {
	while(!q.empty()) {
		printf("Pressed %c\n", q.front());
		q.pop();
	}
}

/* skeleton program for play */
void Play(double seconds){
	initTermios(); // initailize new terminal setting to make kbhit() and getch() work
	char cc;
	queue<char> q;
	const double TIME_LIMIT = seconds * CLOCKS_PER_SEC;
	clock_t startTime = clock();
	int prev = seconds;
	while ((clock() - startTime) <= TIME_LIMIT){
		while(1) {
			double time = (clock() - startTime) / CLOCKS_PER_SEC;
			int now = (int) time;
			if (kbhit()){
				cc = getch();
				q.push(cc);
				resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
				system("clear");
				printf("Waktu sekarang %d\n", (int)(seconds) - now); // process character
				output(q);
				initTermios(); // use new terminal setting again to make kbhit() and getch() work
			}
			if(time != prev) {
				resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
				system("clear");
				printf("Waktu sekarang %d\n", (int)(seconds) - now); // process character
				output(q);
				initTermios(); // use new terminal setting again to make kbhit() and getch() work
				prev = time;
			}
		}
	}
	printf("\nTime Up\n");
	resetTermios(); // restore default terminal setting
}

int main(){
	system("clear");
	Play(120); // play with time limit 120 seconds (2 minutes)
	return 0;
}