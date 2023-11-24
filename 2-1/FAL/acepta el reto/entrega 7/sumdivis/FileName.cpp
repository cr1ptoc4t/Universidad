#include <iostream>
using namespace std;

int cuentaSumDivisibles(
	int n,		
	int k,
	int sumaDigitosSolParcial
);

int main() {

	cout << cuentaSumDivisibles(5, 0,0);

	return 0;
}


int cuentaSumDivisibles(
	int n,				//descripcion del problema
	//int solParcial[],	//solucion parcial
	int k,
	int sumaDigitosSolParcial
	) {


	//solucion ya es total
	if (n == k) {
		
		return 1;
	}

	int ret = 0;
	for (int i = 0; i < 10; i++) {
		if ((sumaDigitosSolParcial+1)%(k+1)==0){
			//solParcial[k] = i;

			ret+=cuentaSumDivisibles(n,/* solParcial,*/ k + 1, sumaDigitosSolParcial + i);
		}
	}

	return ret;
}


void generaQuasiSecuencias(
	// 
	int n,
	int sm,

	//solucion parcial
	int solParcial[],
	int k,

	int sumaParcial
) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			if (i)
				cout << " ";
			cout << solParcial[i];
		}
		cout << endl;
		return; 
	}
	
	//caso 1: v[i] = v[i-1]
	solParcial[k] = solParcial[k - 1];
	if(sumaParcial + solParcial[k]<=sm)
		generaQuasiSecuencias(n, sm, solParcial, k + 1,sumaParcial+solParcial[k]);
	
	
	//caso 2: v[i] = v[i-1]+ v[i-2]
	solParcial[k] = solParcial[k - 1] + solParcial[k - 2];
	if (sumaParcial + solParcial[k] <= sm)
		generaQuasiSecuencias(n, sm, solParcial, k + 1, sumaParcial + solParcial[k]);


}


bool esPrometedora(int v[], int k, int sm) {
	int i = 0;
	int sumaTotal = 0;

	for (int i = 0; i < k; i++)
		sumaTotal += v[i];


	return sumaTotal<=sm;
}


/*
void generaQuasiSecuencias2(
	// 
	int n,
	int ini,
	int sm
) {
	int v[100];
	v[0] = ini;
	generaQuasiSecuencias(n, sm, v, 1); 
}

*/