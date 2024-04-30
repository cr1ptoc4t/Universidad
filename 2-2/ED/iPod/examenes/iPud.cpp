using namespace std;
#include <iostream>
#include "DiccionarioHash.h"
#include "Lista.h"
class iPud {

	iPud();
	void aniade_cancion(const string& cancion, const string& artista, int duracion);
	void aniade_a_reproduccion(const string& cancion);
	void borra_cancion(const string& cancion);
	void reproduce();
	const string& primera() const;
	int duracion_total() const;
	Lista<string> recientes(int n) const;
private:
	class ECancionNoExiste{};
	class ECancionExiste{};
	class InfoCancion {
	public:
		InfoCancion(const string& artista, int duracion,
			Lista<string>::Iterator& pos_reproduccion,
			Lista<string>::Iterator& pos_reproducidas) {
			this->artista = artista;
			this->duracion = duracion;
			this->pos_reproduccion = pos_reproduccion;
			this->pos_reproducidas = pos_reproducidas;
		}
		string artista;
		int duracion;
		Lista<string>::Iterator pos_reproduccion;
		Lista<string>::Iterator pos_reproducidas;
	};

	DiccionarioHash<string, InfoCancion> _canciones;
	Lista<string> _reproduccion;
	Lista<string> _reproducidas;
	int duracion;

};

void iPud::aniade_cancion(const string& cancion, const string& artista, int duracion) {
	if (_canciones.contiene(cancion))
		throw ECancionExiste();
	else
		_canciones.inserta(cancion, InfoCancion(artista, duracion, _reproduccion.end(), _reproducidas.end()));

}
void iPud::aniade_a_reproduccion(const string& cancion) {
	DiccionarioHash<string, InfoCancion>::Iterator ic = _canciones.busca(cancion);

	if (ic == _canciones.end()) {
		throw ECancionNoExiste();
	}
	else {
		if (ic.valor().pos_reproduccion != _reproduccion.end()) {
			_reproduccion.pon_ppio(cancion);
			ic.valor().pos_reproduccion = _reproduccion.begin();
		}
		duracion += ic.valor().duracion;
	}
}
void iPud::borra_cancion(const string& cancion) {
	DiccionarioHash<string, InfoCancion>::Iterator ic = _canciones.busca(cancion);

	if (ic == _canciones.end()) {
		if (ic.valor().pos_reproduccion != _reproduccion.end()) {
			_reproduccion.eliminar(ic.valor().pos_reproduccion);
		}

		if (ic.valor().pos_reproducidas != _reproducidas.end()) {
			_reproduccion.eliminar(ic.valor().pos_reproducidas);
		}

		_canciones.borra(cancion);

	}
}
void iPud::reproduce() {

}
const string& iPud::primera() const {

}
int iPud::duracion_total() const {

}
Lista<string> iPud::recientes(int n) const {

}
