#include "medicos.h"

int buscarAux(const tListaMedicos& listaMedicos, int codigo, int ini, int fin);
void ordenar(tListaMedicos& lm);

void inicializarListaMedicos(tListaMedicos& lm)
{
	lm.cont = 0;
	
}

bool cargaListaMedicos(tListaMedicos& lm)
{
	bool b = false;
	ifstream archivo;
	archivo.open("medicos.txt");
	tMedico m;
	if (archivo.is_open()) {
		b = true;
		archivo >> lm.cont;
		for (int i = 0; i < lm.cont; i++) {
			archivo >> m.colegiado;
			archivo>> m.citasLibres >> m.importe;
			lm.lista[i] = new tMedico(m);
			
		}
		ordenar(lm);
		archivo.close();
	}
	
	return b;
}

void muestraListaMedicos(tListaMedicos& lm)
{
	for (int i = 0; i < lm.cont; i++) {
		cout << lm.lista[i]->colegiado<< "  " << lm.lista[i]->citasLibres << "  " << lm.lista[i]->importe << endl;
	}
}

void liberarMedicos(tListaMedicos& lm)
{
	for (int i=0; i<lm.cont; i++)
		delete lm.lista[i];
	
	lm.cont = 0;
}

int buscarPosMedico(const tListaMedicos& lm, tPtrMedico med)
{
	return buscarAux(lm, med->colegiado,0, lm.cont);
}

int getTarifaMedico(tPtrMedico ptr_medico)
{
	return ptr_medico->importe;
}

int getLibresMedico(tPtrMedico ptr_medico)
{
	return ptr_medico->citasLibres;
}

void setLibresMedico(tPtrMedico ptr_medico, int libres)
{
	ptr_medico->citasLibres = libres;
}

tPtrMedico buscar(const tListaMedicos& listaMedicos, int codigo)
{
	tPtrMedico m = new tMedico;
	m->colegiado = codigo;
	int pos = buscarPosMedico(listaMedicos, m);
	if (pos == -1)  m = nullptr;
	else m = listaMedicos.lista[pos];

	return m;
}
void eliminar(tListaMedicos& listaMedicos, tPtrMedico ptr_medico)
{

	int pos = buscarPosMedico(listaMedicos, ptr_medico);
	delete ptr_medico;
	for (int i = pos + 1; i < listaMedicos.cont; i++)
		listaMedicos.lista[i - 1] = listaMedicos.lista[i];
	listaMedicos.cont--;
}

int buscarAux(const tListaMedicos& listaMedicos, int codigo, int ini, int fin)
{
	bool encontrado = false;
	int pos = -1;
	while(ini<=fin&&!encontrado) {
		int mitad = (ini + fin) / 2;

		if (listaMedicos.lista[mitad]->colegiado==codigo) {
			pos = mitad;
			encontrado = true;
		}
		else if (listaMedicos.lista[mitad]->colegiado<codigo) {
			fin = mitad - 1;
		}
		else {
			ini = mitad + 1;
		}

	}
	return pos;
}

void ordenar(tListaMedicos& lm)
{
	bool intercambio = true;
	tPtrMedico aux;
	while (intercambio) {
		intercambio = false;
		for (int i = 1; i < lm.cont; i++) {
			if (lm.lista[i]->colegiado>lm.lista[i-1]->colegiado) {
				intercambio = true;

				//swap
				aux = lm.lista[i];
				lm.lista[i] = lm.lista[i - 1];
				lm.lista[i - 1] = aux;
			}
		}
	}
}
