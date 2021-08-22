// Utilizar las funciones de delay no bloqueante de la biblioteca sAPI

#include "sapi.h"
#include "ttim.h"

/**
   @brief Callback to each timer.
            The parameter brings the led number that was configured in ttim_set
   @param hnd
   @param param
 */
void ttim_callback( TTIM_HND_T hnd, void*param )
{
    /* toggle the led */
    gpioToggle( ( gpioMap_t ) param );

    /* restarts the timer */
    ttim_start( hnd );
}


int main( void )
{
    /* onfigure the board */
    boardInit();

    /* initializes the ttim library */
    ttim_init();

    /* time in microseconds */
    ttim_set( 0, 200000  , ttim_callback , LEDB );
    ttim_set( 1, 500000  , ttim_callback , LED1 );
    ttim_set( 2, 1000000 , ttim_callback , LED2 );
    ttim_set( 3, 2000000 , ttim_callback , LED3 );

    ttim_start( 0 );
    ttim_start( 1 );
    ttim_start( 2 );
    ttim_start( 3 );

    while( TRUE )
    {
        __asm volatile( "dsb" ::: "memory" );
        __asm volatile( "wfi" );
        __asm volatile( "isb" );
    }

    return 0;
}
