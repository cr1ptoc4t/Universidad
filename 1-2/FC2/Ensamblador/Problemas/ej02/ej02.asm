/*---------------------------------------------------------------------
**
**  Fichero:
**    ej02.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 2
**
**-------------------------------------------------------------------*/

/*
if (x >= y) {
    x = x+2;
    y = y-2;
}
*/

.global main

.data
	x: .word 15
	y: .word 7

.text
main:
	//meter en un registro
	la t0, x
	la t1, y

	lw s1, 0(t0)
	lw s2, 0(t0)

	blt s2, s1, fin //3 num de lineas a continuacion
	addi s1, s1, 2
	addi s2, s2, -1
	sw   s1,0(t0)
    sw   s2,0(t1)

fin:
    j .
.end
