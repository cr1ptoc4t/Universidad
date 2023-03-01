/*---------------------------------------------------------------------
**
**  Fichero:
**    ej11.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 11
**
**-------------------------------------------------------------------*/


/*
#define N 12
int V[N];
V[0] = 0;
V[1] = 1;
for (i=0; i< N-2; i++)
    V[i+2] = V[i+1] + V[i];
*/

.global main
.equ n,12
.bss
v:  .space 48
.text
main:
    la   t1,v       # t1=@base de v
    mv   t0,zero
    sw   t0,0(t1)   # V[0] = 0
    addi t0,t0,1    # i=1
    slli t0,t0,2    # i*4
    add  t0, t0,t1  # t0=@efectiva de i=1
    addi t2,zero,1  # t2=1
    sw   t2,0(t0)   # v[1]=1
    mv   t0,zero    # i=0
    li   t3,n
    add  t3,t3,-2   # t3=N-2 luego t3=10
for:
    bge  t0,t3,fin
    slli t2,t0,2    # i*4
    add  t4,t1,t2
    lw   t5,0(t4)
    addi t4,t4,4
    lw   t6,0(t4)
    add  t6,t6,t5
    addi t4,t4,4
    sw   t6,0(t4)
    addi t0,t0,1
    j   for
fin:
    j .
.end
