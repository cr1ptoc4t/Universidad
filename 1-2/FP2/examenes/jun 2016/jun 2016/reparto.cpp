#include "reparto.h"

void cargar(ifstream& fichero, tReparto& reparto)
{
	fichero >> reparto.contador;
	fichero.ignore();
	for (int i = 0; i < reparto.contador; i++){
		getline(fichero, reparto.lista[i]);

	}
}

bool aparece(const tReparto& reparto, string nombre, int pos) {
	bool encontrado = false;

	if (pos < reparto.contador) {
		if (reparto.lista[pos] == nombre)
			encontrado = true;
		else
			encontrado = aparece(reparto, nombre, pos + 1);
	}

	return encontrado;
}