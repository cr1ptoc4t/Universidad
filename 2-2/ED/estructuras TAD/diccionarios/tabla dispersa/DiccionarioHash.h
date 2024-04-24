/**
 *  @file diccionarioHash.h
 * 
 *  Implementación dinámica del TAD Diccionario utilizando
 *  tablas dispersas
 * 
 *  Estructura de Datos y Algoritmos
 *  Facultad de Informática
 *  Universidad Complutense de Madrid
 * 
 * (c) Antonio Sánchez Ruiz-Granados, 2012, Mercedes Gomez, Jose Luis Sierra, 2017
 *     Modificacion Jose Luis Sierra 2022, para permitir asignación entre iteradores,
 *     y declaración de iteradores sin inicializar. 
 */
#ifndef __DICCIO2_H
#define __DICCIO2_H

#include "hash.h"
#include <cstddef>



 /**
 Implementación dinámica del TAD Diccionario utilizando
 tablas dispersas abiertas.

 Las operaciones son:

 - diccionarioVacio: operación generadora que construye
 un diccionario vacío.

 - inserta(clave, valor): modificadora que añade una
 nueva pareja (clave, valor) al diccionario. Si la
 clave ya estaba se sustituye el valor.

 - borra(clave): operación modificadora. Elimina la
 clave del diccionario.  Si la clave no está,
 la operación no tiene efecto.

 - valorPara(clave): operación observadora que devuelve
 el valor asociado a una clave. Es un error preguntar
 por una clave que no existe.

 - contiene(clave): operación observadora. Sirve para
 averiguar si se ha introducido una clave en el diccionario.

 - esVacio(): operacion observadora que indica si
 el diccionario tiene alguna clave introducida.

 @author Antonio Sánchez Ruiz-Granados ( adaptaciones de Mercedes Gómez y José Luis Sierra)
 */

 /// Excepciones generadas por algunos métodos
class EClaveErronea2 {};

class EAccesoNoValido2 {};

template <class tClave, class tValor>
class DiccionarioHash {
private:
	/**
	 * La tabla contiene un array de punteros a nodos. Cada nodo contiene una 
	 * clave, un valor y un puntero al siguiente nodo.
	 */
	class Nodo {
	public:
		/* Constructores. */
		Nodo(const tClave &clave, const tValor &valor) : 
		_clave(clave), _valor(valor), _sig(NULL) {};
		
		Nodo(const tClave &clave, const tValor &valor, Nodo *sig) : 
		_clave(clave), _valor(valor), _sig(sig) {};
		
		/* Atributos públicos. */
		tClave _clave;    
		tValor _valor;   
		Nodo *_sig;  // Puntero al siguiente nodo.
	};  

	/**
	 * Representación de la tabla. La tabla contiene: (i) el array de punteros a nodos,
	 * (ii) el tamaño actual, (iii) el número de elementos que aloja
	 */
	class Tabla {
	  public:
		Nodo **_v;               ///< Array de punteros a Nodo.
		unsigned int _tam;       ///< Tamaño del array _v.
		unsigned int _numElems;  ///< Número de elementos en la tabla.   
	};
	
	Tabla _tabla;  //< Tabla dispersa

public:
	
	/**
	 * Tamaño inicial de la tabla.
	 */
	static const int TAM_INICIAL = 8;    
	
	/** Constructor por defecto que implementa DiccionarioVacio */
	DiccionarioHash()  {
		_tabla._v = new Nodo*[TAM_INICIAL];
		_tabla._tam = TAM_INICIAL; 
		_tabla._numElems = 0;
		for (unsigned int i = 0; i<_tabla._tam; ++i) {
				_tabla._v[i] = NULL;
		}
	}
	
	/** Destructor; elimina la memoria dinamica */
	~DiccionarioHash() {
		libera(_tabla);
	}
	
