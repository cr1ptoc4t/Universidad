/*-------------------------------------------------------------------
**
**  Fichero:
**    dma.h  11/5/2014
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Contiene las definiciones de los prototipos de funciones
**    para la inicializaci�n del controlador BDMA0
**
**  Notas de dise�o:
**
**-----------------------------------------------------------------*/

#ifndef __DMA_H__
#define __DMA_H__

#include <common_types.h>

/* 
** Inicializa a 0 los registros de control del canal BDMA0
*/
void bdma0_init( void );

/* 
** Instala, en la tabla de vectores de interrupci�n, la funci�n isr como RTI de interrupciones del canal BDMA0
** Borra interrupciones pendientes por BDMA0
** Desenmascara globalmente las interrupciones y espec�ficamente las interrupciones del canal BDMA0
*/
void bdma0_open( void (*isr)(void) );

/* 
** Enmascara las interrupciones del canal BDMA0
** Desinstala la RTI del canal BDMA0
*/
void bdma0_close( void );

#endif
