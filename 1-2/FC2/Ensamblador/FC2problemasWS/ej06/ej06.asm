/*---------------------------------------------------------------------
**
**  Fichero:
**    ej06.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 6
**
**-------------------------------------------------------------------*/


/*
for (i=2; i<=n; i++) {
    f=f+f;
}
*/

.global main
.equ n,5
.data
f: .word 2
n: .word 5
.bss
i: .space 4

.text
main :
    la t1,f         # t1=@f
    lw s1,0(t1)     # s1 es f
    la s2,n         # s2 es n
    lw s2,0(s2)
    la t2,i
    li s3,2         # s3 es el i inicializado a 2
    sw s3,0(t2)
for:
    bgt s3,s2,end   # condición inversa
    add s1,s1,s1
    sw s1,0(t1)
    addi s3,s3,1
    sw s3,0(t2)
    j for
end:
    j .
.end
