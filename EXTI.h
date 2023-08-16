/*
 * EXTI.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Mayar
 */

#ifndef EXTI_H_
#define EXTI_H_



#include "../common/STD_TYPE.h"
#include "../common/Util.h"


#define EXTI_Line_0										    0
#define EXTI_Line_1										    1
#define EXTI_Line_2										    2
#define EXTI_Line_3										    3
#define EXTI_Line_4										    4
#define EXTI_Line_5										    5
#define EXTI_Line_6										    6
#define EXTI_Line_7										    7
#define EXTI_Line_8										    8
#define EXTI_Line_9										    9
#define EXTI_Line_10										10
#define EXTI_Line_11										11
#define EXTI_Line_12										12
#define EXTI_Line_13										13
#define EXTI_Line_14										14
#define EXTI_Line_15										15
#define EXTI_Line_16_PVD									16
#define EXTI_Line_17_RTCalarm								17
#define EXTI_Line_18_OTG									18
#define EXTI_Line_21_RTCtamper								21
#define EXTI_Line_22_wakeup									22


#define EXTI_Port_A											0
#define EXTI_Port_B											1
#define EXTI_Port_C											2
#define EXTI_Port_D											3
#define EXTI_Port_E											4
#define EXTI_Port_H											7

#define EXTI_M_Enable										1
#define EXTI_M_Disable										0

#define Trigger_Mode_Rissing								0
#define Trigger_Mode_Falling								1
#define Trigger_Mode_OnChange								2



ret_t MEXTI_PortSelectionConfig(u32 EXTI_Line, u32 EXTI_Port);

ret_t MEXTI_INTLine_EN_DIS(u32 EXTI_Line, u32 EXTI_M);

ret_t MEXTI_EVENTLine_EN_DIS(u32 EXTI_Line, u32 EXTI_M);

ret_t MEXTI_TriggerConfig(u32 EXTI_Line,u32 Trigger_Mode);

ret_t MEXTI_SW_INT_Generate(u32 EXTI_Line);

ret_t MEXTI_ClearPinding(u32 EXTI_Line);

void EXTI_CallBack(u32 EXTI_Line,void (*FuncPtr)(void));





#endif /* EXTI_H_ */
