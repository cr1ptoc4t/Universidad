/*---------------------------------------------------------------------
**
**  Fichero:
**    pr3_lab.asm  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 3_lab
**
**-------------------------------------------------------------------*/
.extern _stack
.global main
.equ N, 6
.equ c, 3
.equ d, 5
.equ e, 2
.equ f, 4

.data
A: .word 3, 5, -1, 9, 7, 4
B: .word 1,-6, 2, 3, 5, 8

.bss
resultado: .space 4

.text
main:

	la a0, A
	li a1, c
	li a2, d
	la a3, B
	li a4, e
	li a5, f
	li a6, N

	call comparacion

	la t0, resultado
	sw a0, 0(t0)
end:
	j .


comparacion:
	addi sp , sp , -24	//
	sw ra , 20( sp)		//
	sw s0 , 16( sp)		//
	sw s1 , 12( sp)		// PRÓLOGO
	sw s2 , 8( sp)		//
	sw s3 , 4( sp) 	//
	sw s4 , 0( sp)		//

	li s0, 0 // s0= diff

	//normA = s1
	mv s3, a3
	mv a3, a6
	call dotprodmodif
	mv s1, a0

	//normB = s2
	mv a0, s3
	mv a1, a4
	mv a2, a5
	mv a3, a6
	call dotprodmodif
	mv s2, a0

	sub s0, s1, s2

	mv a0, s0

	lw ra , 20( sp) 	//
	lw s0 , 16( sp) 	//
	lw s1 , 12( sp) 	//
	lw s2 , 8( sp)		// EPÍLOGO
	lw s3 , 4( sp) 		//
	lw s4 , 0(sp)

	addi sp , sp , 24 	//
	ret


dotprodmodif:
	addi sp , sp , -28	//
	sw ra , 24( sp)		//
	sw s0 , 20( sp)		//
	sw s1 , 16( sp)		//
	sw s2 , 12( sp)		// PRÓLOGO
	sw s3 , 8( sp)		//
	sw s4 , 4( sp) 		//
	sw s5 , 0( sp)		//


	li s0, 0			//s0=i
	mv s1, a3
	srl s1, s1, 1		//DIVIDIR S1/2
	li s2, 0			// s2= acc
	mv s5, a0			//s5= dir V
	//mv s6, a1

	for1:
		bge s0, s1, end_for_1

		// V[i] -> a0
		slli s4, s0, 2    //s4=desplazamiento
		add s4, s4, s5    //s4=dirección elemento
		lw a0, 0(s4)

		call mul

		add s2, s2, a0 //acc+=mul
		addi s0, s0, 1	//i++
		j for1
	end_for_1:
	mv s6, a3
	srl s6, s6, 1//dividir a0/2
	mv s1, a3
	mv a1, a2
	for2:
		bge s6, a3, end_for_2

		// V[i] -> a0
		slli s4, s6, 2    //s4=desplazamiento
		add s4, s4, s5    //s4=dirección elemento
		lw a0, 0(s4)

		call mul

		add s2, s2, a0 //acc+=mul
		addi s6, s6, 1	//i++
		j for2
	end_for_2:

	mv a0, s2

	lw ra , 24( sp) 	//
	lw s0 , 20( sp) 	//
	lw s1 , 16( sp) 	//
	lw s2 , 12( sp)		// EPÍLOGO
	lw s3 , 8( sp) 		//
	lw s4 , 4( sp) 		//
	lw s5 , 0( sp) 		//
	addi sp , sp , 28 	//
	ret



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
	li s1, 0;			//int res = 0;
	mv t1, a1;
	while:
		beq zero, t1, end_while
		add s1, s1, a0	//res+=a
		addi t1, t1, -1
		j while
	end_while:
	mv a0 , s1
	lw ra , 20( sp) 	//
	lw s0 , 16( sp) 	//
	lw s1 , 12( sp) 	//
	lw s2 , 8( sp)		// EPÍLOGO
	lw s3 , 4( sp) 		//
	lw s4 , 0( sp) 		//
	addi sp , sp , 24 	//
	ret // devuelvo control

.end
