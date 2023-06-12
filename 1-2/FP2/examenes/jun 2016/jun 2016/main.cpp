#include <iostream>
#include "listaPeliculas.h"
using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	tListaPeliculas lista;
	cargar(lista);
	mostrar(lista);
	string actor;
	getline(cin, actor);
	tListaPeliculas lp = filtrarPorActor(lista, actor);
	ordenarPorGenero(lp);
	cout <<endl << "ORDENADO POR GENERO: " << endl << endl;
	mostrar(lp);

	ordenarPorValoracion(lp);
	cout << endl << "ORDENADO POR VALORACION: " << endl << endl;
	mostrar(lp);

	return 0;
}