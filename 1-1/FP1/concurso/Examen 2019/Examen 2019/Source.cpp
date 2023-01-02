using namespace std;
#include <iomanip>
#include <iostream>

const int MAX_MESAS = 20;
const int MAX_RESERVAS = 50;
const int MAX_CANC = 20;

typedef enum tipoReserva {RESERVA, CANCELACION} tipo;


//cambiar solo tenemos mesas pares y tendriamos que poner con n-1 tambien

struct tMesa{
	int cap;
	char ubi;
	bool reservada;
	string cliente;
};

struct tReserva {
	tipo tipo;
	int com; //comensales
	string cliente;
	char ubi;
	bool realizado;
};

struct tCancelacion {
	string cliente;
};

struct tListaRes {
	int cont;
	tReserva lr[MAX_RESERVAS];
};

struct tListaMes {
	int cont;
	tMesa lm[MAX_MESAS];
};

struct tListaCanc {
	int cont;
	tCancelacion lc[MAX_CANC];
};

int main() {


	return 0;
}


bool cargarMesas(tMesa lm[MAX_MESAS ]) {
	return true;
}

int buscarCliente(tListaMes lm, string cliente) {
	int i = 0;
	while (lm.lm[i].cliente != cliente && i<lm.cont) i++;

	if (i >= lm.cont-1) i = -1;

	return i;
}

int buscarMesa(tListaMes lm, int com, char zona) {
	int i = 0;
	while (!(lm.lm[i].cap == com && lm.lm[i].reservada == false && zona == lm.lm[i].ubi))i++;

	if (i>=lm.cont-1) i = -1;

	return i;
}

void reservar(tListaMes lm, tListaRes lr, tReserva res) {
	int i = buscarMesa(lm, res.com, res.ubi);
	if (i == -1) cout << "No se ha podido reservar";
	else {
		lr.lr[lr.cont].cliente = res.cliente;
		lr.lr[lr.cont].tipo = res.tipo;

		lm.lm[i].cliente = res.cliente;
		lm.lm[i].reservada = true;
		cout << "reservada";

		lr.cont++;
	}
}

void mostrar(){
}