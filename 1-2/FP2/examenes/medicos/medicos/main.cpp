using namespace std;
#include <iostream>
#include "medicos.h"
#include "citas.h"


void procesarPeticiones(tListaCitas& lc, tListaMedicos& lm);

int main() {
	tListaMedicos lm;
	tListaCitas lc;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	inicializarListaCitas(lc);
	inicializarListaMedicos(lm);

	if(cargaListaCitas(lc)&&cargaListaMedicos(lm)){

		muestraListaCitas(lc);
		muestraListaMedicos(lm);

		procesarPeticiones(lc, lm);

		liberarCitas(lc);
		liberarMedicos(lm);
	}
	return 0;
}

void procesarPeticiones(tListaCitas& lc, tListaMedicos& lm) {

}