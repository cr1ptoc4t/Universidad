#pragma once
#include "monomio.h"
#include <fstream>
const int MAX_GRADO = 8;
typedef struct tPolinomio
{
	tMonomio array_monomios[MAX_GRADO + 1];
	int cont = 0;
};
void mostrarPolinomio(const tPolinomio& poli);
void cargarPolinomio(ifstream& archivo, tPolinomio& poli);
bool sumarDosPolinomios(const tPolinomio& poli1, const tPolinomio& poli2,
	tPolinomio& resultado);
bool multiplicarDosPolinomios(const tPolinomio& poli1, const tPolinomio& poli2,
	tPolinomio& resultado);
int gradoPolinomio(const tPolinomio& poli);