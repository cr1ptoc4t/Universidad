/**
  @file lista.h

  Implementaci�n del TAD Lista, utilizando una
  lista doblemente enlazada.

  Estructura de Datos y Algoritmos
  Facultad de Inform�tica
  Universidad Complutense de Madrid

 (c) Marco Antonio G�mez Mart�n, 2012    Mercedes G�mez Albarr�n, 2016
*/

#ifndef __LISTA_H
#define __LISTA_H

/// Excepciones generadas por algunos m�todos
class EListaVacia {};
class EAccesoInvalido {};
#include <cassert>
#include <stddef.h>

/**
 Implementaci�n del TAD Lista utilizando una lista doblemente enlazada.

 Las operaciones son:

 - Crear una lista vac�a: listaVacia: --> Lista. Generadora
 - A�adir un elemento al final: pon_final: Lista, Elem --> Lista. Generadora
 - A�adir un elemento al principio: pon_ppio: Lista, Elem --> Lista. Generadora
 - Eliminar un elemento por el final: quita_final: Lista -> Lista. Modificadora parcial.
 - Eliminar un elemento por el principio: quita_ppio: Lista -> Lista. Modificadora parcial.
 - Acceder al primer elemento: primero: Lista -> Elem. Observadora parcial.
 - Acceder al �ltimo elemento: : ultimo: Lista -> Elem. Observadora parcial.
 - Acceder al elemento i-�simo: elem: Lista -> Elem. Observadora parcial.
 - Averiguar si la lista tiene elementos: esVacia: Lista-> Bool. Observadora.
 - Obtener el n�mero de elementos de la lista: longitud: Lista -> Int. Observadora.


 @author Marco Antonio G�mez Mart�n, Mercedes G�mez Albarr�n
 */

template <class T>
class Lista {
public:
	/*
	 Operaci�n 'repatir' a implementar
	 Aparte de esta m�todo, puedes implementar todas los m�todos (privados) auxiliares
	 que consideres oportuno.

	 COMPLEJIDAD: Debes indicar aqu�, justificadamente,la complejidad de
	 tu implementaci�n:


	*/

	void repartir() {
		Lista<int> primer_tramo;
		int elem1 = primero();
		for (int i = 0; i < longitud()) {
			if (elem(i) < elem1) {
				primer_tramo.pon_final(elem(i));
				borraElem(i);
			}
			else
				i++;
		}
	}


private:

	/**
	 Clase nodo que almacena internamente el elemento (de tipo T),
	 y dos punteros, uno al nodo anterior y otro al nodo siguiente.
	 Ambos punteros podr�an ser NULL si el nodo es el primero
	 y/o �ltimo de la lista enlazada.
	 */
	class Nodo {
	public:
		Nodo() : _sig(NULL), _ant(NULL) {}
		Nodo(const T& elem) : _elem(elem), _sig(NULL), _ant(NULL) {}
		Nodo(Nodo* ant, const T& elem, Nodo* sig) :
			_elem(elem), _sig(sig), _ant(ant) {}

