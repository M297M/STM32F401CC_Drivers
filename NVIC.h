/*
 * NVIC_Driver.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Mayar
 */

#ifndef NVIC_H_
#define NVIC_H_




#include "../common/STD_TYPE.h"
#include "../common/Util.h"


#define NVIC_ID_WWDG									0
#define NVIC_ID_EXTI16_PVD								1
#define NVIC_ID_EXTI21_TAMP_STAMP						2
#define NVIC_ID_EXTI22_RTC_WKUP							3
#define NVIC_ID_FLASH							        4
#define NVIC_ID_RCC								        5
#define NVIC_ID_EXTI0							        6
#define NVIC_ID_EXTI1							        7
#define NVIC_ID_EXTI2							        8
#define NVIC_ID_EXTI3							        9
#define NVIC_ID_EXTI4							        10
#define NVIC_ID_DMA1_Stream0						    11
#define NVIC_ID_DMA1_Stream1						    12
#define NVIC_ID_DMA1_Stream2						    13
#define NVIC_ID_DMA1_Stream3						    14
#define NVIC_ID_DMA1_Stream4						    15
#define NVIC_ID_DMA1_Stream5						    16
#define NVIC_ID_DMA1_Stream6						    17
#define NVIC_ID_ADC								        18
#define NVIC_ID_EXTI9_5							        23
#define NVIC_ID_TIM1_BRK_TIM9					        24
#define NVIC_ID_TIM1_BRK_TIM10					        25
#define NVIC_ID_TIM1_TRG_COM_TIM11				       	26
#define NVIC_ID_TIM1_CC							        27
#define NVIC_ID_TIM2							        28
#define NVIC_ID_TIM3							        29
#define NVIC_ID_TIM4							        30
#define NVIC_ID_I2C1_EV							        31
#define NVIC_ID_I2C1_ER							        32
#define NVIC_ID_I2C2_EV							        33
#define NVIC_ID_I2C2_ER							        34
#define NVIC_ID_SPI1							        35
#define NVIC_ID_SPI2							        36
#define NVIC_ID_USART1							        37
#define NVIC_ID_USART2							        38
#define NVIC_ID_EXTI15_10						        40
#define NVIC_ID_TIM17_RTCAlaram					        41
#define NVIC_ID_TIM18_OTG_FS_WKUP				        42
#define NVIC_ID_DMA1_Stream7					       	47
#define NVIC_ID_SDIO							        49
#define NVIC_ID_TIM5							        50
#define NVIC_ID_SPI3							        51
#define NVIC_ID_DMA2_Stream0						    56
#define NVIC_ID_DMA2_Stream1						    57
#define NVIC_ID_DMA2_Stream2						    58
#define NVIC_ID_DMA2_Stream3						    59
#define NVIC_ID_DMA2_Stream4						    60
#define NVIC_ID_OTG_FS							        67
#define NVIC_ID_DMA2_Stream5						    68
#define NVIC_ID_DMA2_Stream6						    69
#define NVIC_ID_DMA2_Stream7						    70
#define NVIC_ID_USART6							        71
#define NVIC_ID_I2C3_EV							        72
#define NVIC_ID_I2C3_ER							        73
#define NVIC_ID_FPU								        81
#define NVIC_ID_SPI4							        84
//////////////////////////////////////////////////////////////////////////////////////
#define Group_0											0
#define Group_1											1
#define Group_2											2
#define Group_3											3
#define Group_4											4
#define Group_5											5
#define Group_6											6
#define Group_7											7
#define Group_8											8
#define Group_9										    9
#define Group_10									    10
#define Group_11									    11
#define Group_12									    12
#define Group_13									    13
#define Group_14									    14
#define Group_15									    15
#define Group_NONE										20
//SUB_GROUBS
#define SUB_Group_0									    0
#define SUB_Group_1									    1
#define SUB_Group_2									    2
#define SUB_Group_3									    3
#define SUB_Group_4									    4
#define SUB_Group_5									    5
#define SUB_Group_6									    6
#define SUB_Group_7									    7
#define SUB_Group_8									    8
#define SUB_Group_9										9
#define SUB_Group_10									10
#define SUB_Group_11									11
#define SUB_Group_12									12
#define SUB_Group_13									13
#define SUB_Group_14									14
#define SUB_Group_15									15
#define SUB_Group_NONE									20

/*Priority options*/
								//5FA0-> VECKEY Password  0 0->Our option 000
#define Groub16_SubGroub0      0x5FA00000
								//5FA0-> VECKEY Password  0 4->Our option 000
#define Groub8_SubGroub2       0x5FA00400
								//5FA0-> VECKEY Password  0 5->Our option 000
#define Groub4_SubGroub4       0x5FA00500
								//5FA0-> VECKEY Password  0 6->Our option 000
#define Groub2_SubGroub8       0x5FA00600
								//5FA0-> VECKEY Password  0 7->Our option 000
#define Groub0_SubGroub16      0x5FA00700  //closed nested
//#################################################################################
//Priority Config
#define SW_Priority       Groub8_SubGroub2
//#################################################################################

void MNVIC_PriorityInit(void);

ret_t MNVIC_EnableINT_ID(u32 NVIC_ID);
ret_t MNVIC_DisableINT_ID(u32 NVIC_ID);

ret_t MNVIC_SetPending(u32 NVIC_ID);
ret_t MNVIC_ClrPending(u32 NVIC_ID);

ret_t MNVIC_SetINT_Periority(u32 NVIC_ID,u32 Groub,u32 Sub_Groub);












#endif /* NVIC_H_ */
