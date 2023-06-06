#include "citas.h"

void inicializarListaCitas(tListaCitas& lc)
{
	lc.cap = 20;
	lc.cont = 0;
	lc.citas = new tCita [lc.cap];
}

bool cargaListaCitas(tListaCitas& lc) {
	ifstream archivo;
	archivo.open("citas.txt");
	bool ok = false;
	if (archivo.is_open()) {
		int num;
		archivo >> num;

		for (int i = 0; i < num; i++) {
			if (i >= lc.cap)
				ampliar(lc);
			archivo >> lc.citas[i].codMed >> lc.citas[i].codPac;
			lc.cont++;
		}
		
		ok = true;
	}

	return ok;
}

void ampliar(tListaCitas& lc)
{
	tCita* aux = new tCita[lc.cap+5];

	for (int i = 0; i < lc.cont;i++)
		aux[i] = lc.citas[i];

	delete[] lc.citas;
	lc.citas = aux;
	lc.cap += 5;
	aux = nullptr;
}

void liberarCitas(tListaCitas& lc)
{
	lc.cap = 0;
	delete [] lc.citas;
	lc.citas = nullptr;
	lc.cont = 0;
}

void muestraListaCitas(tListaCitas& lc) {
	for (int i = 0; i < lc.cont; i++) {
		cout<<"el paciente " << lc.citas[i].codPac << " pide hora con el medico " << lc.citas[i].codMed << endl;
	}
}