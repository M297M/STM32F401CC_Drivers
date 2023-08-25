/* * Sched.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Mayar
 */



//SELF LAYER INCLUDE
//OTHER LAYERS INCLUDE

#include "../Mcal/SYSTICK.h"
#include "Sched.h"


static struct{
	u32 size;
	Task_t * Runnable_Task[Max_Task];
}Tasks;


u32 SchedIsReady;

///////////////////////////////////////FUN////////////////////

//Static Function prototypes
static void SchedReady();
static void Scheduler(void);




void RTOS_SchedStart(void)
{
	RTOS_SchedInit();
	while(1)
	{
		if(SchedIsReady)
		{
			SchedIsReady=0;
			Scheduler();
		}
	}
}


#define SysTickMs		1000
#define Max_Task		10
//Function
void RTOS_SchedInit(void)
{



	STK_CallBack(&SchedReady);

	STK_CallBack(SysTickMs);
}

void RTOS_AddTask(const Task_t* UserTask)
{
	if((UserTask!=NULL)&&(Tasks.size<=Max_Task))
	{
		Tasks.Runnable_Task[UserTask->Priority]=UserTask;
		Tasks.size++;
	}
}


//static functions Implementation


static void SchedReady()
{
	SchedIsReady=1;
}

static void Scheduler(void)
{

	static u32 Time;
	u32 index;
	if(Time)
	{
	for(index=0;index<Max_Task;index++)
	{
		if((Tasks.Runnable_Task[index]!=NULL) && (Time % (Tasks.Runnable_Task[index]->Pericity))==0)
		{
			Tasks.Runnable_Task[index]->Func_ptr();
		}
	}
	}
	Time += SysTickMs;

}
