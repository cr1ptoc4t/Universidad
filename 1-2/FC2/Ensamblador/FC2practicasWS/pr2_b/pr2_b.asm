/*---------------------------------------------------------------------
**
**  Fichero:
**    pr2_b.asm  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 2b
**
**  Notas de diseño:
**
**	# define N 8
**	# define INT_MAX 65536
**	int V [ N ] = { -7 ,3 , -9 ,8 ,15 , -16 ,0 ,3};
**	int W [ N ];
**	int min , index ;
**	for ( j = 0; j < N ; j ++) {
**		min = INT_MAX ;
**		for ( i = 0; i < N ; i ++) {
**			if ( V [ i ] < min ) {
**				min = V [ i ];
**				index = i ;
**			}
**		}
**		W [ j ] = V [ index ];
**		V [ index ] = INT_MAX ;
**	}
**
**-------------------------------------------------------------------*/

.global main
.equ N , 8
.equ INT_MAX , 65536

.data
V: 	 .word -7 ,3 , -9 ,8 ,15 , -16 ,0 ,3
.bss
W: 	 .space N *4
min: .space 4
ind: .space 4

.text
main:
	li t0, 0			//t0=j
	li t1, N			//t1=N(8)
	li t2, INT_MAX		//t2=INT_MAX
	la t3, V			//t3=@V
	la t4, W			//t4=@W
	la t5, min			//t5=@min
	la t6, ind			//t6=@ind

	//i=s2

for_j:
	bge t0, t1, e_for_j
	mv s1, t2
	sw s1, 0(t5)    	//min=INT_MAX
	li s2, 0        	//s2=i=0

	for_i:
	bge s2, t1, e_for_i
	slli s3, s2, 2   	// desplazamiento
	add s3, s3, t3   	// direccion
	lw s3, 0(s3)     	// s3= V[i]

		if:
		bge s3, s1, end_if //salta si s3 = v[i] >= s1 = min
		mv s1, s3
		sw s1, 0(t5)     //min=V[i]
		sw s2, 0(t6)     //ind=i
		end_if:
	addi s2, s2, 1    	//i++
	j for_i

	e_for_i:

	//W[j]=V[index]
	slli s4, t0, 2    //s4=desplazamiento
	add s4, s4, t4    //s4=dirección elemento a colocar
	sw s1, 0(s4)      //W[j]=V[ind]

	//V[index]=INT_MAX
	lw s5, 0(t6)      //s5=ind
	slli s5, s5, 2    //desplazamiento
	add s5, s5, t3    //direccion
	sw t2, 0(s5)      //V[index]=INT_MAX

	//j++ y jump
	addi t0,t0,1
	j for_j
e_for_j:
fin: j .
.end
