#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int N = 10;

typedef int tMatriz[N][N];

void showMatrix(tMatriz matriz);
void sumaMatriz(tMatriz matriz1, tMatriz matriz2, tMatriz& suma);
void restaMatriz(tMatriz matriz1, tMatriz matriz2, tMatriz& suma);
void inicializar(tMatriz matriz, double elem);
void inicializarRandom(tMatriz matriz);


bool simetria(tMatriz matriz);
int menu();


int main() {
	tMatriz mat1, mat2;
	inicializarRandom(mat1);
	inicializarRandom(mat2);

	showMatrix(mat1);
	showMatrix(mat2);

	int opcion = 0;
	while (opcion != -1) {
		opcion = menu();
		switch (opcion) {
			case 1: {
				tMatriz suma;
				sumaMatriz(mat1, mat2, suma);

				cout << "La suma es: " << endl;
				showMatrix(suma);

			}break;
			case 2: {
				tMatriz resta;
				restaMatriz(mat1, mat2, resta);

				cout << "La resta es: " << endl;
				showMatrix(resta);

			}break;
			case 3: {
				// multiplicar
			}break;
			case 4: {
				if (simetria(mat1)) cout << "la matriz 1 es simetrica";
				else cout << "la matriz 1 no es simetrica";
			}break;
			case 5: {
				//trasponer
			}break;
			case 6: {
				//mostrar matriz señalando
			}
		}
		
	}
	

	return 0;
}


void showMatrix(tMatriz matrix) {
	cout << "esta es tu matriz: "<<endl;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N;j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}

void sumaMatriz(tMatriz matriz1, tMatriz matriz2, tMatriz& suma){
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N; j++) {
			suma[i][j] = matriz1[i][j] + matriz2[i][j];
		}
	}
}

void inicializar(tMatriz matriz, double elem){
	for (int fila = 0; fila < N; fila++)
		for (int columna = 0; columna < N; columna++)
			matriz[fila][columna] = elem;
}

void inicializarRandom(tMatriz matriz)
{
	for (int fila = 0; fila < N; fila++)
		for (int columna = 0; columna < N; columna++)
			matriz[fila][columna] = rand()%100;
}

bool simetria(tMatriz matriz){
	bool simetria = true;
	int i = 0;
	int j = 0;
	while (simetria && i < N) {
		while (simetria&& j<N) {
			if (matriz[i][j] != matriz[j][i]) {
				simetria = false;
				j++;
			}
		}
		i++;
	}
	return simetria;
}

int menu()
{
	int opcion;

	//opciones
	cout << "Elija entre las siguientes opciones:"<<endl;
	cout << "1- sumar 2 matrices"<<endl;
	cout << "2- restar 2 matrices" << endl;
	cout << "3- Determinar si una matriz es simetrica"<<endl;
	cout << "4- transponer una matriz" << endl;
	cout << "5- Mostrar una matriz señalando cuáles son los puntos de silla" << endl;

	cin >> opcion;

	return opcion;
}

void restaMatriz(tMatriz matriz1, tMatriz matriz2, tMatriz& suma) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			suma[i][j] = matriz1[i][j] - matriz2[i][j];
		}
	}
}

