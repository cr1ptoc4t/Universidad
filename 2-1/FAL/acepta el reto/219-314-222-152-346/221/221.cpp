using namespace std;
#include <iostream>


//hay que editarlo, esta es la version facil
bool bienFormada(int v[], int n);

int main() {

	return 0;
}

bool bienFormada(int v[], int n) {
	bool primerTramo = true;

	int i = 0;
	
	
	/* demasiado poco legible¿? 
	while (i < n && v[i] % 2 == 0) i++;
	while (i < n && v[i] % 2 == 1) i++;
	*/

	while (i<n && ((i==0)||(v[i] % 2 == 0) || v[i-1] % 2 == 1)) i++;


	return i == n;
}