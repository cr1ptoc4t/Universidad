/*---------------------------------------------------------------------
**
**  Fichero:
**    pr2_lab.asm  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 2_lab
**
**  Notas de diseño:
**
**-------------------------------------------------------------------*/
.global main
.equ N , 8
.equ INT_MAX , 2147483647

.data
V: 	 .word 7 ,3 , 25 ,4 ,75 , -2 ,1 ,1
.bss
W: 	 .space N *4
C: 	 .space N *4
min: .space 4
ind: .space 4

.text
main:
	li t1, N			//t1=N´
	la s8, ind			//s8=ind=0
	li s8, 0
	la s5, min
	li s5, 0			//min=s5=0
	li t0, INT_MAX		//t0=INT_MAX
	li t2, 0			//t2=i
	li t4, 0			//t4=j
	la t3, V
	la t6, W
	la s7, C


for:
	bge t2, t1, fin_for		//si cc, saltar
	li t4, 0
segundo_for:
	bge t4, t1, fin_segundo_for


if:
	slli t5, t4, 2			//desplazamiento
	add t5, t5, t6			//t5=t5+t3
	lw  s6, 0(t5)     		// @s1=v[i]
	ble s5, s3, fin_if
	mv s5,s3
	mv s8,t4

fin_if:
	addi t4, t4, 1
	j segundo_for

fin_segundo_for:

	slli t5, t2, 2			//desplazamiento
	add t5, t5, s6			//t5=t5+t6
	mv s6, t5
	mv t5, t1

	//operaciones array C
	//s6

	addi t2, t2, 1 			//incrementar indice
	j for


fin_for:

	j end
end:
	j .
	.end
