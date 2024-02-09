/*---------------------------------------------------------------------
**	CATALINA FULLANA MORA
**  Fichero:
**    pr1_a.asm  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 1a
**
**  Notas de diseño:
**
**	# define N 10
**	int res = 0;
**	for (int i = 0; i < N ; i ++) {
**		res += i ;
**	}
**
**-------------------------------------------------------------------*/

.global main
.data
//defino la constante N
.equ N, 10
//reservo espacio para el resultado
.bss
res:	.space 4

//programa
.text
main:
	li t2, N
	li t3, 0	//t3=res
	li t4, 0	//t4=i
	li t5, 0
for:
	bge t4, t2, end
	add t3, t3, t4
	addi t4, t4, 1
	j for
end_for:
	la t5, res
	sw t3, 0(t5)

end:
    j .
.end


/*
main:
	li t2, N 			//t2=N
	li t3, 0			//t3=i
	li t4, 0			//t4=res
	li t5, 0

for:
	bge t3, t2, fin_for //	Si condicion contraria n<i saltar al final del for
	add t4, t4, t3		//	Instruccion res+=i
	addi t3, t3, 1		//	Incrementar indice
	j for				//	Volver a empezar bucle

fin_for:
	la t5, res     		// Carga la dirección de memoria de "res" en t5
	sw t4, 0(t5)		// Guardar t4(contenido) en la dirección de memoria de "res"
	j end				//	Terminar programa

end:
	j .
.end

*/
