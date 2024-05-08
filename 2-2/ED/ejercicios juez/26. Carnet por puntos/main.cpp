#include "CarnetPorPuntos.h"

#include <iostream>
#include <string>
using namespace std;


void nuevo(CarnetPorPuntos& gestionPuntos) {
	string dni;
	cin >> dni;
	try {
		gestionPuntos.nuevo(dni);
		cout << "OK" << endl;
	}
	catch (EConductorDuplicado) {
		cout << "CONDUCTOR_YA_EXISTE" << endl;
	}
}

void ajustar(CarnetPorPuntos& gestionPuntos, bool a_favor) {
	string dni;
	unsigned int puntos;
	cin >> dni >> puntos;
	try {
		if (a_favor)
			gestionPuntos.recuperar(dni, puntos);
		else
			gestionPuntos.quitar(dni, puntos);
		cout << gestionPuntos.consultar(dni) << endl;
	}
	catch (EConductorNoExiste) {
		cout << "CONDUCTOR_NO_EXISTE" << endl;
	}
}

void quitar(CarnetPorPuntos& gestionPuntos) {
	ajustar(gestionPuntos, false);
}

void recuperar(CarnetPorPuntos& gestionPuntos) {
	ajustar(gestionPuntos, true);
}

void consultar(const CarnetPorPuntos& gestionPuntos) {
	string dni;
	cin >> dni;
	try {
		cout << gestionPuntos.consultar(dni) << endl;
	}
	catch (EConductorNoExiste) {
		cout << "CONDUCTOR_NO_EXISTE" << endl;
	}
}

void cuantos_con_puntos(const CarnetPorPuntos& gestionPuntos) {
	unsigned int puntos;
	cin >> puntos;
	try {
		cout << gestionPuntos.cuantos_con_puntos(puntos) << endl;
	}
	catch (EPuntosNoValidos) {
		cout << "PUNTOS_NO_VALIDOS" << endl;
	}
}

void lista_por_puntos(const CarnetPorPuntos& gestionPuntos) {
	unsigned int puntos;
	cin >> puntos;
	try {
		const Lista<string>& conductores = gestionPuntos.lista_por_puntos(puntos);
		Lista<string>::ConstIterator iconductor = conductores.cbegin();
		while (iconductor != conductores.cend()) {
			cout << iconductor.elem() << " ";
			iconductor.next();
		}
		cout << endl;
	}
	catch (EPuntosNoValidos) {
		cout << "PUNTOS_NO_VALIDOS" << endl;
	}
}

int main() {
	CarnetPorPuntos gestionPuntos;
	string comando;
	while (cin >> comando) {
		if (comando == "nuevo") nuevo(gestionPuntos);
		else if (comando == "quitar") quitar(gestionPuntos);
		else if (comando == "recuperar") recuperar(gestionPuntos);
		else if (comando == "consultar") consultar(gestionPuntos);
		else if (comando == "cuantos_con_puntos") cuantos_con_puntos(gestionPuntos);
		else if (comando == "lista_por_puntos") lista_por_puntos(gestionPuntos);
	}
	return 0;
}