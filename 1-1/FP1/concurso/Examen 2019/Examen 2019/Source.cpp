using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#define inFile "mesas.txt";

const int MAX_MESAS = 20;
const int MAX_RESERVAS = 50;
const int MAX_CANC = 20;

typedef enum {RESERVA, CANCELACION} tipo;

struct tMesa{
	int cap;
	char ubi;
	bool reservada=false;
	string cliente;
	int com;
};

struct tReserva {
	tipo tipo;
	int com; //comensales	
	string cliente;
	char ubi;
	bool realizado=false;
	int mesa=0;
};

struct tCancelacion {
	string cliente;
};

struct tListaRes {
	int cont=0;
	tReserva lr[MAX_RESERVAS];
};

struct tListaMes {
	int cont=0;
	tMesa lm[MAX_MESAS];
};

struct tListaCanc {
	int cont=0;
	tCancelacion lc[MAX_CANC];
};

//-------------------------------------------------------------------
bool cargarMesas(tListaMes& lm);
bool cargarReservas(tListaRes& lr);
int buscarCliente(tListaMes lm, string cliente);
int buscarMesa(tListaMes lm, int com, char zona);
void reservar(tListaMes lm, tListaRes lr, tReserva res);
void mostrar(tListaMes lm, tListaRes lr);
string charAstringUbicacion(char r);
string boolAstringConfirmada(bool b);
//-------------------------------------------------------------------


int main() {
	tListaMes lm;
	tListaRes lr;
	if (cargarMesas(lm) && cargarReservas(lr)){
		mostrar(lm, lr);
		for (int z = 0; z < 5;z++) cout << endl;
		for (int i = 0; i < lr.cont;i++) {
			reservar(lm, lr, lr.lr[i]);
		}
		mostrar(lm, lr);
	}
	else { cout << "error"; }

	return 0;
}


bool cargarMesas(tListaMes& lm) {
	//lm.cont = 0;
	bool cargado = false;
	int cadena;
	char tipo;
	int i = 0;
	ifstream archivo;
	archivo.open("mesas.txt");
	if (archivo.is_open()) {
		archivo >> cadena;
		while (cadena!=-1) {
			lm.lm[i].cap=cadena;
			archivo >> lm.lm[i].ubi;
			lm.cont++; i++;
			archivo >> cadena;
		}
		cargado = true;
	} 

	return cargado;
}


bool cargarReservas(tListaRes& lr) {
	lr.cont = 0;

	bool cargado = false;
	ifstream archivo;
	archivo.open("reservas.txt");
	char c=' ';
	int i = 0;

	if (archivo.is_open()) {
		archivo >> c;
		while (c!='X') {
			if (c=='R') lr.lr[i].tipo = RESERVA;
			else lr.lr[i].tipo = CANCELACION;

			archivo >> lr.lr[i].cliente;

			if (c=='R') {
				archivo >> lr.lr[i].com;
				archivo >> lr.lr[i].ubi;
			}
			lr.cont++;
			i++;
			archivo >> c;

		}
		cargado = true;
	}


	return cargado;
}

int buscarCliente(tListaMes lm, string cliente) {
	int i = 0;
	while (lm.lm[i].cliente != cliente && i<lm.cont) i++;

	if (i >= lm.cont-1) i = -1;

	return i;
}

int buscarMesa(tListaMes lm, int com, char zona) {
	int i = 0;
	while (!(lm.lm[i].cap == com && lm.lm[i].reservada == false && zona == lm.lm[i].ubi)&&i<lm.cont) { i++; }

	if (i>=lm.cont-1) i = -1;

	return i;
}

void reservar(tListaMes lm, tListaRes lr, tReserva res) {
	int i = buscarMesa(lm, res.com, res.ubi);

	if (i == -1) {
		cout << "No se ha podido reservar";
		lr.lr[lr.cont].realizado = false;
	}
	else {
		//reservar mesa

		lr.lr[lr.cont].mesa = i;
		lm.lm[i].reservada = true;
		lm.lm[i].cliente = res.cliente;
		lm.lm[i].com = res.com;

		lr.lr[lr.cont].cliente = res.cliente;
		lr.lr[lr.cont].com = res.com;
		
		lr.cont++;
	}
}


void mostrar(tListaMes lm, tListaRes lr){

	for (int i = 0; i < lr.cont;i++) {
		if (lr.lr[i].tipo == RESERVA) {
			cout << "Reservar en " << charAstringUbicacion(lr.lr[i].ubi) << ", " << lr.lr[i].cliente << ", " <<
				lr.lr[i].com << " pax : " << boolAstringConfirmada(lr.lr[i].realizado);

			if (lr.lr[i].realizado) cout << ". Mesa " << lr.lr[i].mesa;
		}
		else {
			cout << "Cancelar mesa de " << lr.lr[i].cliente << " : Cancelada mesa " << lr.lr[i].mesa;
		}
		cout << endl;
	}
	        

	for (int i = 0; i < lm.cont; i++) {
		cout << "Mesa " << i << " (" << lm.lm[i].ubi << lm.lm[i].cap;
		if (lm.lm[i].reservada) {
			cout << ") : Reservada a "<< lm.lm[i].cliente << " (" << lm.lm[i].com << ")" << endl;
		} else {
			cout << ") : No reservada";
		}
	}
}

string charAstringUbicacion(char r) {
	string n="";
	if (r == 'I' || r == 'i') n = "interior";
	else if (r == 'T' || r == 't') n = "exterior";
	return n;
}

string boolAstringConfirmada(bool b) {
	string r = "";
	if (b) r = "Confirmada";
	else r = "imposible";

	return r;
}