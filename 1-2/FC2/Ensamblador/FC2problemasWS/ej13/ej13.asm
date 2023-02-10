/*---------------------------------------------------------------------
**
**  Fichero:
**    ej13.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 13
**
**-------------------------------------------------------------------*/

/*
#define N 10

for (i=0; i<N; i++) {
    aux = A[i]+B[N-1-i];
    // if aux is negative, change the sign
    if (aux < 0)
        aux = 0-aux;
    C[i] = aux;
}
*/

.global main
.equ n,10

.data
A:      .word 1,2,3,4,5,6,7,8,9,10
B:      .word 10,9,8,7,6,5,4,3,2,1

.bss
C:      .space 40 #2,4,6,8,10,12,14,16,18,20

.text
main:
    li   t1,n       # t1=n=10
    mv   t2,zero    # t2 es i
for:
    bge  t2,t1, fin_for
    la   t3,A       # t3 =@base A
    slli t4,t2,2    # i*4
    add  t4, t4,t3  # @efectiva de i
    lw   s1,0(t4)   # s1=A[i]
    la   t3,B       # t3 =@base de B
    li   t4,9       # t4=9
    sub  t4,t4,t2   # t4=9-i
    slli t4,t4,2
    add  t4,t4,t3
    lw   s2,0(t4)
    add  s1,s1,s2
    bge  s1,zero, store
    sub  s1,zero,s1 # negativo
store:
    la   t3,C
    slli t4,t2,2    # i*4
    add  t4, t4,t3  # @efectiva de i
    sw   s1,0(t4)
    addi t2,t2,1
    j    for
fin_for:
    j .
.end
