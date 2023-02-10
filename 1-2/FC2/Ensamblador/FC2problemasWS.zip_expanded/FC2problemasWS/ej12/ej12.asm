/*---------------------------------------------------------------------
**
**  Fichero:
**    ej12.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 12
**
**-------------------------------------------------------------------*/

/*
#define N 12
int A[N]={0,1,2,7,-8,4,5,12,11,-2,6,3};
int B[N];
int countB=0;
j=0;
for (i=0; i<N; i++) {
    if (A[i] > 0 && A[i] es par){
        B[j]=A[i];
        j++;
    }
}
countB=j;
*/

.global main
.equ n,12
.data
a:      .word 0,1,2,7,-8,4,5,12,11,-2,6,3
.bss
b:      .space 48
countB: .space 4
.text
main:
    mv   t1,zero    # t1 es j
    mv   t2,zero    # t2 es i
    la   s1,a       # s1 es la @base de a
    la   s2,b       # s2 es la @base de b
    li   s3,n       # s3 contien la constante n
for:
    bge  t2,s3,fin_for
    slli t3,t2,2    # i*4
    add  t3,t3,s1   # @efectiva de i
    lw   t4,0(t3)
    blez t4,fin_if
    andi t6,t4,1    # pone a cero todos los bits menos el
                    # último, que depende de t4
    bnez t6,fin_if
    slli t3,t1,2
    add  t3,t3,s2
    sw   t4,0(t3)   # B[j]=A[i]
    addi t1,t1,1
fin_if:
    addi t2,t2,1
    j    for
fin_for:
    la   t3,countB
    sw   t1,0(t3)   # countB=j
fin:
    j .
.end
