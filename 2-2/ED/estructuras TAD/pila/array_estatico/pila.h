/**
  @file Pila.h

  Implementación del TAD Pila utilizando un
  array estático.

  Estructura de Datos y Algoritmos
  Facultad de Informática
  Universidad Complutense de Madrid

 (c) Antonio Sánchez Ruiz-Granados, 2013  Mercedes Gómez Albarrán, 2016
*/
#ifndef __PILAE_H
#define __PILAE_H


/// Excepciones generadas por algunos métodos
class EPilaLlena {};
class EPilaVacia {};

/**
 Implementación del TAD Pila utilizando un array estático.

 Las operaciones son:

 - PilaVacia: -> Pila. Generadora implementada en el
   constructor sin parámetros.
 - apila: Pila, Elem -> Pila. Generadora parcial.
 - desapila: Pila - -> Pila. Modificadora parcial.
 - cima: Pila - -> Elem. Observadora parcial.
 - esVacia: Pila -> Bool. Observadora.

 @author Antonio Sánchez Ruiz-Granados   Mercedes Gómez Albarrán
 */
template <class T>
class Pila {
public:
	/** Número máximo de elementos. */
	static const int TAM_MAX = 100;

	/** Constructor; operación PilaVacia */
	Pila() : _numElems(0) {	}

	
	/**
	 Apila un elemento. Operación generadora parcial.

	 @param elem Elemento a apilar.
	 error: no se puede apilar cuando la pila está llena
	*/
	void apila(const T &elem) {
		if (_numElems == TAM_MAX)
			throw EPilaLlena();
		_v[_numElems] = elem;
		_numElems++;
	}
	
	/**
	 Desapila un elemento. Operación modificadora parcial,
	 que falla si la pila está vacía.
	 error: no se puede desapilar una pila vacía
	*/
	void desapila() {
		if (esVacia())
			throw EPilaVacia();
		_numElems--;
	}

	/**
	 Devuelve el elemento en la cima de la pila. Operación
	 observadora parcial
	 error: falla si la pila está vacía.
	 @return Elemento en la cima de la pila.
	 */
	const T &cima() const {
		if (esVacia())
			throw EPilaVacia();
		return _v[_numElems-1];
	}

	/**
	 Devuelve true si la pila no tiene ningún elemento
	 @return true si la pila no tiene ningún elemento.
	 */
	bool esVacia() const {
		return _numElems == 0;
	}


	/** 
	 Operador de comparación. 
	*/
	bool operator==(const Pila<T> &rhs) const {
		bool iguales = true;
		if (_numElems != rhs._numElems)
			iguales = false;
		else{
			unsigned int i = 0;
			while (iguales && i < _numElems) {
				if (_v[i] != rhs._v[i])
					iguales = false;
				i++;
			}
		}
		return iguales;			
	}

	bool operator!=(const Pila<T> &rhs) const {
		return !(*this == rhs);
	}

private:

	/** Array de elementos. */
	T _v[TAM_MAX];

	/** Número de elementos almacenados en la pila. */
	unsigned int _numElems;
};

#endif // __PILAE_H
