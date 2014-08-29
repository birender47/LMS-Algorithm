#include "xyzcfg.h"
#include "dsk6713.h"
#include "dsk6713_aic23.h"
#define beta 1E-12
#define N 30

short int adaptive_filter(short int, short int);
float delay[N];
float w[N];

DSK6713_AIC23_Config config= {\
0x0017, \
0x0017, \
0x00d8, \
0x00d8, \
0x0011, \
0x0000, \
0x0000, \
0x0043, \
0x0081, \
0x0001, \
};
void main
{
DSK6713_AIC23_CodecHandle hCodec;

int l_input, r_input;
int l_output, r_output;
DSK6713_init();

hCodec= DSK6713_AIC23_openCodec(0, &config);
DSK6713_AIC23_setFreq(hCodec,1);
while(1)
{
while(!DSK6713_AIC23_read(hCodec,&l_input));
while(!DSK6713_AIC23_read(hCodec,&r_input);
l_output=(short int)adaptive_filter(l_input,r_input);
r_output=l_output;

while(DSK6713_AIC23_write(hCodec, r_output));
}


DSK6713_AIC23_closeCodec(hCodec);
}

short int adaptive_filter(short l_input1, short r_input1)
{
short i, output, T;
float yn=0, E=0, dplusn=0, desired=0, noise=0;
for(T=0;T<30;T++)
{
w[T]=0;
delay[T]=0;
}
desired = l_input1;
noise= r_input1;
dplusn= desired+noise;
delay[0]= noise;
for(i=0;i<N;i++)
yn+=(w[i]*delay[i]);
E=(desired+noise)-yn;
for(i=N-1;i>=0;i--)
{
w[i]=w[i]+beta*E*delay[i];
delay[i]=delay[i-1];
}
output=((short)E);
return(output);
}
