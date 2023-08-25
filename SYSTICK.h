/*
 * SYSTICK.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mayar
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_



#include "../common/BIT_MATH.h"
#include "../common/STD_TYPE.h"
#include "../common/Util.h"



/*STK_CLK_SRC options*/
#define AHB					1
#define AHB_Div_8			0

/*STK_INT_EN options*/
#define DISABLE			0
#define ENABLE			1

			//Pre_build Configuration
//#########################################
#define STK_CLK_SRC				AHB_Div_8
#define STK_INT_EN				ENABLE
//#########################################

void STK_StartInit(void);

void STK_Stop(void);

void STK_PeriodMS(u32 PeriodMS);

u32 STK_RemainingTime(void);

u32 STK_ElapsedTime(void);

void STK_CallBack(void (*ptr)(void));



void MSYSTICK_PeriodUs(u32 PERIOD_Us);







#endif /* SYSTICK_H_ */
