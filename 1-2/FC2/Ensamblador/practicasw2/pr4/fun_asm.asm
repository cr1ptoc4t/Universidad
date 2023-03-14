/*---------------------------------------------------------------------
**
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


//rellenar con directivas .extern y .global
//con las funciones apropiadas

//int eucl_dist(int * w, int size);
eucl_dist:
    //recibo dirección de W en a0, y tamaño N en a1
    //realizo los cálculos pertinentes
    //devuelvo el resultado en a0

//int guardar(char valor, char * ubicacion);
guardar:
    //recibo el valor en a0, y la dirección destino en a1
    //asegurarse que sólo se guarda UN BYTE!!
