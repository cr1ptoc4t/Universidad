/*---------------------------------------------------------------------
**
**  Fichero:
**    ej25.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 25
**
**-------------------------------------------------------------------*/

.global main
.extern _stack
.equ n,6
.equ cc,45
.data
V: .word 3,5,5,7,10,15
.bss
noeliano : .space 4
.text
main :
    la sp,_stack
    la a0,V
    li a1,n
    call Sum45
    mv s0,a0    # s0 resultado de la suma45
    addi s3,zero,1  # s3 = 1
    bne s0,s3,falso # no cumple la condición suma =45
    la t0,V         # t0 =@V
    li t3,n-1   # t3=n-1 (n-1 comparaciones creciente)
    mv t1,zero  # t1=i=0
do:
    slli t2,t1,2    # i *4
    add t2,t2,t0    # t2 = @i
    lw s4,0(t2)
    lw s5,4(t2)
    bgt s4,s5,falso # no cumple y salta
    addi s3,zero,1  # noeliano = true
    la t4,noeliano
    sw s3,0(t4)
    addi t1,t1,1    # i++
    blt t1,t3,do    # i<n
    j fin
falso :
    la t1,noeliano
    sw zero,0(t1)
fin:
    j .


Sum45 :
    #prólogo
    addi sp,sp,-20
    sw s0,0(sp)
    sw s1,4(sp)
    sw s3,8(sp)
    sw s4,12(sp)
    sw s5,16(sp)

    # cuerpo
    mv s0,a0    # s0=@v
    mv s1,a1    # s1=n
    mv s3,zero  # s3 es i
    mv s5,zero  # s5 es acumulador
    # suma del vector
for:
    bge s3,s1,fin_for
    slli s4,s3,2
    add s4,s4,s0
    lw s4,0(s4)
    add s5,s5,s4
    addi s3,s3,1
    j for
# comparación de la suma con 45
fin_for :
    addi s3,zero,45
    bne s5,s3,else
    addi s4,zero,1
    mv a0,s4    # a0 =1 suma es 45
    j fin_sr
else :
    mv a0,zero

    #epílogo
fin_sr :
    lw s0,0(sp)
    lw s1,4(sp)
    lw s3,8(sp)
    lw s4,12(sp)
    lw s5,16(sp)
    addi sp,sp,20
    ret
.end
