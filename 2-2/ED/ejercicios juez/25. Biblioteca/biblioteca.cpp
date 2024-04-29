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

DiccionarioHash <tSignatura, Cola<Codigo_y_Nombre>> _lista_espera;

DiccionarioHash <tCodigo, Lista<Signatura_y_Fecha>> _prestados_a;


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
Biblioteca::Biblioteca() {}


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
		return 0;
	}

	else if (_libros.valorPara(signatura)>0) {
		//si quedan libros

		//si has prestado alguno al user
		if (_prestados_a.contiene(id)) {
			Lista<Signatura_y_Fecha> libros_aux = _prestados_a.valorPara(id);
			Signatura_y_Fecha s;
			s.signatura = signatura;
			s.fecha = fecha;

			libros_aux.pon_final(s);
			_prestados_a.inserta(id, libros_aux);

		}
		//si no has prestado ninguno al user
		else {
			Lista<Signatura_y_Fecha> libros_aux;
			Signatura_y_Fecha s;
			s.signatura = signatura;
			s.fecha = fecha;

			libros_aux.pon_final(s);
			_prestados_a.inserta(id, libros_aux);
		}

		int cantidad = _libros.valorPara(signatura);
		_libros.inserta(signatura, cantidad - 1);

		return 1;
	}
	else {
		if (!_lista_espera.contiene(signatura)) {
			Cola<Codigo_y_Nombre> c = _lista_espera.valorPara(signatura);
			_lista_espera.inserta(signatura, c);
		}

		Cola<Codigo_y_Nombre> c1 = _lista_espera.valorPara(signatura);
		Codigo_y_Nombre aux;
		aux.id = id;
		aux.n = _socios.valorPara(id);

		c1.pon(aux);
		_lista_espera.inserta(signatura, c1);

		return 2;
	}

}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
Codigo_y_Nombre Biblioteca::primeroEnEspera(tSignatura signatura) const {
	if (_lista_espera.contiene(signatura) && !_lista_espera.valorPara(signatura).esVacia())
		return  _lista_espera.valorPara(signatura).primero();
	else if (!_libros.contiene(signatura))
		throw ELibroInexistente();
	else
		throw ESinEsperas();

	Codigo_y_Nombre c;
	return c;
}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
Lista<Signatura_y_Fecha> Biblioteca::prestados(tCodigo id) const {
	if (!_prestados_a.contiene(id)){
		throw ESocioInexistente();
		Lista <Signatura_y_Fecha> l;
		return l;
	}

	return _prestados_a.valorPara(id);
	
}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/

bool Biblioteca::devolver(tSignatura signatura, tCodigo id, tFecha fecha) {
	// Verificar si el libro y el socio existen
	if (!_libros.contiene(signatura) || !_socios.contiene(id)) {
		throw EDevolucionNoAdmitida();
	}

}
