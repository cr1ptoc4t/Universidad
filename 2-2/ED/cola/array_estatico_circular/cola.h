/** 
  @file Cola.h 
 
  Implementación del TAD Pila utilizando un
  array estático circular.

  Estructura de Datos y Algoritmos
  Facultad de Informática
  Universidad Complutense de Madrid

 (c) Mercedes Gómez Albarrán, 2016
*/

#ifndef ARRAY_QUEUE_
#define ARRAY_QUEUE_


/// Excepciones generadas por algunos métodos
class EColaVacia {};
class EColaLlena {};


/**
Implementación del TAD Cola utilizando el array circular.

Las operaciones son:

- ColaVacia: -> Cola. Generadora implementada en el
constructor sin parámetros.
- pon: Cola, Elem -> Cola. Generadora
- quita: Cola - -> Cola. Modificadora parcial.
- primero: Cola - -> Elem. Observadora parcial.
- esVacia: Cola -> Bool. Observadora.

@author Mercedes Gómez Albarrán
*/

template<class ItemType>
class Cola {
public:
	static const int DEFAULT_CAPACITY = 5;

	/** Constructor; operacion ColaVacia */
	Cola(): _front(0), _back(DEFAULT_CAPACITY - 1), _count(0)  {}

	/**
	Indica si la cola está vacía.
	@return true si la cola no tiene ningún elemento.
	*/
	bool esVacia() const {
		return _count == 0;
	}

	/**
	Añade un elemento en la parte trasera de la cola.
	Operación generadora parcial.

	error: falla si la cola está llena
	@param newEntry Elemento a añadir.
	*/
	void pon(const ItemType& newEntry){
		if (_count == DEFAULT_CAPACITY)
			throw EColaLlena();
		_back = (_back + 1) % DEFAULT_CAPACITY;
		_items[_back] = newEntry;
		_count++;
	}


	/**
	Elimina el primer elemento de la cola.
	Operación modificadora parcial. 

	error: falla si la cola está vacía.
	*/
	void quita(){
		if (esVacia())
			throw EColaVacia();
		_front = (_front + 1) % DEFAULT_CAPACITY;
		_count--;
	}

	/**
	Devuelve el primer elemento de la cola. 
	Operación observadora parcial

	error: falla si la cola está vacía
	@return El primer elemento de la cola.
	*/
	const ItemType& primero(){
		if (esVacia())
			throw EColaVacia();
		return _items[_front];
	}


private:
	ItemType _items[DEFAULT_CAPACITY]; // array de elementos
	int      _front;                   // índice del primer elemento de la cola
	int      _back;                    // índice del último elemento de la cola
	int      _count;                   // nº real de elementos de la cola

}; 
#endif