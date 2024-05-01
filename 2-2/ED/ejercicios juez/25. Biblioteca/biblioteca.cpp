/**
  NOMBRE Y APELLIDOS:	Catalina Fullana Mora
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#include "biblioteca.h"
#include "Cola.h"
#include "Diccionario.h"
#include <iostream>
using namespace std;

Diccionario <tSignatura, tNumEjemplares> _libros;

Diccionario <tCodigo, tNombre> _socios;

Diccionario <tSignatura, Cola<Codigo_y_Nombre>> _lista_espera;

Diccionario <tCodigo, Lista<Signatura_y_Fecha>> _prestados_a;

void actualizalibros(tSignatura s, int n);

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

	if (!_socios.contiene(id)||!_libros.contiene(signatura)){
		throw EPrestamoNoAdmitido();
	}
	else if (socio_tiene_libro(id, signatura)) {
		return 0;
	}	else if (_libros.valorPara(signatura)>0) {
		//si quedan libros
		//si has prestado alguno al user
		if (_prestados_a.contiene(id)) {
			Diccionario<tCodigo, Lista<Signatura_y_Fecha>>::Iterator t = _prestados_a.busca(id);
			Signatura_y_Fecha s;
			s.signatura = signatura;
			s.fecha = fecha;

			t.valor().pon_final(s);
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

		actualizalibros(signatura, -1);

		return 1;
	}
	else {
		if (!_lista_espera.contiene(signatura)) {
			Cola<Codigo_y_Nombre> c;
			_lista_espera.inserta(signatura, c);
		}



		Diccionario <tSignatura, Cola<Codigo_y_Nombre>>::Iterator t = _lista_espera.busca(signatura);

		Codigo_y_Nombre aux;
		aux.id = id;
		aux.n = _socios.valorPara(id);

		t.valor().pon(aux);

		return 2;
	}
}

void actualizalibros(tSignatura s, int n) {

	Diccionario <tSignatura, tNumEjemplares>:: Iterator it = _libros.busca(s);
	if (it != _libros.end())
		it.valor() += n;
	else
		_libros.inserta(s, n);
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
Codigo_y_Nombre Biblioteca::primeroEnEspera(tSignatura signatura) const {
	if (!_libros.contiene(signatura))
		throw ELibroInexistente();
	else if (_lista_espera.contiene(signatura) && !_lista_espera.valorPara(signatura).esVacia())
		return  _lista_espera.valorPara(signatura).primero(); 
	else
		throw ESinEsperas();
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
	}else
		return _prestados_a.valorPara(id);
	
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
		Lista<Signatura_y_Fecha> l = _prestados_a.valorPara(id);

		Lista<Signatura_y_Fecha>::Iterator t = l.begin();
		while (t!= l.end() && t.elem().signatura != signatura) {
			t.next();
		}


		l.eliminar(t);
		_prestados_a.inserta(id, l);
		

		bool prestado = false;
		if (_lista_espera.contiene(signatura)&&!_lista_espera.valorPara(signatura).esVacia()) {
			Diccionario <tSignatura, Cola<Codigo_y_Nombre>>::Iterator t = _lista_espera.busca(signatura);

			if (t != _lista_espera.end()) {
				//buscar persona
				tCodigo c = t.valor().primero().id;

				//insertar en prestados
				Signatura_y_Fecha s;
				s.fecha = fecha;
				s.signatura = signatura;

				
				if(_prestados_a.contiene(c))
					_prestados_a.busca(c).valor().pon_final(s);
				else {
					Lista<Signatura_y_Fecha> l;
					l.pon_final(s);
					_prestados_a.inserta(c, l);
				}
				//eliminar del anterior dueño
				Lista<Signatura_y_Fecha> l =_prestados_a.valorPara(id);
				Lista<Signatura_y_Fecha>::Iterator it = l.begin();

				while (it != l.end()&& it.elem().signatura!=signatura) {
					it.next();
				}

				if(it!=l.end())
					l.eliminar(it);

				_prestados_a.inserta(id,l);

				//borrar de lista de espera
				_lista_espera.busca(signatura).valor().quita();


				prestado = true;
			}
		} 



		if(!prestado)  //eliminar de libros
			actualizalibros(signatura, 1);

		/*
		// prestar al siguiente de la lista
		if (_lista_espera.contiene(signatura) && !_lista_espera.valorPara(signatura).esVacia()) {
			//a quien le prestaremos
			Codigo_y_Nombre cod = primeroEnEspera(signatura);
			
			//buscamos si existe lista de espera
			Diccionario <tSignatura, Cola<Codigo_y_Nombre>>::Iterator t = _lista_espera.busca(signatura);
			
			if (t != _lista_espera.end()) {
				Lista<Signatura_y_Fecha> l;
				if(_prestados_a.contiene(cod.id))
					l = _prestados_a.valorPara(cod.id);

				Signatura_y_Fecha f;
				f.fecha = fecha;
				f.signatura = signatura;
				l.pon_final(f);
				_prestados_a.inserta(cod.id, l);

				t.valor().quita();
				prestado = true;
				if (t.valor().esVacia())
					_lista_espera.borra(t.clave());
			}
		}
		*/

		return true;
	}

}

bool Biblioteca::socio_tiene_libro(tCodigo id, tSignatura signatura) {
	if (!_prestados_a.contiene(id))
		return false;
	else {
		Lista <Signatura_y_Fecha> lista = _prestados_a.valorPara(id);

		return estaLibro(lista, signatura);
	}
}

bool Biblioteca::estaLibro(Lista<Signatura_y_Fecha> l, tSignatura signatura) {
	int i = 0;
	while (i < l.longitud() && l.elem(i).signatura != signatura)
		i++;

	if (i == l.longitud())
		return false;
	else
		return true;
}