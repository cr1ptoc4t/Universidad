/**
  @file dcola.h

  Implementación del TAD Doble Cola, utilizando una 
  lista doblemente enlazada.

  Estructura de Datos y Algoritmos
  Facultad de Informática
  Universidad Complutense de Madrid

 (c) Mercedes Gómez Albarrán, 2016
*/

#ifndef __DCOLA_H
#define __DCOLA_H

/// Excepciones generadas por algunos métodos
class EDColaVacia {};
#include <cassert>
#include <cstddef>

/**
 Implementación del TAD Doble Cola utilizando una lista doblemente enlazada.

 Las operaciones son:

 - Crear una doble cola vacía: dcolaVacia: --> DCola. Generadora
 - Añadir un elemento al final: pon_final: DCola, Elem --> DCola. Generadora
 - Añadir un elemento al principio: pon_ppio: DCola, Elem --> DCola. Generadora
 - Eliminar un elemento por el final: quita_final: DCola--> DCola. Modificadora parcial.
 - Eliminar un elemento por el principio: quita_ppio: DCola--> DCola. Modificadora parcial.
 - Acceder al primer elemento: primero: DCola--> Elem. Observadora parcial.
 - Acceder al último elemento: : ultimo: DCola--> Elem. Observadora parcial.
 - Averiguar si una doble cola tiene elementos: esVacia: DCola--> Bool. Observadora.


 @author Mercedes Gómez Albarrán
 */
template <class T>
class DCola {
public:

	/** Constructor; operación dcolaVacia. */
	DCola() : _prim(NULL), _ult(NULL) {}

	
	/**
	 Añade un nuevo elemento en la cabeza de la dcola (a la "izda").
	 Operación generadora.

	 @param elem Elemento que se añade en la cabecera de la dcola.
	*/
	void pon_ppio (const T &elem) {
		_prim = insertaElem(elem, NULL, _prim);
		if (_ult == NULL) // lista vacia
			_ult = _prim;
	}

	/**
	 Añade un nuevo elemento al final de la dcola (a la "derecha"). Operación generadora.

	 @param elem Elemento que se añade en la cabecera de la dcola.
	*/
	void pon_final(const T &elem) {
		_ult = insertaElem(elem, _ult, NULL);
		if (_prim == NULL) 
			_prim = _ult;
	}

	/**
	 Devuelve el valor almacenado en la cabecera de la
	 dcola. Observadora parcial.
	 
	 error: falla si la dcola está vacía
	 @return Elemento en la cabecera de la dcola.
	 */
	const T &primero() const {
		if (esVacia())
			throw EDColaVacia();
		return _prim->_elem;
	}

	/**
	 Devuelve el valor almacenado en la última posición de la dcola (a la derecha).
	 Observadora parcial

	 error: falla si la dcola está vacía
	 @return Elemento en la cola de la dcola.
	 */
	const T &ultimo() const {
		if (esVacia())
			throw EDColaVacia();
		return _ult->_elem;
	}

	/**
	 Elimina el primer elemento de la dcola. Modificadora parcial.
	 
	 error: al intentar eliminar en una dcola vacía.
	*/
	void quita_ppio() {
		if (esVacia())
			throw EDColaVacia();
		Nodo *aBorrar = _prim;
		_prim = _prim->_sig;
		borraElem(aBorrar);
		if (_prim == NULL) 
			_ult = NULL;
	}

	/**
	 Elimina el último elemento de la dcola. Modificadora parcial
	 
	 error: al intentar eliminar en una dcola vacía.
	*/
	void quita_final() {
		if (esVacia())
			throw EDColaVacia();
		Nodo *aBorrar = _ult;
		_ult = _ult->_ant;
		borraElem(aBorrar);
		if (_ult == NULL) 
			_prim = NULL;
	}

	/**
	 Operación observadora para saber si una dcola tiene o no elementos.

	 @return true si la dcola no tiene elementos.
	 */
	bool esVacia() const {
		return _prim == NULL;
	}

	

	/** Destructor; elimina la lista doblemente enlazada. */
	~DCola() {
		libera();
		_prim = NULL;
		_ult = NULL;
	}


	/** Constructor copia */
	DCola(const DCola<T> &other) {
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
		Nodo *p1 = _prim;
		Nodo *p2 = rhs._prim;
		while ((p1 != NULL) && (p2 != NULL) && (p1->_elem == p2->_elem)) {
			p1 = p1->_sig;
			p2 = p2->_sig;
		}
		return (p1 == NULL) && (p2 == NULL);
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
		Nodo() : _sig(NULL), _ant(NULL) {}
		Nodo(const T &elem) : _elem(elem), _sig(NULL), _ant(NULL) {}
		Nodo(Nodo *ant, const T &elem, Nodo *sig) : 
		    _elem(elem), _sig(sig), _ant(ant) {}

		T _elem;
		Nodo *_sig;
		Nodo *_ant;
	};

	/**
	 Inserta un elemento entre el nodo apuntado por nodo1 y el nodo apuntado por nodo2.
	 Devuelve el puntero al nodo creado.
	 Caso general: los dos nodos existen.
	    nodo1->_sig == nodo2
	    nodo2->_ant == nodo1
	 Casos especiales: alguno de los nodos (o los dos) no existe
	    nodo1 == NULL --> insertamos por el principio
		nodo2 == NULL --> insertamos por el final
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
	 Elimina el nodo n. Si el nodo tiene nodo predecesor
	 y/o sucesor, actualiza sus punteros siguiente y anterior, respectivamente.
	 Caso general: hay nodos anterior y siguiente.
	 Casos especiales: algunos de los nodos (anterior o siguiente
	 a n) no existen.
	*/
	static void borraElem(Nodo *n) {
		assert(n != NULL);
		Nodo *ant = n->_ant;
		Nodo *sig = n->_sig;
		if (ant != NULL) // hay nodo predecesor
			ant->_sig = sig;
		if (sig != NULL) // hay nodo sucesor
			sig->_ant = ant;
		delete n;
	}

	void copia(const DCola<T> &other) {
		_prim = NULL;
		_ult = NULL;
		Nodo *act = other._prim;
		while (act != NULL) {
			pon_final(act->_elem);
			act = act->_sig;
		}
	}


	/**
	 Elimina todos los nodos de la lista enlazada.
	 Se admite que la lista pueda sea NULL (no habrá nada que
	 liberar).
	 */

	void libera() {
		while (_prim != NULL) {
			Nodo *aux = _prim;
			_prim = _prim->_sig;
			delete aux;
		}
	}


	// Puntero al primer y último elemento
	Nodo *_prim, *_ult;

};

#endif // __DCOLA_H
