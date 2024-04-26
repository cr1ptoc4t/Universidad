// NO MODIFIQUES NADA DE LO QUE APARECE EN ESTE FICHERO

#include <iostream>
#include <string>
using namespace std;
#include "biblioteca.h"


void registraLibro(Biblioteca& biblio) {
	tSignatura sign;
	tNumEjemplares nej;
	cin >> sign >> nej;
	try {
		biblio.annadir_libro(sign, nej);
		cout << "REGISTRO_LIBRO_OK" << endl;
	}
	catch (ELibroExistente) {
		cout << "ERROR_LIBRO_DUPLICADO" << endl;
	}
}

void registraSocio(Biblioteca& biblio) {
	tCodigo codigo;
	tNombre nombre;
	cin >> codigo >> nombre;
	try {
		biblio.annadir_socio(codigo, nombre);
		cout << "REGISTRO_SOCIO_OK" << endl;
	}
	catch (ESocioExistente) {
		cout << "ERROR_SOCIO_DUPLICADO" << endl;
	}
}

void prestar(Biblioteca& biblio) {
	tSignatura sign;
	tCodigo id;
	tFecha fecha;
	cin >> sign >> id >> fecha;
	try {
		unsigned int resultado = biblio.prestar(sign, id, fecha);
		if (resultado == 0) cout << "PRESTAMO_PREVIO" << endl;
		else if (resultado == 1) cout << "PRESTAMO_OK" << endl;
		else if (resultado == 2) cout << "EN_ESPERA" << endl;
	}
	catch (EPrestamoNoAdmitido) {
		cout << "ERROR_PRESTAMO" << endl;
	}
}

void primeraEspera(Biblioteca& biblio) {
	tSignatura sign;
	cin >> sign;
	try {
		Codigo_y_Nombre cod_nom = biblio.primeroEnEspera(sign);
		cout << "PRIMERA ESPERA PARA SIGNATURA " << sign << " = " << cod_nom.id << " - " << cod_nom.n << endl;
	}
	catch (ELibroInexistente) {
		cout << "ERROR_LIBRO_INEXISTENTE" << endl;
	}
	catch (ESinEsperas) {
		cout << "ERROR_LISTA_ESPERA_VACIA" << endl;
	}
}

void mostrarListaSignaturaFecha(const Lista<Signatura_y_Fecha>& l) {
	Lista<Signatura_y_Fecha>::ConstIterator it = l.cbegin();
	while (it != l.cend()) {
		cout << it.elem().signatura << " - " << it.elem().fecha << "  //  ";
		it.next();
	}
}

void prestados(const Biblioteca& biblio) {
	tCodigo id;
	cin >> id;
	try {
		cout << "PRESTADOS: ";
		mostrarListaSignaturaFecha(biblio.prestados(id));
		cout << endl;
	}
	catch (ESocioInexistente) {
		cout << "ERROR_SOCIO_INEXISTENTE" << endl;
	}
}

void devolver(Biblioteca& biblio) {
	tSignatura sign;
	tCodigo id;
	tFecha fecha;
	cin >> sign >> id >> fecha;
	try {
		if (biblio.devolver(sign, id, fecha))
			cout << "DEVOLUCION_OK" << endl;
		else
			cout << "LIBRO_NO_PRESTADO_AL_SOCIO" << endl;
	}
	catch (EDevolucionNoAdmitida) {
		cout << "ERROR_DEVOLUCION" << endl;
	}
}


int main() {
	Biblioteca biblio;
	string comando;

	while (cin >> comando) {
		if (comando == "registraLibro") registraLibro(biblio);
		else if (comando == "registraSocio") registraSocio(biblio);
		else if (comando == "prestaLibro") prestar(biblio);
		else if (comando == "primeraEspera") primeraEspera(biblio);
		else if (comando == "prestados") prestados(biblio);
		else if (comando == "devolver") devolver(biblio);
	}
	return 0;
}

