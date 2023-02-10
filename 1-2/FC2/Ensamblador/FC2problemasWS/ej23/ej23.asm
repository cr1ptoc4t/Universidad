/*---------------------------------------------------------------------
**
**  Fichero:
**    ej23.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 23
**
**-------------------------------------------------------------------*/

/*
.global main
.equ N,21
.bss
bonito : .space 4

.text
main :
    mv s0,zero  # bonito = false
    li s1,N
    li s2,100000
    mv s3,zero  # s3 es el acumulador
    mv s4,zero  # s4 es el generador de naturales
do:
    add s3,s3,s4
    addi s4,s4,1
    bge s3,s2,fin   # acumulador >=100000
    bgt s3,s1,fin   # acumulador >n
    beq s3,s1,bontrue
    j do

bontrue:
    addi s0,zero,1 # bonito = true

fin:    la t2,bonito
    sw s0,0(t2)
    j .
.end*/

.global main
.extern _stack
.equ N,5
.data
A: .word 3,5,6,15,13    # array de muestra
M: .word 5      # longitud del array de muestra
.bss
cuenta_bonitos: .space 4
.text
main :
    la sp,_stack
    la s1,M
    lw s1,0(s1) # s1 =M
    la s2,A         # s2=@A
    mv s3,zero  # s3 es el índice i del vector A
    mv s4,zero  # s4 es la cuenta de números bonitos
    li s5,1         # s5 guarda un uno para comparaciones
    mv s6,zero  # s6 para construir la dirección de acceso a A
for:
    bge s3,s1,fin_for
    slli s6,s3,2    # s6=s3 *4
    add s6,s6,s2    # @efectiva
    lw a0,0(s6)     # pasa elemento de A como argumento
    call bonito     # llama a la subrutina
    addi s3,s3,1    # i=i+1
    beq a0,s5,exito
    j for
exito:
    addi s4,s4,1    # aumentamos la cuenta de números bonitos
    j for
fin_for :
    la s1,cuenta_bonitos
    sw s4,0(s1)
    j .

bonito : #prólogo
    addi sp,sp,-20
    sw s0,0(sp)
    sw s1,4(sp)
    sw s2,8(sp)
    sw s3,12(sp)
    sw s4,16(sp)

    # cuerpo;
    mv s0,zero  # bonito = false
    li s2,100000
    mv s3,zero  # s3 es el acumulador
    mv s4,zero  # s4 es el generador de naturales
do:
    add s3,s3,s4
    addi s4,s4,1
    bge s3,s2,fin   # acumulador >=100000
    bgt s3,a0,fin   # acumulador >n
    beq s3,a0,bontrue
    j do

bontrue:
    addi s0,zero,1 # bonito = true
    mv a0,s0

fin:    #epílogo
    lw s0,0(sp)
    lw s1,4(sp)
    lw s2,8(sp)
    lw s3,12(sp)
    lw s4,16(sp)
    addi sp,sp,20
    ret
.end
