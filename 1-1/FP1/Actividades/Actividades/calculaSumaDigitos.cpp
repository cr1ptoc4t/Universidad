#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void introduceCantidadInicio(float num, fstream& archivo);
void eliminaCantidadPosicion(float pos, fstream& archivo);
int localizaCantidad(float num, fstream& archivo);
void muestraLista(fstream& archivo);
void introduceCantidadFinal(float n , fstream& archivo);
void menu(fstream& archivo,int& opcion);

int main() {
	fstream archivo1;
	archivo1.open("lista.txt");
	if (archivo1.is_open()) {
		int n = 0;
		int opcion = 0;
		while (opcion != -1) {
			menu(archivo1, opcion);
			archivo1 << opcion;
		}
		archivo1.close();
	}
	else cout << "no se abrió" << endl;
	
}

void menu(fstream& archivo, int& opcion) {
	cout << "1- nueva cantidad final lista" << endl;
	cout << "2- nueva cantidad inicio lista" << endl;
	cout << "3- eliminar cantidad posicion lista" << endl;
	cout << "4- localizar cantidad lista" << endl;
	cout << "5- mostrar lista" << endl;
	cout << "6- guardar lista en el archivo" << endl;

	cin >> opcion;
	float num;
	switch (opcion) {
		case 1: {
			cout << "numero a introducir: ";
			cin >> num;
			introduceCantidadFinal(num, archivo);
		}break;
		case 2: {
			cout << "numero a introducir: ";
			cin >> num;
			introduceCantidadInicio(num, archivo);
		} break;
		case 3: {
			cin >> num;
			eliminaCantidadPosicion(num, archivo);
		}break;
		case 4: {
			cin >> num;
			localizaCantidad(num, archivo);
		} break;
		case 5: {
			muestraLista(archivo);
		}break;
		case 6: {

		}
	}
}

void introduceCantidadFinal (float num, fstream& archivo){
	int basura = 0;
	while (basura != -1) {
		archivo >> basura;
	} archivo << num<< " ";
}

void introduceCantidadInicio(float num, fstream& archivo) {
	archivo << num << " ";
}

void eliminaCantidadPosicion(float pos, fstream& archivo) {
	int basura;
	for (int i = 0; i < pos - 1; i++) {
		archivo >> basura;
	} archivo << "";
}

int localizaCantidad(float num, fstream& archivo) {
	int pos=0;
	return pos;
}
void muestraLista(fstream& archivo) {
	cout << "MOSTRAR LISTA:" << endl;
	int num = 0;
	while (num!=-1) {
		archivo >> num;
		cout << num << " | ";
	}
	cout << endl;
}
