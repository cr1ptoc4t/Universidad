#include <iostream>
#include "listapolinomios.h"
using namespace std;
int menu();
void procesarOpcion(tListaPolinomios& lista_polinomios, int opcion);
void leerIndices(int& i, int& j, int max);
int main()
{
	int opcion;
	tListaPolinomios lista_polinomios;
	if (!cargar(lista_polinomios))
		cout << "No se pudo abrir el archivo!" << endl;
	else
	{
		opcion = menu();
		while (opcion != 0)
		{
			procesarOpcion(lista_polinomios, opcion);
			opcion = menu();
		}
	}
	return 0;
}
int menu()
{
	int opcion;
	do
	{
		cout << "1. Mostrar lista polinomios" << endl;
		cout << "2. Sumar dos polinomios" << endl;
		cout << "3. Multiplicar dos polinomios" << endl;
		cout << "0. Salir" << endl;
		cin >> opcion;
	} while (opcion < 0 || opcion > 3);
	return opcion;
}
void procesarOpcion(tListaPolinomios& lista_polinomios, int opcion)
{
	int i, j, max;
	tPolinomio resultado;
	max = numPolinomiosLista(lista_polinomios);
	if (opcion == 1)
		mostrarListaPolinomios(lista_polinomios);
	else if (opcion == 2)
	{
		leerIndices(i, j, max);
		sumarDosPolinomios(lista_polinomios, i, j, resultado);
		mostrarPolinomio(resultado);
		cout << endl;
	}
	else if (opcion == 3)
	{
		leerIndices(i, j, max);
		if (multiplicarDosPolinomios(lista_polinomios, i, j, resultado))
			mostrarPolinomio(resultado);
		else
			cout << "Imposible (resultado no cabe)" << endl;
		cout << endl;
	}
}
void leerIndices(int& i, int& j, int max)
{
	do
	{
		cout << "Introduce dos indices (entre 1 y " << max << ") " << endl;
		cin >> i >> j;
	} while (i < 1 || i > max || j < 1 || j > max);
	i--;
	j--;
}