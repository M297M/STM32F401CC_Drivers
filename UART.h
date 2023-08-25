/*
 * UART.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Mayar
 */

#ifndef UART_H_
#define UART_H_


#include "../common/STD_TYPE.h"
#include "../common/BIT_MATH.h"
#include "../common/Util.h"

#define USART_1			1
#define USART_2			2
#define USART_6			6





ret_t MUSART_Init(u32 USART);

ret_t MUSART_SendByteSynch(u32 USART,u8 DataSend);

u8 MUSART_ReciveByteSynch(u32 USART);

ret_t MUSART_SendStringSynch(u32 USART,char * SendString);

void MUSART_ReciveStringSynch(u32 USART,u8 RecivedStg[]);



#endif /* UART_H_ */
