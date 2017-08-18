/*************************************************************************
    > File Name: socklib.h
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年08月18日 星期五 16时13分39秒
 ************************************************************************/
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

int make_server_socket(int );
int connect_to_server(char *,int);

