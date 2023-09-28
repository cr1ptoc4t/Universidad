using namespace std;
#include <iostream>

void resuelveCaso();

int main() {
	int ncasos;
	cin >> ncasos;
	for (int i = 0; i < ncasos; i++)
		resuelveCaso();
	
	
	return 0;
}

void resuelveCaso() {
	int npicos = 0;
	int nvalles = 0;
	int ultimo=-1;
	int v[10000];
	//leer array
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin>>v[i];
	//procesar array y aumentar picos y valles
	for (int i = 2; i < n; i++){
		if (v[i-1] > v[i - 2] && v[i-1] > v[i]){
			npicos++;
			ultimo = i;
		}
		else if (v[i-2]>v[i-1]&& v[i-1]<v[i]) {
			nvalles++;
		}
	}
	
	cout << npicos << " " << nvalles << endl;

}