/*************************************************************************
    > File Name: socklib.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年08月17日 星期四 20时55分49秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<time.h>
#include<string.h>
#include<arpa/inet.h>

#define BACKLOG 1

int make_server_socket_q(int,int);
int make_server_socket(int portnum)
{
  return make_server_socket_q(portnum,BACKLOG);
}
int make_server_socket_q(int portnum,int backlog)
{
  struct sockaddr_in saddr;
  int sock_id;
  sock_id = socket(PF_INET,SOCK_STREAM,0);
  if(sock_id == -1)
    return -1;
  bzero((void *)&saddr,sizeof(saddr));
  saddr.sin_addr.s_addr = inet_addr("192.168.211.129");
  saddr.sin_port = htons(portnum);
  saddr.sin_family = AF_INET;
  if(bind(sock_id,(struct sockaddr *)&saddr,sizeof(saddr)) != 0)
    return -1;
  if(listen(sock_id,backlog) != 0)
    return -1;
  return sock_id;
}
int connect_to_server(char *ip,int portnum)
{
  int sock;
  struct sockaddr_in servadd;
  sock = socket(AF_INET,SOCK_STREAM,0);
  if(sock == -1)
    return -1;
  bzero(&servadd,sizeof(servadd));
  servadd.sin_addr.s_addr = inet_addr(ip);
  servadd.sin_port = htons(portnum);
  servadd.sin_family = AF_INET;
  if(connect(sock,(struct sockaddr *)&servadd,sizeof(servadd)) != 0)
    return -1;
  return sock;
}
