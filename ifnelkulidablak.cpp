
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <sys/ioctl.h>
using namespace std;
int
main (void)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int xj = 0, xk = 0, yj = 0, yk = 0;
    

    WINDOW *ablak;
    ablak = initscr ();
    noecho ();
    cbreak ();
    nodelay (ablak, true);

   while(true)
    {
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        int mx = w.ws_col*2 , my = w.ws_row*2;
        
        xj = (xj - 1) % mx;
        xk = (xk + 1) % mx;

        yj = (yj - 1) % my;
        yk = (yk + 1) % my;
        	
        clear ();
        for (int i=0; i<w.ws_col; i++) 
        {
 	mvprintw(0, i, "-"); 
	}
        for (int i=0; i<w.ws_col; i++) 
        {
 	mvprintw(w.ws_row-1, i, "-"); 
	}
        mvprintw (abs ((yj + (my - yk)) / 2), abs ((xj + (mx - xk)) / 2), "O");

        refresh ();
        usleep (150000);

    }
    return 0;
}
