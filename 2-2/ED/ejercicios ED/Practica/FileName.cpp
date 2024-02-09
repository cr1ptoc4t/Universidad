#include "Memoria.h"
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <string>
using namespace std;


class Par {
public:
	Par(int x, int y) : _x(x), _y(y) {}
	int val_1() const { return _x; }
	int val_2() const { return _y; }
private:
	int _x;
	int _y;
};


const static int MAX_TAM = 100;
Memoria<Par> random_men() {
	unsigned int tam = unsigned(rand() % MAX_TAM);
	Memoria<Par> mem(tam);
	for (unsigned int i = 0; i < tam; i++) {
		if (rand() % 2 == 0) {
			mem.almacena(i, Par(rand(), rand()));
		}
	}
	return mem;
}


bool ejecuta_caso(Memoria<Par> mem, Memoria<Par>& resul) {
	Memoria<Par> m(1);
	m = mem;
	string comando;
	cin >> comando;
	if (comando == "almacena") {
		int d, x, y;
		cin >> d >> x >> y;
		try {
			m.almacena(d, Par(x, y));
			cout << "OK" << endl;
		}
		catch (EDireccionInvalida) {
			cout << "DIRECCION_INVALIDA" << endl;
		}
		resul = m;
		return true;
	}
	else if (comando == "valor") {
		int d;
		cin >> d;
		try {
			Par v = m.valor(d);
			cout << v.val_1() << " " << v.val_2() << endl;
		}
		catch (EDireccionInvalida) {
			cout << "ERROR_DE_LECTURA" << endl;
		}
		catch (ECeldaSinInicializar) {
			cout << "ERROR_DE_LECTURA" << endl;
		}
		resul = m;
		return true;
	}
	else if (comando == "inicializada") {
		int d;
		cin >> d;
		try {
			if (m.inicializada(d)) {
				cout << "SI" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		catch (EDireccionInvalida) {
			cout << "DIRECCION_INVALIDA" << endl;
		}
		resul = m;
		return true;
	}
	else if (comando == "termina") {
		return false;
	}
	return false;
}


int cont = 0;
const static int TAM_MEM_PRUEBA = 1024;
typedef class {
	int a[TAM_MEM_PRUEBA];
} tElem;
void crea_memoria() {
	Memoria<int> m(TAM_MEM_PRUEBA);
	for (int i = 0; i < TAM_MEM_PRUEBA; i++) {
		m.almacena(i, 5);
	}
	Memoria<int> m2(TAM_MEM_PRUEBA);
	for (int i = 0; i < TAM_MEM_PRUEBA; i++) {
		m2.almacena(i, 5);
	}
	Memoria<int> m3(1);
	m2 = m3;
	Memoria<tElem> m4(1);
	m4.almacena(0, tElem());
	m4.almacena(0, tElem());
}

const static int INTENTOS_CREACION = 1000;
void valida_liberacion() {
	for (int i = 0; i < INTENTOS_CREACION; i++) {
		crea_memoria();
	}
	cont++;
}

int main() {
	valida_liberacion();
	int capacidad;
	cin >> capacidad;
	Memoria<Par> m(capacidad);
	Memoria<Par> r(1);
	while (ejecuta_caso(m, r)) {
		m = r;
	}
	return 0;
}