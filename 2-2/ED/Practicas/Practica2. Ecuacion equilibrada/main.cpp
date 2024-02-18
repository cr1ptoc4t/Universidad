/*
N�mero de grupo: g25

Nombre y apellidos de los autores de la pr�ctica (si alguno de los miembros del grupo
no hay realizado la pr�ctica, no debe incluirse su nombre):
ALAI MIRANDA BLANCO
CATALINA FULLANA MORA


*/
#include "pila.h"
#include <iostream>
#include <string>
using namespace std;

bool es_operando(char car);
bool cierraA(char car, char car2);
bool es_operando_cerrado(char car);
bool es_operando_abierto(char car);

bool esEquilibrada(const string& cadena) {
	Pila <int> opds;
	int i = 0;
	bool b = true;
	while (i < cadena.length() && b) {
		if (es_operando(cadena[i])) {
			if (opds.esVacia())
				opds.apila(cadena[i]);
			else if (cierraA(opds.cima(), cadena[i])) {
				opds.desapila();
			}
			else {
				if (es_operando_cerrado(cadena[i])) b = false;
				else opds.apila(cadena[i]);
			}
		}

		i++;
	}
	return opds.esVacia();
}
bool es_operando(char car) {
	return (car == '(' || car == '{' || car == '['
		|| car == ')' || car == '}' || car == ']');
}

bool es_operando_abierto(char car) {
	return (car == '(' || car == '{' || car == '[');
}

bool es_operando_cerrado(char car) {
	return (car == ')' || car == '}' || car == ']');
}

bool cierraA(char car, char car2) {
	return car == '(' && car2 == ')' ||
		car == '{' && car2 == '}' ||
		car == '[' && car2 == ']';
}


int main() {
	string cadena;
	while (getline(cin, cadena)) {
		if (esEquilibrada(cadena))
			cout << "EQUILIBRADA" << endl;
		else
			cout << "NO_EQUILIBRADA" << endl;
	}
	return 0;
}

