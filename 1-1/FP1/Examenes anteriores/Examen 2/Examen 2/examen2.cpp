#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_JUGUETES= 10, MAX_CARTAS=10, MAX_PEDIDOS =3, MAX_NOMBRES =10;

struct tCartas {
	string persona;
	string ciudad;
	 
	bool preparado;
	bool pendiente;
};

struct tListaCartas {
	tCartas listaCartas[MAX_CARTAS];
	int cont;
};

struct tJuguetes {
	string nombre;
	double peso;
	int unidades;
};
struct tListaJuguetes {
	tJuguetes juguetes[MAX_JUGUETES];
	int cont;
};
//----------------------------------------------------------------------------
bool cargarJuguetes(tListaJuguetes& lista);
bool cargarCartas(tListaCartas& lista);
bool comprobarPedido(const tListaJuguetes juguetes, string pedido[MAX_PEDIDOS]);

void listarJuguetes(const tListaJuguetes lista);
void cargarTrineos(tListaCartas& cartas, tListaJuguetes& listaJuguetes);
void listarPendientes(const tListaCartas cartas);

int buscarCiudad(string& ciudad, const tListaCartas& listaCartas);
int buscarJuguete(const string nombre, const tListaJuguetes lista);

double trineoDestino(string& ciudad, tListaCartas& listaCartas, tListaJuguetes& listaJuguetes);
//----------------------------------------------------------------------------


int main() {
	tListaJuguetes listaJug;
	tListaCartas listaCartas;
	cargarJuguetes(listaJug);
	cargarCartas(listaCartas);

	listarJuguetes(listaJug);
	cargarTrineos(listaCartas, listaJug);

	listarPendientes(listaCartas);

	return 0;
}

bool cargarJuguetes(tListaJuguetes& lista) {
	bool cargado = false;
	string nombre;
	ifstream archivo;
	archivo.open("juguetes.txt");
	if (archivo.is_open()) {
		int i = 0;
		archivo >> nombre;
		while (i < MAX_JUGUETES && nombre != "XXX") {
			lista.juguetes[i].nombre = nombre;
			archivo >> lista.juguetes[i].peso;
			archivo >> lista.juguetes[i].unidades;
			i++;
		}
		lista.cont = i - 1;

		archivo.close();
		cargado = true;
	}

	return cargado;
}

bool cargarCartas(tListaCartas& lista) {

}

void listarJuguetes(const tListaJuguetes lista) {
	cout << "Listado de los juguetes que hay en la fabrica:" << endl;
	cout << "Nombre \nPeso\nCant." << endl;
	for (int i = 0; i < lista.cont-1; i++) {
		cout << setw(MAX_NOMBRES) << left << lista.juguetes[i].nombre;
		cout << setw(MAX_NOMBRES) << fixed << setprecision(2) << lista.juguetes[i].peso;
		cout << setw(MAX_NOMBRES) << lista.juguetes[i].unidades;
		cout << '\n';
	}
}

int buscarJuguete(const string nombre, const tListaJuguetes lista){
	int i = 0;
	while (i<lista.cont-1 && lista.juguetes[i].nombre != nombre) i++;
	return i;
}

double trineoDestino(string& ciudad, tListaCartas& listaCartas, tListaJuguetes& listaJuguetes){

}

bool comprobarPedido(const tListaJuguetes juguetes, string pedido[MAX_PEDIDOS]){

}

void cargarTrineos(tListaCartas& cartas, tListaJuguetes& listaJuguetes){

}

void listarPendientes(const tListaCartas cartas){

}


int buscarCiudad(string& ciudad, const tListaCartas& listaCartas) {

}
// El programa principal carga los dos ficheros de datos en sus listas.
// Luego muestra los juguetes de la fábrica, carga los trineos y por último 
// lista las cartas que no han sido cargadas en los trineos.
//