#pragma once
#include <iostream>
using namespace std;

typedef struct tArray2 {
	string personas[10];
	int cont = 5;
};
typedef struct tArray {
	int elementos[10];
	int cont = 5;
};

void bSort(tArray2& array);
void swap(tArray2& array, int indice1, int indice2);
void printArray2(tArray2 array);
void insertionSort(tArray2& a);
void inserta(tArray2& ar, int a, int b);
void selSort(tArray2& array);

bool busquedaBinaria(tArray a, int e, int& indice);