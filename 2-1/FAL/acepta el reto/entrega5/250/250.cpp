#include <iostream>
using namespace std;

void solucionaCaso(int num);
int cambioCerradura(int v[], int n, int t);

int main() {
	int num, act;
	cin >> num;
	while (num != 0) {
		solucionaCaso(num);
		cin >> num;
	}
	return 0;
}
void solucionaCaso(int num) {
	long long int suma = 0;
	int v[1000000];

	for (int i = 0; i < num; i++) {
		cin >> v[i];
		suma += v[i];
	}

	int i = cambioCerradura(v, num, suma);
	cout << i << endl;
}

int cambioCerradura(int v[], int n, int t) {
	int k = 0;
	int i = v[0];
	int d = t - i;
	int dif = abs(d) - abs(i);
	int min = t;
	int pos = 0;


	while (k < (n - 1)) {
		d = t - i;
		dif = abs(d) - abs(i);
		if (abs(dif) < abs(min) && abs(dif) != abs(t)) {
			pos = k + 1;
			min = abs(dif);
		}

		++k;
		i += v[k];
	}

	return pos;
}