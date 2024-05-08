/**
  @file Pila.h

  Implementación del TAD Pila utilizando un
  vector dinámico cuyo tamaño va creciendo si
  es necesario.

  Estructura de Datos y Algoritmos
  Facultad de Informática
  Universidad Complutense de Madrid

 (c) Marco Antonio Gómez Martín, 2012   Mercedes Gómez Albarrán, 2016
*/
#ifndef __PILAVD_H
#define __PILAVD_H
#include <cstddef>

/// Excepciones generadas por algunos métodos
class EPilaVacia {};

/**
 Implementación del TAD Pila utilizando vectores dinámicos.

 Las operaciones son:

 - PilaVacia: -> Pila. Generadora implementada en el
   constructor sin parámetros.
 - apila: Pila, Elem -> Pila. Generadora
 - desapila: Pila - -> Pila. Modificadora parcial.
 - cima: Pila - -> Elem. Observadora parcial.
 - esVacia: Pila -> Bool. Observadora.

 @author Marco Antonio Gómez Martín  Mercedes Gómez Albarrán
 */
template <class T>
class Pila {
public:

	/** Tamaño inicial del vector dinámico. */
	static const int TAM_INICIAL = 10;

	/** Constructor; operación PilaVacia */
	Pila() {
		_v = new T[TAM_INICIAL];
		_tam = TAM_INICIAL;
		_numElems = 0;
	}

	/**
	 Apila un elemento. Operación generadora.

	 @param elem Elemento a apilar.
	*/
	void apila(const T& elem) {
		_v[_numElems] = elem;
		_numElems++;
		if (_numElems == _tam)
			amplia();
	}

	/**
	 Desapila un elemento. Operación modificadora parcial.
	 error: falla si la pila está vacía
	*/
	void desapila() {
		if (esVacia())
			throw EPilaVacia();
		--_numElems;
	}

	/**
	 Devuelve el elemento en la cima de la pila. Operación
	 observadora parcial.

	 error: falla si la pila está vacía
	 @return Elemento en la cima de la pila.
	 */
	const T& cima() const {
		if (esVacia())
			throw EPilaVacia();
		return _v[_numElems - 1];
	}

	/**
	 Indica si la pila está vacía.

	 @return true si la pila no tiene ningún elemento.
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

	/** Operador de asignación */
	Pila<T>& operator=(const Pila<T>& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/**  Operador de comparación. 	*/
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

	/** Tamaño del vector _v. */
	unsigned int _tam;

	/** Número de elementos reales guardados. */
	unsigned int _numElems;

	/** Código para liberar la memoria dinámica usada en la pila */
	void libera() {
		delete[]_v;
		_v = NULL;
	}

	/** Código para copiar sobre el receptor */
	void copia(const Pila<T>& other) {
		_tam = other._numElems + TAM_INICIAL;
		_numElems = other._numElems;
		_v = new T[_tam];
		for (unsigned int i = 0; i < _numElems; ++i)
			_v[i] = other._v[i];
	}

	/** Código para hacer crecer el vector dinámico */
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
