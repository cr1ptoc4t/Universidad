/**
  @file DColaC.h

  Implementación del TAD doble cola, utilizando una
  lista doblemente enlazada con nodo fantasma o
  cabecera.

  Estructura de Datos y Algoritmos
  Facultad de Informática
  Universidad Complutense de Madrid

 (c) Marco Antonio Gómez Martín, 2012   Mercedes Gómez Albarrán, 2016
*/
#ifndef __DCOLAC_H
#define __DCOLAC_H
#include <cstddef>


/// Excepciones generadas por algunos métodos
class EDColaVacia {};
#include <cassert>

/**
 Implementación del TAD Doble Cola utilizando una lista doblemente
 enlazada circular y con nodo fantasma.

 Las operaciones son:

Crear una doble cola vacía: dcolaVacia: --> DCola. Generadora
Añadir un elemento al final: pon_final: DCola, Elem --> DCola. Generadora
Añadir un elemento al principio: pon_ppio: DCola, Elem --> DCola. Generadora
Eliminar un elemento por el final: quita_final: DCola--> DCola. Modificadora parcial.
Eliminar un elemento por el principio: quita_ppio: DCola--> DCola. Modificadora parcial.
Acceder al primer elemento: primero: DCola--> Elem. Observadora parcial.
Acceder al último elemento: : ultimo: DCola--> Elem. Observadora parcial.
Averiguar si una doble cola tiene elementos: esVacia: DCola--> Bool. Observadora.

 @author Marco Antonio Gómez Martín   Mercedes Gómez Albarrán
 */

template <class T>
class DCola {
public:

	/** Constructor; operación DColaVacia. */
	DCola() {
		_fantasma = new Nodo();
		_fantasma->_sig = _fantasma;
		_fantasma->_ant = _fantasma;
	}


	/**
	 Añade un nuevo elemento al final de la dcola (a la "derecha"). Operación generadora.
	 
	 @param elem Elemento que se añade en la final de la dcola.
	*/
	void pon_final(const T &e) {
		insertaElem(e, _fantasma->_ant, _fantasma);
	}

	/**
	 Añade un nuevo elemento en la cabeza de la dcola (a la "izquierda"). Operación generadora.

	 @param elem Elemento que se añade en la cabecera de la dcola.
	*/
	void pon_ppio (const T &e) {
		insertaElem(e, _fantasma, _fantasma->_sig);
	}

	/**
	 Devuelve el valor almacenado en la cabecera de la dcola.
	 Observadora pacial.
	 
	 error: falla al preguntar por el primero de una dcola vacía.
	 @return Elemento en la cabecera de la dcola.
	 */
	const T &primero() const {
		if (esVacia())
			throw EDColaVacia();
		return _fantasma->_sig->_elem;
	}


	/**
	 Elimina el primer elemento de la dcola. Modificadora parcial.
	 Es un error intentar eliminar en una dcola vacía.
	*/
	void quita_ppio() {
		if (esVacia())
			throw EDColaVacia();
		borraElem(_fantasma->_sig);
	}

	

	/**
	 Devuelve el valor almacenado en la última posición
	 de la dcola (a la derecha).
	 Es un error preguntar por el primero de una dcola vacía.

	 @return Elemento en la cola de la dcola.
	 */
	const T &ultimo() const {
		if (esVacia())
			throw EDColaVacia();
		return _fantasma->_ant->_elem;
	}

	/**
	 Elimina el último elemento de la dcola. Modificadora parcial.

	 error: al intentar eliminar en una dcola vacía.
	*/
	void quita_final()  {
		if (esVacia())
			throw EDColaVacia();
		borraElem(_fantasma->_ant);
	}

	
	/**
	 Operación observadora para saber si una dcola tiene o no elementos.

	 @return true si la dcola no tiene elementos.
	 */
	bool esVacia() const {
		return _fantasma->_sig == _fantasma;
	}

	
	/** Destructor; elimina la lista doblemente enlazada. */
	~DCola() {
		libera();
	}

