/*---------------------------------------------------------------------
**
**  Fichero:
**    ej05.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 5
**
**-------------------------------------------------------------------*/

/*
n = 5;
fant = 1;
f = 1;
i = 2;
while (i <= n) {
    faux = f;
    f = f + fant;
    fant = faux;
    i = i+1;
}
*/


.global main
.bss
n: .space 4
fprev : .space 4
f: .space 4
i: .space 4
faux : .space 4

.text
main:
//declarar
	li t1, 5 		//n=t1
	li t2, 2		//i=t2
	li t3, 1		//fant=t3
	li t4, 1		//f=t4
	li t5, 0		//faux=t5
	blt t1, t2, end

while:
	//cuerpo del bucle
	sw t4, 0(t5)
	add t4, t4, t3
	sw t4, 0(t3)
	addi t2, t2, 1
	bge t1, t2, while

end:
	j .
	.end
