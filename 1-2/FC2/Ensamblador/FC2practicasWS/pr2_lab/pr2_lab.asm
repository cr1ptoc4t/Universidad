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
.equ N , 10
.equ INT_MAX , 65536
.data
V: 	 .word 21, -5, 3, -10, 4, -23, 35, -10, 41, 2
.bss
W: 	 .space N *4
X: 	 .space N *4
min: .space 4
ind: .space 4

.text
main:
	li t0, 0			//t0=i
	li t1, N			//t1=N(8)
	la t3, V			//t3=@V
	la t4, W			//t4=@W

for:
	bge t0, t1, e_for

	//mv s0, t0 //s0<-t0
	// V[i] -> t2
	slli s4, t0, 2
	add s4, s4, t3
	lw t2, 0(s4)


	sub t2, t2, t0	//t2-= i
	add t2, t2, t1	// t2+= N

	// W[i]=t2
	slli s4, t0, 2    //s4=desplazamiento
	add s4, s4, t4    //s4=dirección elemento a colocar
	sw t2, 0(s4)
	//i++ y jump
	addi t0,t0,1
	j for
e_for:
	li t2, INT_MAX		//t2=INT_MAX
	la t5, min			//t5=@min
	la t6, ind			//t6=@ind
	la t3, X
	li t0,0
for_orden:
	bge t0, t1, e_for_orden
	mv s1, t2
	sw s1, 0(t5)    	//min=INT_MAX
	li s2, 0        	//s2=i=0
	li s4, -5
	li s5, 35
	for_i:
	bge s2, t1, e_for_i
	slli s3, s2, 2   	// desplazamiento
	add s3, s3, t4   	// direccion
	lw s3, 0(s3)     	// s3= W[i]

		if:
		bge s3, s1, end_if //salta si s3 = v[i] >= s1 = min
		bge s4, s3, end_if
		bge s3, s5, end_if
		mv s1, s3
		sw s1, 0(t5)     //min=W[i]
		sw s2, 0(t6)     //ind=i
		end_if:
	addi s2, s2, 1    	//i++
	j for_i

	e_for_i:

	//X[j]=W[index]
	slli s4, t0, 2    //s4=desplazamiento
	add s4, s4, t3    //s4=dirección elemento a colocar
	sw s1, 0(s4)      //X[j]=W[ind]

	//X[index]=INT_MAX
	lw s5, 0(t6)      //s5=ind
	slli s5, s5, 2    //desplazamiento
	add s5, s5, t4    //direccion
	sw t2, 0(s5)      //W[index]=INT_MAX

	//j++ y jump
	addi t0,t0,1
	j for_orden
e_for_orden:



fin: j .
.end
