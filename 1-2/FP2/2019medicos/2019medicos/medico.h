#pragma once

using namespace std;
#include <iostream>
#include <string>

const int MAX_MEDICOS = 100;

typedef struct tMedico {
	int nCol;
	int nCitasLib;
	int tarifa;
};

typedef tMedico* arraymed[MAX_MEDICOS];

typedef struct tListaMedicos {
	arraymed array_medicos;
	int cont;
};

void eliminar(tListaMedicos& listaMedicos, tMedico* ptr_medico);
bool leerMedicos(tListaMedicos& lista);
void inicializarListaMedicos(tListaMedicos& listaMed);
void mostrarListaMedicos(const tListaMedicos lm);
void liberarMemoriaM(tListaMedicos& lm);

int buscarMedicoAux (const tListaMedicos lm, int codigo, int inicio, int fin);
int buscarMedico (const tListaMedicos lm, int codigo);