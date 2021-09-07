/*
 * scheduler.c
 *
 * Created: 08/08/2021 02:14:22 AM
 *  Author: Salma
 */ 

#include "scheduler.h"

extern u8 current_state ;

/************** PRIVATE FUNCTIONS PROTOTYPES ***************/
/*Description : Put the system into 'Sleep' mode
  Parameters  : none
  Return type : void */
void SCH_Go_To_Sleep(void) ;
/***********************************************************/

/******************* PRIVATE VARIABLES ********************/
//Keep track of time since last error was recorded
static u8 ERROR_tick_count_G ;
//The code of the last error
static u16 Last_error_code_G ;
/***********************************************************/

//The array of tasks
sTask SCH_tasks_G[SCH_MAX_TASKS] ;

//Used to display the error code
u16 Error_Code_G = 0 ;


void SCH_Init_T1 (void) 
{
	u16 i ;
	
	for ( i=0 ; i< SCH_MAX_TASKS ; i++ )
	{
		SCH_Delete_Task(i) ;
	}
	
	// Reset the global error variable
	// - SCH_Delete_Task() will generate an error code,
	// (because the task array is empty)
	Error_Code_G = 0 ;
	
	//Enable interrupt for timer over flow.
	//TIMSK_  |= 0x10 ;
	SET_BIT(TIMSK_ , TIMSK_OCIE1A) ;
	//Enable the global interrupt.	
	SREG   |= 0x80 ;		
	//Timer1_Manual_Reload 
	//OC1A state at compare match & mode of the timer.
	TCCR_1A |= 0x00 ;		
	TCNT_1 = 0 ;
	OCR_1A = 16 ;
	TCCR_1B = 13 ;	
}

u16 SCH_Add_Task( void (*pFunction)() , const u8 DELAY , const u8 PERIOD) 
{
	u16 Index = 0 ;
	
	// First find a gap in the array (if there is one)
	while ( (SCH_tasks_G[Index].ptask != 0) && (Index < SCH_MAX_TASKS) )
	{
		Index++ ;
	}
	
	// Have we reached the end of the list? 
	if ( Index == SCH_MAX_TASKS )
	{
		// Task list is full
		//
		// Set the global error variable
		Error_Code_G = ERROR_SCH_TOO_MANY_TASKS ;
		
		// Also return an error code
		return SCH_MAX_TASKS ;
	}
	
	// If we're here, there is a space in the task array
	SCH_tasks_G[Index].ptask = pFunction ;
	SCH_tasks_G[Index].delay = DELAY ;
	SCH_tasks_G[Index].priod = PERIOD ;
	SCH_tasks_G[Index].RunMe = 0 ;
	
	// return position of task (to allow later deletion)
	return Index ;	
}

void SCH_Dispatch_Tasks( void )
{
	u16 Index ;
	
	//Dispatches (runs) the next task (if one is readt)
	for ( Index=0 ; Index<SCH_MAX_TASKS ; Index++ )
	{
		if ( SCH_tasks_G[Index].RunMe > 0 )
		{
			(*SCH_tasks_G[Index].ptask)() ;		// Run the task
			
			SCH_tasks_G[Index].RunMe -= 1 ;		// Reset / reduce RunMe flag
			
			//Periodic tasks will automatically run again
			//- if this is a 'one shot' task, remove it from the array 
			if ( SCH_tasks_G[Index].priod == 0 )
			{
				SCH_Delete_Task(Index) ;
			}
		}
	}
	
	//Report system status
	SCH_Report_Status() ;
	
	//The scheduler enters idle mode at this point
	SCH_Go_To_Sleep() ;
}

void SCH_Start(void)
{
	sei() ;
}

void SCH_STOP(void)
{
	u8 INDEX = 0 ;
	
		
	for (INDEX=0 ; INDEX<SCH_MAX_TASKS ; INDEX++)
	{
		SCH_tasks_G[INDEX].delay = SCH_tasks_G[INDEX].delay ;
	}
}



u16 SCH_Delete_Task(const u16 Task_Index)
{
	u16 Return_Code ;
	
	if ( SCH_tasks_G[Task_Index].ptask == 0 )
	{
		//No task at this location...
		//
		//set the global error variable
		Error_Code_G = ERROR_SCH_CANNOT_DELETE_TASK ;
		//...also return an error code
		Return_Code = RETURN_ERROR ;
	}
	else
	{
		Return_Code = RETURN_NORMAL ;
	}
	
	SCH_tasks_G[Task_Index].ptask = 0x0000 ;
	SCH_tasks_G[Task_Index].delay = 0 ;
	SCH_tasks_G[Task_Index].priod = 0 ;
	
	SCH_tasks_G[Task_Index].RunMe = 0 ;
	
	return Return_Code ;		//return status
}

void SCH_Go_To_Sleep(void)
{
	// Enter idle mode 
	CLEAR_BIT(MCUCR , SM2) ;
	CLEAR_BIT(MCUCR , SM1) ;
	CLEAR_BIT(MCUCR , SM0) ;
}

void SCH_Report_Status(void)
{
#ifdef SCH_REPORT_ERRORS
	//ONLY APPLIES IF WE ARE REPORTING ERRORS
	//Check for a new error code
	if ( Error_Code_G != Last_error_code_G )
	{
		//Navigate logic on LEDs assumed
		Error_port = 255 - Error_Code_G ;
		
		Last_error_code_G = Error_Code_G ;
		
		if ( Error_Code_G != 0 )
		{
			ERROR_tick_count_G = 60000 ;
		}
		else
		{
			ERROR_tick_count_G = 0 ;
		}
	}
	else
	{
		if ( ERROR_tick_count_G != 0 )
		{
			if ( --ERROR_tick_count_G == 0 )
			{
				Error_Code_G = 0 ;		//Reset error code
			}
		}
	}
#endif
}

//This is the scheduler ISR.
ISR ( TIMER1_COMPA_vect )
{
	if (current_state == HEATER_ON)
	{
		SCH_Update() ;
	}
	else if(current_state == HEATER_OFF)
	{
		cli() ;
	}
}

void SCH_Update (void)
{
	u16 Index ;
	
	//INTF2 = 0 ;		// Have to manually clear this. 
	
	for ( Index=0 ; Index<SCH_MAX_TASKS ; Index++ )
	{
		//Check if there is a task at this location
		if ( SCH_tasks_G[Index].ptask )
		{
			if ( SCH_tasks_G[Index].delay == 0 )
			{
				//The task is due to run
				SCH_tasks_G[Index].RunMe += 1 ;		//Inc. the 'RunMe' flag
			
				if ( SCH_tasks_G[Index].priod )
				{
					//Schedule periodic tasks to run again
					SCH_tasks_G[Index].delay = SCH_tasks_G[Index].priod ;
				}
			}
			else
			{
				//Not yet ready to run : just decrement the delay
				SCH_tasks_G[Index].delay -= 1 ;
			}
		}
	}
}