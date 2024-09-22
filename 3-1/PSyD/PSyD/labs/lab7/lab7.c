/*-------------------------------------------------------------------
**
**  Fichero:
**    lab7.c  20/10/2022
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Test del laboratorio 7
**
**  Notas de dise�o:
**
**-----------------------------------------------------------------*/

#include <s3c44b0x.h>
#include <common_types.h>
#include <system.h>
#include <lcd.h>

/*
** Direcciones en donde se encuentran cargados los BMP tras la ejecucion en
** la consola del depurador los comandos:
**   cd <ruta>
**   source load_bmp.txt
*/

#define ARBOL      ((uint8 *)0x0c210000)
#define PADRINO    ((uint8 *)0x0c220000)
#define PICACHU    ((uint8 *)0x0c230000)
#define HARRY      ((uint8 *)0x0c240000)
#define CHAPLIN    ((uint8 *)0x0c250000)
#define PULP       ((uint8 *)0x0c260000)
#define MAPA       ((uint8 *)0x0c270000)

void one_second_loop( void );

void main( void )
{
    uint16 x, y;
    uint8 backup[LCD_WIDTH*LCD_HEIGHT], *p;
    
    sys_init();
    lcd_init();
    
    lcd_clear();
    lcd_on();
    
    while( 1 )
    {
        /************************************/

        lcd_draw_box( 10, 10, 310, 230, BLACK, 5 );

        /************************************/

        lcd_puts( 20, 16, BLACK, "ABCDEFGHIJKLMN�OPQRSTUVWXYZ" );
        lcd_puts( 20, 32, BLACK, "abcdefghijklmn�opqrstuvwxyz" );
        lcd_puts( 20, 48, BLACK, "0123456789!$%&/()=^*+{}-.,;: " );
        lcd_putint( 20, 64, BLACK, 1234567890 );
        lcd_puthex( 108, 64, BLACK, 0xabcdef );

        /************************************/

        lcd_puts_x2( 20, 80, BLACK, "ABCDEFGHIJKLMN�OP" );
        lcd_puts_x2( 20, 112, BLACK, "abcdefghijklmn�op" );
        lcd_puts_x2( 20, 144, BLACK, "0123456789!$%&/()" );
        lcd_putint_x2( 20, 176, BLACK, 1234567890 );
        lcd_puthex_x2( 196, 176, BLACK, 0xabcdef );

        /************************************/

        one_second_loop();

        p = backup;
        for( x=0; x<LCD_WIDTH; x++ )
            for( y=0; y<LCD_HEIGHT; y++, p++ )
                *p = lcd_getpixel( x, y );

        lcd_clear();

        p = backup;
        for( x=0; x<LCD_WIDTH; x++ )
            for( y=0; y<LCD_HEIGHT; y++, p++ )
                lcd_putpixel( x, y, *p );
            
        /************************************/

        one_second_loop();
        lcd_putWallpaper( ARBOL );
        one_second_loop();
        lcd_putWallpaper( PADRINO );
        one_second_loop();
        lcd_putWallpaper( PICACHU );
        one_second_loop();
        lcd_putWallpaper( HARRY );
        one_second_loop();
        lcd_putWallpaper( CHAPLIN );
        one_second_loop();
        lcd_putWallpaper( PULP );
        one_second_loop();
        lcd_putWallpaper( MAPA );

        /************************************/

        one_second_loop();
        lcd_clear();
    }
}

void one_second_loop( void )
{
    uint32 i;

    for( i=591436; i; i-- );
}