	/**
	 *	 Operación generadora que añade una nueva clave/valor
	 *	 a este diccionario
	 *	 @param clave Clave nueva.
	 *	 @param valor Valor asociado a esa clave. Si la clave
	 *	 ya se había insertado previamente, sustituimos el valor
	 *	 viejo por el nuevo.
	 */
	void inserta(const tClave &clave, const tValor &valor) {
		insertaAux(_tabla, clave, valor);
	}

	
	/**
	 *	 Operación modificadora que elimina una clave del diccionario.
	 *	 Si la clave no existía la operación no tiene efecto.
	 *	 @param clave Clave a eliminar.
	 */
	void borra(const tClave &clave) {
		borraAux(_tabla, clave);
	}
	
	/**
	 *	 Operación observadora que devuelve el valor asociado
	 *	 a una clave dada.
	 *	 @param clave Clave por la que se pregunta.
	 */
	const tValor &valorPara(const tClave &clave) const {
		return buscaAux(_tabla,clave);
	}

	/**
	 *	 Operación observadora que permite averiguar si una clave
	 *	 determinada está o no en el diccionario.
	 *	 @param clave Clave por la que se pregunta.
	 *	 @return true si el diccionario contiene un valor asociado
	 *	 a esa clave.
	 */
	bool contiene(const tClave &clave) const {
		// Obtenemos el índice asociado a la clave.
		unsigned int ind = ::h(clave) % _tabla._tam;
		
		// Buscamos un nodo que contenga esa clave.
		Nodo *nodo = buscaNodo(clave, _tabla._v[ind]);
		return nodo != NULL;
	}
	
	/**
	 *	 Operación observadora que devuelve si el diccionario
	 *	 es vacío (no contiene elementos) o no.
	 */
	bool esVacio() const {
		return _tabla._numElems == 0;
	}
	
	
	// //
	// ITERADOR CONSTANTE Y FUNCIONES RELACIONADAS
	// //
	
	/**
	 *	 Clase interna que implementa un iterador que permite 
	 *   recorrer la tabla pero no permite modificarla.
	 */
	class ConstIterator {
	public:
		ConstIterator(): _diccionario(NULL), _act(NULL), _ind(0) {}
		void next() {
			if (_act == NULL) throw EAccesoNoValido2();
			
			// Buscamos el siguiente nodo de la lista de nodos.
			_act = _act->_sig;
			
			// Si hemos llegado al final de la lista de nodos, seguimos
			// buscando por el vector _v.
			while ((_act == NULL) && (_ind < _diccionario->_tabla._tam - 1)) {
				++_ind;
				_act = _diccionario->_tabla._v[_ind];
			}
		}
		
		const tClave &clave() const {
			if (_act == NULL) throw EAccesoNoValido2();
			return _act->_clave;
		}
		
		const tValor &valor() const {
			if (_act == NULL) throw EAccesoNoValido2();
			return _act->_valor;
		}
		
		bool operator==(const ConstIterator &other) const {
			return _act == other._act;
		}
		
		bool operator!=(const ConstIterator &other) const {
			return !(this->operator==(other));
		}
			
	protected:
		// Para que pueda construir objetos del tipo iterador
		friend class DiccionarioHash;
		
		ConstIterator(const DiccionarioHash* diccionario, Nodo* act, unsigned int ind) 
			: _diccionario(diccionario), _act(act), _ind(ind) { }
		
		const DiccionarioHash* _diccionario;     ///< Diccionario que se está recorriendo
		Nodo* _act;             ///< Puntero al nodo actual del recorrido
		unsigned int _ind;      ///< Índice actual en el vector _v
	};
	
	/**
	 *	 Devuelve el iterador constante al principio del
	 *	 diccionario.
	 *	 @return iterador al principio del diccionario;
	 *	 coincidirá con cend() si el diccionario está vacío.
	 */
	ConstIterator cbegin() const {
		unsigned int ind = 0;
		Nodo *act = _tabla._v[0];
		while (ind < _tabla._tam-1 && act == NULL) {
			ind++;
			act = _tabla._v[ind];
		}
		return ConstIterator(this, act, ind);
	}
	
