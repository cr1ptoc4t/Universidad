/*---------------------------------------------------------------------
**
**  Fichero:
**    ej15.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 15
**
**-------------------------------------------------------------------*/

.global main
.extern _stack  # La @ de inicio de pila esta en el archivo de lincado

.data
a:  .word 10
b:  .word 15

.text
main:
    la sp,_stack    # iniciación de la pila
    la a0,a         # paso de parámetros
    la a1,b
    jal swamp       # jal=call, salto a subrutina
fin:
    j .

swamp:
    #prologo
    addi sp,sp,-8   # es sr hoja, no hay que guardar el
                    # registro de retorno ra

    #cuerpo
    sw s1,0(sp)
    sw s2,4(sp)
    lw s1,0(a0)
    lw s2,0(a1)
    sw s1,0(a1)
    sw s2,0(a0)

    #epilogo
    lw s1,0(sp)
    lw s2,4(sp)
    addi sp,sp,8
    jr ra           # también ret
.end
