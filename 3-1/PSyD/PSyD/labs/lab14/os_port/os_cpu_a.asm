/*-----------------------------------------------------------------
**
**  Fichero:
**    os_cpu_a.asm  20/1/2017
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Portar el kernel de tiempo real uC/OS-II a la placa de prototipado
**    Embest S3CEV40, implementando las funciones:
**      - void OSStartHighRdy( void )
**      - void OSCtxSw( void )
**      - void OSIntCtxSw( void )
**      - void OSTickISR( void )
**
**  Notas de dise�o:
**    - Implementado seg�n las especificaciones del cap�tulo 13 del
**      libro "MicroC/OS-II. The Real-Time Kernel (2nd. edition)" 
**      de Jean J. Labrosse
**    - Asume que la fuente de interrupciones de tiempo es el timer0 y
**      que interrumpe por IRQ
**    - Asume que el kernel se ejecuta con repertorio ARM en modo SVC
**
**---------------------------------------------------------------*/

.include "s3c44b0x.asm"
.include "s3cev40.asm"

  /* Referencias externas */

  .extern OSRunning      /* BOOLEAN OSRunning         -- flag que indica si el kernel est� en ejecuci�n                        */
  .extern OSIntNesting   /* INT8U OSIntNesting        -- nivel de anidaci�n de interrupciones                                  */
  .extern OSTaskSwHook   /* void OSTaskSwHook( void ) -- funci�n definible por el usuario                                      */
  .extern OSTCBCur       /* OS_TCB *OSTCBCur          -- puntero al TCB de la tarea en ejecuci�n (a suspender)                 */
  .extern OSPrioCuR      /* INT8U OSPrioCur           -- prioridad de la tarea en ejecuci�n (a suspender)                      */
  .extern OSTCBHighRdY   /* OS_TCB *OSTCBHighRdy      -- puntero al TCB de la tarea preparada de m�xima prioridad (a reanudar) */
  .extern OSPrioHighRdy  /* INT8U OSPrioHighRdy       -- prioridad de la tarea preparada de m�xima prioridad (a reanudar)      */
  .extern OSIntEnter     /* void OSIntEnter( void )   -- funci�n del kernel                                                    */
  .extern OSIntExit      /* void OSIntExit( void )    -- funci�n del kernel                                                    */
  .extern OSTimeTick     /* void OSTimeTick( void )   -- funci�n del kernel                                                    */

  /* Funciones definidas en este m�dudo */

  .global OSStartHighRdy /* void OSStartHighRdy( void ) */
  .global OSCtxSw        /* void OSCtxSw( void )        */
  .global OSIntCtxSw     /* void OSIntCtxS( void )      */
  .global OSTickISR      /* void OSTickISR( void )      */

  /* Modos de operaci�n */

  .equ IRQMODE, (0x12)
  .equ SVCMODE, (0x13)

  /* M�scara para desabilitar IRQ y FIQ */

  .equ NOINT,   (0xc0)

.section .text

/*
** void OSStartHighRdy( void )
**
** Comienza la multitarea arrancando la tarea preparada con mayor prioridad.
** Esta funci�n es llamada por OSStart().
**
*/

OSStartHighRdy:  
  
  bl    OSTaskSwHook            /* (1) Llama a la funci�n OSTaskSwHook() */

  ldr   r4, =OSRunning          /* (2) OSRunning = TRUE                  */
  mov   r5, #1
  strb  r5, [r4]

  ldr   r4, =OSTCBHighRdy       /* (3) SP = OSTCBHighRdy->OSTCBStkPtr    */
  ldr   r4, [r4]
  ldr   sp, [r4]

  ldmfd sp!, {r4}               /* (4) Restaura de la pila el contexto de la tarea preparada con mayor prioridad ... */
  msr   spsr, r4
  ldmfd sp!, {r0-r12,lr,pc}^    /* (5) ... retorna a dicha tarea (^ copia el SPSR al CPSR a la vez que restaura el PC) */

/*
** void OSCtxSw( void )
**
** Conmuta (desde nivel tarea) de la tarea actual a la tarea preparada con mayor prioridad
** Esta funci�n es llamada por OS_Sched() con las interrupciones desabilitadas.
**
** void OSIntCtxSw( void )
**
** Conmuta (desde nivel interrupci�n) de la tarea actual a la tarea preparada con mayor prioridad
** Su funcionalidad es equivalente a OSCtxSw pero sin guardar el contexto de la tarea actual (lo hizo la correspondiente RTI)
** Esta funci�n es llamada por OSIntExit() con las interrupciones desabilitadas.
**
*/

