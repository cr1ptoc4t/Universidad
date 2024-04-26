/**
  NOMBRE Y APELLIDOS:	Catalina Fullana Mora
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#include "biblioteca.h"
#include "Cola.h"
#include "DiccionarioHash.h"
#include <iostream>
using namespace std;

DiccionarioHash <tSignatura, tNumEjemplares> _libros;

DiccionarioHash <tCodigo, tNombre> _socios;

DiccionarioHash <tSignatura, Cola<Codigo_y_Nombre>> _cola_libros;

DiccionarioHash <tCodigo, Lista<Signatura_y_Fecha>> _prestados_a;


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
Biblioteca::Biblioteca() {
	// A IMPLEMENTAR

}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
void Biblioteca::annadir_libro(tSignatura signatura, tNumEjemplares num_ejemplares) {
	if (_libros.contiene(signatura))
		throw ELibroExistente();
	else
		_libros.inserta(signatura, num_ejemplares);
	
}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
void Biblioteca::annadir_socio(tCodigo id, tNombre nombre) {
	// A IMPLEMENTAR
	if (_socios.contiene(id))
		throw ESocioExistente();
	else {
		_socios.inserta(id, nombre);
	}
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
unsigned int Biblioteca::prestar(tSignatura signatura, tCodigo id, tFecha fecha) {
	// A IMPLEMENTAR
	if (!_socios.contiene(id)||!_libros.contiene(signatura)){
		throw EPrestamoNoAdmitido();
	}
	else if (_libros.valorPara(signatura)!=0) {
		if (_prestados_a.contiene(id)) {
			Lista<Signatura_y_Fecha> libros_aux = _prestados_a.valorPara(id);
			Signatura_y_Fecha s;
			s.signatura = signatura;
			s.fecha = fecha;

			libros_aux.pon_final(s);
			_prestados_a.inserta(id, libros_aux);
			
			int cantidad = _libros.valorPara(signatura);
			_libros.inserta(signatura, cantidad-1);

		}
		else {
			Lista<Signatura_y_Fecha> libros_aux;
			Signatura_y_Fecha s;
			s.signatura = signatura;
			s.fecha = fecha;

			libros_aux.pon_final(s);
			_prestados_a.inserta(id, libros_aux);

			int cantidad = _libros.valorPara(signatura);
			_libros.inserta(signatura, cantidad - 1);
		}
	}
	else {
		/*
		if (_cola_libros.contiene(signatura)) {
			Cola<Codigo_y_Nombre> c = _cola_libros.valorPara(signatura);
			c.pon(id);
			_cola_libros.inserta(signatura, c);
		}
		else {
			Cola<Codigo_y_Nombre> c;
			c.pon(id);
			_cola_libros.inserta(signatura, c);
		}
		*/
	}


	return 0;
}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
Codigo_y_Nombre Biblioteca::primeroEnEspera(tSignatura signatura) const {
	return _cola_libros.valorPara(signatura).primero();
}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
Lista<Signatura_y_Fecha> Biblioteca::prestados(tCodigo id) const {

	return _prestados_a.valorPara(id);
}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
bool Biblioteca::devolver(tSignatura signatura, tCodigo id, tFecha fecha) {

	return false;
}