	/**
	 *	 @return Devuelve un iterador al final del diccionario
	 *	 (fuera de éste).
	 */
	ConstIterator cend() const {
		return ConstIterator(this, NULL, 0);
	}
	
	/**
	 *	 @return Devuelve un iterador constante a la posicion de 
	 *	 clave, o al final del diccionario si clave no encontrada
	 */
	ConstIterator cbusca(const tClave &clave) const  {
		// Obtenemos el índice asociado a la clave.
		unsigned int ind = ::h(clave) % _tabla._tam;
		
		// Buscamos un nodo que contenga esa clave.
		Nodo *nodo = buscaNodo(clave, _tabla._v[ind]);
		
		// si nodo == NULL, devuelve en realidad cend()
		return ConstIterator(this, nodo, ind);
	}
	
	// //
	// ITERADOR NO CONSTANTE Y FUNCIONES RELACIONADAS
	// //
	
	/**
	 *	 Clase interna que implementa un iterador que permite recorrer 
	 *   la tabla e incluso alterar el valor de sus elementos.
	 */
	class Iterator {
	public:
		Iterator() : _diccionario(NULL), _act(NULL), _ind(0) {}
		void next() {
			if (_act == NULL) throw EAccesoNoValido2();
			
			// Buscamos el siguiente nodo de la lista de nodos.
			_act = _act->_sig;
			
			// Si hemos llegado al final de la lista de nodos, seguimos
			// buscando por el vector _v.
			while ((_act == NULL) && (_ind < _diccionario->_tabla._tam - 1)) {
				++_ind;
				_act = _diccionario->_tabla._v[_ind];
			}
		}
		
		const tClave &clave() const {
			if (_act == NULL) throw EAccesoNoValido2();
			return _act->_clave;
		}
		
		tValor &valor() const {
			if (_act == NULL) throw EAccesoNoValido2();
			return _act->_valor;
		}

		void setVal(const tValor& v) {
			if (_act == NULL) throw EAccesoNoValido2();
			_act->_valor = v;
		}
		
		bool operator==(const Iterator &other) const {
			return _act == other._act;
		}
		
		bool operator!=(const Iterator &other) const {
			return !(this->operator==(other));
		}
	protected:
		// Para que pueda construir objetos del tipo iterador
		friend class DiccionarioHash;
		
		Iterator(DiccionarioHash* diccionario, Nodo* act, unsigned int ind) 
		: _diccionario(diccionario), _act(act), _ind(ind) { }
		
		DiccionarioHash* _diccionario;  ///< Diccionario que se está recorriendo
		Nodo* _act;             ///< Puntero al nodo actual del recorrido
		unsigned int _ind;      ///< Índice actual en el vector _v
	};
	
	/**
	 *	 Devuelve el iterador al principio de la tabla.
	 *	 @return iterador al principio de la tabla;
	 *	 coincidirá con final() si la tabla está vacía.
	 */
	Iterator begin() {
		unsigned int ind = 0;
		Nodo *act = _tabla._v[0];
		while (ind < _tabla._tam-1 && act == NULL) {
			ind++;
			act = _tabla._v[ind];
		}
		return Iterator(this, act, ind);        
	}
	
	/**
	 *	 @return Devuelve un iterador al final del recorrido
	 *	 (fuera de éste).
	 */
	Iterator end()  {
		return Iterator(this, NULL,0);
	}
	
	/**
	 *	 @return Devuelve un iterador a la posicion de 
	 *	 clave, o al final del recorrido si clave no encontrada
	 */
	Iterator busca(const tClave &clave) {
		// Obtenemos el índice asociado a la clave.
		unsigned int ind = ::h(clave) % _tabla._tam;
		
		// Buscamos un nodo que contenga esa clave.
		Nodo *nodo = buscaNodo(clave, _tabla._v[ind]);
		
		// si nodo == NULL, devuelve en realidad cend()
		return Iterator(this, nodo, ind);
	}
	
	
	// //
	// MÉTODOS DE "FONTANERÍA" DE C++ QUE HACEN VERSÁTIL
	// A LA CLASE
	// //
	
