#ifndef _RACIONAL_H
#define _RACIONAL_H

#include <iostream>
#include <string>

using namespace std;

class Racional {
public:
	//Excepcion que se lanza cuando se trata de crear
	//una fraccion con denominador 0
	class EDenominadorCero {};
	//Excepcion que se lanza cuando se produce una division
	//por 0
	class EDivisionPorCero {};

	// Funcion que permite escribir una fraccion en un 'stream'
	friend ostream& operator<<(ostream& out, const Racional& f);

	//**** COMPLETAR
	//  Deben declararse los metodos publicos de la clase
	//****
	Racional(long _numer, long _denom) {
		this->_numer = _numer;
		this->_denom = _denom;
		if (_denom == 0) throw EDenominadorCero();
		if (_numer == 0) throw EDivisionPorCero();

		reduce();
	}

	Racional() {
		_numer = 0;
		_denom = 1;

	}
	Racional operator*(const Racional& r1);
	Racional operator-(const Racional& r1);
	Racional& operator=(const Racional& r1);
	Racional operator*=(const Racional& r1);
	bool operator==(const Racional& r1);
	Racional suma(const Racional& v1);
	void divideYActualiza(Racional r1);

private:
	long _numer;     // El numerador
	long _denom;     // El denominador 
	void reduce();   // Transforma la fraccion en una equivalente irreducible (es decir, una en la que
	// el denominador es siempre positivo, y el unico divisor comun del numerador y el 
	// denominador es 1)	
	static long mcm(long v1, long v2);     // Minimo comun multiplo de v1 y v2
	static long mcd(long v1, long v2);     // Maximo comun divisor de v1 y v2 

	void init();


};

#endif

