// NO MODIFIQUES NADA DE LO QUE APARECE EN ESTE FICHERO

#include "Apetitoxo.h"

#include <iostream>
#include <string>
using namespace std;


void admite(Apetitoxo& apetitoxo) {
	tDni dni;
	tFecha fecha;
	cin >> dni >> fecha;
	try {
		apetitoxo.annadeSolicitud(dni, fecha);
		cout << "OK" << endl;
	}
	catch (EErrorCliente) {
		cout << "CLIENTE EN LA FILA" << endl;
	}
}


void enEspera(const Apetitoxo& apetitoxo) {
	tDni dni;
	cin >> dni;
	try {
		tFecha f;
		f = apetitoxo.enEspera(dni);
		cout << "Fecha solicitada: " << f << endl;
	}
	catch (EErrorCliente) {
		cout << "NO EN ESPERA" << endl;
	}
}


void primeroEnEspera(const Apetitoxo& apetitoxo) {
	tDni dni;
	try {
		apetitoxo.primeroEnEspera(dni);
		cout << "Primera solicitud: " << dni << endl;
	}
	catch (ENoHaySolicitudes) {
		cout << "NO HAY SOLICITUDES" << endl;
	}
}


void atiendeSolicitud(Apetitoxo& apetitoxo) {
	if (apetitoxo.atiendeSolicitud())
		cout << "OK" << endl;
	else
		cout << "SIN EFECTO" << endl;
}


void disponible(const Apetitoxo& apetitoxo) {
	tFecha fecha;
	cin >> fecha;
	if (apetitoxo.disponible(fecha))
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
}


void mostrarListaReservas(const Lista<tReserva>& l) {
	Lista<tReserva>::ConstIterator it = l.cbegin();
	while (it != l.cend()) {
		cout << it.elem().getFecha() << " - " << it.elem().getDni() << "  //  ";
		it.next();
	}
}

void reservas(const Apetitoxo& apetitoxo) {
	cout << "Reservas: ";
	mostrarListaReservas(apetitoxo.reservas());
	cout << endl;
}


void cede(Apetitoxo& apetitoxo) {
	tDni dni_del_que_cede, dni_nuevo;
	tFecha fecha_nuevo;
	cin >> dni_del_que_cede >> dni_nuevo >> fecha_nuevo;
	try {
		apetitoxo.cedePuesto(dni_del_que_cede, dni_nuevo, fecha_nuevo);
		cout << "OK" << endl;
	}
	catch (EErrorCliente) {
		cout << "NO SE CEDE PUESTO" << endl;
	}
}



int main() {
	Apetitoxo apetitoxo;
	string comando;

	while (cin >> comando) {
		if (comando == "admite") admite(apetitoxo);
		else if (comando == "enEspera") enEspera(apetitoxo);
		else if (comando == "primero") primeroEnEspera(apetitoxo);
		else if (comando == "atiende") atiendeSolicitud(apetitoxo);
		else if (comando == "disponible") disponible(apetitoxo);
		else if (comando == "reservas") reservas(apetitoxo);
		else if (comando == "cede") cede(apetitoxo);
	}
	return 0;
}