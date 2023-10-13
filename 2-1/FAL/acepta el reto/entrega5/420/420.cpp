
using namespace std;
#include <iostream>

void solucionaCaso();

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		solucionaCaso();

	return 0;
}

void solucionaCaso() {
	long long int v[250000];
	int numero, total=0, n = 0, a = 0;

	cin >> numero;
	getchar();
	//for (int i = 0; i < n; i++)
	while(a>=0&&a<=10){
		a = getchar() - 48;
		v[n] = a;
		n++;
	}

	//analisis del vector

	int j = 0;
	while (j < n) {
		int i = j;
		int suma = 0;

		while (i<n && suma<numero) {
			suma += v[i];
			i++;
		}

		if (suma == numero)
			total++;

		j++;
	}
	cout << total << endl;

}