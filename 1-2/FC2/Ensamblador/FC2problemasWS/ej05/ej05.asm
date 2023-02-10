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
main :
    la t1,f
    li s1,1         # cargo f en s1 y la guardo
    sw s1,0(t1)
    la t0,i
    li s2,2         # cargo i en s2 y la guardo
    sw s2,0(t0)
    la t0,fprev
    li s3,1         # cargo fprev en s3 y la guardo
    sw s3,0(t0)
    la t0,n
    li s4,5         # cargo n en s4 y la guardo
    sw s4,0(t0)

while :
    bgt s2,s4,end
    mv t2,s1        # t2 es faux , guardo al modificar
    la t3,faux
    sw t2,0(t3)
    add s1,s1,s3        # f = f + fprev
    sw s1,0(t1)         # guardo f al modificarse
    mv s3,t2        # modifico fprev , la guardo
    la t3,fprev
    sw s3,0(t3)
    addi s2,s2,1        # modifico i, la guardo
    la t3,i
    sw s2,0(t3)
    j while
end:
    j .
.end
