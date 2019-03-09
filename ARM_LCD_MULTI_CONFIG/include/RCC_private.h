#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

typedef struct 
{
	Register_32Bit CR;
	Register_32Bit CFGR;
	Register_32Bit CIR;
	Register_32Bit APB2RSTR;
	Register_32Bit APB1STR;
	Register_32Bit AHBENR;
	Register_32Bit APB2ENR;
	Register_32Bit APB1ENR;
	Register_32Bit BDCR;
	Register_32Bit CSR;	

}RCC_Register;

#define RCC ((RCC_Register*)0x40021000)

#define BIT0
#define BIT1
#define BIT2
#define BIT3

#define MUL_TWO      0b0000
#define MUL_THREE    0b0001
#define MUL_FOUR     0b0010
#define MUL_FIVE     0b0011
#define MUL_SIX      0b0100
#define MUL_SEVEN    0b0101
#define MUL_EIGHT    0b0110
#define MUL_NINE     0b0111
#define MUL_TEN      0b1000
#define MUL_ELEVEN   0b1001
#define MUL_TWELVE   0b1010
#define MUL_THRTEEN  0b1011
#define MUL_FOURTEEN 0b1100
#define MUL_FIFTEEN  0b1101
#define MUL_SIXTEEN  0b1110

#define RCC_CFGR_MUL_SHIFT_VAL 17

#endif
