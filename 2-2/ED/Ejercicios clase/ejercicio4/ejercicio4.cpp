using namespace std;
#include <iostream>
#include "pila.h"


int main() {

	return 0;
}



//si entra un numero por teclado → a la pila.
// si entra un simbolo → desapilamos los dos anteriores y operamos
int evalua(string exp) {
	Pila <int> opds;

	for (int i = 0; i < exp.length(); i++)
		if (es_operando(exp[i]))
			opds.apila(exp[i]);
		else {
			int arg2 = opds.cima();
			opds.desapila();
			int arg1 = opds.cima();
			opds.desapila();
			opds.apila(opera(exp[i], arg1, arg2));
		}
	return opds.cima();
}