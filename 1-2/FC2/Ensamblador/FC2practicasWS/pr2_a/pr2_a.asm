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
.equ INT_MAX, 2147483647
.data
V:   .word -7,3,-9,8,15,-16,0,3

.bss
min: .space 4
.text
main:
	li t3, N		//t3=N
    li t2, INT_MAX  //t0=int_max
    la t4, V		//t4 =dir de V
    la  t6, min    // Carga la dirección de memoria de min en t6
	sw  t2, 0(t6)
	li t1, 0		//t1=i

for:
	bge t1, t3, end_for
	//t5 = V[i]

	//lw  t5, 0(t4)
	slli t0, t1, 2
	add s5, s5, t4
	lw t5, 0(s5)

	if:
		bge t5, t2, end_if
		addi t0, t5, 0
	end_if:
		addi t1, t1, 1
	j for
end_for:
	//guardar en memoria min
end:
	 j end



/*
main:
	li t1, N		//t1=N
    la s5, min		//s5=min
    li s5, 0
    li t0, INT_MAX	//t0=INT_MAX
    sw t0, 0(s5)
    li t2, 0		//t2=i
    //lw s1, V
	la t3, V
for:
	bge t2, t1, fin_for		//si cc, saltar
	slli t5, t2, 2			//desplazamiento
	add t5, t5, t3		//t5=t5+t3
	lw  s3, 0(t5)     	// @s1=v[i]

if:
	ble s5, s3, fin_if
	mv s5,s3
	//sw s3, 0 (s5)		//almacenar el valor de s3 en min

	//min toma valor de s3

fin_if:
	addi t2, t2, 1 			//incrementar indice
	j for

fin_for:
	la s3, min
	la s5, min //resultado en s5
	j end

end:
	j .
	.end
*/