	/** Constructor copia */
	DCola(const DCola<T> &other) : _fantasma(NULL) {
		copia(other);
	}

	/** Operador de asignación */
	DCola<T> &operator=(const DCola<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparación. */
	bool operator==(const DCola<T> &rhs) const {
		Nodo *p1 = _fantasma->_sig; // primer nodo "real" de la dcola receptora
		Nodo *p2 = rhs._fantasma->_sig; // primer nodo "real" de la dcola rhs
		while ((p1 != _fantasma) && (p2 != rhs._fantasma) && (p1->_elem == p2->_elem)) {
			p1 = p1->_sig;
			p2 = p2->_sig;
		}
		return (p1 == _fantasma) && (p2 == rhs._fantasma);
	}


	bool operator!=(const DCola<T> &rhs) const {
		return !(*this == rhs);
	}

private:

	/**
	 Clase nodo que almacena internamente el elemento (de tipo T),
	 y dos punteros, uno al nodo anterior y otro al nodo siguiente.
	 Ambos punteros podrían ser NULL si el nodo es el primero
	 y/o último de la lista enlazada.
	 */
	class Nodo {
	public:
		Nodo() : _sig(NULL) {}
		Nodo(const T &elem) : _elem(elem), _sig(NULL), _ant(NULL) {}
		Nodo(Nodo *ant, const T &elem, Nodo *sig) : 
		    _elem(elem), _sig(sig), _ant(ant) {}

		T _elem;
		Nodo *_sig;
		Nodo *_ant;
	};

	/**
	 Inserta un elemento entre el nodo1 y el nodo2.
	 Devuelve el puntero al nodo creado.
	 Caso general: los dos nodos existen.
	    nodo1->_sig == nodo2
	    nodo2->_ant == nodo1
	 Casos especiales: alguno de los nodos no existe
	    nodo1 == NULL y/o nodo2 == NULL
	*/
	static Nodo *insertaElem(const T &e, Nodo *nodo1, Nodo *nodo2) {
		Nodo *nuevo = new Nodo(nodo1, e, nodo2);
		if (nodo1 != NULL) // hay un nodo anterior al nuevo
			nodo1->_sig = nuevo;
		if (nodo2 != NULL) // hay un nodo posterior al nuevo
			nodo2->_ant = nuevo;
		return nuevo;
	}

	/**
	Genera una copia de other en el receptor
	*/
	void copia(const DCola<T> &other) {
		_fantasma = new Nodo();
		_fantasma->_sig = _fantasma;
		_fantasma->_ant = _fantasma;

		Nodo *act = other._fantasma->_sig;
		while (act != other._fantasma) {
			pon_final(act->_elem);
			act = act->_sig;
		}
	}

	/**
	 Elimina el nodo n. Si el nodo tiene nodos antes
	 o después, actualiza sus punteros anterior y siguiente.
	 Caso general: hay nodos anterior y siguiente.
	 Casos especiales: algunos de los nodos (anterior o siguiente
	 a n) no existen.
	*/
	static void borraElem(Nodo *n) {
		assert(n != NULL);

		Nodo *ant = n->_ant;
		Nodo *sig = n->_sig;
		if (ant != NULL)
			ant->_sig = sig;
		if (sig != NULL)
			sig->_ant = ant;
		delete n;
	}

	/**
	Libera los nodos de la lista que sustenta al receptor
	*/
	void libera() {
		// Antes de empezar a liberar quitamos la circularidad para evitar bucle
		// infinito...
		_fantasma->_ant->_sig = NULL;
		_fantasma->_ant = NULL;
		// Una vez convertida en una lista lineal se liberan los nodos
		while (_fantasma != NULL) {
			Nodo *aux = _fantasma;
			_fantasma = _fantasma->_sig;
			delete aux;
		}
		_fantasma = NULL;
	}


	// Puntero al nodo fantasma
	Nodo *_fantasma;
};

#endif // __DCOLAC_H
