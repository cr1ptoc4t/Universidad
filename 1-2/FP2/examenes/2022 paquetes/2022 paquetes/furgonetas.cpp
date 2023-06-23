#include "furgonetas.h"

bool cargarCodigos(tListaFurgonetas listaFurgonetas) {
	ifstream archivo;
	bool ok = false;
	
	return ok;
}

void mostrarFurgonetas(const tListaFurgonetas listaFurgonetas)
{
	for (int f = 0; f < MAX_FURGONETAS; f++)
	{
		cout << "Furgoneta " << f + 1 << " reparte en " <<
			listaFurgonetas[f].cp;
		if (listaFurgonetas[f].lc.cont == 0)
			cout << " - Sin paquetes asignados" << endl;
		else
		{
			cout << " - Paquetes asignados: ";
			for (int c = 0; c < listaFurgonetas[f].lc.cont; c++)
				cout << listaFurgonetas[f].lc.id[c] << " ";
			cout << endl;
		}
	}
}
int buscarFurgoneta(const tListaFurgonetas listaFurgonetas, int codigo) {
	return 0;
}

int buscarFurgonetaAux(const tListaFurgonetas listaFurgonetas, int codigo, int inicio, int fin) {
	return 0;
}

void setIdPaquete(tListaFurgonetas listaFurgonetas, int pos, string id_paquete) {

}

void liberarFurgonetas(tListaFurgonetas listaFurgonetas)
{

}

int getNumCargados(const tListaFurgonetas& lf, int i)
{
	return 0;
}