	/** Constructor copia */
	DiccionarioHash(const DiccionarioHash &other) {
		copia(_tabla,other._tabla);
	}
	
	/** Operador de asignación */
	DiccionarioHash &operator=(const DiccionarioHash &other) {
		if (this != &other) {
			libera(_tabla);
			copia(_tabla,other._tabla);
		}
		return *this;
	}


	

private:
	
	// Para que el iterador pueda acceder a la parte privada
	friend class Iterador;    


	/**
	* Inserta un par clave-valor en la tabla.
	*/
	static void insertaAux(Tabla& tabla, const tClave &clave, const tValor &valor) {
		// Si la ocupación es muy alta ampliamos la tabla
		float ocupacion = 100 * ((float)tabla._numElems) / tabla._tam;
		if (ocupacion > MAX_OCUPACION)
			amplia(tabla);

		// Obtenemos el índice asociado a la clave.
		unsigned int ind = ::h(clave) % tabla._tam;

		// Si la clave ya existía, actualizamos su valor
		Nodo *nodo = buscaNodo(clave, tabla._v[ind]);
		if (nodo != NULL) {
			nodo->_valor = valor;
		}
		else {
			// Si la clave no existía, creamos un nuevo nodo y lo insertamos
			// al principio
			tabla._v[ind] = new Nodo(clave, valor, tabla._v[ind]);
			tabla._numElems++;
		}
	}

	/**
	* Borra una clave de la tabla.
	*/
	static void borraAux(Tabla& tabla, const tClave& clave) {
		// Obtenemos el índice asociado a la clave.
		unsigned int ind = ::h(clave) % tabla._tam;

		// Buscamos el nodo que contiene esa clave y el nodo anterior.
		Nodo *act = tabla._v[ind];
		Nodo *ant = NULL;
		buscaNodo(clave, act, ant);

		if (act != NULL) {

			// Sacamos el nodo de la secuencia de nodos.
			if (ant != NULL) {
				ant->_sig = act->_sig;
			}
			else {
				tabla._v[ind] = act->_sig;
			}

			// Borramos el nodo extraído.
			delete act;
			tabla._numElems--;
		}
	}

	/**
	* Busca el valor asociado a una clave en la tabla.
	*/
	static tValor &buscaAux(const Tabla& tabla, const tClave &clave) {
		// Obtenemos el índice asociado a la clave.
		unsigned int ind = ::h(clave) % tabla._tam;

		// Buscamos un nodo que contenga esa clave.
		Nodo *nodo = buscaNodo(clave, tabla._v[ind]);
		if (nodo == NULL)
			throw EClaveErronea2();

		return nodo->_valor;
	}


	/**
	 * Libera toda la memoria dinámica reservada para la tabla.
	 */
	static void libera(Tabla& tabla) {
		
		// Liberamos las listas de nodos.
		for (unsigned int i=0; i<tabla._tam; i++) {
			liberaNodos(tabla._v[i]);
		}
		
		// Liberamos el array de punteros a nodos.
		if (tabla._v != NULL) {
			delete[] tabla._v;
			tabla._v = NULL;
		}
		tabla._tam = 0;
		tabla._numElems = 0;
	}
	
	/**
	 * Libera un nodo y todos los siguientes.
	 *
	 * @param prim puntero al primer nodo de la lista a liberar.
	 */
	static void liberaNodos(Nodo *prim) {
		
		while (prim != NULL) {
			Nodo *aux = prim;
			prim = prim->_sig;
			delete aux;
		}       
	}
	
