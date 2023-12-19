using namespace std;
#include <iostream>

int main() {

	return 0;
}


// { Pre: }
bool esMinimalista(int v[], int n) {
	int minimo=v[0];
	int i=1;



	/*
	* invariante: 
	* {	i:
	*		0 < i<= n ^
	*		minimo = min(v,i)
	*		P.t. j: 0<j<i: numMins(v, j)-1
	* }
	* Cota: n-i
	* Complejidad: O(n)
	* 
	*/

	while (i<n&&v[i]!=minimo) {
		minimo = min(minimo, v[i]);
		
		i++;
	}
	return i==n;
}
// { Post: 
//		ret= P t i: 0<i<n: numMins(v, i)=1
//		
//		numMins(v, n)= freq(v,n, minimo(v,n))
//		minimo(v, n)= min i:0<=i<n:v[i]
//		freq(v, n, elem)=
//	}

//	minimalista si el elemento más pequeño sale sólo 1 vez

/*
while (i < n && v[i] != minimo && acum == 0) {
	minimo = min(minimo, v[i]);
	if (minimo == v[i])
		acum = 0;
	else acum++;
	i++;
}
*/



// a	num llamadas recursivas que hacer
// b	en cuanto dividimos el tamaño de los datos en las llamadas recurs
// k	complejidad de lo que no son llamadas recursivas

// de lo anterior usamos la ecuacion y sale complejidad o (nlog n)

//Intervalo abierto v[a, b)					//parametro estrictamente de salida
bool esHiperMinimalista(int v[], int a, int b, int& minimo) {
	
	
	int numElems = b - a;
	if (numElems == 1) {
		minimo = v[a];
		return true;
	}
	if (numElems == 2) {
		minimo = min(v[a], v[b]);
		return v[a] != v[b - 1];
	}
	
	
	
	
	
	int minimo = v[a];
	int i = a+1;


	int m = (a + b) / 2;

	int minIz, minDer;
	bool esIz = esHiperMinimalista(v,a,m,minIz);
	bool esDer = esHiperMinimalista(v, a, m, minDer);


	minimo = min(minIz, min(minDer, v[i]));

	int numVeces = 0;
	if (minimo == minIz) ++numVeces;

	if (minimo == v[m]) numVeces++;
	if (minimo == minDer) numVeces++;


	return numVeces==1 && esIz && esDer;
}

bool esHiperMinimalista(int v[], int n, int &minimo){

	return esHiperMinimalista(v,0,n, minimo);
}


//en el main:
/*
* int vals[100];
* int numValores;
* int umbral;
* 
* lectura
* 
* 
* llamamos
* int ret = cuantos(vals, nvals, umbral, 0, 0, _____ );
*/

//cuantos minimalistas  se pueden hacer cuya suma no superen el umbral u
int cuantos(int elems[], int n, int umbral,
	int k,int sumaParcial, int minimoParcial
) {
	int ret = (k>0);

	for (int i = 0; i < n; i++) {
		if(sumaParcial+elems[i]<= umbral &&
			(k==0||elems[i]!=minimoParcial))
			ret += cuantos(elems, n, umbral,
				k+1, sumaParcial+ elems[i],
				(k==0)? elems[i]
					: min(minimoParcial,elems[i]));
	}

	return ret;
}