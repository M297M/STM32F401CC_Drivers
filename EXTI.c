/*
 * EXTI.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Mayar
 */

#include "EXTI.h"

static void (*APP_Func[16])(void);


///////////////////////////////////////////////////////////

#define EXTI_BASEADDRESS				0x40013C00
#define SYSCFG_BASEADDRESS				0x40013800

typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;

typedef struct{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 CMPCR;
}SYSCFG_t;



static volatile EXTI_t * const EXTI_ptr = (volatile EXTI_t * const)EXTI_BASEADDRESS;
static volatile SYSCFG_t * const SYSCFG_ptr = (volatile SYSCFG_t * const)SYSCFG_BASEADDRESS;



///////////////////////////////////////////////////////


ret_t MEXTI_PortSelectionConfig(u32 EXTI_Line, u32 EXTI_Port)
{
	u32 state = ret_Error;
	if(EXTI_Line==19 || EXTI_Line==20 || EXTI_Port==5 || EXTI_Port==6)
	{
		state = ret_Error;
	}
	else if(EXTI_Line>=0 && EXTI_Line<=22 && EXTI_Port>=0 && EXTI_Port<=7)
	{

		SYSCFG_ptr->EXTICR[EXTI_Line/4] &= ~(0xF<<(EXTI_Line%4)*4);
		SYSCFG_ptr->EXTICR[EXTI_Line/4] |= (EXTI_Port<<(EXTI_Line%4)*4);

		state = ret_OK;
	}
	else
	{
		state = ret_Error;
	}
	return state;
}

ret_t MEXTI_INTLine_EN_DIS(u32 EXTI_Line, u32 EXTI_M)
{
	u32 state =ret_Error;
	if(EXTI_Line==19 || EXTI_Line==20)
	{
		state =ret_Error;
	}
	else if(EXTI_Line>=0 && EXTI_Line<=22 && EXTI_M>=0 && EXTI_M<=1)
	{

		EXTI_ptr->IMR &= ~(1<<EXTI_Line);
		EXTI_ptr->IMR |= (EXTI_M<<EXTI_Line);

		state =ret_OK;
	}
	else
	{
		state =ret_Error;
	}
	return state;
}

ret_t MEXTI_EVENTLine_EN_DIS(u32 EXTI_Line, u32 EXTI_M)
{
	u32 state =ret_Error;
	if(EXTI_Line==19 || EXTI_Line==20)
	{
		state =ret_Error;
	}
	else if(EXTI_Line>=0 && EXTI_Line<=22 && EXTI_M>=0 && EXTI_M<=1)
	{
		u32 temp = EXTI_ptr->EMR;
		temp &= ~(1<<EXTI_Line);
		temp |= (EXTI_M<<EXTI_Line);
		EXTI_ptr->EMR = temp;

		/*
		if(EXTI_M==0)
		{
		EXTI_ptr->EMR &= ~(1<<EXTI_Line);
		}
		else if(EXTI_M==1)
		{
		EXTI_ptr->EMR |= (1<<EXTI_Line);
		}
		*/
		state =ret_OK;
	}
	else
	{
		state =ret_Error;
	}
	return state;
}

ret_t MEXTI_TriggerConfig(u32 EXTI_Line,u32 Trigger_Mode)
{
	u32 state =ret_Error;
	if(EXTI_Line==19 || EXTI_Line==20)
	{
		state =ret_Error;
	}
	else if(EXTI_Line>=0 && EXTI_Line<=22 && Trigger_Mode>=0 && Trigger_Mode<=2)
	{

		switch(Trigger_Mode)
		{
		case Trigger_Mode_Rissing:  EXTI_ptr->RTSR |= 1<<EXTI_Line; EXTI_ptr->FTSR &= ~(1<<EXTI_Line); break;
		case Trigger_Mode_Falling:  EXTI_ptr->FTSR |= 1<<EXTI_Line; EXTI_ptr->RTSR &= ~(1<<EXTI_Line); break;
		case Trigger_Mode_OnChange:	EXTI_ptr->RTSR |= 1<<EXTI_Line; EXTI_ptr->FTSR |= 1<<EXTI_Line; break;
		}
		state =ret_OK;
	}
	else
	{
		state =ret_Error;
	}
	return state;
}

ret_t MEXTI_SW_INT_Generate(u32 EXTI_Line)
{
	u32 state =ret_Error;
	if(EXTI_Line==19 || EXTI_Line==20)
	{
		state =ret_Error;
	}
	else if(EXTI_Line>=0 && EXTI_Line<=22)
	{

		EXTI_ptr->SWIER |= (1<<EXTI_Line);

		state =ret_OK;
	}
	else
	{
		state =ret_Error;
	}
	return state;
}

