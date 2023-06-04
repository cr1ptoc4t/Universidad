using namespace std;
#include <iostream>
#include <fstream>

const int MAX_MEDICOS = 100;
struct tMedico {
	int numcol;
	int numlib;
	int importe;
};

struct tListaMedicos {
	tMedico* lm[MAX_MEDICOS];
	int cont;
};

void inicializarListaMedicos(tListaMedicos& lm);
bool cargaListaMedicos(tListaMedicos& lm);
void muestraListaMedicos(tListaMedicos& lm);
void liberarMedicos(tListaMedicos& lm);
