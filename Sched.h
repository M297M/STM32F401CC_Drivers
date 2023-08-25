/*
 * Sched.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mayar
 */

#ifndef SCHED_H_
#define SCHED_H_




#include "../Common/STD_TYPE.h"
#include "../../Common/Util.h"

#include "../Mcal/SYSTICK.h"

#define SysTickMs		1000
#define Max_Task		10

typedef struct{
	void (*Func_ptr)(void);
	u32 Pericity;
	u32	Priority;
	u8 * Name;
}Task_t;

void RTOS_SchedInit(void);

void RTOS_SchedStart(void);

void RTOS_AddTask(const Task_t* UserTask);






#endif /* SCHED_H_ */
