/*
#include <s3c44b0x.h>
#include <s3cev40.h>
#include <system.h>
#include <segs.h>
#include <uart.h>

#define USRMODE (0x10)
#define FIQMODE (0x11)
#define IRQMODE (0x12)
#define SVCMODE (0x13)
#define ABTMODE (0x17)
#define UNDMODE (0x1b)
#define SYSMODE (0x1f)

#define SET_OPMODE( mode )                 \
    asm volatile (                         \
        "mrs r0, cpsr               \n"    \
        "bic r0, r0, #0x1f          \n"    \
        "orr r0, r0, %0             \n"    \
        "msr cpsr_c, r0               "    \
        :                                  \
        : "i" (mode)                       \
        : "r0"                             \
    )

#define GET_OPMODE( mode_p )               \
    asm volatile (                         \
        "mrs r0, cpsr               \n"    \
        "and r0, r0, #0x1f          \n"    \
        "strb r0, %0                  "    \
        : "=m" (*mode_p)                   \
        :                                  \
        : "r0"                             \
    );
  
#define SET_IRQFLAG( value )               \
    asm volatile (                         \
        "mrs r0, cpsr               \n"    \
        "bic r0, r0, #0x80          \n"    \
        "orr r0, r0, %0             \n"    \
        "msr cpsr_c, r0               "    \
        :                                  \
        : "i" (value<<7)                   \
        : "r0"                             \
    )

#define SET_FIQFLAG( value )              \
    asm volatile (                        \
        "mrs r0, cpsr               \n"   \
        "bic r0, r0, #0x40          \n"   \
        "orr r0, r0, %0             \n"   \
        "msr cpsr_c, r0               "   \
        :                                 \
        : "i" (value<<6)                  \
        : "r0"                            \
    )

static inline void port_init( void );
static inline void install_dummy_isr( void );
static inline void show_sys_info( void );
static void sys_recovery( void );

void isr_SWI_dummy( void)        __attribute__ ((interrupt ("SWI")));
void isr_UNDEF_dummy( void )     __attribute__ ((interrupt ("UNDEF")));
void isr_IRQ_dummy( void )       __attribute__ ((interrupt ("IRQ")));
void isr_FIQ_dummy( void )       __attribute__ ((interrupt ("FIQ")));
void isr_PABORT_dummy( void )    __attribute__ ((interrupt ("ABORT")));
void isr_DABORT_dummy( void )    __attribute__ ((interrupt ("ABORT")));
void isr_ADC_dummy( void )       __attribute__ ((interrupt ("IRQ")));
void isr_RTC_dummy( void )       __attribute__ ((interrupt ("IRQ")));
    ...
void isr_USB_dummy( void )       __attribute__ ((interrupt ("IRQ")));

void sys_init( void )
{
    uint8 mode;

    WTCON  = 0;             // deshabilita el watchdog    
    INTMSK = ~0;            // enmascara todas las interrupciones
    
    GET_OPMODE( &mode );    // lee el modo de ejecuci�n del procesador
    if( mode != SVCMODE )
        sys_recovery();     // si no es SVC (por una reejecuci�n de la aplicaci�n tras una excepci�n sin reset HW previo) recupera el modo SVC y restaura las pilas del sistema

    // Configuracion del gestor de reloj
    LOCKTIME = ...;         // estabilizacion del PLL = 512 us
    PLLCON   = ...;         // MCLK = 64MHz
    CLKSLOW  = ...;         // MCLK_SLOW = 500 KHz
    CLKCON   = ...;         // modo NORMAL y reloj distribuido a todos los controladores

    // Configuracion del arbitro de bus   
    SBUSCON = ...;          // prioridad fija por defecto LCD > ZDMA > BDMA > IRQ
    
    // Configuracion de cache   
    SYSCFG = ...;           // deshabilitada

    // Configuacion del controlador de interrupciones    
    I_PMST = ...;           // prioridades fijas por defecto
    I_PSLV = ...;
    INTMOD = ...;           // todas las interrupciones en modo IRQ
    install_dummy_isr();    // instala rutinas de tratamiento por defecto para todas las interrupciones
    EXTINTPND = ...;        // borra las interrupciones externas pendientes por linea EINT7..4
    I_ISPC = ...;           // borra todas las interrupciones pendientes
    INTCON = ...;           // IRQ vectorizadas, linea IRQ activada, linea FIQ desactivada
    SET_IRQFLAG( 0 );       // Habilita IRQ en el procesador
    SET_FIQFLAG( 1 );       // Deshabilita FIQ en el procesador

    // Configuracion de puertos
    port_init();
    
    // Configuracion de dispositivos
    segs_init();
    uart0_init();

    show_sys_info();
}

static inline void port_init( void )
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

static inline void install_dummy_isr( void )
{ 
    ...
    pISR_TICK = (uint32) isr_TICK_dummy;
    ...
}        

void isr_SWI_dummy( void )
{
    ...
}

void isr_UNDEF_dummy( void )
{
    ...
}

void isr_IRQ_dummy( void )
{
    ...
}

void isr_FIQ_dummy( void )
{
    ...
}

void isr_PABORT_dummy( void )
{
    ...
}

void isr_DABORT_dummy( void )
{
    ...
}

void isr_ADC_dummy( void )
{
    ...
}

void isr_RTC_dummy( void )
{
    ...
}

void isr_UTXD1_dummy( void )
{
    ...
}

void isr_UTXD0_dummy( void )
{
    ...
}

void isr_SIO_dummy( void )
{
    ...
}

void isr_IIC_dummy( void )
{
    ...
}

void isr_URXD1_dummy( void )
{
    ...
}

void isr_URXD0_dummy( void )
{
    ...
}

void isr_TIMER5_dummy( void )
{
    ...
}

void isr_TIMER4_dummy( void )
{
    ...
}

void isr_TIMER3_dummy( void )
{
    ...
}

void isr_TIMER2_dummy( void )
{
    ...
}

void isr_TIMER1_dummy( void )
{
    ...
}

void isr_TIMER0_dummy( void )
{
    ...
}

void isr_UERR01_dummy( void )
{
    ...
}

void isr_WDT_dummy( void )
{
    ...
}

void isr_BDMA1_dummy( void )
{
    ...
}

void isr_BDMA0_dummy( void )
{
    ...
}

void isr_ZDMA1_dummy( void )
{
    ...
}

void isr_ZDMA0_dummy( void )
{
    ...
}

void isr_TICK_dummy( void )
{
    uart0_puts( "\n\n*** ERROR FATAL: ejecutando isr_TICK_dummy" );
    SEGS = 0x75;
    while( 1 );
}

void isr_PB_dummy( void )
{
    ...
}

void isr_ETHERNET_dummy( void )
{
    ...
}

void isr_TS_dummy( void )
{
    ...
}

void isr_KEYPAD_dummy( void )
{
    ...
}

void isr_USB_dummy( void )
{
    ...
}

static inline void show_sys_info( void )
{
    ...
}

inline void sleep( void )
{
    CLKCON |= (1 << 2);    // Pone a la CPU en estado IDLE
}

static void sys_recovery( void ) // NO TOCAR
{
    uint8 mode;
    uint32 sp, fp;
    uint32 *addrSrc, *addrDst;
    uint32 diffStacks;
    
    asm volatile ( "str sp, %0" : "=m" (sp) : : );    // lee el puntero a la cima de la pila de excepci�n (SP) 
    asm volatile ( "str fp, %0" : "=m" (fp) : : );    // lee el puntero al marco de activaci�n (FP) de sys_recovery() en la pila de excepci�n
    
    GET_OPMODE( &mode );    // lee el modo de ejecuci�n del procesador
    switch( mode )
    {
        case IRQMODE:
            diffStacks = IRQSTACK - SVCSTACK;     // calcula la distancia entre la bases de la pila IRQ y la SVC
            addrSrc = (uint32 *)IRQSTACK;         // base de la pila IRQ
            break;
        case FIQMODE:
            diffStacks = FIQSTACK - SVCSTACK;     // calcula la distancia entre la bases de la pila FIQ y la SVC
            addrSrc = (uint32 *)FIQSTACK;         // base de la pila FIQ
            break;
        case ABTMODE:
            diffStacks = ABTSTACK - SVCSTACK;     // calcula la distancia entre la bases de la pila ABT y la SVC
            addrSrc = (uint32 *)ABTSTACK;         // base de la pila ABT
            break;
        case UNDMODE:
            diffStacks = UNDSTACK - SVCSTACK;     // calcula la distancia entre la bases de la pila UND y la SVC
            addrSrc = (uint32 *)UNDSTACK;         // base de la pila UND
            break;         
        case SYSMODE:
        case USRMODE:
            // Habr�a que hacer algo an�logo a lo anterior y adem�s para volver a modo SVC dado que no es v�lido SET_OPMODE( SVCMODE ), es necesario esto:
            // pISR_SWI = (uint32) isr_SWI;
            // SWI( 0 );  
        default:
            while( 1 );                           // aqu� no deber�a llegarse
            break;
    }    
        
    asm volatile ( "ldr sp, %0" : "=m" (addrSrc) : : );    // restaura el SP de excepci�n a su base para desechar su contenido y evitar su desbordamiento     
        
    for( addrDst = (uint32 *)SVCSTACK; addrSrc > (uint32 *)sp; )    // copia el contenido completo de la pila excepci�n en la pila SVC
        *(--addrDst) = *(--addrSrc);

    addrDst = (uint32 *)(fp-diffStacks);   // carga el puntero al marco de activaci�n de sys_recovery() en la pila SVC
    addrDst--;                             // salta el PC apilado
    addrDst--;                             // salta el LR apilado
    *addrDst -= diffStacks;                // actualiza SP apilado para que apunte a la pila SVC
    addrDst--;                             // salta el SP apilado
    *addrDst -= diffStacks;                // actualiza el FP apilado para que apunte a la pila SVC
    
    addrDst = (uint32 *)(*addrDst);        // carga el puntero al marco de activaci�n de sys_init()
    addrDst--;                             // salta el PC apilado
    addrDst--;                             // salta el LR apilado
    *addrDst -= diffStacks;                // actualiza SP apilado para que apunte a la pila SVC
    addrDst--;                             // salta el SP apilado
    *addrDst -= diffStacks;                // actualiza el FP apilado para que apunte a la pila SVC
   
    SET_OPMODE( SVCMODE );                           // cambia a modo SVC

    sp -= diffStacks;
    asm volatile ( "ldr sp, %0" : : "m" (sp) : );    // actualiza SP_svc para que apunte a la cima de la pila SVC
    
    fp -= diffStacks;                 
    asm volatile ( "ldr fp, %0" : : "m" (fp) : );    // actualiza FP para que apunte al marco de la pila SVC, debe ser siempre la �ltima sentencia
}

*/
