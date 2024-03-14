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
**	int mul(int a, int b) {
**	    int res = 0;
**	    while (b > 0) {
**	        res += a;
**	        b--;
**	    }
**	    return res;
**	}
**
**	int dotprod(int[] V, int[] W, int n) {
**	    int acc = 0;
**	    for (int i = 0; i < n; i++) {
**	        acc += mul(V[i], W[i]);
**	    }
**	    return acc;
**	}
**
**	#define N 4
**	int[] A = {3, 5, 1, 9}
**	int[] B = {1, 6, 2, 3}
**
**	int res;
**
**	void main() {
**	    int normA = dotprod(A, A, N);
**	    int normB = dotprod(B, B, N);
**	    if (normA > normB)
**	        res = 0xa;
**	    else
**	        res = 0xb;
**	}
**
**-------------------------------------------------------------------*/
.extern _stack
.global main
.equ N, 4

.data
A: .word 3,5,1,9
B: .word 1,6,2,3
.bss
res: .space 4
.text
main:
	la sp , _stack
	la a0, A		//a0=A
	la a1, A
	li a2, N		//N=a2
	call dot_prod	//llamar a la funcion
	mv t2, a0		//t2=normA

	la a0, B		//a0=B
	la a1, B		//a1=B
	li a2, N
	call dot_prod	//llamar a la funcion
	mv t3, a0		//t3= normB

	if:
	bge t3, t2, else //Salto si normB=t3>=t2=normA
	li t4, 0xa 		//res=0xa
	j end_if
	else:
	li t4, 0xb	//res=0xb
	end_if:
	la t3, res;
	sw t4, 0(t3)

end:
	j .

dot_prod:
	addi sp , sp , -24
	sw ra , 20( sp) //
	sw s0 , 16( sp) //
	sw s1 , 12( sp) // PRÓLOGO
	sw s2 , 8( sp) //
	sw s3 , 4( sp) //
	sw s4 , 0( sp) //

	//a0=V
	//a1=W
	//a2=n

	li s0 , 0 // s0 guarda acc
	li s1 , 0 // s1 guarda i
	mv s2 , a0 // s2 = dir V
	mv s3 , a1 // s3= dir W
	//mv s4 , a2 // s4 guarda n
	li s4, 0

	for:
		bge s1, a2, fin_for

		// a0 = W[i] (dir s3)
		slli s4, s1, 2    //s4=desplazamiento
		add s4, s4, s3    //s4=dirección elemento
		lw a0, 0(s4)

		// a1 = V[i] (dir s2)
		slli s5, s1, 2
		add s5, s5, s2    //s4=dirección elemento a colocar
		lw a1, 0(s5)		//a1 = v[i]

		call mul

		add s0, s0, a0

		addi s1, s1, 1
		j for
	fin_for:
		mv a0 , s0 // colocar acc para devolver
		lw ra , 20( sp) //
		lw s0 , 16( sp) //
		lw s1 , 12( sp) //
		lw s2 , 8( sp) // EPÍLOGO
		lw s3 , 4( sp) //
		lw s4 , 0( sp) //
		addi sp , sp , 24 // ///
		ret // devuelvo control



mul:
	addi sp , sp , -24	//
	sw ra , 20( sp)		//
	sw s0 , 16( sp)		//
	sw s1 , 12( sp)		// PRÓLOGO
	sw s2 , 8( sp)		//
	sw s3 , 4( sp) 		//
	sw s4 , 0( sp)		//
	//a0=a
	//a1=b

	li s0, 0;			//int res = 0;
	while:
		beq zero, a1, end_while
		add s0, s0, a0	//res+=a
		addi a1, a1, -1
		j while

	end_while:
	mv a0 , s0
	lw ra , 20( sp) 	/////
	lw s0 , 16( sp) 	//
	lw s1 , 12( sp) 	//
	lw s2 , 8( sp)		// EPÍ LOGO
	lw s3 , 4( sp) 		//
	lw s4 , 0( sp) 		//
	addi sp , sp , 24 	/////
	ret // devuelvo control

.end
