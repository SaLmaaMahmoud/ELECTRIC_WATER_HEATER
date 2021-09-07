/*
 * scheduler.h
 *
 * Created: 08/08/2021 02:14:08 AM
 *  Author: Salma
 */ 


#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "BITMATH.h"
#include "STD_TYPES.h"

#include "TMR.h"
#include "main.h"
#include <avr/interrupt.h>
			
/*************** PUBPLIC CONSTANTS ****************/
// The maximum number of tasks required at any one time
// during the execution of the program
//
// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS	(8)			
//#define Error_port	PORT_A
/*************************************************/

#define F_CPU		8000000		//The crystal oscillator frequency
#define TICK_ms		(5)			//Determine the tick time in ms

/***************** ERROR CODES ******************/
#define ERROR_SCH_TOO_MANY_TASKS (1)
#define ERROR_SCH_CANNOT_DELETE_TASK (2)
#define RETURN_NORMAL (u8) 0
#define RETURN_ERROR (u8) 1
/*************************************************/
	
/* Total memory for task is 7-bytes */
typedef struct
{
	//pointer to the task (must be a 'void (void)' function)
	void (* ptask) (void) ;

	// Delay (ticks) until the function will (next) be run
	// - see SCH_Add_Task() for further details
	u8 delay ;

	// Interval (ticks) between subsequent runs.
	// - see SCH_Add_Task() for further details
	u8 priod ;

	// Incremented (by scheduler) when task is due to execute
	u16 RunMe ;
	} sTask ;

/************** PUBPLIC FUNCTIONS PROTOTYPES ***************/
/*****************Core scheduler functions******************/

/*Description : Prepares scheduler data structures and sets up 
				timer interrupts at required rate. Must call this 
				function before using the scheduler.
  Parameters  : none
  Return type : void */
void SCH_Init_T1 (void) ;

/*Description : Causes a task (function) to be executed at regular
				intervals or after a user-defined delay
  Parameters  : the name of the function (task) -> void (*pFunction)
				the delay before task is first executed -> const tWord DELAY
				the interval between repeated executions of the task -> const tWord PERIOD
  Return type : u16 */
u16 SCH_Add_Task( void (*pFunction)() , const u8 DELAY , const u8 PERIOD) ;
	
/*Description : When a task (function) is due to run, SCH_Dispatch_Tasks() 
				will run it. This function must be called (repeatedly) 
				from the main loop.
  Parameters  : none
  Return type : void */
void SCH_Dispatch_Tasks(void) ;

/*Description : After all the tasks have been added, this function 
				is called to begin the scheduling process. The function
				achieves this by globally enabling interrupts.
  Parameters  : none
  Return type : void */
void SCH_Start(void) ;
	
/*Description : Delete Tasks from the array
  Parameters  : The task index -> const u16 Task_Index
  Return type : u16 */
u16 SCH_Delete_Task(const u16 Task_Index) ;
		
/*Description : Report the error codes
  Parameters  : none
  Return type : void */
void SCH_Report_Status(void) ;

/*Description : This is the scheduler ISR. It is called at a rate
				determined by the timer settings in the 'init' function.
				This version is triggered by Timer 2 interrupts:
				timer is automatically reloaded.
  Parameters  : none
  Return type : void */
void SCH_Update (void) ;


#endif /* SCHEDULER_H_ */
