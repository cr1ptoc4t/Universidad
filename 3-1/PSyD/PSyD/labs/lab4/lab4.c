/*-------------------------------------------------------------------
**
**  Fichero:
**    lab4.c  29/1/2021
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Test del laboratorio 4
**
**  Notas de dise�o:
**
**-----------------------------------------------------------------*/

#include <common_types.h>
#include "systemLab4.h"
#include <uart.h>

void main( void )
{
	char   s[256];
	
	sys_init();
	uart0_init();

    /************************************/

	uart0_puts( "\n\nEste programa fue compilado el dia " );
	uart0_puts( __DATE__ );
	uart0_puts( " a las " );
	uart0_puts( __TIME__ );
	uart0_puts( "\n\n" );

    /************************************/

	while( 1 )
    {

        uart0_puts( "Esto es una cadena\n" );
        uart0_putchar( '\n' );
        
        uart0_puts( "Esto es el entero 0:                           " );
        uart0_putint( 0 );
        uart0_putchar( '\n' );
        uart0_puts( "Esto es el entero positivo peque�o 25:         " );
        uart0_putint( 25 );
        uart0_putchar( '\n' );
        uart0_puts( "Esto es el entero positivo grande 987654321:   " );
        uart0_putint( 987654321 );
        uart0_putchar( '\n' );
        uart0_puts( "Esto es el entero negativo peque�o -25:       " );
        uart0_putint( -25 );
        uart0_putchar( '\n' );
        uart0_puts( "Esto es el entero negativo grande -987654321: " );
        uart0_putint( -987654321 );
        uart0_putchar( '\n' );    
     
        uart0_puts( "Esto es el hexadecimal 0:                      " );
        uart0_puthex( 0 );
        uart0_putchar( '\n' );    
        uart0_puts( "Esto es el hexadecimal peque�o AB:             " );
        uart0_puthex( 0xAB );
        uart0_putchar( '\n' );
        uart0_puts( "Esto es el entero positivo grande FEDCBA98:    " );
        uart0_puthex( 0xFEDCBA98 );
        uart0_putchar( '\n' );
        uart0_putchar( '\n' );

        uart0_puts( "Escriba su nombre: " );
        uart0_gets( s );
        uart0_puts( "Este es su nombre: " );
        uart0_puts( s );
        uart0_putchar( '\n' );
        uart0_putchar( '\n' );

        uart0_puts( "Escriba 0: " );
        if( uart0_getint() != 0 )
           uart0_puts( "ERROR en uart0_getint()\n" );
        uart0_puts( "Escriba 25: " );
        if( uart0_getint() != 25 )
           uart0_puts( "ERROR en uart0_getint()\n" );    
        uart0_puts( "Escriba 987654321: " );
        if( uart0_getint() != 987654321 )
           uart0_puts( "ERROR en uart0_getint()\n" );  
        uart0_puts( "Escriba -25: " );
        if( uart0_getint() != -25 )
           uart0_puts( "ERROR en uart0_getint()\n" );    
        uart0_puts( "Escriba -987654321: " );
        if( uart0_getint() != -987654321 )
           uart0_puts( "ERROR en uart0_getint()\n" );  
        uart0_putchar( '\n' );

        uart0_puts( "Escriba 0: " );
        if( uart0_gethex() != 0 )
           uart0_puts( "ERROR en uart0_gethex()\n" );
        uart0_puts( "Escriba AB: " );
        if( uart0_gethex() != 0xAB )
           uart0_puts( "ERROR en uart0_gethex()\n" );    
        uart0_puts( "Escriba ab: " );
        if( uart0_gethex() != 0xAB )
           uart0_puts( "ERROR en uart0_gethex()\n" );   
        uart0_puts( "Escriba FEDCBA98: " );
        if( uart0_gethex() != 0xFEDCBA98 )
           uart0_puts( "ERROR en uart0_gethex()\n" );  
        uart0_puts( "Escriba fedcba98: " );
        if( uart0_gethex() != 0xFEDCBA98 )
           uart0_puts( "ERROR en uart0_gethex()\n" );  
        uart0_putchar( '\n' );

    }

}

