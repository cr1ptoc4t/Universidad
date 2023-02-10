/*---------------------------------------------------------------------
**
**  Fichero:
**    ej17.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 17
**
**-------------------------------------------------------------------*/

/*
do
    swapped=0
    for i from 0 to N-2 do:
        if V[i] > V[i+1] then
            swap( V[i], V[i+1] )
            swapped = true
        end if
    end for
while swapped
*/


.global main
.extern _stack
.equ n, 10
.data
V: .word 2,5,6,0,9,4,6,5,-10,-1
.text
main :
    la sp,_stack
    li s4,n         # s1 =n
    addi s4,s4,-1
do:
    mv s3,zero  # s3= swapped = false
    mv s5,zero  # t1=i
for:
    bge s5,s4, fin_for
    la t2,V         # t2= @base v
    slli t3,s5,2    # i*4
    add a0,t3,t2    # @i
    lw s1,0(a0)     # V[i]
    addi a1,a0,4    # @i +1
    lw s2,0(a1)     # V[i +1]
if:
    ble s1,s2,fin_if
    call swap
    li s3,1         # swapped = true
fin_if :
    addi s5,s5,1
    j for
fin_for :
    li t4,1
    beq s3,t4,do
fin:
j .

#vamos a utilizar el código de la subrutina
#swap del problema 15 modificado:
#los parámetros de llamada son las direcciones
#de memoria de los valores a intercambiar.

swap :
    # prologo
    addi sp,sp,-8
    sw s1,0(sp)
    sw s2,4(sp)

    # cuerpo
    lw s1,0(a0)
    lw s2,0(a1)
    sw s1,0(a1)
    sw s2,0(a0)

    # epílogo
    lw s1,0(sp)
    lw s2,4(sp)
    addi sp,sp,8
    jr ra       # también ret
.end
