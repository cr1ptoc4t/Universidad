#ifndef furgo_h
#define furgo_h

#include <string>
using namespace std;

const int MAX_IDS = 8;
const int NUM_FURGONETAS = 10;

struct tCargados
{
	string* array;
	int cont;
};

struct tFurgoneta
{
	int codigo_postal;
	tCargados cargados;
};

typedef tFurgoneta tListaFurgonetas[NUM_FURGONETAS];

bool cargarCodigos(tListaFurgonetas listaFurgonetas);
void mostrarFurgonetas(const tListaFurgonetas listaFurgonetas);
void liberarFurgonetas(tListaFurgonetas listaFurgonetas);
int buscarFurgoneta(const tListaFurgonetas listaFurgonetas, int codigo_postal);
int getNumCargados(const tListaFurgonetas listaFurgonetas, int pos);
void setIdPaquete(tListaFurgonetas listaFurgonetas, int pos, string id_paquete);

#endif