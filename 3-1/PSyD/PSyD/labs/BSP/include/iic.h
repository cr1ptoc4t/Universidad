/*-------------------------------------------------------------------
**
**  Fichero:
**    iic.h  5/3/2015
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Contiene las definiciones de los prototipos de funciones
**    para la comunicaci�n por el bus IIC del chip S3C44BOX 
**
**  Notas de dise�o:
**
**-----------------------------------------------------------------*/

#ifndef __IIC_H__
#define __IIC_H__

#include <common_types.h>

/*
** Modos de funcionamiento del controlador de IIC
*/
#define IIC_Rx      (2)
#define IIC_Tx      (3)

/*
** Macros para indicar si en recepci�n se env�a ACK o no
*/
#define RxACK       (1)
#define NO_RxACK    (0)

/*
** Configura el controlador de IIC seg�n los siguientes par�metros 
**   Interrupciones: habilitadas
**   Transmisi�n/recepci�n: activada
**   Frecuencia de comunicaci�n: 250 KHz
**   Generaci�n de ACK: autom�tica
*/
void iic_init( void );

/*
** Inicia un flujo de transmici�n/recepci�n en la que el microcontrolador act�a como master:
**   Genenera la START condition
**   Env�a la direcci�n del dispositivo esclavo
**   Espera la recepci�n de ACK 
*/
void iic_start( uint8 mode, uint8 byte );

/*
** Actuando el microcontrolador como master:
**   Env�a el byte indicado 
**   Espera la recepci�n de ACK
*/
void iic_putByte( uint8 byte );

/*
** Actuando el microcontrolador como master:
**   Espera la recepci�n de un byte
**   Genera o no ACK 
**   Devuelve el byte recibido
*/
uint8 iic_getByte( uint8 ack );

/*
** Env�a la stop condition y espera los ms indicados para que haga efecto
*/
void iic_stop( uint16 ms );

#endif
