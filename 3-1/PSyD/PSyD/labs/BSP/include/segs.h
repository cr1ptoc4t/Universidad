/*-------------------------------------------------------------------
**
**  Fichero:
**    segs.h  5/4/2013
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Contiene las definiciones de los prototipos de funciones
**    para el acceso al display 7-segmentos de la placa de
**    prototipado S3CEV40
**
**  Notas de dise�o:
**
**-----------------------------------------------------------------*/

#ifndef __SEGS_H__
#define __SEGS_H__

#include <common_types.h>

#define SEGS_OFF (0xff)

/*
** Inicializa el display 7-segmentos y lo apaga
*/
void segs_init( void );

/*
** Apaga el display 7-segmentos
*/
void segs_off( void );

/*
** Visualiza el n�mero indicado en el display 7-segmentos
*/
void segs_putchar( uint8 n ); 

/*
** Devuelve el n�mero que se est� visualizando en el display 
** 7-segmentos o SEGS_OFF si est� apagado
*/
uint8 segs_status( void );

#endif
