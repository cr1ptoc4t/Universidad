
#include "polinomio.h"
#include <fstream>
#include <iostream>
using namespace std;
tPolinomio multiplicarMonomioPorPolinomio(const tMonomio& monomio, const
	tPolinomio& poli);
void copiarResto(const tPolinomio& poli, tPolinomio& resultado, int i, int& cont);
void cargarPolinomio(ifstream& archivo, tPolinomio& poli)
{
	int grado;
	poli.cont = 0;
	archivo >> grado;
	for (int i = 0; i <= grado; i++)
		if (cargarMonomio(archivo, poli.array_monomios[poli.cont], grado - i))
			poli.cont++;
}
void mostrarPolinomio(const tPolinomio& poli)
{
	bool primero = true;
	if (poli.cont == 0)
		cout << "Polinomio nulo";
	else
	{
		for (int i = 0; i < poli.cont; i++)
		{
			escribirMonomio(poli.array_monomios[i], primero);
			primero = false;
		}
	}
	cout << endl;
}
bool sumarDosPolinomios(const tPolinomio& poli1, const tPolinomio& poli2,
	tPolinomio& resultado)
{
	tMonomio monomio;
	int grado1, grado2;
	int cont = 0;
	int i1 = 0, i2 = 0;
	while (i1 < poli1.cont && i2 < poli2.cont && cont <= MAX_GRADO)
	{
		grado1 = gradoMonomio(poli1.array_monomios[i1]);
		grado2 = gradoMonomio(poli2.array_monomios[i2]);
		if (grado1 > grado2)
		{
			resultado.array_monomios[cont] = poli1.array_monomios[i1];
			i1++;
			cont++;
		}
		else if (grado2 > grado1)
		{
			resultado.array_monomios[cont] = poli2.array_monomios[i2];
			i2++;
			cont++;
		}
		else
		{
			monomio = sumaMonomios(poli1.array_monomios[i1],
				poli2.array_monomios[i2]);
			i1++;
			i2++;
			if (coeficiente(monomio) != 0)
			{
				resultado.array_monomios[cont] = monomio;
				cont++;
			}
		}
	}
	copiarResto(poli1, resultado, i1, cont);
	copiarResto(poli2, resultado, i2, cont);
	resultado.cont = cont;
	return cont <= MAX_GRADO;
}
void copiarResto(const tPolinomio& poli, tPolinomio& resultado, int i, int& cont)
{
	while (i < poli.cont && cont <= MAX_GRADO)
	{
		resultado.array_monomios[cont] = poli.array_monomios[i];
		i++;
		cont++;
	}
}
bool multiplicarDosPolinomios(const tPolinomio& poli1, const tPolinomio& poli2,
	tPolinomio& resultado)
{
	tPolinomio aux, res_parcial;
	bool exito = true;
	if (poli1.cont == 0 || poli2.cont == 0)
		resultado.cont = 0;
	else
	{
		res_parcial = multiplicarMonomioPorPolinomio(poli1.array_monomios[0],
			poli2);
		int i = 1;
		while (i < poli1.cont && exito)
		{
			aux = multiplicarMonomioPorPolinomio(poli1.array_monomios[i],
				poli2);
			exito = sumarDosPolinomios(res_parcial, aux, resultado);
			if (exito)
			{
				res_parcial = resultado;
				i++;
			}
		}
	}
	return exito;
}
tPolinomio multiplicarMonomioPorPolinomio(const tMonomio& monomio,
	const tPolinomio& poli)
{
	tPolinomio resultado;
	resultado.cont = poli.cont;
	for (int i = 0; i < poli.cont; i++)
		resultado.array_monomios[i] = multiplicarDosMonomios(monomio,
			poli.array_monomios[i]);
	return resultado;
}
int gradoPolinomio(const tPolinomio& poli)
{
	return gradoMonomio(poli.array_monomios[0]);
}