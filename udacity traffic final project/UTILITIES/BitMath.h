#ifndef BitMath_h_
#define BitMath_h_

#define SetBit(reg,bit)         reg|=(1<<bit)

#define ClearBit(reg,bit)       reg&=~(1<<bit)

#define ReadBit(reg,bit)        ((reg>>bit)&1)

#define ToggleBit(reg,bit)      reg^=(1<<bit)

#endif