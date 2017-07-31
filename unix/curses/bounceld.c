/*************************************************************************
    > File Name: bounceld.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月21日 星期五 09时35分12秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<curses.h>
#include<signal.h>
#include<sys/time.h>

#define MESSAGE "hello"
#define BLANK "     "
int row;
int col;
int dir;
int set_ticker(int);
int main()
{
  int delay;
  int ndelay;
  int c;
  void move_msg(int);
  initscr();
  crmode();
  noecho();
  clear();
  row = 10;
  col = 0;
  dir = 1;
  delay = 200;
  move(row,col);
  addstr(MESSAGE);
  signal(SIGALRM,move_msg);
  set_ticker(delay);
  while(1)
  {
    ndelay = 0;
    c=getch();
    if(c=='Q') break;
    if(c=='v') dir=-dir;
    if(c=='f'&&delay>2) ndelay=delay/2;
    if(c=='s') ndelay=delay*2;
    if(ndelay>0)
      set_ticker(delay=ndelay);
  }
  endwin();
  return 0;

}
int set_ticker(int n_msecs)
{
  struct itimerval new_timste;
  long n_sec,n_usecs;
  n_sec = n_msecs/1000;
  n_usecs = (n_msecs%1000)*1000L;
  new_timste.it_interval.tv_sec = n_sec;
  new_timste.it_interval.tv_usec = n_usecs;
  new_timste.it_value.tv_sec = n_sec;
  new_timste.it_value.tv_usec = n_usecs;
  return setitimer(ITIMER_REAL,&new_timste,NULL);
}
void move_msg(int signum)
{
  signal(SIGALRM,move_msg);
  move(row,col);
  addstr(BLANK);
  col+=dir;
  //move(row,col);
  //addstr(MESSAGE);
  mvaddch(row,col,'o');
  refresh();
  if(dir==-1&&col<=0)
    dir = 1;
  else if(dir==1&&(col+strlen(MESSAGE)>=COLS))
    dir=-1;
}
