/** ADT Arbin: �rboles binarios.
 @file Arbin.h */

#ifndef __ARBIN_H
#define __ARBIN_H

#include <cstddef>

using namespace std;

/**
Implementaci�n del TAD Arbol binario mediante nodos y punteros en
memoria din�mica

Las operaciones son:

- ArbolVacio: -> Arbin. Generadora que crea un �rbol vac�o.
Implementada mediante un constructor sin par�metros.
- ArbolSimple: Elem -> Arbin. Generadora que crea un �rbol con
un �nico nodo. Implementada mediante un constructor con par�metro
el valor a poner en el nodo.
- Cons: Arbin, Elem, Arbin -> Arbin. Generadora que construye un
�rbol con un hijo izquierdo, un nodo raiz, y un hijo derecho.
Implementada mediante un constructor que toma como primer argumento
el hijo izquierdo, como segundo el valor a poner en la raiz, y como
tercer argumento el hijo derecho.
- raiz: Arbin -> Elem. Observadora (parcial) que devuelve el valor
de la raiz (no definida para �rboles vac�os)
- hijoIz: Arbin -> Arbin. Observadora (parcial) que devuelve el
hijo izquierdo (no definida para �rboles vac�os)
- hijoDer: Arbin -> Arbin. Observadora (parcial) que devuelve el
hijo derecho (no definida para �rboles vac�os)
- esVacio: Arbin -> bool. Observadora que determina si un �rbol
es vac�o o no

@author Adaptada por Mercedes G�mez y Jos� Luis Sierra a partir de una implementaci�n de  Marco Antonio G�mez Mart�n, 2012
*/

/// Excepci�n generada por algunos m�todos
class EArbolVacio {};

template <class T>
class Arbin {
public:
	/** Constructor; operaci�n ArbolVac�o */
	Arbin() {
		_ra = NULL;
	};

	/** Constructor; operaci�n ArbolSimple (construye un �rbol con
		un �nico nodo)

		@param elem Elemento a alojar en la ra�z del �rbol generado */
	Arbin(const T& elem) {
		_ra = new Nodo(elem);
		_ra->addRef();
	};

	/** Constructor; operaci�n Cons (construye un �rbol con un hijo izquierdo,
		una ra�z y un hijo derecho)

		@param iz El hijo izquierdo
		@param elem El valor a poner en la ra�z
		@param dr El hijo derecho
	 */
	Arbin(const Arbin& iz, const T& elem, const Arbin& dr) {
		_ra = new Nodo(iz._ra, elem, dr._ra);
		_ra->addRef();
	};

	/** Devuelve el valor alojado en la ra�z del �rbol

		error: Falla si el �rbol est� vac�o (excepci�n EArbolVacio)

		@return El valor en la ra�z
	 */
	const T& raiz() const {
		if (_ra == NULL) {
			throw EArbolVacio();
		}
		return _ra->_elem;
	}

	/** Devuelve el hijo izquierdo del �rbol

		error: Falla si el �rbol est� vac�o (excepci�n EArbolVacio)

		@return El hijo izquierdo
	 */
	Arbin hijoIz() const {
		if (_ra == NULL) {
			throw EArbolVacio();
		}
		return Arbin(_ra->_iz);
	}


	/** Devuelve el hijo derecho del �rbol

		error: Falla si el �rbol est� vac�o (excepci�n EArbolVacio)

		@return El hijo derecho
	 */
	Arbin hijoDer() const {
		if (_ra == NULL) {
			throw EArbolVacio();
		}
		return Arbin(_ra->_dr);
	}

	/** Determina si el �rbol est� vac�o.

		@return true si el �rbol est� vac�o; false en otro caso
	 */
	bool esVacio() const {
		return _ra == NULL;
	}


	/** Operador de igualdad entre �rboles binarios

		@param el �rbol cuya igualdad con el receptor quiere comprobarse

		@return true si los �rboles son iguales; false en otro caso
	 */
	bool operator==(const Arbin& a) const {
		return sonIguales(_ra, a._ra);
	}

