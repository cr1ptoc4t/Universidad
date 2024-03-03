/*---------------------------------------------------------------------
**
**  Fichero:
**    pr1_lab.asm  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 1_lab
**
**  Notas de diseño:
**	propuesta para el laboratorio:
**
**-------------------------------------------------------------------*/
.equ N, 7
.global main

.data
	a: .word 5
	b: .word 3
.bss
	res: .space 4

.text
main:
	li t0, -4 //t0=i
	li t1, 0 //res=t1
	li t2, 2
	la t3, a
	la t4, b
	lw t3, 0(t3) //t3=a
	lw t4, 0(t4) //t4=b
	li t5, N //t5=N
	li t6, 0 //t6 = abs(i)
for:
	bge t0, t5, end_for
	add t6, t0, x0
	if:
		bge t0, x0,end_if
		sub t6, zero, t6
	end_if:
	mul t6, t6, t2
	add t1, t1, t6
	addi t0,t0, 1
	j for
end_for:
	la t2, res
	sw t1, 0(t2)
end:
	j end
.end


