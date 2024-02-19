/*---------------------------------------------------------------------
**
**  Fichero:
**    pr2_a.asm  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 2a
**
**  Notas de diseño:
**
** 	# define N 8
** 	# define INT_MAX 65536
**	int V [ N ] = { -7 ,3 , -9 ,8 ,15 , -16 ,0 ,3};
**	int min = INT_MAX ;
**	for ( i = 0; i < N ; i ++) {
**		if ( V [ i ] < min )
**			min = V [ i ];
**	}
**
**-------------------------------------------------------------------*/

.global main
.equ N, 8
.equ INT_MAX, 65536
.data
V:   .word -7,3,-9,8,15,-16,0,3

.bss
min: .space 4

.text
main:
    la s1, min
    li t0, INT_MAX
    sw t0, 0(s1)	//t0=min
	li t3, N		//t3=N
//completar
	li t1, 0		//t1=i
	
for:
	bge t1, t3, end_for
	//slli
	if:
		bge ____, t0, end_if
		addi t0, ______, 0
	end_if:
		
		addi t1, t1, 1
	j for
end_for:
	//guardar en memoria min
end:
	 j end
