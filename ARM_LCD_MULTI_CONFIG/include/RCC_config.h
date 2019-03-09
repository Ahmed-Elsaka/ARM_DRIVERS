#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

#define OFF 0
#define ON 1
/*Range: PLL , HSI , HSE*/
#define CLOCK_SRC    HSE
/*STATE: ON/OFF*/
#define HSI_STATE  OFF
#define HSE_STATE  ON 
#define PLL_STATE  OFF
/*x2 up to x16*/
#define PLL_MULTIPLIER  MUL_FIVE    
/*HALF_HSI , HSE , HALF_HSE*/
#define PLL_SRC       HSI
/*Range 1,2,3,.. -> 512*/
#define AHB_PRESCALAR     1
/*1,2,4,8,16*/
#define APB1_PRESCALAR    1
/*1,2,4,8,16*/
#define APB2_PRESCALAR    1


#endif
