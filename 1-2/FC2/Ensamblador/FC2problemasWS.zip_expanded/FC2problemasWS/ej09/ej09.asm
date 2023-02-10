/*---------------------------------------------------------------------
**
**  Fichero:
**    ej09.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 9
**
**-------------------------------------------------------------------*/


/*
#define N 10
int V[N]={12,1,-2,15,-8,4,-31,8,8,25};
for (i=0; i<N; i++)
    V[i] = V[i]+1;
*/

.global main
.equ n,10
.data
v:  .word 12,1,-2,15,-8,4,-31,8,8,25

.text
main:
    li   s1,n       # s1=n
    mv   s2, zero   # s2 es i
for:
    beq  s2,s1, fin
    la   t1,v       # t1=@base de v
    slli t3,s2,2    # i*4
    add  t2,t1,t3   # t2=@efectiva de v[i]
    lw   s3,0(t2)
    addi s3,s3,1
    sw   s3,0(t2)
    addi s2,s2,1    # i=i+1
    j    for
fin:
    j .
.end
