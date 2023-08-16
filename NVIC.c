/*
 * NVIC.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Mayar
 */



#include "NVIC.h"

/////////////////////////////////////Registers
#define AIRCR_BASE_ADDRESS    0xE000ED00
#define NVIC_BASEADDRESS 	  0xE000E100

typedef struct{
	u32 ISER[8];
	u32 Reserved_0[24];
	u32 ICER[8];
	u32 Reserved_1[24];
	u32 ISPR[8];
	u32 Reserved_2[24];
	u32 ICPR[8];
	u32 Reserved_3[24];
	u32 IAPR[8];
	u32 Reserved_4[56];
	u8 IPR[240];
	u32 Reserved_5[580];
	u32 STIR;
}NVIC_t;


static volatile NVIC_t * const NVIC_ptr = (volatile NVIC_t * const) NVIC_BASEADDRESS;
static volatile u32 * const AIRCR_ptr   = (volatile NVIC_t * const) AIRCR_BASE_ADDRESS;

//////////////////////////////////Func


void MNVIC_PriorityInit(void)
{
	*AIRCR_ptr = SW_Priority;
}

ret_t MNVIC_EnableINT_ID(u32 NVIC_ID)
{
	if(NVIC_ID>=0 && NVIC_ID<=84)
	{
	NVIC_ptr->ISER[NVIC_ID/32] = (1<<(NVIC_ID%32));
	}
	else
	{
		return ret_Error;
	}
	return ret_OK;
}
ret_t MNVIC_DisableINT_ID(u32 NVIC_ID)
{
	if(NVIC_ID>=0 && NVIC_ID<=84)
	{
	NVIC_ptr->ICER[NVIC_ID/32] = (1<<(NVIC_ID%32));
	}
	else
	{
		return ret_Error;
	}
	return ret_OK;
}

ret_t MNVIC_SetPending(u32 NVIC_ID)
{
	if(NVIC_ID>=0 && NVIC_ID<=84)
	{
	NVIC_ptr->ISPR[NVIC_ID/32] = (1<<(NVIC_ID%32));
	}
	else
	{
		return ret_Error;
	}
	return ret_OK;
}
ret_t MNVIC_ClrPending(u32 NVIC_ID)
{
	if(NVIC_ID>=0 && NVIC_ID<=84)
	{
	NVIC_ptr->ICPR[NVIC_ID/32] = (1<<(NVIC_ID%32));
	}
	else
	{
		return ret_Error;
	}
	return ret_OK;
}

ret_tMNVIC_SetINT_Periority(u32 NVIC_ID,u32 Groub,u32 Sub_Groub)
{
#if SW_Priority==Groub16_SubGroub0
if(Groub>=0 && Groub<=15 && Sub_Groub==0)
{
NVIC_ptr->IPR[NVIC_ID] = (Groub<<4);
return ret_OK;
}
else
{
	return ret_Error;
}

#elif SW_Priority==Groub8_SubGroub2

NVIC_ptr->IPR[NVIC_ID] = ((Groub<<5) | (Sub_Groub<<4));


#elif SW_Priority==Groub4_SubGroub4

if(Groub>=0 && Groub<=4 && Sub_Groub>=0 && Sub_Groub<=4)
{
NVIC_ptr->IPR[NVIC_ID] = ((Groub<<6) | (Sub_Groub<<4));
return ret_OK;
}
else
{
	return ret_Error;
}
#elif(SW_Priority==Groub2_SubGroub8)

NVIC_ptr->IPR[NVIC_ID] = ((Groub<<7) | (Sub_Groub<<4));

#elif (SW_Priority==Groub0_SubGroub16)

NVIC_ptr->IPR[NVIC_ID] = (Sub_Groub<<4);

#endif


}


