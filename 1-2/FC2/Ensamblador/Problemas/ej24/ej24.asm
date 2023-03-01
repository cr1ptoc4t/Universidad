/*---------------------------------------------------------------------
**
**  Fichero:
**    ej24.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 24
**
**-------------------------------------------------------------------*/

 .global main
.extern _stack
.equ n,6
.data
V:      .word 2,1,10,2,2,3
.bss
melcho: .space 4
.text
main:
    la   sp,_stack
    mv   fp,zero
    la   a0,V
    li   a1,n
    call sumavector
    mv   s1,a0    #s1 contiene el sumatorio del vector
    la   t1,V     #s1=@V
    mv   t2,zero  #t2=i
    li   t3,n
do:
    slli t3,t2,2
    add  t3,t3,t1
    lw   s2,0(t3)
    slli s2,s2,1
    beq  s2,s1,meltrue
    addi t2,t2,1        #i++
    bge  t2,t3, fin
    j    do
meltrue:
    addi s1,zero,1
    la   t1,melcho
    sw   s1, 0(t1)
fin:
    j .

sumavector:
    #prólogo
    addi sp,sp,-12
    sw   s0,0(sp)
    sw   s1,4(sp)
    sw   s2,8(sp)
    #cuerpo
    mv   s0,a0        #s0=@V
    mv   s1,a1        #s1=n
    mv   s2,zero  #s2=i
    mv   s5,zero  #acumulador
for:
    bge  s2,s1,fin_for
    slli s3,s2,2
    add  s3,s3,s0
    lw   s4,0(s3)
    add  s5,s5,s4
    addi s2,s2,1
    j    for
fin_for:
    mv   a0,s5
    #epílogo
    lw   s0,0(sp)
    lw   s1,4(sp)
    lw   s2,8(sp)
    addi sp,sp,12
    ret
.end
