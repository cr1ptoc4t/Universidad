/*-------------------------------------------------------------------
**
**  Fichero:
**    adc.h  12/3/2015
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Contiene las definiciones de los prototipos de funciones
**    para el acceso al conversor A/D de la placa de prototipado 
**    S3CEV40  
**
**  Notas de dise�o:
**
**-----------------------------------------------------------------*/

#ifndef __ADC_H__
#define __ADC_H__

#include <common_types.h>

/* 
** Idenficadores de los canales del conversor
*/
#define ADC_AIN0 (0) 
#define ADC_AIN1 (1)        
#define ADC_AIN2 (2)        
#define ADC_AIN3 (3)        
#define ADC_AIN4 (4)        
#define ADC_AIN5 (5)        
#define ADC_AIN6 (6)        
#define ADC_AIN7 (7)        

/* 
** Inicializa el conversor A/D
*/
void adc_init( void );

/* 
** Enciende el conversor A/D
*/
void adc_on( void );

/* 
** Apaga el conversor A/D
*/
void adc_off( void );

/*
** Devuelve el estado del conversor A/D
*/
uint8 adc_status( void );

/*
** Devuelve la media de 5 lecturas consecutivas del conversor A/D
*/
uint16 adc_getSample( uint8 ch );

/* 
** Instala, en la tabla de vectores de interrupci�n, la funci�n isr como RTI de interrupciones por fin de conversi�n A/D
** Borra interrupciones pendientes por fin de conversi�n A/D
** Desenmascara globalmente las interrupciones y espec�ficamente las interrupciones por fin de conversi�n A/D
*/
void adc_open( void (*isr)(void) );

/* 
** Enmascara las interrupciones por fin de conversi�n A/D
** Desinstala la RTI por fin de conversi�n A/D
*/
void adc_close( void );

#endif
