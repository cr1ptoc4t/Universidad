#include <msp430.h> 
#include <driverlib.h>
#include <msp430fr6969>

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	

	 GPIO_setAsOutputPin(
	        GPIO_PORT_P1,
	        GPIO_PIN0
	        );

	    // Disable the GPIO power-on default high-impedance mode
	    // to activate previously configured port settings
	    PMM_unlockLPM5();

	    while(1)
	    {
	        // Toggle P1.0 output
	        GPIO_toggleOutputOnPin(
	            GPIO_PORT_P1,
	            GPIO_PIN0
	            );

	        // Delay
	        __delay_cycles(30000);
	    }

	return 0;
}
