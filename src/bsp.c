
#include "sapi.h"
#include "ttim.h"

/*==================[internal functions declaration]=========================*/

/**
   @brief Timer 0 ISR
            code taken from
            https://github.com/epernia/firmware_v3/blob/77214dd0f6ab9528db88621b2f6b36eb56821095/libs/sapi/sapi_v0.6.2/soc/peripherals/src/sapi_timer.c#L257

 */
void TIMER0_IRQHandler( void )
{
    uint8_t compareMatchNumber = 0;

    for( compareMatchNumber = TIMERCOMPAREMATCH0;
            compareMatchNumber <= TIMERCOMPAREMATCH3;
            compareMatchNumber++ )
    {
        if( Chip_TIMER_MatchPending( LPC_TIMER0, compareMatchNumber ) )
        {
            Chip_TIMER_ClearMatch( LPC_TIMER0, compareMatchNumber );

            /* call the method for handling one shot timouts */
            ttim_update();
        }
    }
}
