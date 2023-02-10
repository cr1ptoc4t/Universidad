/*---------------------------------------------------------------------
**
**  Fichero:
**    ej08.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 8
**
**-------------------------------------------------------------------*/

/*
f=g+h+B[4]; //B es un vector de 10 componentes
*/

.global main
.equ n,4
.data
g:  .word 2
h:  .word 3
b:  .word 0,1,2,3,4,5,6,7,8,9
.bss
f:  .space 4
.text
main:
    la   t2,g
    lw   s2, 0(t2)  # g en s2
    la   t3, h
    lw   s3,0(t3)   # h en s3
    la   t4,b       # t4 es la dirección base de e
    li   t5,n       # t5contiene el índice, en este caso 4
    slli t5,t5,2    # se multiplica en índice por 4 porque
                    # el tamaño es palabra (4 bytes)
    add  t5,t5,t4   # @=dirbase+indice*4
    lw   t5,0(t5)   # t5=B[4]
    add  s2,s2,s3   # g+h
    add  s2,s2,t5   # g+h+B[4]
    la   t1,f
    sw   s2,0(t1)
fin:
    j .
.end
