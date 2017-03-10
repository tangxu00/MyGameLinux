/*************************************************************************
    > File Name: audio.c
    > Author: dooon
    > Mail: tangxu314@gmail.com 
    > Created Time: 2017年03月09日 星期四 16时31分56秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define PI M_PI


typedef unsigned int UI;
typedef unsigned long int UL;
typedef unsigned short int US;
typedef unsigned char UC;
typedef signed int SI;
typedef signed long int SL;
typedef signed short int SS;
typedef signed char SC;


#define attr(a) __attribute__((a))

#define packed attr(packed)


typedef struct{
 UL riff;
 UL len;
 UL wave;
 UL fmt;
 UL flen;
 US one;
 US chan;
 UL hz;
 UL bpsec;
 US bpsmp;
 US bitpsmp;
 UL dat;
 UL dlen;
}WAVHDR;



int savefile(const char*const s,const void*const m,const int ml){
FILE*f=fopen(s,"wb");
 int ok=0;
if(f){
ok=fwrite(m,1,ml,f)==ml;
fclose(f);
}
 return ok;
}



#define dw(a) (*(UL*)(a))




void wavhdr(void*m,UL hz,UL dlen){
WAVHDR*p=m;
p->riff=dw("RIFF");
p->len=dlen+44;
p->wave=dw("WAVE");
 p->fmt=dw("fmt");
p->flen=0x10;
p->one=1;
p->chan=1;
p->hz=hz;
p->bpsec=hz;
p->bpsmp=1;
p->bitpsmp=8;
p->dat=dw("data");
p->dlen=dlen;
}



UC sinewave(UL rate,float freq,UC amp,UL z){
 return sin(z*((PI*2/rate)*freq))*amp+128;
}



void makeaud(UC*p,const UL rate,UL z){
 float freq=500;
 UC amp=120;
while(z--){
*p++=sinewave(rate,freq,amp,z);
}
}



void makewav(const UL rate,const UL dlen){
 const UL mlen=dlen+44;
 UC*const m=malloc(mlen);
if(m){
wavhdr(m,rate,dlen);
makeaud(m+44,rate,dlen);
savefile("out.wav",m,mlen);
}
}


int main(){
 if(sizeof(WAVHDR)!=44)puts("bad struct");
makewav(22050,64000);
 return 0;
}
