/*
 * S2P.c

 *
 *  Created on: Aug 22, 2023
 *      Author: Mayar
 */




#include "S2P.h"
#include "../../Mcal/Gpio.h"

void HS2P_SENDBytesynch(S2P_t *S2P_INFO,u32 user_byte)
{
	u8 MSB ;
	s8 i=0;
	for(i=7;i>=0;i--)
	{
	MSB=(user_byte>>i)&1 ;
	MGPIO_SetPinValue(S2P_INFO->DS_PORT,S2P_INFO->DS_PIN,MSB);
	MGPIO_SetPinValue(S2P_INFO->SR_PORT,S2P_INFO->SR_PIN,VALUE_HIGH);
	MGPIO_SetPinValue(S2P_INFO->SR_PORT,S2P_INFO->SR_PIN,VALUE_LOW);

}

	MGPIO_SetPinValue(S2P_INFO->ST_PORT,S2P_INFO->ST_PIN,VALUE_HIGH);
	MGPIO_SetPinValue(S2P_INFO->ST_PORT,S2P_INFO->ST_PIN,VALUE_LOW);
}
