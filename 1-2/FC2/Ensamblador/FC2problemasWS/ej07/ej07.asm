/*---------------------------------------------------------------------
**
**  Fichero:
**    ej07.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 7
**
**-------------------------------------------------------------------*/

/*
int a=5, b=15, mcd;

while (a!=b){
    if (a>b)
        a=a-b;
    else
        b=b-a;
}
mcd=a;
*/

.global main
.text
a:  .word 5
b:  .word 15

mcd:.space 4

main:
    la   t1,a
    lw   s1,0(t1)       # s1 es a
    la   t2,b
    lw   s2,0(t2)       # s2 es b
while:
    beq  s1,s2, fin_while
    ble  s1,s2, else
    sub  s1,s1,s2       # a=a-b
    j    fin_if
else:
    sub  s2,s2,s1       # b=b-a
fin_if:
    j    while
fin_while:
    la   t3,mcd         # t3 = @mcd
    sw   s1,0(t3)

fin:
    j .
.end
