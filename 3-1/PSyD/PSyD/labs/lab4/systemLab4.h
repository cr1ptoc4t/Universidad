/*-------------------------------------------------------------------
**
**  Fichero:
**    systemLab4.h  26/8/2016
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Contiene las definiciones de los prototipos de las funciones
**    para la inicializaci�n del sistema
**
**  Notas de dise�o:
**    Versi�n reducida orientada al desarrollo del lab4
**
**-----------------------------------------------------------------*/

#ifndef __SYSTEM_H__
#define __SYSTEM_H__

/*
**  Inicializa el sistema (versi�n lab4)
**    Deshabilita el watchdog
**    Enmascara todas las interrupciones
**    Configura el gestor de reloj
**      Tiempo de estabilizaci�n del PLL m�ximo
**      MCLK = 64 MHz
**      MCLK_SLOW = 500 KHz
**      Modo de funcionamiento normal
**      Reloj distribuido a todos los controladores
**    Arbitro de bus con prioridades por defecto
**    Cache deshabilitada
**    Configura los puertos de E/S
*/
void sys_init( void );

#endif
