#include <iostream>
using namespace std;

int main() {
	int puntos[20][20];

	int solucion[20];
	int maximaPuntuacion=-1; //el peor de los casos
	int dummy[20];

	nReinasMejorPuntuacion2(4, puntos, dummy, 0, 0, maximaPuntuacion, solucion);


	return 0;
}

//devuelve los mejores puntos
int nReinasMejorPuntuacion(
	//descripcion del problema
	int n,
	int puntos[20][20],

	//solucion parcial
	int solParcial[],
	int k,

	//marcaje de la optimizacion
	int puntosParciales,
	int mejorSolucion[]
	) {

	if (n == k) {
		//escribeTablero(solParcial,n)
		//cout<<endl;
		for (int i = 0; i < n; i++)
			mejorSolucion[i] = solParcial[i];

		return puntosParciales;
	}

	int ret;

	for (int y = 0; y < n; y++) {
		solParcial[k] = y;
		if (noCome(solParcial, k)){
			int aux;
			int mejorAux[20];
			aux=nReinasMejorPuntuacion(n, puntos, solParcial, k+1, puntosParciales+puntos[y][k], mejorAux);
			ret = max(ret, aux);
			if (aux > ret) {
				ret = aux;
				for (int i = 0; i < n; i++)
					mejorSolucion[i] = mejorAux[i];
			}
		}
		
	}


	return ret;
}


bool noCome(int v[], int k) {
	return false;
}


void nReinasMejorPuntuacion2(
	//descripcion del problema
	int n,
	int puntos[20][20],

	//solucion parcial
	int solParcial[],
	int k,
	int puntosParciales,

	//marcaje de la optimizacion
	int &mejorPuntuacion,
	int mejorSolucion[]
) {

	if (n == k) {
		//escribeTablero(solParcial,n)
		//cout<<endl;
		if(puntosParciales> mejorPuntuacion){
			mejorPuntuacion = puntosParciales;
			for (int i = 0; i < n; i++)
				mejorSolucion[i] = solParcial[i];
		}
	}

	for (int y = 0; y < n; y++) {
		solParcial[k] = y;
		if (noCome(solParcial, k)) {
			nReinasMejorPuntuacion2(
				n, puntos, solParcial,
				k + 1, puntosParciales + puntos[y][k],
				mejorPuntuacion, mejorSolucion);
			
		}

	}
