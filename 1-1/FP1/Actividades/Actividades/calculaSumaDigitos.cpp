#include <iostream>
#include <fstream>
using namespace std;

const int LONGITUD_ARRAY1 = 20;
typedef int tArray[LONGITUD_ARRAY1];

int main() {
	tArray array1;
	for (int i = 0; i < LONGITUD_ARRAY1; i++) {
		array1[i] = i;
		cout << array1[i] << " | ";
	}


	/*
	ifstream archivo;
	archivo.open("datos.txt");
	int num=1, sumaTotal = 0, sumaDiv;
	if (archivo.is_open()) {
		archivo >> num;
		while (num!=0) {
			
			sumaDiv = 0;
			for (int i = num - 1; i > 0; i--) {
				if (num%i==0) {
					sumaDiv = sumaDiv + i;
				}
			}
			if (sumaDiv==num) {
				sumaTotal++;
				cout << num << endl;
			}
			archivo >> num;
		}
	}
	else { cout << "ARCHIVO SIN ABRIR!!!" << endl; }
	archivo.close();
	cout << "hay un total de: " << sumaTotal << " numeros perfectos" << endl;
	return 0;

	*/
}


