/*---------------------------------------------------------------------
** Catalina Fullana Mora
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

//defino la constante N
.equ N, 10
//reservo espacio para el resultado
.bss
	res: 	.space 4
//programa
.text

.global main


main:
	li t0, 0  	//	res=t0
	li t1, 0 	//	t1=i
	li t2, 0
	li t3, N	//	t3=N
for:
	bge t1, t3, end_for
	add t0, t0, t1
	addi t1, t1, 1
	j for

end_for:
	la t2, res
	sw t0, 0(t2)
end:
	j end

	.end
