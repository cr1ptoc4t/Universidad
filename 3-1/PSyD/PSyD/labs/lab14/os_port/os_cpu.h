/*-----------------------------------------------------------------
**
**  Fichero:
**    os_cpu.h  30/1/2014
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Portar el kernel de tiempo real uC/OS-II a la placa de prototipado
**    Embest S3CEV40
**
**  Notas de dise�o:
**    - Implementado seg�n las especificaciones del cap�tulo 13 del
**      libro "MicroC/OS-II. The Real-Time Kernel (2nd. edition)" 
**      de Jean J. Labrosse
**
**---------------------------------------------------------------*/

#ifndef __OS_CPU_H__
#define __OS_CPU_H__

#include "common_types.h"
#include "system.h"

/* 
** Definici�n de tipos de datos usados por el uc/OS-II
*/

typedef boolean BOOLEAN;
typedef uint8   INT8U;
typedef int8    INT8S;
typedef uint16  INT16U;
typedef int16   INT16S;
typedef uint32  INT32U;
typedef int32   INT32S;
typedef float   FP32;
typedef double  FP64;

typedef uint32  OS_STK;
typedef uint32  OS_CPU_SR;

/* 
** Definici�n del m�todo de entrada/salida a secciones cr�ticas
*/

#define OS_CRITICAL_METHOD  2            /* Indica al kernel del tipo de m�todo de acceso a secciones cr�ticas usado */

#if      OS_CRITICAL_METHOD == 1
#error   OS_CRITICAL_METHOD no implementado
#endif

#if      OS_CRITICAL_METHOD == 2
#define OS_ENTER_CRITICAL() INT_DISABLE  /* Entrada a secci�n critica: Desabilita interrupciones previo apilado del CPSR */
#define OS_EXIT_CRITICAL()  INT_ENABLE   /* Salida de secci�n critica: Desapilado del CPSR                               */
#endif


#if      OS_CRITICAL_METHOD == 3
#error   OS_CRITICAL_METHOD no implementado
#endif

/* 
** Miscel�nea
*/
 
#define OS_STK_GROWTH       1            /* Indica al kernel del sentido de crecimiento de la pila: de direcciones ALTAS hacia BAJAS */

#define OS_TASK_SW()        OSCtxSw()    /* Indica al kernel la rutina a usar para realizar cambios de contexto entre tareas */

#endif /*__OS_CPU_H__*/
