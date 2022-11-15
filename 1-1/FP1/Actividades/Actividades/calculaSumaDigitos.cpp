#include <iostream>
#include <fstream>
using namespace std;

int main() {
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
}
