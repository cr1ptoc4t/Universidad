#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 10;
struct tMatrizCuadrada {
	int matriz[MAX][MAX];
	int dimension; // no de filas y columnas usadas
};

bool esXpar(const tMatrizCuadrada& m);
void esCuadradoRotado(const tMatrizCuadrada& m, bool& loEs);
void inicializarm(ifstream& archivo, tMatrizCuadrada& m);

int main() {
	tMatrizCuadrada m;
	ifstream archivo;
	archivo.open("matriz1.txt");
	inicializarm(archivo, m);
	bool b;
	esCuadradoRotado(m, b);
	cout << b;
	return 0;
}

bool esXpar(const tMatrizCuadrada& m) {
	int mitad = m.dimension / 2;
	bool loEs= true;
	int i = -mitad, j=-mitad;

	while (loEs&&i>0&&j<m.dimension) {

		while (loEs&&j>0&&j<m.dimension) {


			j++;
		}
		i++;
	}

	return loEs;
}

void esCuadradoRotado(const tMatrizCuadrada& m, bool& loEs) {
	loEs = true; int i = 0; int  j = 0;
	while (loEs&&i<m.dimension-1) {
		j = 0;
		while (loEs && j<m.dimension-1) {
			if (m.matriz[i][j]!=m.matriz[i+1][j+1]) {
				loEs = false;
			}
			j++;
		}
		i++;
	}
}

void inicializarm(ifstream&archivo, tMatrizCuadrada& m) {
	archivo >> m.dimension;
	for (int i = 0; i < m.dimension; i++)
		for (int j = 0; j < m.dimension; j++)
			archivo >> m.matriz[i][j];
}