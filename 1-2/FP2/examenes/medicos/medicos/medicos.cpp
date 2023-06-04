#include "medicos.h"


void inicializarListaMedicos(tListaMedicos& lm)
{
	lm.cont = 0;
}


bool cargaListaMedicos(tListaMedicos& lm) {
	bool ok = false;

	ifstream archivo;
	archivo.open("medicos.txt");
	if (archivo.is_open()) {
		tMedico m;
		int num;
		archivo >> num;
		for (int i = 0; i < num; i++) {
			archivo >> m.numcol>>m.numlib>> m.importe;
			lm.lm[i] = new tMedico (m);
			lm.cont++;
		}

		archivo.close();
		ok = true;
	}

	return ok;
}
void muestraListaMedicos(tListaMedicos& lm) {
	for (int i = 0; i < lm.cont; i++) {
		cout << "el medico " << lm.lm[i]->numcol << ". tiene " << lm.lm[i]->numlib << " horas. con tarifa " << lm.lm[i]->importe << endl;
	}
}

void liberarMedicos(tListaMedicos& lm)
{
	for(int i=0; i<lm.cont; i++)
	 delete lm.lm[i];
	lm.cont = 0;
}
