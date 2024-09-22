/*-----------------------------------------------------------------
**
**  Fichero:
**    lab14-isr-wrappers.asm  24/1/2014
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Implementa wrappers para cada una de las RTI de la aplicaci�n
**    ejecutada bajo el kernel de tiempo real uC/OS-II 
**
**  Notas de dise�o:
**    - El wrapper para timer0 est� implementado en os_cpu_a.asm
**
**---------------------------------------------------------------*/

.include "../os_port/os_cpu_isr_wrapper.asm"

  /* Referencias externas */

  .extern isr_pb         /* void isr_pb( void ) -- RTI por presi�n de un pushbutton */
  
  /* Funciones definidas en este m�dudo */

  .global OS_CPU_isr_pb       /* void OS_CPU_isr_pb( void ) */
  
.section .text

/*
** void OS_CPU_isr_pb( void )
**
** Wrapper + isr_pb
**
*/

OS_CPU_isr_pb:
  OS_CPU_ISR_WRAPPER isr_pb

