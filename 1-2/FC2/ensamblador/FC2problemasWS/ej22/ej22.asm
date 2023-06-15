/*---------------------------------------------------------------------
**
**  Fichero:
**    pr5_asm.asm  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 5
**
**-------------------------------------------------------------------*/

/*
 void Fletcher64( unsigned int data[], int length, unsigned int crc[] ) {
    unsigned int sum1 = 0;
    unsigned int sum2 = 0;
    int index;
    for ( index = 0; index < length; index++ ) {
        sum1 = sum_mod64(sum1, data[index]);
        sum2 = sum_mod64(sum1 , sum2);
    }
    crc[0] = sum1;
    crc[1] = sum2;
}
*/

.global main
.extern _stack
.equ Nv,64
.equ Nw,128

.data
V: .word 0x12340000, 0x00005678
W: .word 0xAB000000, 0x00CD0000, 0x0000EF00, 0x00000011

.bss
crc_v: .space 2*4
crc_w: .space 2*4

.text
main:
    la sp,_stack
    mv fp,zero
    la a0,V         # en a0 1er argumento
    li a1,Nv    # en a1 segundo argumento
    la a2,crc_v     # en a2 tercer argumento
    call Fletcher64

    la a0,W         # en a0 1er argumento
    li a1,Nw    # en a1 segundo argumento
    la a2,crc_w     # en a2 tercer argumento
    call Fletcher64

    j .

Fletcher64:
	#prólogo
    addi sp,sp,-32
    sw s0,0(sp)
    sw s1,4(sp)
    sw s2,8(sp)
    sw s3,12(sp)
    sw s4,16(sp)
    sw s5,20(sp)
    sw s6,24(sp)
    sw ra,28(sp)

    # cuerpo
    mv s1,zero  # s1 guarda sum1
    mv s2,zero  # s2 guarda sum2
    mv s0,a0    # en s0 la dirección del vector
    mv s3,a1    # en s3 la longitud del vector
    mv s4,a2    # en s4 la dirección del vector resultado
    mv s5,zero  # s5 es el índice i del vector A
    mv s6,zero  # s6 para dirección de acceso a A
for:
    bge s5,s3,fin_for
    slli s6,s5,2    # s6=s5*4
    add s6,s6,s0    # @efectiva
    lw s7,0(s6)     # pasa elemento de A como argumento
    mv a0,s1
    mv a1,s7
    call sum_mod64  # llama a la subrutina
    mv s1,a0
    mv a1,s2
    call sum_mod64
    mv s2,a0
    addi s5,s5,1    # i=i+1
    j for
fin_for : mv a0,s1
     mv a1,s2
     sw a0,0(s4)
     addi s4,s4,4
     sw a1,0(s2)

    #epílogo
    lw s0,0(sp)
    lw s1,4(sp)
    lw s2,8(sp)
    lw s3,12(sp)
    lw s4,16(sp)
    lw s5,20(sp)
    lw s6,24(sp)
    lw ra,28(sp)
    addi sp,sp,32
    ret

sum_mod64:
    #prólogo
    addi sp,sp,-12
    sw   s0,0(sp)
    sw   s1,4(sp)
    sw   s2,8(sp)
    #cuerpo
    mv   s0,a0
    mv   s1,a1
    add  s2,s0,s1
    andi s2,s2,63
    mv   a0,s2
    #epílogo
    lw   s0,0(sp)
    lw   s1,4(sp)
    lw   s2,8(sp)
    addi sp,sp,12
    ret
.end


