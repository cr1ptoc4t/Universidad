/*
Número de grupo:G25

Nombre y apellidos de los autores de la práctica (si alguno de los miembros del grupo
no hay realizado la práctica, no debe incluirse su nombre): 
Alai Miranda Blanco
Catalina Fullana Mora
*/

using namespace std;
#include <iostream>

#ifndef _MEMORIA_H_
#define _MEMORIA_H_

/// Excepción de direccion invalida
class EDireccionInvalida {
};

/// Excepción de celda sin inicializar
class ECeldaSinInicializar {
};

template<class T>
class Memoria {
private:
	unsigned int _capacidad;
	
	T** _celdas;
	
public:
	/**
	 * crea una memoria con 'capacidad' celdas.
	 */

	Memoria(unsigned int capacidad) {
		_capacidad = capacidad;
		_celdas = new T * [_capacidad];

		for (unsigned int i = 0; i < _capacidad; ++i) {
			_celdas[i] = nullptr;
		}
	}
	
	//constructor de copia
	Memoria(const Memoria& m) {
		this->_capacidad = m._capacidad;
		this->_celdas = new T * [_capacidad];

		for (unsigned int i = 0; i < m._capacidad; i++) {
			if (m._celdas[i] != nullptr) {
				this->_celdas[i] = new T(*m._celdas[i]);
			}
			else {
				this->_celdas[i] = nullptr;
			}
		}	

	}
	/*
	~Memoria() {
		for (unsigned int i = 0; i < _capacidad; i++) {
			delete _celdas[i];
			_celdas[i] = nullptr;
		}
		delete[] _celdas; 
	}
	*/

	/**
	 * Devuelve el valor almacenado en la celda 'd'.
	 * Si 'd' está fuera de rango, levanta EDireccionInvalida.
	 * Si la celda 'd' no está inicializada, levanta ECeldaSinInicializar.
	 */

	const T& valor(unsigned int d) const {
		if (d < 0 || d >= _capacidad) throw EDireccionInvalida();
		else if (_celdas[d] == nullptr) throw ECeldaSinInicializar();
		else return *_celdas[d];

	}

	/**
	 * Almacena 'v' en la celda 'd'.
	 * Si 'd' está fuera de rango, levanta EDireccionInvalida.
	 */
	void almacena(unsigned  d, const T& v) {
		if (d < 0 || d >= _capacidad)
			throw EDireccionInvalida();
		else{
			if (_celdas[d] == nullptr) {
				_celdas[d] = new T(v);
			}
			else {
				*_celdas[d] = v;
			}
		}
	}

	/**
	 * Devuelve 'true' si la celda 'd' está inicializada.
	 * En otro caso devuelve 'false'.
	 * Si 'd' está fuera de rango, levanta EDireccionInvalida.
	 */
	bool inicializada(unsigned int d) const {
		// A implementar 
		if (d < 0 || d >= _capacidad ) throw EDireccionInvalida();
		else return _celdas[d] != nullptr;
	}

	
	
	//operador de asignacion
	Memoria& operator=(const Memoria& m1) {
		
		if (&m1!=this) {

			//si la nueva memoria es mayor
			if (_capacidad < m1._capacidad) {
				//redimensionamos el array this a longitud m1._capacidad

				//eliminamos todo
				for (unsigned int i = 0; i < _capacidad; i++) {
					delete _celdas[i];
					_celdas[i] = nullptr;
				}
				delete[] _celdas;

				//reconstruimos
				this->_celdas = new T * [m1._capacidad];
				
				//todo a null
				for (int i = 0; i < m1._capacidad; i++)
					_celdas[i] = nullptr;
			}
			//copiamos al nuevo
			for (int i = 0; i < m1._capacidad; i++)
				_celdas[i] = m1._celdas[i];
			//nueva capacidad
			this->_capacidad = m1._capacidad;

		}
		return *this;
	}



	void muestra() {
		cout << _capacidad << endl;
		for (int i = 0; i < _capacidad; i++)
			if(_celdas[i] == nullptr)
				cout << i << "- \t" << "nullptr" << "\t" << endl;
			else
				cout << i << "- \t" << _celdas[i] << "\t" << endl;

	}

	/* Implementar el resto de operaciones y métodos necesarios
	   para que la implementación funcione */

//private:
	/* Declarar los campos necesarios para representar los
	   valores de este TAD, así como las operaciones auxiliares
	   que se consideren oportunas */

};


#endif


