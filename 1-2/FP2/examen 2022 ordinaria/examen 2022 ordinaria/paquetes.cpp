#include "paquetes.h"

bool cargarPaquetes(tListaPaquetes& listaPaquetes) {
	bool cargado= false;
	ifstream archivo;
	archivo.open("paquetes.txt");
	tPaquete paq;

	if (archivo.is_open()) {
		archivo >> listaPaquetes.cont;
		if (listaPaquetes.cont > 50) listaPaquetes.cont = 49;
		for (int i = 0; i < listaPaquetes.cont; i++) {
			archivo >> paq.id;
			archivo >> paq.codigo_postal;
			listaPaquetes.array_paquetes[i] = new tPaquete(paq);
		}
		cargado = true;
		archivo.close();
	}

	return cargado; 
	
}

void mostrarPaquetes(const tListaPaquetes& listaPaquetes) {
	tPaquete p ;
	for (int i = 0; i < listaPaquetes.cont; i++) {
		p = *listaPaquetes.array_paquetes[i];
		cout << p.id << " va a "<< p.codigo_postal << " - cargado: "<< boolAString(p.cargado)<<endl;

	}
}

string boolAString(bool b) {
	string str;
	if (b) str = "SI";
	else str = "NO";
	return str;
}

int getNumPaquetes(const tListaPaquetes lp)
{
	return lp.cont;
}

int getCodigoPostalPaquete(const tListaPaquetes listaPaquetes, int pos)
{
	return listaPaquetes.array_paquetes[pos]->codigo_postal;
}

