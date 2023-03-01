/*---------------------------------------------------------------------
**
**  Fichero:
**    ej16.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 16
**
**-------------------------------------------------------------------*/

.global main
.extern _stack
.equ n,10
.data
V:  .word 1,0,2,0,3,0,4,0,5,0
.bss
numceros:   .space 4

.text
main:
    la  sp,_stack           #inicia la pila
    la  a0,V                #paso de parámetros a la subrutina
    li  a1,n
    call cuenta0s           #llamada a subrutina
    la  t1,numceros
    sw  a0,0(t1)
fin:
    j .


cuenta0s:
    #prólogo
    addi sp,sp,-24
    sw   s1,(sp)
    sw   s2,4(sp)
    sw   s3,8(sp)
    sw   s4,12(sp)
    sw   s5,16(sp)
    sw   s6,20(sp)

    #cuerpo
    mv   s1,zero     # s1=i
    mv   s2,a1       # s2=n
    mv   s3,a0       # s3=@base v
    mv   s6,zero     # s6 cuenta ceros
for:
    bge  s1,s2, fin_for
    slli s4,s1,2
    add  s4,s4,s3
    lw   s5,0(s4)
    bnez s5, fin_if
    addi s6,s6,1
fin_if:
    addi s1,s1,1
    j    for
fin_for:
    mv   a0,s6      # devolución del valor

#epílogo
    lw   s1,(sp)
    lw   s2,4(sp)
    lw   s3,8(sp)
    lw   s4,12(sp)
    lw   s5,16(sp)
    lw   s6,20(sp)
    addi sp,sp,24
    ret
.end
