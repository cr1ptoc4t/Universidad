#include "CarnetPorPuntos.h"


/**
Implementa aquí los métodos de las clases adicionales
*/

CarnetPorPuntos:: CarnetPorPuntos() {
	
}

/**
Debes completar la implementación de las operaciones de CarnetPorPuntos,
y justificar la complejidad de las mismas.
*/

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 O(1)
*/
void CarnetPorPuntos::nuevo(const string& dni) {
	if (_conductores.contiene(dni))
		throw EConductorDuplicado();

	_conductores.inserta(dni, 15);
	_conductores_ord.inserta(dni, 15);
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 O(log n)
*/
void CarnetPorPuntos::quitar(const string& dni, unsigned int puntos) {
	DiccionarioHash<string, unsigned int>::Iterator c = _conductores.busca(dni);
	Diccionario<string, unsigned int>::Iterator d = _conductores_ord.busca(dni);
	if (c == _conductores.end())
		throw EConductorNoExiste();
	
	c.valor() -= puntos;
	if (c.valor() < 0) c.valor() = 0;
	
	d.valor() -= puntos;
	if (d.valor() < 0) d.valor() = 0;


	int p = c.valor();
	_conductores.borra(dni);
	_conductores.inserta(dni, p);

}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 o(log n)
*/
void CarnetPorPuntos::recuperar(const string& dni, unsigned int puntos) {
	DiccionarioHash<string, unsigned int>::Iterator c = _conductores.busca(dni);
	Diccionario<string, unsigned int>::Iterator d = _conductores_ord.busca(dni);

	if (c == _conductores.end())
		throw EConductorNoExiste();

	c.valor() += puntos;
	if (c.valor() >15) c.valor() = 15;
	d.valor() += puntos;
	if (d.valor() >15) d.valor() = 15;

	
	int p = c.valor();
	_conductores.borra(dni);
	_conductores.inserta(dni, p);
	
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 o(log n)
*/
unsigned int CarnetPorPuntos::consultar(const string& dni) const {
	DiccionarioHash<string, unsigned int>::ConstIterator c = _conductores.cbusca(dni);

	if (c == _conductores.cend())
		throw EConductorNoExiste();

	return c.valor();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 O(n)
*/
unsigned int CarnetPorPuntos::cuantos_con_puntos(unsigned int puntos) const {
	if (puntos < 0 || puntos>15)
		throw EPuntosNoValidos();

	DiccionarioHash<string, unsigned int>::ConstIterator c = _conductores.cbegin();
	unsigned int cont = 0;
	while (c != _conductores.cend()) {
		if (c.valor()==puntos) {
			cont++;
		}
		c.next();
	}
	return cont;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 o(n)
*/
const Lista<string>& CarnetPorPuntos::lista_por_puntos(unsigned int puntos) const {
	if (puntos < 0 || puntos>15)
		throw EPuntosNoValidos();

	Lista<string> *lista = new Lista<string>();

	DiccionarioHash<string, unsigned int>::ConstIterator c = _conductores.cbegin();
	while (c != _conductores.cend()) {
		if (c.valor() == puntos) {
			lista->pon_ppio(c.clave());
		}
		c.next();
	}
	
	//const Lista<string> l2 = lista;

	//return l2;
	return *lista;
}

 