	/**
	 * Hace una copia de la tabla que recibe como parámetro. Antes de llamar
	 * a este método se debe invocar al método "libera".
	 *
	 * @param other tabla que se quiere copiar.
	 */
	static void copia(Tabla& tabla, const Tabla &other) {
		tabla._tam = other._tam;
		tabla._numElems = other._numElems;
		
		// Reservar memoria para el array de punteros a nodos.
		tabla._v = new Nodo*[tabla._tam];
		for (unsigned int i=0; i<tabla._tam; ++i) { 
			tabla._v[i] = NULL;
			
			// Copiar la lista de nodos de other._v[i] a _v[i].
			// La lista de nodos queda invertida con respecto a la original.
			Nodo *act = other._v[i];
			while (act != NULL) {
				tabla._v[i] = new Nodo(act->_clave, act->_valor, tabla._v[i]); 
				act = act->_sig;
			}
		}
	}
	
	/**
	 * Este método duplica la capacidad del array de punteros actual.
	 */
	static void amplia(Tabla& tabla) {
		// Creamos un puntero al array actual y anotamos su tamaño.
		Nodo **vAnt = tabla._v;
		unsigned int tamAnt = tabla._tam;
		
		// Duplicamos el array en otra posición de memoria.
		tabla._tam *= 2; 
		tabla._v = new Nodo*[tabla._tam];
		for (unsigned int i=0; i<tabla._tam; ++i)
			tabla._v[i] = NULL;
		
		// Recorremos el array original moviendo cada nodo a la nueva 
		// posición que le corresponde en el nuevo array.
		for (unsigned int i=0; i<tamAnt; ++i) {
			
			// IMPORTANTE: Al modificar el tamaño también se modifica el índice
			// asociado a cada nodo. Es decir, los nodos se mueven a posiciones
			// distintas en el nuevo array.
			
			// NOTA: por eficiencia movemos los nodos del array antiguo al 
			// nuevo, no creamos nuevos nodos. 
			
			// Recorremos la lista de nodos
			Nodo *nodo = vAnt[i];
			while (nodo != NULL) {
				Nodo *aux = nodo;
				nodo = nodo->_sig;
				
				// Calculamos el nuevo índice del nodo, lo desenganchamos del 
				// array antiguo y lo enganchamos al nuevo.
				unsigned int ind = ::h(aux->_clave) % tabla._tam;
				aux->_sig = tabla._v[ind];
				tabla._v[ind] = aux;
			}
		}
		
		// Borramos el array antiguo (ya no contiene ningún nodo).
		delete[] vAnt;
	}
	
	/**
	 * Busca un nodo a partir del nodo "act" que contenga la clave dada. Si lo 
	 * encuentra, "act" quedará apuntando a dicho nodo y "ant" al nodo anterior.
	 * Si no lo encuentra "act" quedará apuntando a NULL.
	 *
	 * @param clave clave del nodo que se busca.
	 * @param act [in/out] inicialmente indica el primer nodo de la búsqueda y 
	 *            al finalizar indica el nodo encontrado o NULL.
	 * @param ant [out] puntero al nodo anterior a "act" o NULL.
	 */
	static void buscaNodo(const tClave &clave, Nodo* &act, Nodo* &ant) {
		ant = NULL;
		bool encontrado = false;
		while ((act != NULL) && !encontrado) {
			
			// Comprobar si el nodo actual contiene la clave buscada
			if (act->_clave == clave) {
				encontrado = true;
			} else {
				ant = act;
				act = act->_sig;
			}
		}
	}
	
	/**
	 * Busca un nodo a partir de "prim" que contenga la clave dada. A 
	 * diferencia del otro método "buscaNodo", este no devuelve un puntero al
	 * nodo anterior.
	 *
	 * @param clave clave del nodo que se busca.
	 * @param prim nodo a partir del cual realizar la búsqueda. 
	 * @return nodo encontrado o NULL.
	 */
	static Nodo* buscaNodo(const tClave &clave, Nodo* prim) {
		Nodo *act = prim;
		Nodo *ant;
		buscaNodo(clave, act, ant);
		return act;
	}
	
	/**
	 * Ocupación máxima permitida antes de ampliar la tabla en tanto por cientos.
	 */
	static const unsigned int MAX_OCUPACION = 80;

	
};

#endif //__DICCIO2_H