		T _elem;
		Nodo* _sig;
		Nodo* _ant;
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
	static Nodo* insertaElem(const T& e, Nodo* nodo1, Nodo* nodo2) {
		Nodo* nuevo = new Nodo(nodo1, e, nodo2);
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
	static void borraElem(Nodo* n) {
		assert(n != NULL);
		Nodo* ant = n->_ant;
		Nodo* sig = n->_sig;
		if (ant != NULL) // hay nodo predecesor
			ant->_sig = sig;
		if (sig != NULL) // hay nodo sucesor
			sig->_ant = ant;
		delete n;
	}

	void copia(const Lista<T>& other) {
		_prim = NULL;
		_ult = NULL;
		_numElems = 0;
		Nodo* act = other._prim;
		while (act != NULL) {
			pon_final(act->_elem);
			act = act->_sig;
		}
	}


	/**
	 Elimina todos los nodos de la lista enlazada.
	 Se admite que la lista pueda sea NULL (no habr� nada que
	 liberar).
	 */

	void libera() {
		while (_prim != NULL) {
			Nodo* aux = _prim;
			_prim = _prim->_sig;
			delete aux;
		}
	}


	// Puntero al primer y �ltimo elemento
	Nodo* _prim, * _ult;
	// N�mero de elementos (n�mero de nodos entre _prim y _ult)
	unsigned int _numElems;

public:



	/** Constructor; operaci�n listaVacia. */
	Lista() : _prim(NULL), _ult(NULL), _numElems(0) {}

	/**
	 A�ade un nuevo elemento en la cabeza de la lista.
	 Operaci�n generadora.

	 @param elem Elemento que se a�ade en la cabecera de la lista.
	*/
	void pon_ppio(const T& elem) {
		_prim = insertaElem(elem, NULL, _prim);
		_numElems++;
		if (_ult == NULL) // lista vacia
			_ult = _prim;
	}

	/**
	 A�ade un nuevo elemento al final de la Lista (a la "derecha"). Operaci�n modificadora.

	 @param elem Elemento que se a�ade al final de la lista.
	*/
	void pon_final(const T& elem) {
		_ult = insertaElem(elem, _ult, NULL);
		_numElems++;
		if (_prim == NULL)
			_prim = _ult;
	}

	/**
	 Devuelve el valor almacenado en la cabecera de la
	 Lista. Observadora parcial.

	 error: al preguntar por el primero de una lista vac�a
	 @return Elemento en la cabecera de la Lista.
	 */
	const T& primero() const {
		if (esVacia())
			throw EListaVacia();
		return _prim->_elem;
	}

	/**
	 Devuelve el valor almacenado en la �ltima posici�n de la Lista (a la "derecha").
	 Observadora parcial.

	 error: al preguntar por el �ltimo de una lista vac�a
	 @return Elemento en la cola de la Lista.
	 */
	const T& ultimo() const {
		if (esVacia())
			throw EListaVacia();
		return _ult->_elem;
	}

	/**
	 Devuelve el elemento i-�simo de la lista, teniendo
	 en cuenta que el primer elemento (primero())
	 es el elemento situado en la posici�n 0 y
	 que el �ltimo (ultimo()) est� en numElems()-1,
	 es decir, idx est� en [0..numElems()-1].
	 Operaci�n observadora parcial que puede fallar
	 si se da un �ndice incorrecto. El �ndice es
	 entero sin signo, para evitar que se puedan
	 pedir elementos negativos.
	 Observadora parcial.

	 error: si idx >= _numElems
	 @return Elemento en la posici�n idx de la Lista.
	*/
	const T& elem(unsigned int idx) const {
		if (idx >= _numElems)
			throw EAccesoInvalido();
		Nodo* aux = _prim;
		for (unsigned int i = 0; i < idx; ++i)
			aux = aux->_sig;
		return aux->_elem;
	}


	/**
	 Elimina el primer elemento de la Lista. Observadora parcial.

	 error: intentar eliminar en una Lista vac�a.
	*/
	void quita_ppio() {
		if (esVacia())
			throw EListaVacia();
		Nodo* aBorrar = _prim;
		_prim = _prim->_sig;
		borraElem(aBorrar);
		_numElems--;
		if (_prim == NULL)
			_ult = NULL;
	}

	/**
	 Elimina el �ltimo elemento de la Lista. Observadora parcial.

	 error: intentar eliminar en una Lista vac�a.
	*/
	void quita_final() {
		if (esVacia())
			throw EListaVacia();
		Nodo* aBorrar = _ult;
		_ult = _ult->_ant;
		borraElem(aBorrar);
		_numElems--;
		if (_ult == NULL)
			_prim = NULL;
	}

	/**
	 Operaci�n observadora para saber si una Lista tiene o no elementos.

	 @return true si la Lista no tiene elementos.
	 */
	bool esVacia() const {
		return _prim == NULL;
	}


	/**
	 Devuelve el n�mero de elementos que hay en la lista (observadora).

	 @return N�mero de elementos.
	 */
	unsigned int longitud() const {
		return _numElems;
	}


	/** Destructor; elimina la lista doblemente enlazada. */
	~Lista() {
		libera();
		_prim = NULL;
		_ult = NULL;
	}


	/** Constructor copia */
	Lista(const Lista<T>& other) {
		copia(other);
	}

	/** Operador de asignaci�n */
	Lista<T>& operator=(const Lista<T>& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparaci�n. */
	bool operator==(const Lista<T>& rhs) const {
		bool iguales;
		if (_numElems != rhs._numElems)
			iguales = false;
		else {
			Nodo* p1 = _prim;
			Nodo* p2 = rhs._prim;
			while ((p1 != NULL) && (p2 != NULL) && (p1->_elem == p2->_elem)) {
				p1 = p1->_sig;
				p2 = p2->_sig;
			}
			iguales = (p1 == NULL) && (p2 == NULL);
		}
		return iguales;
	}

	bool operator!=(const Lista<T>& rhs) const {
		return !(*this == rhs);
	}


	//
	//  ITERADORES
	//

	/**
	 Clase interna que implementa un iterador sobre
	 la lista que permite recorrer la lista pero no
	 permite cambiarlos.
	 */
	class ConstIterator {
	public:
		void next() {
			if (_act == NULL) throw EAccesoInvalido();
			_act = _act->_sig;
		}

		const T& elem() const {
			if (_act == NULL) throw EAccesoInvalido();
			return _act->_elem;
		}

		bool operator==(const ConstIterator& other) const {
			return _act == other._act;
		}

		bool operator!=(const ConstIterator& other) const {
			return !(this->operator==(other));
		}

	protected:
		// Para que pueda construir objetos del
		// tipo iterador
		friend class Lista;

		ConstIterator() : _act(NULL) {}
		ConstIterator(Nodo* act) : _act(act) {}

		// Puntero al nodo actual del recorrido
		Nodo* _act;
	};

	/**
	 Devuelve el iterador de lectura al principio de la lista.

	 @return iterador al principio de la lista;
	 coincidir� con final() si la lista est� vac�a.
	 */
	ConstIterator cbegin() const {
		return ConstIterator(_prim);
	}

	/**
	 Devuelve el iterador de lectura apuntando fuera del recorrido

	 @return Devuelve un iterador al final del recorrido (NULL en este caso).
	 */
	ConstIterator cend() const {
		return ConstIterator();
	}


	/**
	 Clase interna que implementa un iterador sobre
	 la lista que permite recorrer la lista e incluso
	 alterar el valor de sus elementos.
	 */
	class Iterator {
	public:
		void next() {
			if (_act == NULL) throw EAccesoInvalido();
			_act = _act->_sig;
		}

		const T& elem() const {
			if (_act == NULL) throw EAccesoInvalido();
			return _act->_elem;
		}

		void set(const T& elem) {
			if (_act == NULL) throw EAccesoInvalido();
			_act->_elem = elem;
		}

		bool operator==(const Iterator& other) const {
			return _act == other._act;
		}

		bool operator!=(const Iterator& other) const {
			return !(this->operator==(other));
		}
	protected:
		// Para que pueda construir objetos del tipo iterador
		friend class Lista;

		Iterator() : _act(NULL) {}
		Iterator(Nodo* act) : _act(act) {}

		// Puntero al nodo actual del recorrido
		Nodo* _act;
	};

	/**
	 Devuelve el iterador de escritura al principio de la lista.

	 @return iterador al principio de la lista;
	 coincidir� con end() si la lista est� vac�a.
	 */
	Iterator begin() {
		// no lo declaramos como const porque el efecto del iterador va a ser poder modificar la lista
		// (aunque eso no ocurra en este m�todo)
		return Iterator(_prim);
	}

	/**
	 Devuelve un iterador de escritura al final del recorrido (fuera de �ste).

	 @return iterador al final del recorrido
	 */
	Iterator end() const {
		return Iterator();
	}

	// M�TODOS QUE USAN ITERADORES
	/**
	 M�todo para insertar un elemento en la lista
	 en el punto marcado por el iterador. En concreto,
	 se a�ade _justo antes_ que el elemento actual. Es
	 decir, si it==lista.begin(), el elemento insertado se
	 convierte en el primer elemento (y el iterador
	 apuntar� al segundo). Si it==lista.end(), el elemento
	 insertado ser� el �ltimo (e it seguir� apuntando
	 fuera del recorrido). Generadora.

	 @param elem Valor del elemento a insertar.
	 @param it Punto en el que insertar el elemento.
	 */
	void insertar(const T& elem, const Iterator& it) {
		if (_prim == it._act)
			pon_ppio(elem);
		else if (it._act == NULL)
			pon_final(elem);
		else {
			insertaElem(elem, it._act->_ant, it._act);
			_numElems++;
		}
	}


	/**
	 Permite eliminar de la lista el elemento
	 apuntado por el iterador que se pasa como par�metro.
	 El iterador recibido DEJA DE SER V�LIDO. En su
	 lugar, deber� utilizarse el iterador devuelto, que
	 apuntar� al siguiente elemento al borrado.

	 @param it Iterador colocado en el elemento que se
	 quiere borrar.
	 @return Nuevo iterador colocado en el elemento siguiente
	 al borrado (ser� end() si el elemento que se borr� era el �ltimo de la lista).
	 */
	Iterator eliminar(const Iterator& it) {
		if (it._act == NULL) throw EAccesoInvalido();
		if (it._act == _prim) {
			quita_ppio();
			return Iterator(_prim);
		}
		else if (it._act == _ult) {
			quita_final();
			return Iterator();
		}
		else {
			Nodo* sig = it._act->_sig;
			borraElem(it._act);
			_numElems--;
			return Iterator(sig);
		}
	}

};

#endif // __LISTA_H
