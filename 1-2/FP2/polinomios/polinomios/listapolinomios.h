#pragma once
#include "polinomio.h"
const int MAX_POLINOMIOS = 10;
typedef struct tListaPolinomios
{
	tPolinomio array_polinomios[MAX_POLINOMIOS];
	int cont = 0;
};
bool cargar(tListaPolinomios& lista);
void mostrarListaPolinomios(const tListaPolinomios& lista);
bool sumarDosPolinomios(const tListaPolinomios& lista_polinomios, int i, int j,
	tPolinomio& resultado);
bool multiplicarDosPolinomios(const tListaPolinomios& lista_polinomios, int i, int j,
	tPolinomio& resultado);
int numPolinomiosLista(const tListaPolinomios& lista_polinomios);