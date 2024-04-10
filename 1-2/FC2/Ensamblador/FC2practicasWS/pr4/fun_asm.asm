/*---------------------------------------------------------------------
**	Catalina Fullana Mora
**  Fichero:
**    fun_asm.c  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 4
**
**-------------------------------------------------------------------*/

.data
	a: .word 3, 5, -1, 9, 7, 4, 8
	n: .word 7

.global swap
.global merge_sort
.global main
.extern _stack
.data
.bss

.text
merge_sort:
	addi sp, sp, -28
	sw ra, 24(sp) //
	sw s0, 20(sp) //
	sw s1, 16(sp) // PRÓLOGO
	sw s2, 12 (sp) //
	sw s3, 8 (sp) //
	sw s4, 4 (sp) //
	sw s5, 0 (sp)

	addi t1, a2, 1		//t1 = l+1
	bne a3, t1, else	//if r !=l+1-> salta
	mv t2, a0
	mv t3, a1

	li s1,0
	mv s3, a0			//s3 = dir vector
	slli s1, a2, 2   	// desplazamiento
	add a0, s3, s1  	// a0= &a[l]
	lw s2, 0(a0)		// s2 = a[l]

	li s1, 0
	slli s1, a3, 2   	// desplazamiento
	add a1, s3, s1  	// a1= &a[r]
	lw s3, 0(a1)		// s3 = a[r]

	bge s3, s2, end			//if2
	call swap				//swap

	else:
	li t5, 2

	div t4, a3, t5
	add t4, t4, a2
	mv a3, t4			//operaciones l+r/2 en a3
	call merge_sort;

	//operaciones l+r/2 +1 en a2
	div t4, a3, t5
	add t4, t4, a2
	mv a2, t4


	mv a1, t3
	call merge_sort;

	call merge;
end:
	lw ra , 24( sp) 	//
	lw s0 , 20( sp) 	//
	lw s1 , 16( sp) 	//
	lw s2 , 12( sp)		// EPÍLOGO
	lw s3 , 8( sp) 		//
	lw s4 , 4( sp) 		//
	lw s5 , 0( sp) 		//
	addi sp , sp , 28 	//
	ret


swap:
	addi sp, sp, -28
	sw ra, 24(sp) //
	sw s0, 20(sp) //
	sw s1, 16(sp) // PRÓLOGO
	sw s2, 12 (sp) //
	sw s3, 8 (sp) //
	sw s4, 4 (sp) //
	sw s5, 0 (sp)

	mv a0, t2;
	mv a1, a0;
	mv t2, a1;

	lw ra , 24( sp) 	//
	lw s0 , 20( sp) 	//
	lw s1 , 16( sp) 	//
	lw s2 , 12( sp)		// EPÍLOGO
	lw s3 , 8( sp) 		//
	lw s4 , 4( sp) 		//
	lw s5 , 0( sp) 		//
	addi sp , sp , 28 	//
	ret
/*
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
*/

main:
	la a0, a
	lw a1, n
	li a2, 0
	addi a3, a1, -1

	call merge_sort

	//merge_sort(a, n, 0, n - 1);
/*
void merge_sort(int *a, int n, int l, int r)
{
    if (r - l == 1)
    {
        if (a[l] > a[r])
            swap(&a[l], &a[r]);
    }
    else if (l != r)
    {
        merge_sort(a, n, l, (l + r) / 2);
        merge_sort(a, n, ((l + r) / 2) + 1, r);
        merge(a, l, r, n);
    }

    /* no change if l == r */
//}
//*/

.end
