#ifndef TTIM_CONFIG_H
#define TTIM_CONFIG_H

#include "chip.h"
#include "timer_18xx_43xx.h"

#include "sapi.h"
#include "sapi_timer.h"

/* GENERAL =============================================================================================================================== */

#define TTIM_CB_MODE                TTIM_CB_MODE_PARAM
#define TTIM_MM_MODE                TTIM_MM_MODE_STATIC
#define TTIM_COUNT                  4

/* Critical section */
#define TTIM_CRITICAL_START()       __asm volatile ("cpsid i")
#define TTIM_CRITICAL_END()         __asm volatile ("cpsie i")

/* TIMEBASE LL CONFIGURATION FOR TESTING ================================================================================================ */
#define TTIM_TIMEBASE_INIT()
#define TTIM_TIMEBASE_START(TIME)   Timer_Init( 0 , Timer_microsecondsToTicks(TIME) , NULL );
#define TTIM_TIMEBASE_IS_RUNNING()  ((LPC_TIMER0)->TCR & TIMER_ENABLE)
#define TTIM_TIMEBASE_IS_STOPPED()  (! ((LPC_TIMER0)->TCR & TIMER_ENABLE))
#define TTIM_TIMEBASE_STOP()        Timer_DeInit( 0 )
#define TTIM_TIMEBASE_ELAPSED()     (Chip_TIMER_ReadCount(LPC_TIMER0)/(LPC4337_MAX_FREC/1000000))




#endif // TTIM_CONFIG_H
