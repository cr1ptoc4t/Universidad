using namespace std;
#include <iostream>
#include <string>
#include <fstream>

const int CAP_INI = 20;

struct tCita {
	int codmed;
	string codpac;
};

struct tListaCitas {
	tCita* citas;
	int cont;
	int cap;
};


void inicializarListaCitas (tListaCitas& lc);
bool cargaListaCitas(tListaCitas& lc);
void ampliar(tListaCitas& lc);
void liberarCitas(tListaCitas& lc);


void muestraListaCitas(tListaCitas& lc);
int getNumElems(const tListaCitas& listaCitas);
int getCodigoMedico(const tListaCitas& listaCitas, int pos);