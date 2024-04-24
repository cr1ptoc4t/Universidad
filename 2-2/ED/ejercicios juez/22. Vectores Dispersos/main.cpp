#include "lista.h"
#include "DiccionarioHash.h"
#include <iostream>
#include <string>
using namespace std;


typedef struct {
	int x;
	double val;
} tEntrada;

typedef Lista<tEntrada> tVector;


double producto_escalar(const tVector& u, const tVector& v) {
	// A IMPLEMENTAR
}

bool leeVector(tVector& v) {
	if (cin.peek() == '(') {
		char sep;
		cin >> sep;
		while (cin.peek() != ')') {
			tEntrada e;
			unsigned int i;
			double val;
			cin >> e.x >> sep >> e.val;
			if (cin.peek() != ')') {
				cin >> sep;
			}
			v.pon_final(e);
		}
		cin >> sep;
		return true;
	}
	else return false;
}
void saltaLinea() {
	string s;
	getline(cin, s);
}

int main() {
	bool fin = false;
	while (!fin) {
		tVector u;
		tVector v;
		if (leeVector(u)) {
			leeVector(v);
			saltaLinea();
			cout << producto_escalar(u, v) << endl;
		}
		else {
			fin = true;
		}
	}
}