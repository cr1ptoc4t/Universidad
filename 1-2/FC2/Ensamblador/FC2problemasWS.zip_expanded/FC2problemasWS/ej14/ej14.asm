/*---------------------------------------------------------------------
**
**  Fichero:
**    ej14.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 14
**
**-------------------------------------------------------------------*/

/*
int a=13, b=16;

while (a>10){
    a=a-1;
    b=b+2;
}
if (a<b)
    swap (a, b);
else
    b= a-1;
*/


.global main
.data
a:  .word 13
b:  .word 16

.text
main:
    la   t1,a
    lw   s1,0(t1)
    la   t2,b
    lw   s2,0(t2)
    li   t3,10
while:
    ble  s1,t3,if
    addi s1,s1,-1
    addi s2,s2,2
    j    while
if:
    bge  s1,s2, else
    sw   s1,0(t2)
    sw   s2,0(t1)
    j    fin
else:
    addi s2,s1,-1
    sw   s1,0(t1)
    sw   s2,0(t2)
fin:
    j .
.end
