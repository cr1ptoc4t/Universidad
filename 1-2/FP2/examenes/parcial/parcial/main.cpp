#include <iostream>
#include "estructuras.h"

using namespace std;


int main() {
	tArray2 array;
	array.cont = 5;
	array.personas[0] = "d";
	array.personas[1] = "f";
	array.personas[2] = "a";
	array.personas[3] = "b";

	printArray2(array);
	selSort(array);
	printArray2(array);


	tArray array2;
	array2.cont=6;
	array2.elementos[0] = 1;
	array2.elementos[1] = 5;
	array2.elementos[2] = 9;
	array2.elementos[3] = 14;
	array2.elementos[4] = 18;
	array2.elementos[5] = 29;
	int encontrado=0;
	cout << busquedaBinaria(array2, 2,encontrado)<<" " << encontrado;




}