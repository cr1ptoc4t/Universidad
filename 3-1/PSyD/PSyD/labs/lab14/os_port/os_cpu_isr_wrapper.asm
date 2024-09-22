/*-----------------------------------------------------------------
**
**  Fichero:
**    os_cpu_isr_wrapper.asm  20/1/2017
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Implementa una macro que permite a�adir un wrapper a una RTI
**    de una aplicaci�n ejecutada bajo el kernel de tiempo real uC/OS-II 
**
**  Notas de dise�o:
**    - Implementado seg�n las especificaciones del cap�tulo 3 del
**      libro "MicroC/OS-II. The Real-Time Kernel (2nd. edition)" 
**      de Jean J. Labrosse
**    - Asume que interrumpen por IRQ
**
**---------------------------------------------------------------*/

.include "s3c44b0x.asm"
.include "s3cev40.asm"

  /* Referencias externas */

  .extern OSIntNesting   /* INT8U OSIntNesting        -- nivel de anidaci�n de interrupciones                  */
  .extern OSTCBCur       /* OS_TCB *OSTCBCur          -- puntero al TCB de la tarea en ejecuci�n (a suspender) */
  .extern OSIntEnter     /* void OSIntEnter( void )   -- funci�n del kernel                                    */
  .extern OSIntExit      /* void OSIntExit( void )    -- funci�n del kernel                                    */
  
  /* Modos de operaci�n */

  .equ IRQMODE, (0x12)
  .equ SVCMODE, (0x13)

  /* M�scara para desabilitar IRQ y FIQ */

  .equ NOINT,   (0xc0)

/*
**
** Macro para el tratamiento de una interrupci�n gen�rica
**
** IMPORTANTE: La rutina comienza su ejecuci�n en modo IRQ (con SP, LR y CPSR propios)
**
*/

.macro OS_CPU_ISR_WRAPPER isr

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

  ldr  r0, =OSIntNesting        /* (3) Si OSIntNesting == 1 ...                 */
  ldrb r0, [r0]
  cmp  r0, #1
  bne  label\isr
  ldr  r0, =OSTCBCur            /*     ... OSTCBCur->OSTCBStkPtr = SP           */
  ldr  r1, [r0]
  str  sp, [r1]

label\isr:

  msr cpsr_c, #(NOINT|IRQMODE) /* Cambia a modo IRQ (para que la pila IRQ sea usada para tratar la interrupci�n */

  bl  \isr                     /* (6) Llama a la funci�n pasada por argumento a la macro esta funci�n deber�:  */
                               /*     - (4) Borrar interrupci�n pendiente                                      */
                               /*     - (5) Opcionalmente habilitar interrupciones                             */

  msr cpsr_c, #(NOINT|SVCMODE) /* Cambia a modo SVC                            */

  bl  OSIntExit                /* (6) Llama a la funci�n OSIntExit()           */

                               /* Si ha vuelto de OSintExit() porque no hay una tarea preparada con mayor prioridad */
  ldmfd sp!,  {r4}             /* (7) Restaura de la pila el contexto de la tarea actual y ...                      */
  msr   spsr, r4
  ldmfd sp!,  {r0-r12,lr,pc}^  /* (9) ... retorna a dicha tarea                */


.endm



