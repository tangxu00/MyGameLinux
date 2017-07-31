/*************************************************************************
    > File Name: playagain0.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月16日 星期日 16时04分49秒
 ************************************************************************/

#include<stdio.h>
#include<termios.h>

#define QUESTION "Do you want another transaction"

int get_response(char*);
int main()
{
  int response;
  response=get_response(QUESTION);
  return response;
}

int get_response(char *question)
{
  printf("%s(y/n)?",question);
  while(1)
  {
    switch(getchar()){
      case 'Y':
      case 'y':return 0;
      case 'N':
      case'n':
      case EOF:return 1;
    }
  }
}
