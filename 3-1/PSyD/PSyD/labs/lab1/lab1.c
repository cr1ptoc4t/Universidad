/*-------------------------------------------------------------------
**
**  Fichero:
**    lab1.c  25/8/2016
**
**    (c) J.M. Mendias
**    Programación de Sistemas y Dispositivos
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Test del laboratorio 1
**
**  Notas de diseño:
**    Presupone que todo el SoC ha sido previamente configurado
**    por el programa residente en ROM que se ejecuta tras reset
**
**-----------------------------------------------------------------*/

#define SEGS (*(volatile unsigned char *) ... )

void main(void) 
{

    unsigned char i;
    unsigned int j;

    SEGS = 0xff;
    while( 1 )
        for( i=0; i<16; i++ )
        {
            for( j=0; j<300000; j++ );
            switch( i ){
                case 0x00:
                    SEGS = 0x12; // 0b00010010;
                    break;
                case 0x01:
                    SEGS = ...; 
                    break;
                ...
                case 0x0f:
                    SEGS = ...; 
                    break;
                default:
                    SEGS = ...;
                    break;
            }                    
        }

}


/*

const unsigned char hex2segs[16] = {0x12, ... };

void main(void) 
{

    unsigned char i;
    unsigned int j;

    SEGS = 0xff;
    while( 1 )
        for( i=0; i<16; i++ )
        {
            for( j=0; j<300000; j++ );
                SEGS = hex2segs[i];
        }

}

*/