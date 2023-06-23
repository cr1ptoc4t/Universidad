using namespace std;
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_CARGADOS = 8;
const int MAX_FURGONETAS = 10;

struct tCargados {
	string* id;
	int cont;
};

struct tFurgoneta {
	int cp;
	tCargados lc;
};
typedef tFurgoneta tListaFurgonetas[MAX_FURGONETAS];


bool cargarCodigos(tListaFurgonetas listaFurgonetas);
void mostrarFurgonetas(const tListaFurgonetas listaFurgonetas);
int buscarFurgoneta(const tListaFurgonetas listaFurgonetas, int codigo);
int buscarFurgonetaAux(const tListaFurgonetas listaFurgonetas, int codigo, int inicio, int fin);
void setIdPaquete(tListaFurgonetas listaFurgonetas, int pos, string id_paquete);
void liberarFurgonetas(tListaFurgonetas listaFurgonetas);
int getNumCargados(const tListaFurgonetas& lf, int i);
