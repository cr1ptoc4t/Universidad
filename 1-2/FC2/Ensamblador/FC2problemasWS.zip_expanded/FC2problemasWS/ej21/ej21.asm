/*---------------------------------------------------------------------
**
**  Fichero:
**    ej21.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 21
**
**-------------------------------------------------------------------*/

/*
#define N 4
int A[3*N] = {una lista de 3*N valores},
int B[N];
int i, j=0;
void main (void)
    {
        for (i=0; i<N; i++){
        	B[i] = sum_mod_32(A, j, 3);
    	j=j+3
	}
}
sum_mod_32 (int A[ ], int j, int len)
{
    int i, sum=0;
    for (i=0; i<len; i++)
        sum = sum + A[j+i];
    sum=mod_power_of_2(sum,5);
    return sum;
}
*/


.global main
.extern _stack
.equ n,4
.data
A: .word 10,11,12,10,11,12,10,11,12,10,11,12
.bss
B: .space 16 # también se puede .zero

.text
main :
    la sp,_stack
    mv fp,zero
    la s1,A         # s1 tiene la @base de A
    la s2,B         # s2 @base de B
    mv s3,zero  # s3 es i
    mv s4,zero  # s4 es j
    li s5,n         # s5=n
for:
    bge s3,s5,fin_for
    la a0,A         # pasa @base A como argumento
    mv a1,s4    # pasa j como argumento
    li a2,3         # pasa 3 como argumento
    call sum_mod    # llama a la subrutina
    la s6,B         # s6 @base de B
    slli t0,s3,2    # t0=s3 *4
    add t0,t0,s6    # @efectiva
    sw a0,0(t0)
    addi s4,s4,3    # j=j+3
    addi s3,s3,1    # i=i+1
    j for
fin_for :
    j .

sum_mod : #prólogo
    addi sp,sp,-20
    sw s0,0(sp)
    sw s1,4(sp)
    sw s2,8(sp)
    sw s3,12(sp)
    sw s4,16(sp)

    # cuerpo; a0 es @base de A; a1 es j; a2 es 3
    mv s0,zero  # s0 es el índice del for2
    mv s4,zero  # inicializa el acumulador
for2 :
    bge s0,a2,fin_for2 # compara con a2 =3
    slli s1,a1,2    # a1 es j=>j*4
    add s2,s1,a0    # s2 = @efectiva =j*4+ @base
    lw s3,0(s2)
    add s4,s4,s3    # s4 acumulador
    addi s0,s0,1    # indice +1
    addi a1,a1,1    # j+1
    j for2
fin_for2 :
    andi s4,s4,31
    mv a0,s4
    #epílogo
    lw s0,0(sp)
    lw s1,4(sp)
    lw s2,8(sp)
    lw s3,12(sp)
    lw s4,16(sp)
    addi sp,sp,20
    ret
.end
