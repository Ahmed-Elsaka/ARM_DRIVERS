#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


#define RCC_u8_GPIOA        0
#define RCC_u8_GPIOB        1 
#define RCC_u8_GPIOC		2
#define RCC_u8_GPIOD 		3

#define HSE 0
#define HSI 1
#define PLL 2

#define PLL_HALF_HSI 0
#define PLL_HSE      1
#define PLL_HALF_HSE 2


/*Continue to all prephirals ... Timers, and so on ...*/

void RCC_voidInitialze(void);

u8 RCC_u8EnablePrephiral(u8 Copy_u8Prephiral);


#endif
