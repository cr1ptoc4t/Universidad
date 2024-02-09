#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	//WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	

    // Stop watchdog timer
       WDT_A_hold(__MSP430_BASEADDRESS_WDT_A__);

       // Disable the GPIO power-on default high-impedance mode to activate
       // previously configured port settings
       //PMM_unlockLPM5();

       //enable interrupts
       //__enable_interrupt();

       // Initializations
       //Init_GPIO();
       //Init_Clock();
       Init_LCD();

       //GPIO_clearInterrupt(GPIO_PORT_P1, GPIO_PIN1);
       //GPIO_clearInterrupt(GPIO_PORT_P1, GPIO_PIN2);

       //__enable_interrupt();

	displayScrollText("Hola mundo");

	return 0;
}
