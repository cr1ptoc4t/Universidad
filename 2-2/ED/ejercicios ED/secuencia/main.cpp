#include "Secuencia.h"
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <string>
using namespace std;


int cont=0;

void haz_consulta(Secuencia<int> sec, int elem) {

	try {
		cout << sec.elem(elem) << endl;
	}
	catch (ElementoInvalido) {
		cout << "ERROR" << endl;
	}
}

void muestra(Secuencia<int> s) {
	for (int i = 0; i < s.num_elems(); i++) {
		cout << s.elem(i) << " ";
	}
	cout << endl;
}

Secuencia<int> valida_copias(Secuencia<int> s) {
	Secuencia<int> s2;
	s2 = s;
	s2 = s2;
	cont++;
	return s2;
}


bool ejecuta_caso(Secuencia<int>& sec) {
	sec = valida_copias(sec);
	string comando;
	cin >> comando;
	if (comando == "pon") {
		int elem;
		cin >> elem;
		sec.pon(elem);
		cout << sec.num_elems() << endl;
		return true;
	}
	else if (comando == "consulta") {
		int elem;
		cin >> elem;
		haz_consulta(sec, elem);
		return true;
	}
	else if (comando == "muestra") {
		muestra(sec);
		return true;
	}
	else if (comando == "limpia") {
		sec = Secuencia<int>();
		cout << "OK" << endl;
		return true;
	}
	else if (comando == "termina") {
		return false;
	}
	return false;
}

void crea_secuencia() {
	Secuencia<int> s2;
	cont++; 
}

const static int INTENTOS_CREACION = 1024 * 1024;
void valida_liberacion() {
	for (int i = 0; i < INTENTOS_CREACION; i++) {
		crea_secuencia();
	}
}


int main() {
	valida_liberacion();
	Secuencia<int> sec;
	while (ejecuta_caso(sec));
	return 0;
}