ret_t MEXTI_ClearPinding(u32 EXTI_Line)
{
	u32 state =ret_Error;
	if(EXTI_Line==19 || EXTI_Line==20)
	{
		state =ret_Error;
	}
	else if(EXTI_Line>=0 && EXTI_Line<=22)
	{

		EXTI_ptr->PR |= (1<<EXTI_Line);

		state =ret_OK;
	}
	else
	{
		state =ret_Error;
	}
	return state;
}


void EXTI_CallBack(u32 EXTI_Line,void (*FuncPtr)(void))
{
	if(FuncPtr!=NULL)
	{
		switch(EXTI_Line)
		{
		case EXTI_Line_0 :  APP_Func[0]=FuncPtr;  break;
		case EXTI_Line_1 :  APP_Func[1]=FuncPtr;  break;
		case EXTI_Line_2 :  APP_Func[2]=FuncPtr;  break;
		case EXTI_Line_3 :  APP_Func[3]=FuncPtr;  break;
		case EXTI_Line_4 :  APP_Func[4]=FuncPtr;  break;
		case EXTI_Line_5 :  APP_Func[5]=FuncPtr;  break;
		case EXTI_Line_6 :  APP_Func[6]=FuncPtr;  break;
		case EXTI_Line_7 :  APP_Func[7]=FuncPtr;  break;
		case EXTI_Line_8 :  APP_Func[8]=FuncPtr;  break;
		case EXTI_Line_9 :  APP_Func[9]=FuncPtr;  break;
		case EXTI_Line_10:  APP_Func[10]=FuncPtr; break;
		case EXTI_Line_11:  APP_Func[11]=FuncPtr; break;
		case EXTI_Line_12:  APP_Func[12]=FuncPtr; break;
		case EXTI_Line_13:  APP_Func[13]=FuncPtr; break;
		case EXTI_Line_14:  APP_Func[14]=FuncPtr; break;
		case EXTI_Line_15:  APP_Func[15]=FuncPtr; break;
		}
	}
	else
	{
		//DO NOTHING
	}
}



void EXTI0_IRQHandler(void)
{
	if(APP_Func[0]!=NULL)
	{
		APP_Func[0]();
		MEXTI_ClearPinding(EXTI_Line_0);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI1_IRQHandler(void)
{
	if(APP_Func[1]!=NULL)
	{
		APP_Func[1]();
		MEXTI_ClearPinding(EXTI_Line_1);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI2_IRQHandler(void)
{
	if(APP_Func[2]!=NULL)
	{
		APP_Func[2]();
		MEXTI_ClearPinding(EXTI_Line_2);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI3_IRQHandler(void)
{
	if(APP_Func[3]!=NULL)
	{
		APP_Func[3]();
		MEXTI_ClearPinding(EXTI_Line_3);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI4_IRQHandler(void)
{
	if(APP_Func[4]!=NULL)
	{
		APP_Func[4]();
		MEXTI_ClearPinding(EXTI_Line_4);
	}
	else
	{
		/*Do Nothing*/
	}
}


void EXTI9_5_IRQHandler(void)
{
	if(APP_Func[5]!=NULL)
	{
		APP_Func[5]();
		MEXTI_ClearPinding(EXTI_Line_5);
	}
	if(APP_Func[6]!=NULL)
	{
		APP_Func[6]();
		MEXTI_ClearPinding(EXTI_Line_6);
	}
	else if(APP_Func[7]!=NULL)
	{
		APP_Func[7]();
		MEXTI_ClearPinding(EXTI_Line_7);
	}
	else if(APP_Func[8]!=NULL)
	{
		APP_Func[8]();
		MEXTI_ClearPinding(EXTI_Line_7);
	}
	else if(APP_Func[9]!=NULL)
	{
		APP_Func[9]();
		MEXTI_ClearPinding(EXTI_Line_7);
	}
	else
	{
		/*do nothing*/
	}

}
void EXTI15_10_IRQHandler(void)
{
	if(APP_Func[10]!=NULL)
	{
		APP_Func[10]();
		MEXTI_ClearPinding(EXTI_Line_10);
	}
	else if(APP_Func[11]!=NULL)
	{
		APP_Func[11]();
		MEXTI_ClearPinding(EXTI_Line_11);
	}
	else if(APP_Func[12]!=NULL)
	{
		APP_Func[12]();
		MEXTI_ClearPinding(EXTI_Line_12);
	}
	else if(APP_Func[13]!=NULL)
	{
		APP_Func[13]();
		MEXTI_ClearPinding(EXTI_Line_13);
	}
	else if(APP_Func[14]!=NULL)
	{
		APP_Func[14]();
		MEXTI_ClearPinding(EXTI_Line_14);
	}
	else if(APP_Func[15]!=NULL)
	{
		APP_Func[15]();
		MEXTI_ClearPinding(EXTI_Line_15);
	}
	else
	{
		/*do nothing*/
	}
}


