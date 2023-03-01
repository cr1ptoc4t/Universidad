/*---------------------------------------------------------------------
**
**  Fichero:
**    ej19.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 19
**
**-------------------------------------------------------------------*/

/*
int fact(int n);
int n=6, rFact;

void main(){
    rFact = fact(n);
    while(1);
}

// La función fact devuelve el
// factorial del entero
// que recibe como argumento (recursiva)

int fact(int num){
    int resu;
    if (num > 1)
        resu = num*fact(num-1);
    else
        resu=1;
    return(resu);
}
*/

.global main
.extern _stack
.equ n,6
.bss
res:    .space 4
.text
main:
    la   sp,_stack        #inicia la pila
    li   a0,n
    call factorial
    la   t1,res
    sw   a0,0(t1)
fin:
    j .

factorial:
    #prologo
    addi sp,sp,-8
    sw   ra,0(sp)
    sw   s1,4(sp)
    #cuerpo
    bnez a0, else
    li   a0,1
    j    end_if
else:
    bltz a0, end_if
    mv   s1, a0
    addi a0,a0,-1
    call factorial
    mul  s1,s1,a0
end_if:
    mv   a0,s1
    #epílogo
    lw   ra,0(sp)
    lw   s1,4(sp)
    addi sp,sp,8
    ret
.end
