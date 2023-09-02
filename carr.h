/*
 * carr.h
 *
 *  Created on: Aug 25, 2023
 *      Author: Mayar
 */

#ifndef CARR_H_
#define CARR_H_


#include "../../common/STD_TYPE.h"
#include "../../common/bit_math.h"

typedef struct{
	u8 gpio;
	u8 pin[4];

}motor_t;


Std_ReturnType motor_init(motor_t *motor);
Std_ReturnType motor_forward(motor_t *motor);
Std_ReturnType motor_backword(motor_t *motor);
Std_ReturnType motor_left(motor_t *motor);
Std_ReturnType motor_right(motor_t *motor);
Std_ReturnType motor_stop(motor_t *motor);



#endif /* CARR_H_ */
