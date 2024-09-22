#include <s3c44b0x.h>
#include "systemLab3.h"    

static void port_init( void )
{
    PDATA = ~0;
    PCONA = ...;

    PDATB = ~0;
    PCONB = ...;

    PDATC = ~0;
    PCONC = ...;
    PUPC  = ...;

    PDATD = ~0;
    PCOND = ...;
    PUPD  = ...;
    
    PDATE = ~0;
    PCONE = ...;
    PUPE  = ...;

    PDATF = ~0;
    PCONF = ...;
    PUPF  = ...;
    
    PDATG = ~0;
    PCONG = ...;
    PUPG  = ...;

    SPUCR = ...;
    
    EXTINT = ...;
}

void sys_init( void )
{
    port_init();    
}