OSCtxSw:

  stmfd sp!, {lr}               /* (1) Guarda en la pila el contexto de la tarea actual */
  stmfd sp!, {r0-r12, lr}
  mrs   r4,  cpsr
  stmfd sp!, {r4}

  ldr r4, =OSTCBCur             /* (2) OSTCBCur->OSTCBStkPtr = SP        */
  ldr r5, [r4]
  str sp, [r5]

OSIntCtxSw:

  bl OSTaskSwHook               /* (3) Llama a la funci�n OSTaskSwHook() */

  ldr r4, =OSTCBCur             /* (4) OSTCBCur = OSTCBHighRdy           */
  ldr r5, =OSTCBHighRdy
  ldr r5, [r5]
  str r5, [r4]

  ldr  r6, =OSPrioHighRdy       /* (5) OSPrioCur = OSPrioHighRdy         */
  ldr  r7, =OSPrioCur
  ldrb r6, [r6]
  strb r6, [r7]

  ldr sp, [r5]                  /* (6) SP = OSTCBHighRdy->OSTCBStkPtr    */

  ldmfd sp!, {r4}               /* (7) Restaura de la pila el contexto de la tarea preparada con mayor prioridad y ... */
  msr   spsr, r4
  ldmfd sp!, {r0-r12,lr,pc}^    /* (8) ... retorna a dicha tarea         */


/*
** void OSTickISR( void )
**
** Rutina de tratamiento de la interrupci�n generada por el temporizador usado por el sistema para hacer el seguimiento
** de retardos y timeouts.
**
** IMPORTANTE: La rutina comienza su ejecuci�n en modo IRQ (con SP, LR y CPSR propios)
**
*/

OSTickISR:

  stmfd sp!, {r1-r3}           /* Apila los registros de trabajo en la pila IRQ  */

  mov r1, sp                   /* Copia en R1 el puntero de la pila IRQ          */
  add sp, sp, #12              /* Ajusta el puntero del la pila IRQ a la posici�n que ten�a antes de la interrupci�n (suma 12 porque ha apilado 3 registros) */
  sub r2, lr, #4               /* Copia en R2, previo ajuste, la direcci�n de retorno a la tarea actual (tras IRQ el PC est� en <dir_actual>+4) */
  mrs r3, spsr                 /* Copia en R3 el SPSR (i.e. el CPSR de la tarea actual interrumpida) */

  msr cpsr_c, #(NOINT|SVCMODE) /* Cambia a modo SVC */

                               /* (1) Guarda en la pila SVC el contexto de la tarea actual              */
  stmfd sp!, {r2}              /*     - Apila la direcci�n de retorno a la tarea actual (previamente copiado en R2) */
  stmfd sp!, {lr}              /*     - Apila el LR de la tarea actual                                  */
  stmfd sp!, {r4-r12}          /*     - Apila los registros R4-R12 de la tarea actual                   */
  ldmfd r1!, {r4-r6}           /*     - Copia en R4-R6 los registros R1-R3 de la tarea actual (previamente almacenados en la pila IRQ) */
  stmfd sp!, {r4-r6}           /*     - Apila los registros R1-R3 de la tarea actual (anteriormente copiados en R4-R6 */
  stmfd sp!, {r0}              /*     - Apila el registro R0 de la tarea actual                         */
  stmfd sp!, {r3}              /*     - Apila el CPSR de la tarea actual (previamente copiado en R3)    */

  bl  OSIntEnter               /* (2) Llama a la funci�n OSIntEnter()          */

  ldr  r0, =OSIntNesting       /* (3) Si OSIntNesting == 1 ...                 */
  ldrb r0, [r0]
  cmp  r0, #1
  bne  OSTickISRcont
  ldr  r0, =OSTCBCur           /*     ... OSTCBCur->OSTCBStkPtr = SP           */
  ldr  r1, [r0]
  str  sp, [r1]

OSTickISRcont:

  msr cpsr_c, #(NOINT|IRQMODE) /* Cambia a modo IRQ (para que la pila IRQ sea usada para tratar la interrupci�n */
  ldr r1, =I_ISPC              /* (4) Borra interrupci�n pendiente por timer */
  mov r2, #BIT_TIMER0
  str r2, [r1]
                               /* (5) Aqu� opcionamente podr�an habilitarse interrupciones */

  bl  OSTimeTick               /* (6) Llama a la funci�n OSTimeTick                        */

  msr cpsr_c, #(NOINT|SVCMODE) /* Cambia a modo SVC                            */

  bl  OSIntExit                /* (6) Llama a la funci�n OSIntExit()           */

                               /* Si ha vuelto de OSintExit() porque no hay una tarea preparada con mayor prioridad */
  ldmfd  sp!, {r4}             /* (7) Restaura de la pila el contexto de la tarea actual y ...                      */
  msr   spsr, r4
  ldmfd  sp!, {r0-r12,lr,pc}^  /* (9) ... retorna a dicha tarea                */

.end


