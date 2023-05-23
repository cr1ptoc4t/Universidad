#include "listapolinomios.h"
#include <fstream>
#include <iostream>
using namespace std;
bool cargar(tListaPolinomios& lista)
{
	ifstream archivo;
	archivo.open("polinomios.txt");
	bool exito = archivo.is_open();
	if (exito)
	{
		archivo >> lista.cont;
		if (lista.cont > MAX_POLINOMIOS)
			exito = false;
		else
			for (int i = 0; i < lista.cont; i++)
				cargarPolinomio(archivo, lista.array_polinomios[i]);
		archivo.close();
	}
	return exito;
}
void mostrarListaPolinomios(const tListaPolinomios& lista)
{
	cout << "Lista de polinomios" << endl;
	cout << "========================================================"
		<< endl << endl;
	for (int i = 0; i < lista.cont; i++)
	{
		cout << "P" << i + 1 << "(x) = ";
		mostrarPolinomio(lista.array_polinomios[i]);
		cout << endl;
	}
}
bool sumarDosPolinomios(const tListaPolinomios& lista_polinomios, int i, int j,
	tPolinomio& resultado)
{
	return sumarDosPolinomios(lista_polinomios.array_polinomios[i],
		lista_polinomios.array_polinomios[j], resultado);
}
bool multiplicarDosPolinomios(const tListaPolinomios& lista_polinomios, int i, int j,
	tPolinomio& resultado)
{
	return multiplicarDosPolinomios(lista_polinomios.array_polinomios[i],
		lista_polinomios.array_polinomios[j], resultado);
}
int numPolinomiosLista(const tListaPolinomios& lista_polinomios)
{
	return lista_polinomios.cont;
}