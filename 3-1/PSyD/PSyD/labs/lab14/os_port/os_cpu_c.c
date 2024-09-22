/*-----------------------------------------------------------------
**
**  Fichero:
**    os_cpu_c.c  15/3/2015
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Portar el kernel de tiempo real uC/OS-II a la placa de prototipado
**    Embest S3CEV40, implementando las funciones:
**      - void OSInitHookBegin( void )
**      - void OSInitHookEnd( void )
**      - void OSTaskCreateHook( OS_TCB *ptcb )
**      - void OSTaskDelHook( OS_TCB *ptcb )
**      - void OSTaskIdleHook( void )
**      - void OSTaskStatHook( void )
**      - OS_STK *OSTaskStkInit( void (*task)(void *pd), void *pdata, OS_STK *ptos, INT16U opt )
**      - void OSTaskSwHook( void )
**      - void OSTCBInitHook( OS_TCB *ptcb )
**      - void OSTimeTickHook( void )
**
**  Notas de dise�o:
**    - Implementado seg�n las especificaciones del cap�tulo 3 del
**      libro "MicroC/OS-II. The Real-Time Kernel (2nd. edition)" 
**      de Jean J. Labrosse
**
**---------------------------------------------------------------*/

#define  OS_CPU_GLOBALS

#include "os_cpu.h"
#include "os_cfg.h"
#include "ucos_ii.h"

/*
** Esta funci�n es llamada con las interrupciones deshabilitadas por OSInit() justo despu�s de su inicio.
*/

#if OS_CPU_HOOKS_EN > 0
void OSInitHookBegin( void )
{
}
#endif

/*
** Esta funci�n es llamada con las interrupciones deshabilitadas por OSInit() justo antes de su fin.
*/

#if OS_CPU_HOOKS_EN > 0
void OSInitHookEnd( void )
{
}
#endif

/*
** Esta funci�n es llamada con las interrupciones deshabilitadas cada vez que se crea una tarea.
** Toma como argumento un puntero al TCB de la tarea reci�n creada.
*/

#if OS_CPU_HOOKS_EN > 0 
void OSTaskCreateHook( OS_TCB *ptcb )
{
}
#endif

/*
** Esta funci�n es llamada con las interrupciones deshabilitadas cada vez que se borra una tarea.
** Toma como argumento un puntero al TCB de la tarea borrada.
*/

#if OS_CPU_HOOKS_EN > 0 
void OSTaskDelHook( OS_TCB *ptcb )
{
}
#endif

/*
** Esta funci�n es llamada con las interrupciones habilitadas por la tarea OS_TaskIdle().
*/

#if OS_CPU_HOOKS_EN > 0
void OSTaskIdleHook( void )
{
    sleep();    /* Pone a la CPU en estado IDLE, sale por interrupci�n */
}
#endif

/*
** Esta funci�n es llamada cada segundo por la tarea OSTaskStat().
*/

#if OS_CPU_HOOKS_EN > 0 
void OSTaskStatHook( void )
{
}
#endif

/*
** Esta funci�n es llamada con las interrupciones deshabilitadas cada vez que se crea una tarea para inicializar su contexto.
** Toma los siguientes argumentos:
**   - void (*task)(void *pd) -- puntero al c�digo de la tarea
**   - void *pdata            -- puntero a los argumentos que tomar� la tarea cuando se ejecute por primera vez
**   - OS_STK *ptos           -- puntero a la cima de la pila en la que la funci�n inicializar� el contexto de la tarea
**   - INT16U opt             -- permite indicar opciones para modificar el comportamiento de la funci�n
** Devuelve un puntero a la nueva cima de la pila
*/
OS_STK *OSTaskStkInit( void (*task)(void *pd), void *pdata, OS_STK *ptos, INT16U opt )
{

    #if OS_STK_GROWTH == 1               /* Si la pila crece de de direcciones ALTAS hacia BAJAS */

    *(ptos)   = (INT32U) task;        /* Apila el punto de entrada a la tarea                 */
    *(--ptos) = (INT32U) 0;           /* Apila LR                                             */
    *(--ptos) = (INT32U) 0;           /* Apila R12                                            */
    *(--ptos) = (INT32U) 0;           /* Apila R11                                            */
    *(--ptos) = (INT32U) 0;           /* Apila R10                                            */
    *(--ptos) = (INT32U) 0;           /* Apila R9                                             */
    *(--ptos) = (INT32U) 0;           /* Apila R8                                             */
    *(--ptos) = (INT32U) 0;           /* Apila R7                                             */
    *(--ptos) = (INT32U) 0;           /* Apila R6                                             */
    *(--ptos) = (INT32U) 0;           /* Apila R5                                             */
    *(--ptos) = (INT32U) 0;           /* Apila R4                                             */
    *(--ptos) = (INT32U) 0;           /* Apila R3                                             */
    *(--ptos) = (INT32U) 0;           /* Apila R2                                             */
    *(--ptos) = (INT32U) 0;           /* Apila R1                                             */
    *(--ptos) = (INT32U) pdata;       /* Apila R0 : argumento                                 */
    *(--ptos) = (INT32U) (0x13|0x0);  /* Apila CPSR (IRQ y FIQ habilitadas, modo SVC)         */

    return (ptos);

#else
#error OS_STK_GROWTH no implementado
#endif

}

/*
** Esta funci�n es llamada con las interrupciones deshabilitadas cada vez que se conmuta de tarea.
** Podr� acceder a las variable globales:
**   - OS_TCB *OSTCBCur que apuntar� al TCB de la tarea en ejecuci�n (a suspender)
**   - OS_TCB *OSTCBHighRdy que apuntar� al TCB de la tarea preparada de m�xima prioridad (a reanudar)
*/

#if (OS_CPU_HOOKS_EN > 0) && (OS_TASK_SW_HOOK_EN > 0)
void OSTaskSwHook( void )
{
}
#endif

/*
** Esta funci�n es llamada cada vez que se crea una tarea justo tras la creaci�n de su TBC pero antes de su enlazado a la lista de tareas.
** Las interrupciones pueden estar habilitadas o deshabilitadas.
** Toma como argumento un puntero al TCB de la tarea reci�n creada.
*/
#if OS_CPU_HOOKS_EN > 0
void OSTCBInitHook( OS_TCB *ptcb )
{
}
#endif

/*
** Esta funci�n es llamada cada tick. Las interrupciones pueden estar habilitadas o deshabilitadas.
*/

#if (OS_CPU_HOOKS_EN > 0) && (OS_TIME_TICK_HOOK_EN > 0)
void OSTimeTickHook( void )
{
}
#endif
