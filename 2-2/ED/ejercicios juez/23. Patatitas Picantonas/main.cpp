#include "GestionComandas.h"

#include <iostream>
#include <string>
using namespace std;


void registra_producto(GestionComandas& gc) {
	tProducto producto;
	unsigned int precio;
	cin >> producto >> precio;
	gc.registra_producto(producto, precio);
	cout << "OK" << endl;
}

void registra_servicio(GestionComandas& gc) {
	tServicio servicio;
	cin >> servicio;
	try {
		gc.registra_servicio(servicio);
		cout << "OK" << endl;
	}
	catch (EServicioYaExiste) {
		cout << "SERVICIO YA EXISTE" << endl;
	}
}

void registra_comanda(GestionComandas& gc) {
	tServicio servicio;
	cin >> servicio;
	unsigned int nprods;
	cin >> nprods;
	Lista<tProducto> productos;
	while (nprods > 0) {
		tProducto prod;
		cin >> prod;
		productos.pon_final(prod);
		nprods--;
	}
	try {
		gc.registra_comanda(servicio, productos);
		cout << "OK" << endl;
	}
	catch (ERegistroComanda) {
		cout << "ERROR REGISTRO COMANDA" << endl;
	}
}

void atiende_comanda(GestionComandas& gc) {
	try {
		gc.atiende_comanda();
		cout << "OK" << endl;
	}
	catch (ENoHayComandas) {
		cout << "NO HAY COMANDAS" << endl;
	}
}

void cierra_servicio(GestionComandas& gc) {
	tServicio servicio;
	cin >> servicio;
	try {
		Cuenta c = gc.cierra_servicio(servicio);
		for (unsigned int i = 0; i < c.apuntes.longitud(); i++) {
			ApunteCuenta apunte = c.apuntes.elem(i);
			cout << "[" << apunte.producto << "," << apunte.unidades << "] ";
		}
		cout << c.precio << endl;
	}
	catch (ECierreServicio) {
		cout << "ERROR CIERRE SERVICIO" << endl;
	}
}

int main() {
	GestionComandas gc;
	string comando;
	while (cin >> comando) {
		if (comando == "registra_producto") registra_producto(gc);
		else if (comando == "registra_servicio") registra_servicio(gc);
		else if (comando == "registra_comanda") registra_comanda(gc);
		else if (comando == "atiende_comanda")  atiende_comanda(gc);
		else if (comando == "cierra_servicio")  cierra_servicio(gc);
	}
	return 0;
}