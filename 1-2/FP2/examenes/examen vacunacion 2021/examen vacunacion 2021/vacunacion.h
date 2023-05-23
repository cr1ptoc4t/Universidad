#pragma once
#include <iostream>
#include <fstream>
using namespace std;
typedef struct tVacuna{
	string nomVacuna;

};

typedef struct tListaVacunas {
	string nomVacuna;

};

void vacunar(ifstream& archivoIn, ofstream& archivoOut, tListaVacunas& l);
void inicializarListaVacunas(tListaVacunas& l);
void liberarListaVacunas(tListaVacunas& l);
void cargarVacunasCentros(ifstream& archivo, tListaVacunas& l);
void mostrar(tListaVacunas& l);