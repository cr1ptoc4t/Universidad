using namespace std;
#include <iostream>


//hay que editarlo, esta es la version facil
bool bienFormada(int v[], int n, int& faltan);

int main() {
	int ncasos;
	int faltan;
	cin >> ncasos;
	int v[10000];
	int n;
	for (int i = 0; i < ncasos;i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}

		if (bienFormada(v, n, faltan)) {
				cout << "SI " << faltan<<endl;
		}
		else
			cout << "NO" << endl;

	}

	return 0;
}

bool bienFormada(int v[], int n, int& faltan) {
	
	int i = 0;
	
	
	/* demasiado poco legible¿? 
	while (i < n && v[i] % 2 == 0) i++;
	while (i < n && v[i] % 2 == 1) i++;
	*/

	//while (i<n && ((i==0)||(v[i] % 2 == 0) || v[i-1] % 2 == 1)) i++;


	while (i < n && v[i] % 2 == 0) i++;
	faltan = i;
	while (i < n && v[i] % 2 == 1) i++;

	return i==n;
}
