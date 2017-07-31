/*************************************************************************
    > File Name: varlib.h
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年07月29日 星期六 17时28分31秒
 ************************************************************************/

int VLstore(char *,char *);
char *VLlookup(char *);
void VLlist();
int VLexport(char *);
int VLenviron2table(char *env[]);
char ** VLtable2environ();
