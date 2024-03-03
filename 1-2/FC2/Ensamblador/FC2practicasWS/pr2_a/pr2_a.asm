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
** 	# define INT_MAX 2147483647
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
.equ INT_MAX, 214748
.data
V:   .word -7,3,-9,8,15,-16,0,3

.bss
min: .space 4
.text
main:
	la s1 , min		//s1= dir min
	li t0 , INT_MAX // t0=MAX
	sw t0 , 0( s1)	//min=max=t0
	li t3, N		//t3=N
    la t4, V		//t4 =dir de V
	li t1, 0		//t1=i
	li t5,0

for:
	bge t1, t3, end_for
	slli t2 , t1 , 2 // t2 contiene ahora (t1 << 2) , igual a "t1 *4"
	add t5 , t4 , t2 // t3 contiene "s1 + t1 *4" , justo la direcci ón buscada
	lw a0 , 0(t5)
	if:
		bge a0, t0, end_if //salta si a0(v[i])>=t0(min)
		addi t0, a0, 0

	end_if:
		addi t1, t1, 1
	j for
end_for:
	sw t0, 0(s1)

end:
	 j end




