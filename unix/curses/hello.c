/*************************************************************************
    > File Name: hello.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月17日 星期一 10时13分27秒
 ************************************************************************/

#include<stdio.h>
#include<curses.h>
#include<unistd.h>
int main(void)
{
  int i;
  initscr();
  clear();
  for(i=0;i<LINES;i++)
  {
    move(i,i+i);
    if(i%2==1)
      standout();
    addstr("Hello,world");
    if(i%2==1)
      standend();
    refresh();
    sleep(1);
    move(i,i+i);
    addstr("           ");
  }
  getch();
  endwin();
}
