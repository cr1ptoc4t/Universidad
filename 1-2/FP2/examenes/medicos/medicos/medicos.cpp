#include "medicos.h"

int buscarAux(const tListaMedicos& listaMedicos, int codigo, int ini, int fin);
void ordenar(tListaMedicos& lm);

int buscarAux(const tListaMedicos& listaMedicos, int codigo, int ini, int fin)
{
	int pos = -1;
	bool encontrado = false;
	int mitad;

	while (ini <= fin && !encontrado)
	{
		mitad = (ini + fin) / 2;
		if (listaMedicos.medicos[mitad]->ncol == codigo)
		{
			pos = mitad;
			encontrado = true;
		}
		else if (codigo > listaMedicos.medicos[mitad]->ncol)
			fin = mitad - 1;
		else
			ini = mitad + 1;
	}

	return pos;
}

void ordenar (tListaMedicos& lm) {
	bool cambios = true;
	while (cambios) {
		cambios = false;
		for (int i = 0; i<lm.cont-1; i++) {
			if (lm.medicos[i]->ncol>lm.medicos[i+1]->ncol) {
				swap(lm.medicos[i], lm.medicos[i+1]);
				cambios = true;
			}
		}

	}
}



void inicializarListaMedicos(tListaMedicos& lm)
{
	lm.cont = 0;
}

bool cargaListaMedicos(tListaMedicos& lm)
{
	bool ok = false;
	ifstream archivo;
	archivo.open("medicos.txt");

	if (archivo.is_open()) {
		ok = true;
		archivo >> lm.cont;
		tMedico p;
		for (int i = 0; i < lm.cont; i++) {
			archivo >> p.ncol >> p.ncitas >> p.importe;
			lm.medicos[i] = new tMedico(p);
		}

		archivo.close();
	}

	return ok;
}

void muestraListaMedicos(tListaMedicos& lm)
{
	for (int i = 0; i < lm.cont; i++) {
		cout << lm.medicos[i]->ncol << " " << lm.medicos[i]->ncitas << " " << lm.medicos[i]->importe << endl;
	}
}

void liberarMedicos(tListaMedicos& lm)
{
	for (int i = 0; i < lm.cont; i++) {
		delete lm.medicos[i];
	}

	lm.cont = 0;
}

int buscarPosMedico(const tListaMedicos& lm, int codMed)
{
	return buscarAux(lm,codMed, 0, lm.cont);
}

int getTarifaMedico(tPtrMedico ptr_medico)
{
	return ptr_medico->importe;
}

int getLibresMedico(tPtrMedico ptr_medico)
{
	return ptr_medico->ncitas;
}

void setLibresMedico(tPtrMedico ptr_medico, int libres)
{
	ptr_medico->ncitas = libres;
}

tPtrMedico buscar(const tListaMedicos& listaMedicos, int codigo)
{
	int pos = buscarPosMedico(listaMedicos,codigo);


	tPtrMedico a = nullptr;
	if (pos != -1) {
		a = listaMedicos.medicos[pos];
	}
	return a;
}

void eliminar(tListaMedicos& listaMedicos, tPtrMedico ptr_medico)
{
	int pos = buscarPosMedico(listaMedicos, ptr_medico->ncol);

	for (int i = pos+1; i < listaMedicos.cont;i++) {
		listaMedicos.medicos[i - 1] = listaMedicos.medicos[i];
	}
	listaMedicos.cont--;
}
