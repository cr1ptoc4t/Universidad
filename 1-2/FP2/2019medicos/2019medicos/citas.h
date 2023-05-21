#pragma once
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

const int MAX_CITAS = 10;
typedef struct tCita {
	int codigoMedico;
	string paciente;
};


typedef struct tListaCitas {
	tCita* citas;
	int cont;
	int capacidad;
};

void mostrarListaCitas(const tListaCitas lm);
void inicializarListaCitas(tListaCitas& listaCitas);
void ampliar(tListaCitas& listaCitas);
bool leerCitas(tListaCitas& lista);

void liberarMemoriaC(tListaCitas& lc);