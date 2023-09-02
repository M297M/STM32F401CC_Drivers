/*
 * S2P.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Mayar
 */

#ifndef S2P_H_
#define S2P_H_



#include "../common/STD_TYPE.h"

typedef struct{

	//port
	u8 DS_PORT;
	u8 SR_PORT;
	u8 ST_PORT;


	u8 DS_PIN;
	u8 SR_PIN;
	u8 ST_PIN;



}S2P_t;

void HS2P_SENDBytesynch(S2P_t*S2P_INFO,u32 User_Byte);



#endif /* S2P_H_ */
