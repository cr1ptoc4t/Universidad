/*---------------------------------------------------------------------
**
**  Fichero:
**    ej3.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 3
**
**-------------------------------------------------------------------*/

/*
if (x >= y) {
    x = x+2;
    y = y+2;
}
else {
    x = x-2;
    y = y-2;
}
*/

.global main

.data               # sección de datos iniciados
x:  .word   5
y:  .word   10

.text               # sección de instrucciones
main:
	la t2, x
	lw t0, 0(t2)

	la t3, y
	lw t1, 0(t3)

if:
	blt t0, t1, else
	addi t0, t0, 2
	addi t1, t1, 2
	j end

else:
	addi t0, t0, -2
	addi t1, t1, -2
	j end

end:
	j .
	.end
