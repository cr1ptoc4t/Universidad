using namespace std;
#include <iostream>

int main() {
	return 0;
}


// { Pre: todos los elementos >0
bool hayCTramo(int v[], int n, int c) {
	int a=0;
	int b=0;
	int sumaAcu=0;

	//	invariante
	//	cota: 2n-a-b 

	while (sumaAcu!=c && b<n) {
		if (sumaAcu + v[b] <= c) {
			sumaAcu += v[b];
			b++;
		}
		else {
			sumaAcu -= v[a];
			a++;
		}
	}
	return sumaAcu == c;
}
// { Post: 
//		ret= Ex i, j 
//	donde
// 
// }

//dado un vector ordenado tienes que decir si hay algun elemento que no es el mayor ni el menor
bool hayNiFuNiFa(int v[], int n) {
	return hayNiFuNiFa(v, 0, n);
}

bool hayNiFuNiFa(int v[], int a, int b) {
	int numElems = b - a;
	
	if (numElems <= 2 || v[a]== v[b-1])
		return false;

	
	int m = (b - a) / 2;

	if (v[a] == v[m])
		return hayNiFuNiFa(v, m, b);
	else if (v[m] == v[b - 1])
		return hayNiFuNiFa(v, a, m+1);
	else
		return false;

}