	/** Operador de asignaci�n

		@param el �rbol que quiere asignarse al receptor

		@return una referencia al objeto receptor
	 */
	Arbin& operator=(const Arbin& a) {
		if (this != &a) {
			libera(_ra);
			if (a._ra != NULL) a._ra->addRef();
			_ra = a._ra;
		}
		return *this;
	}

	/** Constructor de copia

		@param el �rbol que quiere copiarse
	 */
	Arbin(const Arbin& a) {
		if (a._ra != NULL) a._ra->addRef();
		_ra = a._ra;
	}

	/** Destructor
	 */
	~Arbin() {
		libera(_ra);
	}

private:
	/**
	 Clase Nodo que almacena internamente un nodo de un �rbol. Para ello
	 almacena: (i) el valor del nodo, (ii) un puntero al nodo ra�z del �rbol
	 izquierdo, y (iii) un puntero al nodo ra�z del �rbol derecho.
	 Tambi�n se lleva la cuenta del n�mero de punteros que apuntan a dicho
	 nodo, para permitir la representaci�n eficiente de �rboles, permitiendo
	 la compartici�n de estructura entre los mismos.
	 */
	class Nodo {
	public:
		/** Constructor por defecto
		*/
		Nodo() : _iz(NULL), _dr(NULL), _nrefs(0) {}
		/** Constructor; construye un nodo para un �rbol unitario (sin
			hijo izquierdo, sin hijo derecho)

			@param el valor a alojar en el nodo
		 */
		Nodo(const T& elem) : _elem(elem), _iz(NULL), _dr(NULL), _nrefs(0) {}
		/** Constructor; construye un nodo para un �rbol con
			hijo izquierdo e hijo derecho

			@param iz,  el hijo izquierdo
			@param elem, el valor a alojar en la ra�z
			@param dr, el hijo derecho
		 */
		Nodo(Nodo* iz, const T& elem, Nodo* dr) :
			_elem(elem), _iz(iz), _dr(dr), _nrefs(0) {
			if (iz != NULL) iz->addRef();
			if (dr != NULL) dr->addRef();
		}
		/** Contabiliza una nueva referencia al nodo
		 */
		void addRef() { _nrefs++; };
		/** Decrementa el contador de referencias al nodo
		 */
		void rmRef() { _nrefs--; }
		T _elem;         // valor del nodo
		Nodo* _iz;       // hijo izquierdo
		Nodo* _dr;       // hijo derecho
		int _nrefs;      // n�mero de referencias al nodo
	};
	/** Constructor privado; crea un nuevo �rbol con una ra�z dada

	@param ra, el nodo ra�z del �rbol
 */
	Arbin(Nodo* ra) {
		_ra = ra;
		if (_ra != NULL) _ra->addRef();
	}

	/** Liberaci�n de la estructura de nodos, teniendo
		en cuenta la compartici�n.

	   @param n, puntero a la ra�z de la estructura a liberar
	*/
	static void libera(Nodo* n) {
		if (n != NULL) {
			n->rmRef();
			if (n->_nrefs == 0) {
				libera(n->_iz);
				libera(n->_dr);
				delete n;
			}
		}
	}
	/** Comprobaci�n de la igualdad entre dos estructuras de nodos.

	   @param no, primera estructura
	   @param n1, segunda estructura
	   @return true si los punteros apuntan a estructuras que representan
			   el mismo �rbol, false en otro caso
	*/

	static bool sonIguales(const Nodo* no, const Nodo* n1) {
		return no == n1
			||
			no != NULL && n1 != NULL &&
			no->_elem == n1->_elem &&
			sonIguales(no->_iz, n1->_iz) &&
			sonIguales(no->_dr, n1->_dr);

	}

	Nodo* _ra; // puntero al nodo ra�z

};



#endif
