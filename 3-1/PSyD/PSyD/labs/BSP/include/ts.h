/*-------------------------------------------------------------------
**
**  Fichero:
**    ts.h  29/1/2021
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Contiene las definiciones de los prototipos de funciones
**    para el acceso a la touchscreen de la placa de prototipado 
**    S3CEV40  
**
**  Notas de dise�o:
**
**-----------------------------------------------------------------*/

#ifndef __TS_H__
#define __TS_H__

#include <common_types.h>

/* 
** Errorcodes de la touchscreen
*/
#define TS_OK (1)          /* Sin error */
#define TS_FAILURE (0xff)  /* Fallo durante el proceso de scan */
#define TS_TIMEOUT (0xfe)  /* Tiempo de espera sobrepasado */

#define TS_OFF     (1)
#define TS_ON      (0)

/* 
** Inicializa y calibra la touchscreen
*/
void ts_init( void );

/* 
** Enciende el ADC que usa la touchscreen
*/
void ts_on( void );

/* 
** Apaga el ADC que usa la touchscreen
*/
void ts_off( void );

/*
** Devuelve el estado del ADC que usa la touchscreen
*/
uint8 ts_status( void );

/*
** Si la touchscreen est� presionada devuelve TRUE, en otro caso devuelve FALSE
*/
uint8 ts_pressed( void );

/*
** Espera la pulsaci�n de la touchscreen y devuelve la posicion
*/
void ts_getpos( uint16 *x, uint16 *y );

/*
** Espera la pulsaci�n del touchscreen y devuelve la posicion y el intervalo en ms que ha estado pulsada (max. 65535ms)
*/
void ts_getpostime( uint16 *x, uint16 *y, uint16 *ms );

/*
** Espera un m�ximo de ms (no mayor de 6553ms) la pulsaci�n y despulsaci�n de la touchscreen y devuelve la posicion, en caso contrario devuelve TS_TIMEOUT
*/

uint8 ts_timeout_getpos( uint16 *x, uint16 *y, uint16 ms );

/* 
** Instala, en la tabla de vectores de interrupci�n, la funci�n isr como RTI de interrupciones por pulsaci�n de la touchscreen
** Borra interrupciones pendientes por pulsaci�n de la touchscreen
** Desenmascara globalmente las interrupciones y espec�ficamente las interrupciones por pulsaci�n de la touchscreen
*/
void ts_open( void (*isr)(void) );

/* 
** Enmascara las interrupciones por pulsaci�n de la touchscreen
** Desinstala la RTI por pulsaci�n de la touchscreen
*/
void ts_close( void );

#endif
