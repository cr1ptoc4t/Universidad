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
    la   t0,x       # pseudoinstruccions t0=@x
    la   t1,y       # pseudoinstruccions t1=@y
    lw   s1,0(t0)   # s1=5
    lw   s2, 0(t1)  # s2=10
    blt  s1,s2,else # condición inversa s1<s2
    addi s1,s1,2    # x=x+2
    addi s2,s2,2    # y=y+2
    j    fin_if
else:
    addi s1,s1,-2   # x = x-2;
    addi s2,s2,-2   # y = y-2
fin_if:
    sw   s1,0(t0)
    sw   s2,0(t1)
fin:
    j .
.end
