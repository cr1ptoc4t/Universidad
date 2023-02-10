/*---------------------------------------------------------------------
**
**  Fichero:
**    ej20.asm  19/10/2022
**
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para el ejercicio 20
**
**-------------------------------------------------------------------*/

/*
#define N, ...

int Px, Py; //coordenadas x e y del punto P
int V[2N];  //Vector con N puntos V=[x0,y0,x1,y1,...]
int D[N];   //Vector de N distancias

void main(void)
{
    int i;
    for (i=0; i < N; i++)
         D[i] = chevishev(Px, Py, V[2*i], V[2*i + 1]);
}

int chebyshev(x1, y1, x2, y2)
{
    int d1, d2;
    d1 = abs(x1-x2)
    d2 = abs(y1-y2)
    if (d2 > d1)
        d1 = d2;
    return d1;
}
*/


.global main
.extern _stack
.equ n,5    #puntos a testear (2*n componentes)

.data
P: .word 4,5 # coordenadas x e y del punto P
V: .word 1,2,-3,4,5,9,17,-15,20,12 # Vector de N puntos V=[x0,y0,x1,y1,...]
.bss
sol : .space n*4

.text
main :
    la sp,_stack
    mv fp,zero
    mv s1,zero
    li s2,n
    la s3,V

for:
    bge s1,s2,fin_for
    la s6,P
    lw a0,0(s6)
    lw a1,4(s6)
    slli s4,s1,1
    slli s4,s4,2
    add s4,s4,s3
    lw a2,0(s4)
    lw a3,4(s4)
    call chebyshev
    la s5,sol
    slli s4,s1,2
    add s4,s4,s5
    sw a0,0(s4)
    addi s1,s1,1
    j for
fin_for: j .

chebyshev :
    #prólogo
    addi sp,sp,-12
    sw s1,0(sp)
    sw s2,4(sp)
    sw ra,8(sp)

    # cuerpo
d1:
    sub s1,a0,a2 #x1 -x2
    mv a0,s1
    call abs
    mv s1,a0
d2:
    sub s2,a1,a3 #y1 -y2
    mv a0,s2
    call abs
    mv s2,a0
if:
    ble s2,s1,fin_call
    mv s1,s2
fin_call :
    mv a0,s1

# epílogo
    lw s1,0(sp)
    lw s2,4(sp)
    lw ra,8(sp)
    addi sp,sp,12
    ret
abs:
    bgez a0,pos
    sub a0,zero,a0
pos:
    ret
.end
