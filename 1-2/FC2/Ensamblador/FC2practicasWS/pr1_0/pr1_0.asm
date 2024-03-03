/*---------------------------------------------------------------------
**
**  Fichero:
**    pr1_0.asm  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 1
**
**  Notas de diseño:
**
**-------------------------------------------------------------------*/
.data // secci ón de datos con valor inicial
A: .word 5 // dato ’A’ con valor 5
B: .word 5 // dato ’B’ con valor 8

.bss // secci ón de datos sin valor inicial
MAYOR: .space 4// dato ’MAYOR ’ ocupa 4 bytes

.text // secci ón de có digo

.global main // ’’main ’’ se puede llamar desde fuera

main: // punto de entrada del có digo
	la t2 , A // cargamos en t2 la DIRECCI ÓN de A
	lw t0 , 0( t2) // usamos la direcci ón para cargar el VALOR de A
	la t3 , B // cargamos en t3 la DIRECCI ÓN de B
	lw t1 , 0( t3) // usamos la direcci ón para cargar el VALOR de B
	ble t0 , t1 , mayb // Si t0 (A) <= t1 (B), salto ( condici ón inversa )
// en este caso no hemos saltado (a es mayor )
	la t4 , MAYOR // cargamos en t4 la DIRECCI ÓN de MAYOR
	sw t0 , 0( t4) // guardamos t0 (A) en MAYOR
	j fin // saltamos al final del programa
mayb: // en este caso , b es mayor (o igual )
	la t4 , MAYOR // cargamos en t4 la DIRECCI ÓN de MAYOR
	sw t1 , 0( t4) // guardamos t1 (B) en MAYOR
fin: // fin del programa
	j fin // salto sobre sí mismo , parando el programa
