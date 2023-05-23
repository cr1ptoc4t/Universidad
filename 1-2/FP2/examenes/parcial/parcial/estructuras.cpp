#include <iostream>
#include "estructuras.h"
using namespace std;

void printArray2(tArray2 array)
{
	for (int i = 0; i < 10;i++) {
		cout << array.personas[i] << "   ";
	}
	cout << endl;
}

void bSort(tArray2& array) {
	bool inter = true;
	int i = 0;
	while (i < array.cont - 1 && inter) {
		inter = false;
		for (int j = array.cont - 1; j > i; j--)
			if (array.personas[j] < array.personas[j - 1]) {
				swap(array, j, j - 1);
				inter = true;
			}
		i++;

	}
}

void swap(tArray2& array, int indice1, int indice2)
{
	string temp = array.personas[indice1];
	array.personas[indice1] = array.personas[indice2];
	array.personas[indice2] = temp;
}


void insertionSort(tArray2& a) {
	int j;
	for (int i = 1; i < a.cont; i++) {
		string elemento = a.personas[i];
		j = i - 1;
		while (j>=0&&a.personas[j]>elemento) {
			a.personas[j+1] = a.personas[j];
			j--;
		}
		a.personas[j + 1] = elemento;

	}
}

void inserta(tArray2& ar, int a, int b) {
	string temp = ar.personas[a];
	for (int i = a; i > b;i--) {
		ar.personas[i-1] = ar.personas[i];
	}
	ar.personas[b] = temp;
}


void selSort(tArray2& array) {
	int minimum = 0;
	for (int i = 0; i < array.cont;i++) {
		for (int j = i; j < array.cont;j++) {
			if (array.personas[minimum] > array.personas[j]) {
				minimum = j;
			}
		}
		swap(array, i, minimum);
	}
}

bool busquedaBinaria(tArray a, int e, int& indice)
{
	bool encontrado = false;
	int mitad, ini = 0, fin=a.cont;
	while (!encontrado&&ini<fin) {
		mitad = (ini + fin) / 2;
		if (a.elementos[mitad] == e)
			encontrado = true;
		else if (a.elementos[mitad] < e)
			ini = mitad+1;
		else if (a.elementos[mitad] > e)
			fin = mitad-1;
		else ini = fin + 1;
	}
	indice = mitad;
	return encontrado;
}
