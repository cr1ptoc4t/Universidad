/*---------------------------------------------------------------------
**
**  Fichero:
**    ej02.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 2
**
**-------------------------------------------------------------------*/

/*
if (x >= y) {
    x = x+2;
    y = y-2;
}
*/


/*

.global main

.data
x: .word 5
y: .word 8

.text
main:
	la   t0,x       # pseudo instrucción t0=@x
    la   t1,y       # pseudo instrucción t1=@y
    lw   s1,0(t0)   # s1 = 10
    lw   s2,0(t1)   # s2=5
    blt  s1,s2, end # condición inversa  s1<s2
    addi s1,s1,2    # x=x+2
    addi s2,s2,-2   # y=y-2
    sw   s1,0(t0)
    sw   s2,0(t1)
end:
	j
.end

*/





















/* SOLUCION
*/
.global main        # Hace global la etiqueta "main"
.data               # sección de datos iniciados
x:  .word 10        # declara una variable 32 bits de valor 10
y:  .word 5

.text               # sección de instrucciones
main:
    la   t0,x       # pseudo instrucción t0=@x
    la   t1,y       # pseudo instrucción t1=@y
    lw   s1,0(t0)   # s1 = 10
    lw   s2,0(t1)   # s2=5
    blt  s1,s2, fin # condición inversa  s1<s2
    addi s1,s1,2    # x=x+2
    addi s2,s2,-2   # y=y-2
    sw   s1,0(t0)
    sw   s2,0(t1)
fin:
    j .             # última instrucción que se ejecuta
.end                # directiva que indica que se acaba el fichero

