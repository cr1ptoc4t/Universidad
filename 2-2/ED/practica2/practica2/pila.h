/**
  @file Pila.h

  Implementaci�n del TAD Pila utilizando un
  vector din�mico cuyo tama�o va creciendo si
  es necesario.

  Estructura de Datos y Algoritmos
  Facultad de Inform�tica
  Universidad Complutense de Madrid

 (c) Marco Antonio G�mez Mart�n, 2012   Mercedes G�mez Albarr�n, 2016
*/
#ifndef __PILAVD_H
#define __PILAVD_H
#include <cstddef>

/// Excepciones generadas por algunos m�todos
class EPilaVacia {};

/**
 Implementaci�n del TAD Pila utilizando vectores din�micos.

 Las operaciones son:

 - PilaVacia: -> Pila. Generadora implementada en el
   constructor sin par�metros.
 - apila: Pila, Elem -> Pila. Generadora
 - desapila: Pila - -> Pila. Modificadora parcial.
 - cima: Pila - -> Elem. Observadora parcial.
 - esVacia: Pila -> Bool. Observadora.

 @author Marco Antonio G�mez Mart�n  Mercedes G�mez Albarr�n
 */
template <class T>
class Pila {
public:

	/** Tama�o inicial del vector din�mico. */
	static const int TAM_INICIAL = 10;

	/** Constructor; operaci�n PilaVacia */
	Pila() {
		_v = new T[TAM_INICIAL];
		_tam = TAM_INICIAL;
		_numElems = 0;
	}

	/**
	 Apila un elemento. Operaci�n generadora.

	 @param elem Elemento a apilar.
	*/
	void apila(const T& elem) {
		_v[_numElems] = elem;
		_numElems++;
		if (_numElems == _tam)
			amplia();
	}

	/**
	 Desapila un elemento. Operaci�n modificadora parcial.
	 error: falla si la pila est� vac�a
	*/
	void desapila() {
		if (esVacia())
			throw EPilaVacia();
		--_numElems;
	}

	/**
	 Devuelve el elemento en la cima de la pila. Operaci�n
	 observadora parcial.

	 error: falla si la pila est� vac�a
	 @return Elemento en la cima de la pila.
	 */
	const T& cima() const {
		if (esVacia())
			throw EPilaVacia();
		return _v[_numElems - 1];
	}

	/**
	 Indica si la pila est� vac�a.

	 @return true si la pila no tiene ning�n elemento.
	 */
	bool esVacia() const {
		return _numElems == 0;
	}

	/** Destructor; elimina el vector. */
	~Pila() {
		libera();
	}

	/** Constructor copia */
	Pila(const Pila<T>& other) {
		copia(other);
	}

	/** Operador de asignaci�n */
	Pila<T>& operator=(const Pila<T>& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/**  Operador de comparaci�n. 	*/
	bool operator==(const Pila<T>& rhs) const {
		bool iguales = true;
		if (_numElems != rhs._numElems)
			iguales = false;
		else {
			unsigned int i = 0;
			while (iguales && i < _numElems) {
				if (_v[i] != rhs._v[i])
					iguales = false;
				i++;
			}
		}
		return iguales;
	}


	bool operator!=(const Pila<T>& rhs) const {
		return !(*this == rhs);
	}


private:

	/** Puntero al array que contiene los datos. */
	T* _v;

	/** Tama�o del vector _v. */
	unsigned int _tam;

	/** N�mero de elementos reales guardados. */
	unsigned int _numElems;

	/** C�digo para liberar la memoria din�mica usada en la pila */
	void libera() {
		delete[]_v;
		_v = NULL;
	}

	/** C�digo para copiar sobre el receptor */
	void copia(const Pila<T>& other) {
		_tam = other._numElems + TAM_INICIAL;
		_numElems = other._numElems;
		_v = new T[_tam];
		for (unsigned int i = 0; i < _numElems; ++i)
			_v[i] = other._v[i];
	}

	/** C�digo para hacer crecer el vector din�mico */
	void amplia() {
		T* viejo = _v;
		_tam *= 2;
		_v = new T[_tam];

		for (unsigned int i = 0; i < _numElems; ++i)
			_v[i] = viejo[i];

		delete[]viejo;
	}
};

#endif // __PILAVD_H
