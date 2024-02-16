using namespace std;
#include <iostream>

#ifndef _SECUENCIA_H_
#define _SECUENCIA_H_


/// Excepción de elemento inexistente
class ElementoInvalido {};

template<class T>
class Secuencia {
public:
	Secuencia() {
		// A IMPLEMENTA
		count = 0;
		capacidad = MAX;
		crear(capacidad);
	}


	void pon(const T& e) {
		// A IMPLEMENTAR

		if (count == capacidad)
			redimensionar();

		if (secuencia[count] != nullptr)
			delete secuencia[count];

		secuencia[count] = new T(e);

		count++;
	}

	void mostrar() {
		cout << endl << capacidad << " - " << count << endl;
		for (int i = 0; i < count; i++) {
			cout << i << " " << *secuencia[i] << endl;
		}
	}

	const T& elem(int i) {
		// A IMPLEMENTAR
		if (i > count - 1) throw ElementoInvalido();
		return *secuencia[i];
	}

	int num_elems() const {
		return count;
	}

	// DEBEN INCLUIRSE E IMPLEMENTARSE 
	// LAS OPERACIONES ADICIONALES
	// NECESARIAS PARA GARANTIZAR EL CORRECTO
	// FUNCIONAMIENTO DEL TAD
	Secuencia& operator=(const Secuencia& elem) {
		if (!(this == &elem)) {
			destruirSecuencia();
			crear(elem.capacidad);
			copiar(elem);
		}
		return *this;
	}
	bool& operator==(const Secuencia& elem) {
		bool ret = true;
		if (elem != this) {
			if (elem.num_elems() != count) {
				return false;
			}
			else {
				int i = count;
				while (i > 0 && elem.secuencia[i] == secuencia[i]) {
					i++;
				}
				if (i == 0) ret = true;
			}
		}
		return ret;
	}


private:
	// INCLUIR DETALLES DE REPRESENTACION Y OPERACIONES AUXILIARES
	T** secuencia;
	int count = -1;
	const int MAX = 2;
	int capacidad = 2;
	//tamaño 2n
	void redimensionar() {
		T** aux = new T * [capacidad];
		copiarA(aux);
		destruirSecuencia();
		crear(capacidad * 2);
		copiarDe(aux);
		capacidad *= 2;
	}

	void destruirSecuencia() {
		for (int i = 0; i < capacidad; i++) {
			delete secuencia[i];
			secuencia[i] = nullptr;
		}
		delete[] secuencia;
	}

	void crear(int dim) {
		secuencia = new T * [dim];
		for (int i = 0; i < dim; i++) {
			secuencia[i] = nullptr;
		}
	}

	void copiar(const Secuencia& elem) {
		if (&elem != this) {
			for (int i = 0; i < capacidad; i++) {
				delete secuencia[i];
				secuencia[i] = nullptr;
			}
			capacidad = elem.capacidad;
			count = elem.count;
			crear(capacidad); // Reservar memoria para los nuevos elementos

			for (int i = 0; i < count; ++i) {
				if (elem.secuencia[i] != nullptr)
					secuencia[i] = new T(*elem.secuencia[i]); // Copiar el objeto
			}
		}
	}
	void copiarDe(T** aux) {
		muestra(aux, capacidad);
		for (int i = 0; i < capacidad; i++) {
			if (secuencia[i] != nullptr) {
				delete secuencia[i]; // Liberar la memoria del objeto existente
				secuencia[i] = nullptr; // Asignar nullptr al puntero para evitar errores de doble liberación
			}

			if (aux[i] != nullptr) {
				delete secuencia[i];
				secuencia[i] = new T(*aux[i]);
			}
		}
	}
	void copiarA(T**& aux) {
		for (int i = 0; i < capacidad; i++)
			if (secuencia[i] != nullptr)
				aux[i] = new T(*secuencia[i]);
			else
				aux[i] = nullptr;
	}

	void muestra(T** aux, int dim) {
		for (int i = 0; i < dim; i++)
			if (aux[i] != nullptr)
				cout << i << ") " << *aux[i] << endl;
	}
};


#endif




