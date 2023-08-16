/*
 * Gpio.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Mayar
 */

#include "Gpio.h"



#define  GPIOA_BASEADDRESS	 0x40020000
#define  GPIOB_BASEADDRESS   0x40020400
#define  GPIOC_BASEADDRESS   0x40020800

typedef struct{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDER;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIO_t;

#define  	   	GPIOA      ((volatile GPIO_t*)GPIOA_BASEADDRESS)
#define  	   	GPIOB      ((volatile GPIO_t*)GPIOB_BASEADDRESS)
#define  	   	GPIOC      ((volatile GPIO_t*)GPIOC_BASEADDRESS)

ret_t MGPIO_SetPinMode(u32 GPIO_PORT,u32 PIN,u32 Mode){

	switch(GPIO_PORT)
			{
			case GPIO_PORTA: GPIOA->MODER &= ~(3<<(PIN*2)); GPIOA->MODER |= (Mode<<(PIN*2)); break;
			case GPIO_PORTB: GPIOB->MODER &= ~(3<<(PIN*2)); GPIOB->MODER |= (Mode<<(PIN*2)); break;
			case GPIO_PORTC: GPIOC->MODER &= ~(3<<(PIN*2)); GPIOC->MODER |= (Mode<<(PIN*2)); break;
			default : return ret_Error;
			}

		return ret_OK;
}

ret_t MGPIO_SetPinType(u32 GPIO_PORT,u32 PIN,u32 Type){

	if((PIN<=15)&&(Type<=1))
		{
			switch(GPIO_PORT)
			{
			case GPIO_PORTA: GPIOA->OTYPER &= ~(1<<(PIN)); GPIOA->OTYPER |= (Type<<(PIN)); break;
			case GPIO_PORTB: GPIOB->OTYPER &= ~(1<<(PIN)); GPIOB->OTYPER |= (Type<<(PIN)); break;
			case GPIO_PORTC: GPIOC->OTYPER &= ~(1<<(PIN)); GPIOC->OTYPER |= (Type<<(PIN)); break;
			}

		}
		else
		{
			return ret_Error;
		}
	return ret_OK;
}

ret_t MGPIO_SetPinValue(u32 GPIO_PORT,u32 PIN,u32 VALUE){

	if((PIN<=15)&&(VALUE<=1))
			{
				switch(GPIO_PORT)
				{
				case GPIO_PORTA: GPIOA->ODR &= ~(1<<(PIN)); GPIOA->ODR |= (VALUE<<(PIN)); break;
				case GPIO_PORTB: GPIOB->ODR &= ~(1<<(PIN)); GPIOB->ODR |= (VALUE<<(PIN)); break;
				case GPIO_PORTC: GPIOC->ODR &= ~(1<<(PIN)); GPIOC->ODR |= (VALUE<<(PIN)); break;
				}

			}
		else
		{
			return ret_Error;
		}
	return ret_OK;

}

ret_t MGPIO_SetPinSpeed(u32 GPIO_PORT,u32 PIN,u32 Speed){

	if((PIN<=15)&&(Speed<=3))
				{
					switch(GPIO_PORT)
					{
					case GPIO_PORTA: GPIOA->OSPEEDER &= ~(3<<(PIN*2)); GPIOA->OSPEEDER |= (Speed<<(PIN*2)); break;
					case GPIO_PORTB: GPIOB->OSPEEDER &= ~(3<<(PIN*2)); GPIOB->OSPEEDER |= (Speed<<(PIN*2)); break;
					case GPIO_PORTC: GPIOC->OSPEEDER &= ~(3<<(PIN*2)); GPIOC->OSPEEDER |= (Speed<<(PIN*2)); break;
					}

				}
			else
			{
				return ret_Error;
			}
		return ret_OK;
}

ret_t MGPIO_SetPinPUPDR(u32 GPIO_PORT,u32 PIN,u32 PUPDR){

	if((PIN<=15)&&(PUPDR<=2))
					{
						switch(GPIO_PORT)
						{
						case GPIO_PORTA: GPIOA->PUPDR &= ~(3<<(PIN*2)); GPIOA->PUPDR |= (PUPDR<<(PIN*2)); break;
						case GPIO_PORTB: GPIOB->PUPDR &= ~(3<<(PIN*2)); GPIOB->PUPDR |= (PUPDR<<(PIN*2)); break;
						case GPIO_PORTC: GPIOC->PUPDR &= ~(3<<(PIN*2)); GPIOC->PUPDR |= (PUPDR<<(PIN*2)); break;
						}

					}
				else
				{
					return ret_Error;
				}
			return ret_OK;
}

/*ret_t MGPIO_SetPinAtomicValue(u32 GPIO_PORT,u32 PIN,u32 VALUE){

}*/
