#include "xyzcfg.h"
#include "dsk6713.h"
#include "dsk6713_aic23.h"

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
0x0001 \
};
void main
{
DSK6713_AIC23_CodecHandle hCodec;

int l_input, r_input;
int l_output, r_output;
DSK6713_init();
hCodec=DSK6713_AIC23_openCodec(0,&config);
DSK6713_AIC23_setFreq(hCodec,3);
while(1)
{
while(!DSK6713_AIC23_read(hCodec,&l_input));
while(!DSK6713_AIC23_read(hCodec,&r_output);
while(!DSK6713_AIC23_write(hCodec,&l_input));
while(!DSK6713_AIC23_write(hCodec,&r_output);
}

DSK6713_AIC23_closeCodec(hCodec);
}
