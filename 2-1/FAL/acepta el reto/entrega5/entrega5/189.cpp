
using namespace std;
#include <iostream>

int main() {
	int n, npasajeros;
	int v[100000]; //falta 1 cero - almacena en q cubierta tiene su pasaje
	cin >> n;
	while (n != 0) {
		for (int i = 0; i < n; i++)
			cin >> v[i];
		
		cin >> n;
	}
	return 0;
}
