#include <iostream>
#include <fstream>
#include "medico.h"
#include "citas.h"
using namespace std;

void mostrarDatos(const tListaMedicos lm, const tListaCitas lc);
void procesarPeticiones(tListaMedicos& lm, tListaCitas& lc);
void liberarMemoria(tListaMedicos& lm, tListaCitas& lc);

int main() {
	tListaMedicos listaMed;
	tListaCitas listaCitas;


	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	inicializarListaMedicos(listaMed);
	inicializarListaCitas(listaCitas);
	if(leerMedicos(listaMed)){
		if (leerCitas(listaCitas)) {
			mostrarDatos(listaMed, listaCitas);

			procesarPeticiones(listaMed, listaCitas);

			liberarMemoria(listaMed, listaCitas);
		}
	}
	
	return 0;
}

void mostrarDatos(const tListaMedicos lm, const tListaCitas lc){
	mostrarListaMedicos(lm);
	mostrarListaCitas(lc);
}


void procesarPeticiones(tListaMedicos& lm, tListaCitas& lc) {
	int total=0;
	int codigo_medico;
	int medico;
	for (int i = 0; i < lc.cont; i++) {
		medico = buscarMedico(lm, lc.citas[i].codigoMedico);
		tMedico* m = lm.array_medicos[medico];
		if (m!=nullptr&& medico!=-1) {
			total += m->tarifa;
			lm.array_medicos[medico]->nCitasLib--;
			if (lm.array_medicos[medico]->nCitasLib - 1 == 0)
				eliminar(lm, m);

		}
		m = nullptr;
	}
	cout << "importe total: "<<total;
}

void liberarMemoria(tListaMedicos& lm, tListaCitas& lc)
{
	liberarMemoriaM(lm);
	liberarMemoriaC(lc);
}
