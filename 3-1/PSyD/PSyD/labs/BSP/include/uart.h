/*-------------------------------------------------------------------
**
**  Fichero:
**    uart.h  25/2/2015
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Contiene las definiciones de los prototipos de funciones
**    para la creaci�n de un canal de comunicaci�n entre la UART0 
**    del chip S3C44BOX y el PC a trav�s de un puerto RS-232.
**
**  Notas de dise�o:
**
**-----------------------------------------------------------------*/

#ifndef __UART_H__
#define __UART_H__

#include <common_types.h>

/*
** Configura la UART para una comunicaci�n seg�n los siguientes par�metros:
**   E/S programada (por pooling)
**   Control manual de flujo
**   FIFOs: activadas
**   Protocolo: normal, sin paridad, 1 bit de stop, 8 bits de datos
**   Velocidad: 115200 baudios
**   Sin tratamiento de errores  
*/
void uart0_init( void );

/*
** Env�a un caracter por la UART
*/
void uart0_putchar( char ch );

/*
** Env�a una cadena de caracteres por la UART
*/
void uart0_puts( char *s );

/*
** Env�a una cadena de caracteres por la UART que representa en decimal al entero que toma como argumento
*/
void uart0_putint( int32 i );

/*
** Env�a una cadena de caracteres por la UART que representa en hexadecimal al entero que toma como argumento
*/
void uart0_puthex( uint32 i );

/*
** Devuelve un caracter recibido por la UART (espera hasta que llegue)
*/
char uart0_getchar( void );

/*
** Forma una cadena con los caracteres recibidos por la UART hasta la recepci�n de '\n'
*/
void uart0_gets( char *s );

/*
** Forma una cadena con los caracteres recibidos por la UART hasta la recepci�n de '\n' y los interpreta en decimal
*/
int32 uart0_getint( void );

/*
** Forma una cadena con los caracteres recibidos por la UART hasta la recepci�n de '\n' y los interpreta en hexadecimal
*/
uint32 uart0_gethex( void );

#endif
