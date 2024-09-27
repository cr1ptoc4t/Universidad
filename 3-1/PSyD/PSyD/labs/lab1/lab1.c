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

#define SEGS (*(volatile unsigned char *) 0x2140000)

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
                    SEGS = 0x9f; // 0b10011111;
                    break;
                case 0x02:
                    SEGS = 0x31; // 0b10011111;
                    break;
                case 0x03:
                                    SEGS = 0x15; // 0b00010101;
                                    break;
                case 0x04:
                                    SEGS = 0x9c;
                                    break;
                case 0x05:
                                    SEGS = 0x54; // 0b10101011;
                                    break;
                case 0x06:
                                    SEGS = 0x50; // 0b10101111;
                                    break;
                case 0x07:
                                                    SEGS = 0x1f; // 0b00011111;
                                                    break;
                                case 0x08:
                                                    SEGS = 0x10; //	0b00010000;
                                                    break;
                                case 0x09:
                                                    SEGS = 0x1c; // 0b00001100;
                                                    break;
                                case 0x0a:
                                                    SEGS = 0x9f; // 0b10101111;
                                                    break;

                                case 0x0b:
                                                                    SEGS = 0xd0;
                                                                    break;
                                                case 0x0c:
                                                                    SEGS = 0x72; // 0b10101011;
                                                                    break;
                            case 0x0d:
                                 SEGS = 0x91; // 0b10101111;
                                 break;
                           case 0x0e:
                                SEGS = 0x70; // 0b10101011;
                                                 break;
                           case 0x0f:
                        	   	SEGS = 0x78; // 0b10101111;
                                break;
                           default:
                                                                                                	SEGS = 0x00;
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
