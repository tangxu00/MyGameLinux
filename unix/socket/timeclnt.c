/*************************************************************************
    > File Name: timeclnt.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年08月15日 星期二 14时34分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<unistd.h>
#include<strings.h>
#include<arpa/inet.h>

#define oops(msg)  {perror(msg);exit(1);}
int main(int ac,char *av[])
{
  struct sockaddr_in servadd;
  struct hostent *hp;
  int sock_id,sock_fd;
  char message[BUFSIZ];
  int messlen;
  sock_id = socket(AF_INET,SOCK_STREAM,0);
  if(sock_id == -1)
    oops("socket");
  bzero(&servadd,sizeof(servadd));
  //hp = gethostbyname(av[1]);
  //if(hp == NULL)
  //  oops(av[1]);
  //bcopy(hp->h_addr,(struct sockaddr *)&servadd.sin_addr,hp->h_length);
  servadd.sin_addr.s_addr = inet_addr(av[1]);
  servadd.sin_port = htons(atoi(av[2]));
  servadd.sin_family = AF_INET;
  if(connect(sock_id,(struct sockaddr *)&servadd,sizeof(servadd)) !=0)
    oops("connect");
  messlen = read(sock_id,message,BUFSIZ);
  if(messlen == -1)
    oops("read");
  if(write(1,message,messlen) != messlen)
    oops("write");
  close(sock_id);
  return 0;
}
