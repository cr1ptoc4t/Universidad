/*-------------------------------------------------------------------
**
**  Fichero:
**    cooperativo.c  12/1/2021
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Contiene las definiciones de las macros, tipos y prototipos 
**    de las funciones del kernel de planificaci�n no expropiativa
**    de tareas cooperativas multiestado
**
**  Notas de dise�o:
**
**-----------------------------------------------------------------*/

#include <common_types.h>

#define MAX_TASKS        (10)    /* Configuraci�n del kernel */
#define TICKS_PER_SEC   (100)

typedef struct                   /* Definici�n del TCB (task control block) */
{
    void (*pfunction) (void);    /* Funci�n que realiza la tarea */
    uint32 period;               /* Tiempo m�nimo que debe transcurrir entre 2 ejecuciones consecutivas de la tarea (en ticks) */
    uint32 ticks;                /* Tiempo transcurrido desde la �ltima ejecuci�n de la tarea (en ticks) */
    boolean ready;               /* Estado de la tarea: ready = TRUE indica que ha transcurrido un periodo de desde su �ltima ejecuci�n */
} task_t;

uint32 create_task( void (*pfunction)(void), uint32 period );
void delete_task( uint32 i );

void scheduler_init( void );
void scheduler( void ) __attribute__ ((interrupt ("IRQ")));
void dispacher( void );
