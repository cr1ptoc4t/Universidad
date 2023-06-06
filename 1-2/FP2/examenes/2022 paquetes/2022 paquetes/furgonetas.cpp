#include "furgonetas.h"

bool cargarCodigos(tListaFurgonetas listaFurgonetas) {
	ifstream archivo;
	bool ok = false;
	archivo.open("codigo.txt");
	if (archivo.is_open()) {
		ok = true;
		for (int i = 0; i < MAX_FURGONETAS; i++)
		{
			listaFurgonetas[i].cargados.lc = new string[MAX_CARGADOS]; 
			archivo >> listaFurgonetas[i].codigo_postal;

			listaFurgonetas[i].cargados.cont = 0;
		}
		archivo.close();

	}
	return ok;
}

void mostrarFurgonetas(const tListaFurgonetas listaFurgonetas)
{
	for (int f = 0; f < MAX_FURGONETAS; f++)
	{
		cout << "Furgoneta " << f + 1 << " reparte en " <<
			listaFurgonetas[f].codigo_postal;
		if (listaFurgonetas[f].cargados.cont == 0)
			cout << " - Sin paquetes asignados" << endl;
		else
		{
			cout << " - Paquetes asignados: ";
			for (int c = 0; c < listaFurgonetas[f].cargados.cont; c++)
				cout << listaFurgonetas[f].cargados.lc[c] << " ";
			cout << endl;
		}
	}
}
int buscarFurgoneta(const tListaFurgonetas listaFurgonetas, int codigo) {
	return buscarFurgonetaAux(listaFurgonetas,codigo, 0, listaFurgonetas->cargados.cont);

}

int buscarFurgonetaAux(const tListaFurgonetas listaFurgonetas, int codigo, int inicio, int fin) {
	int mitad = (inicio + fin) / 2;
	int pos=-1;
	if (inicio<=fin) {

		if (listaFurgonetas[mitad].codigo_postal == codigo) {
			pos = mitad;
		}
		else if (listaFurgonetas[mitad].codigo_postal > codigo) {
			pos= buscarFurgonetaAux(listaFurgonetas, codigo, mitad+1, fin);
		}
		else {
			pos = buscarFurgonetaAux(listaFurgonetas, codigo, inicio, mitad-1);
		}
	}
	return pos;
}

void setIdPaquete(tListaFurgonetas listaFurgonetas, int pos, string id_paquete) {
	listaFurgonetas[pos].cargados.lc[listaFurgonetas[pos].cargados.cont] = id_paquete;
}

void liberarFurgonetas(tListaFurgonetas listaFurgonetas)
{
	delete[] listaFurgonetas;
}

int getNumCargados(const tListaFurgonetas& lf, int i)
{

	return lf->cargados.cont;
}
