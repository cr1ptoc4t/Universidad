#include <s3c44b0x.h>

#include <uart.h>

void uart0_init( void )
{
UFCON0 = 0x1;
UMCON0 = 0x0;
ULCON0 =  0x3;
UBRDIV0 = 0x22;
UCON0 = 0x5;
}

void uart0_putchar( char ch )
{
while( UFSTAT0 & (1 << 9) );  // Wait while Tx FIFO is full
UTXH0 = ch;
}        

char uart0_getchar( void )
{
while( !(UFSTAT0 & 0xf));  // Wait while Rx FIFO is empty

return URXH0;  // Read character from the Rx buffer
}

void uart0_puts( char *s )
{
while( *s ) {
        uart0_putchar(*s++);
}
}

void uart0_putint( int32 i )
{
char buf[12];
   char *p = buf + 11;
   int is_negative = 0;

   *p = '\0';

   if (i < 0) {
       is_negative = 1;
       i = -i;
   }

   do {
       *--p = '0' + (i % 10);
       i /= 10;
   } while (i);

   if (is_negative) {
       *--p = '-';
   }

   uart0_puts(p);
}

void uart0_puthex( uint32 i )
{
    char buf[8 + 1];
    char *p = buf + 8;
    uint8 c;

    *p = '\0';

    do {
        c = i & 0xf;
        if( c < 10 )
            *--p = '0' + c;
        else
            *--p = 'a' + c - 10;
        i = i >> 4;
    } while( i );

    uart0_puts( p );
}

void uart0_gets( char *s )
{
char ch;

ch = uart0_getchar();
while(ch!= '\n'){
	*s++ = ch;
	ch = uart0_getchar();
}

*s = '\0';

}

int32 uart0_getint( void )
{
    char buf[12];
    int32 result = 0;
    int is_negative = 0;
    char *p = buf;

    uart0_gets(buf);

    // Verificar si el número es negativo
    if (*p == '-') {
        is_negative = 1;
        p++;  // Saltar el signo negativo
    }


    while (*p) {
        if (*p >= '0' && *p <= '9') {
            result = result * 10 + (*p - '0');
        } else if(!(*p == '\n')){

            return 0;
        }
        p++;
    }

    return is_negative ? -result : result;
}

uint32 uart0_gethex( void )
{
    char buf[9];
    uint32 result = 0;
    char *p = buf;

    uart0_gets(buf);
    while (*p) {

    	 if ((*p >= '0' && *p <= '9')) {
    	        result = result * 16 + (*p - '0');
    	 } else if((*p >= 'a' && *p <= 'f')){
	            result = result * 16 + (*p - 'a' + 10);
    	 }else if(*p >= 'A' && *p <= 'F'){
	            result = result * 16 + (*p - 'A' + 10);
    	 }
    	 else if(!(*p == '\n')){
    	     return 0;
    	 }

       p++;
    }

    return result;
}
