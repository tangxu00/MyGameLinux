/*************************************************************************
    > File Name: smsh.h
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月26日 星期三 10时15分21秒
 ************************************************************************/

char *next_cmd(const char *,FILE *);
char **splitline(char *);
void freelist(char **);
void *emalloc(size_t);
void *erealloc(void *,size_t);
int execute(char **);
void fatal(char *,char *,int);
