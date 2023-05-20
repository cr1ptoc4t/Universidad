#ifndef paquetes_h
#define paquetes_h

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_PAQUETES = 50;

typedef struct tPaquete {
	string id;
	int codigo_postal;
	bool cargado = false;
};

typedef tPaquete* lp[MAX_PAQUETES];

typedef struct tListaPaquetes {
	lp array_paquetes;
	int cont;
};

bool cargarPaquetes(tListaPaquetes& listaPaquetes);
void mostrarPaquetes(const tListaPaquetes& listaPaquetes);
string boolAString(bool b);
void recogerPaquete(tListaPaquetes& listaPaquetes);

int getNumPaquetes(const tListaPaquetes lf);

int getCodigoPostalPaquete(const tListaPaquetes listaPaquetes, int pos);

#endif