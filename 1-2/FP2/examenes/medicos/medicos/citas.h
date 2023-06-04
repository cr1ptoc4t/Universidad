using namespace std;
#include <iostream>
#include <string>
#include <fstream>

struct tCita {
	int codMed;
	string codPac;
};

struct tListaCitas {
	tCita* citas;
	int cap;
	int cont;
};

void inicializarListaCitas (tListaCitas& lc);
bool cargaListaCitas(tListaCitas& lc);
void ampliar(tListaCitas& lc);
void liberarCitas(tListaCitas& lc);


void muestraListaCitas(tListaCitas& lc);