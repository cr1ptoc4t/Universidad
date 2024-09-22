/*-------------------------------------------------------------------
**
**  Fichero:
**    L3.h  24/5/2013
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Contiene las definiciones de los prototipos de funciones
**    para la comunicaci�n por el interfaz L3 con el chip UDA1341TS 
**
**  Notas de dise�o:
**
**-----------------------------------------------------------------*/

#ifndef __L3_H__
#define __L3_H__

#include <common_types.h>

#define L3_ADDR_MODE (0)
#define L3_DATA_MODE (1)

/*
** Inicializa a 1 las lineas L3CLOCK y L3MODE  
*/
void L3_init( void );

/*
** Env�a un byte por el interfaz L3 en el modo (ADDR/DATA) indicado 
*/
void L3_putByte( uint8 byte, uint8 mode );

#endif
