using namespace std;
#include <iostream>
bool buscaEnTramo(int a[], int v, int ini, int fin);
int main() {
	int a[] = {1,2,3,4,6,8,12,19,22,42};
	cout << buscaEnTramo(a, 4, 0, 10) << endl;
	cout << buscaEnTramo(a, 5, 0, 10);

	return 0;
}

bool buscaEnTramo(int a[], int v, int ini, int fin) {

	int mitad = (ini + fin) / 2;
	if (ini == fin) {
		return a[ini] == v;
	}

	else if(a[mitad]<v){
		return buscaEnTramo(a, v, mitad+1, fin);
	}
	else {
		return buscaEnTramo(a, v, ini, mitad);
	}
}