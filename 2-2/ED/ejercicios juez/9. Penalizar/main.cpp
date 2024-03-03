/***** NO MODIFICAR *****/

#include <iostream>
#include "cola.h"
using namespace std;



bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n < 0) return false;
	else {
		Cola<int> q;
		for (int i = 0; i < n; i++) {
			int e;
			cin >> e;
			q.pon(e);
		}
		int inicio, fin;
		cin >> inicio >> fin;
		q.penalizaSecuencia(inicio, fin);
		q.imprime();
		cout << endl;
		return true;
	}
}

int main()
{
	while (ejecuta_caso());
	return 0;
}

