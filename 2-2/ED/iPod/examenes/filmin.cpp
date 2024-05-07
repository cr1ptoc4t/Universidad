#include "filmin.h"
#include "Lista.h"
#include "DiccionarioHash.h"
#include "Diccionario.h"

#include <iostream>
using namespace std;


class Filmin {
	Filmin();
	Filmin crea();
	void eliminar(const tPelicula& p);
	void an_categoria(tCategoria c,tPelicula p);
	Lista<> lista_por_nombre(tCategoria c);
	Lista< ? > lista_por_categoria();

public:
private:

	typedef string tPelicula;
	typedef string tCategoria;
	typedef Lista<tPelicula>::Iterator tPosPelicula;
	class InfoCategoria {
	public:
		Lista<tPelicula> peliculas;
		Diccionario<tPelicula, tPosPelicula> info_peliculas;

	};

	class EntradaCategoria {
	public:
		tCategoria categoria;
		tPosPelicula pos;
	};

	DiccionarioHash<tCategoria, InfoCategoria> _categorias;
	DiccionarioHash<tPelicula, Lista<tCategoria>> _peliculas;
};


void Filmin::eliminar(const tPelicula& p) {

	DiccionarioHash<tPelicula, Lista<EntradaCategoria>>::Iterator ip =
		_peliculas.busca(p);
	if (ip != _peliculas.end()) {
		Lista<EntradaCategoria> ::Iterator iec = ip.valor().begin();

		while (iec != ip.valor().end()) {
			DiccionarioHash<tCategoria, InfoCategoria> ::ic =
				_categorias.busca(iec.valor().categoria);

			ic.valor().peliculas.eliminar(iec.valor().posicion);
			ic.valor().info_peliculas.borra(p);
		}
		_peliculas.borra(p);
	}
}