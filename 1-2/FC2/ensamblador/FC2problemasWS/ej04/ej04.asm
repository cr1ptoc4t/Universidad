/*---------------------------------------------------------------------
**
**  Fichero:
**    ej04.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 4
**
**-------------------------------------------------------------------*/

/*
a = 81;
b = 18;
do {
    a = a-b;
} while (a > 0);
*/

.global main
.bss
a: .space 4
b: .space 4

.text
main :
    la t1,a
    la t2,b
    li s1,81
    sw s1,0(t1)     # a = 81
    li s2,18
    sw s2,0(t2)     # b = 18
do:
    sub s1,s1,s2    # a=a-b
    sw  s1,0(t1)
while :
    bgt s1,zero,do  # condición directa
end:
    j .
.end
