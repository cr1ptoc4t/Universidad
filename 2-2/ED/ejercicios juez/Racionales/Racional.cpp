#include "Racional.h"
#include <cmath>

//Metodos publicos

  //**** COMPLETAR
  //  Deben implementarse los metodos publicos de la clase
  //****


// Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

// Metodos privados
void Racional::reduce() {
	// Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	// Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	// El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1);
	v2 = abs(v2);
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1 % v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1 * v2 / mcd(v1, v2);
}

Racional Racional::suma(const Racional& v1) {
	long resultado_numerador = (_numer * v1._denom) + (_denom * v1._numer);
	long resultado_denominador = _denom * v1._denom;
	if (resultado_denominador == 0) throw EDivisionPorCero();
	return Racional(resultado_numerador, resultado_denominador);
}

void Racional::init() {
	if (_denom == 0) throw EDenominadorCero();
	//if (_numer == 0) throw EDivisionPorCero();

	reduce();
}

void Racional::divideYActualiza(Racional r1) {
	_denom = _denom * r1._numer;
	_numer = _numer * r1._denom;
	if (_denom == 0) throw EDivisionPorCero();
	init();
}


Racional Racional:: operator*(const Racional& r1) {
	if (_denom == 0 || r1._numer == 0)throw EDivisionPorCero();
	if (r1._denom == 0 || _numer == 0)throw EDenominadorCero();

	return Racional(r1._numer * _numer, r1._denom * _denom);
}
Racional Racional:: operator-(const Racional& r1) {
	long nuevo_numerador = _numer * mcm(r1._denom, this->_denom) / _denom - r1._numer * mcm(r1._denom, this->_denom) / r1._denom;
	long nuevo_denominador = mcm(r1._denom, this->_denom);
	return Racional(nuevo_numerador, nuevo_denominador);
}
Racional& Racional::operator= (const Racional& r1) {
	_denom = r1._denom;
	_numer = r1._numer;

	return *this;
}

bool Racional::operator==(const Racional& r1) {
	if (_denom == r1._denom && _numer == r1._numer)
		return true;
	else
		return false;
}

Racional Racional:: operator*=(const Racional& r1) {

	if (_denom == 0 || r1._numer == 0)throw EDivisionPorCero();
	if (r1._denom == 0 || _numer == 0)throw EDenominadorCero();
	_numer *= r1._numer;
	_denom *= r1._denom;
	return Racional(_numer, _denom);
}



