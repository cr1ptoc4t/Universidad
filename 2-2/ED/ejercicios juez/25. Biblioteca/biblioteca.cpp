/**
  NOMBRE Y APELLIDOS:	Catalina Fullana Mora
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#include "biblioteca.h"
#include "Cola.h"
#include "Diccionario.h"
#include <iostream>
using namespace std;


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
	
	_libros.inserta(signatura, num_ejemplares);
	Cola<Codigo_y_Nombre> aux;
	_lista_espera.inserta(signatura, aux);
	
}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
void Biblioteca::annadir_socio(tCodigo id, tNombre nombre) {
	// A IMPLEMENTAR
	if (_socios.contiene(id))
		throw ESocioExistente();
	
	_socios.inserta(id, nombre);

	DiccionarioHash<tSignatura, tFecha> aux;
	_prestados_a.inserta(id, aux);

	Diccionario<tSignatura, tFecha> aux_ordenado;
	_prestados_a_ordenado.inserta(id, aux_ordenado);
}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
unsigned int Biblioteca::prestar(tSignatura signatura, tCodigo id, tFecha fecha) {

	if (!_socios.contiene(id)||!_libros.contiene(signatura)){
		throw EPrestamoNoAdmitido();
	}
	else if (socio_tiene_libro(id, signatura)) {
		return 0;
	}
	
	if (_libros.valorPara(signatura)>0) {
		_prestados_a.busca(id).valor().inserta(signatura, fecha);
		_prestados_a_ordenado.busca(id).valor().inserta(signatura, fecha);
		actualizalibros(signatura, -1);

		return 1;
	}
	else {
		if (!_lista_espera.contiene(signatura)) {
			Cola<Codigo_y_Nombre> c;
			_lista_espera.inserta(signatura, c);
		}

		DiccionarioHash <tSignatura, Cola<Codigo_y_Nombre>>::Iterator t = _lista_espera.busca(signatura);

		Codigo_y_Nombre aux;
		aux.id = id;
		aux.n = _socios.valorPara(id);

		t.valor().pon(aux);

		return 2;
	}
}

void Biblioteca::actualizalibros(tSignatura s, int n) {
	DiccionarioHash <tSignatura, tNumEjemplares>:: Iterator aux = _libros.busca(s);
	if (aux != _libros.end())
		aux.valor() += n;
	else
		_libros.inserta(s, n);
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
Codigo_y_Nombre Biblioteca::primeroEnEspera(tSignatura signatura) const {
	if (!_libros.contiene(signatura))
		throw ELibroInexistente();
	else if (_lista_espera.valorPara(signatura).esVacia())
		throw ESinEsperas();
	else 
		return  _lista_espera.valorPara(signatura).primero(); 
	
}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
Lista<Signatura_y_Fecha> Biblioteca::prestados(tCodigo id) const {
	if (!_socios.contiene(id))
		throw ESocioInexistente();
	else if (!_prestados_a.contiene(id)) {
		Lista<Signatura_y_Fecha> l;
		return l;
	}
	else {
		Lista <Signatura_y_Fecha> lista_ret;
		
		Diccionario<tSignatura, tFecha> aux_ord = _prestados_a_ordenado.valorPara(id);
		Diccionario<tSignatura, tFecha>::ConstIterator aux2 = aux_ord.cbegin();


		while (aux2 != _prestados_a_ordenado.valorPara(id).cend()) {
			Signatura_y_Fecha s;
			s.signatura = aux2.clave();
			s.fecha = aux2.valor();
			lista_ret.pon_final(s);

			aux2.next();
		}

		return lista_ret;
	}
	
}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/

bool Biblioteca::devolver(tSignatura signatura, tCodigo id, tFecha fecha) {
	if (!_libros.contiene(signatura) || !_socios.contiene(id))
		throw EDevolucionNoAdmitida();

	else if (_libros.contiene(signatura) && _socios.contiene(id) && !socio_tiene_libro(id, signatura))
		return false;
	
	else {
		//para cada diccionario, editamos valor
		DiccionarioHash<tCodigo, DiccionarioHash<tSignatura,tFecha>>::Iterator it = _prestados_a.busca(id);
		it.valor().borra(signatura);
		
		DiccionarioHash<tCodigo, Diccionario<tSignatura,tFecha>>::Iterator it2 = _prestados_a_ordenado.busca(id);
		it2.valor().borra(signatura);

		actualizalibros(signatura, 1);

		//si la lista no es vacia - prestamos al siguiente
		if (_lista_espera.contiene(signatura)&&!_lista_espera.valorPara(signatura).esVacia()) {
			tCodigo nuevo_adquiridor = _lista_espera.busca(signatura).valor().primero().id;

			(_prestados_a.busca(nuevo_adquiridor)).valor().inserta(signatura, fecha);


			_prestados_a_ordenado.busca(nuevo_adquiridor).valor().inserta(signatura, fecha);
			actualizalibros(signatura, -1);

			_lista_espera.busca(signatura).valor().quita();
		}

		return true;
	}

}

bool Biblioteca::socio_tiene_libro(tCodigo id, tSignatura signatura) {
	return _prestados_a.valorPara(id).contiene(signatura);
}

bool Biblioteca::estaLibro(Lista<Signatura_y_Fecha> l, tSignatura signatura) {

	return true;
}