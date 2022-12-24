#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_JUGUETES= 10, MAX_CARTAS=10, MAX_PEDIDOS =3, MAX_NOMBRES =10;



struct tJuguetes {
	string nombre;
	double peso;
	int unidades;
};

struct tListaJuguetes {
	tJuguetes juguetes[MAX_JUGUETES];
	int cont;
};

struct tCartas {
	string persona;
	string ciudad;
	tListaJuguetes listaJug;
	
	bool preparado;
	bool pendiente;
};

struct tListaCartas {
	tCartas listaCartas[MAX_CARTAS];
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
	string nombre = "";
	ifstream archivo;
	archivo.open("juguetes.txt");
	if (archivo.is_open()) {
		int i = 0;
		while (i < MAX_JUGUETES && nombre != "XXX") {
			archivo >> nombre;
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
	bool cargado = false;
	string nombre = "";
	fstream archivo;
	archivo.open("cartas.txt");
	if (archivo.is_open()) {
		int i = 0;
		
		while (i < MAX_CARTAS && nombre != "XXX") {
			archivo >> lista.listaCartas[i].persona;
			archivo >> lista.listaCartas[i].ciudad;
			for (int j = 0; i < MAX_JUGUETES;i++) {
				archivo >> lista.listaCartas[i].listaJug.juguetes[j].nombre;
			}
			i++;
		}
		lista.cont = i - 1;

		archivo.close();
		cargado = true;
	}

	return cargado;
}

void listarJuguetes(const tListaJuguetes lista) {
	cout << "Listado de los juguetes que hay en la fabrica:" << endl;
	cout << setw(MAX_NOMBRES) << left << "Nombre" << setw(MAX_NOMBRES) << "Peso" << setw(MAX_NOMBRES) << "Cant." << '\n';
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
	return 0.1;
}

bool comprobarPedido(const tListaJuguetes juguetes, string pedido[MAX_PEDIDOS]){
	return true;
}

void cargarTrineos(tListaCartas& cartas, tListaJuguetes& listaJuguetes){

}

void listarPendientes(const tListaCartas cartas){
	cout << endl;
	cout << "Regalos pendientes: " << endl;
	cout << setw(MAX_NOMBRES) << left << "Nombre" << setw(MAX_NOMBRES) << "Ciudad" << setw(MAX_NOMBRES) << "Juguetes" << '\n';

	for (int i = 0; i < cartas.cont - 1; i++) {
		if(cartas.listaCartas[i].pendiente){
			cout << setw(MAX_NOMBRES) << left << cartas.listaCartas[i].persona;
			cout << setw(MAX_NOMBRES) << fixed << setprecision(2) << cartas.listaCartas[i].ciudad;
			for (int j = 0; j < MAX_JUGUETES;j++) {
				cout << cartas.listaCartas[i].listaJug.juguetes[j].nombre<<"   ";
			}
		}
	}
}


int buscarCiudad(string& ciudad, const tListaCartas& listaCartas) {
	return 1;
}
// El programa principal carga los dos ficheros de datos en sus listas.
// Luego muestra los juguetes de la fábrica, carga los trineos y por último 
// lista las cartas que no han sido cargadas en los trineos.
//