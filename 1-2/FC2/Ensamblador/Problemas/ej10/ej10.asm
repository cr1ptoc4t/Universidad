/*---------------------------------------------------------------------
**
**  Fichero:
**    ej10.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 10
**
**-------------------------------------------------------------------*/

/*
#define N 6
int V[N]={14,1,-2,7,-8,4};
int count = 0;

for (i=0; i<N; i++) {
    if (V[i] > 0)
        count = count+1;
}
*/

.global main
.equ n,6
.data
v:      .word -14,-1,-2,-7,-8,4
.bss
count:  .space 4
.text
main:
    la   t1,v           # t1 tiene la dirección base de v
    li   t2,n           # t2=n
    li   t3,0           # t3 es el índice
    li   s2,0           # s2 =count=0
for:
    bge  t3,t2, fin_for
    slli t5, t3,2       # t5=i*4
    add  t5,t5,t1       # @=i*4+@b
    lw   s1, 0(t5)      # @s1=v[i]
    li   t6,0           # t6=0
if:
    ble  s1,t6, fin_if
    add  s2, s2,1
fin_if:
    addi t3,t3,1
    j    for
fin_for:
    la   t1,count
    sw   s2,0(t1)
end:
    j .
.end
