#ifndef furgo_h
#define furgo_h

#include "paquetes.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int MAX_IDS = 8;
const int NUM_FURGONETAS = 10;
typedef struct tCargados {
	string* array_nombres;
	int cont;
};


typedef struct tFurgoneta {
	int cp;
	tCargados listaCargados;

};

typedef struct tListaFurgonetas {
	int cont;
	tFurgoneta listaFurgonetas[NUM_FURGONETAS];
};


bool cargarCodigos(tListaFurgonetas& listaFurgonetas);

void mostrarFurgonetas(const tListaFurgonetas listaFurgonetas);
void cargarPaquetes(tListaFurgonetas listaFurgonetas, tListaPaquetes& listaPaquetes);
void setCargado(tListaPaquetes& lp, int i);
void setIdPaquete(tListaFurgonetas& lf, int pos, string id_paquete);

int buscarFurgoneta(const tListaFurgonetas listaFurgonetas, int codigo);
int getNumCargados(tListaFurgonetas lf, int pos);
string getIdPaquete(tListaPaquetes lp, int i);


#endif