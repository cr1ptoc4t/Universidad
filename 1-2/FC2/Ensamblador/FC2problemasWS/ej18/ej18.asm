/*---------------------------------------------------------------------
**
**  Fichero:
**    ej18.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 18
**
**-------------------------------------------------------------------*/

/*
int fact(int n);
int n=5, rFact;

void main(){
    rFact = fact(n);
    while(1);
}
// La función fact devuelve el
// factorial del entero
// que recibe como argumento
int fact(int num){
    int i,resu;
    if (num > 1){
        resu=num;
        for (i=num-1;i>1;i--)
            resu = resu*i;
    }
    else
        resu=1;
    return(resu);
}
*/

.global main
.extern _stack
.equ n,5
.bss
res: .space 4
.text
main:
    la   sp,_stack
    li   a0,n
    call factorial
    la   t1,res
    sw   a0,0(t1)
fin:
    j .

factorial:
#prologo
	addi sp,sp,-12  # es subrutina hoja,
	sw   s1,0(sp)
	sw   s2,4(sp)
	sw   s3,8(sp)
#cuerpo
    li   s1,1       # s1=f
    mv   s2,a0      # s2=i
    li   s3,1
for:
    ble  s2,s3,fin_for
    mul  s1,s1,s2
    addi s2,s2,-1
    j    for
fin_for:
    mv   a0,s1
#epilogo
    lw   s1,0(sp)
    lw   s2,4(sp)
    lw   s3,8(sp)
    addi sp,sp,12
    jr   ra         # también ret
.end
