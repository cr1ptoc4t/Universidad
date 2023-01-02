#include <iostream>
#include <iomanip>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_RIDERS = 8;
const int MAX_PEDIDOS = 50;


struct tTiempo {
	int horas;
	int minutos;
};

struct tRider {
	string nombre;
	float ganancias;
	bool disponible;

};

struct tArrayRiders {
	int cont;
	tRider listaR[NUM_RIDERS];
};

struct tPedido {
	tTiempo solicitado;
	tTiempo iniciado;
	int duracion;
	int rider;
	bool prioritario;
	bool procesado;
};
struct tListaPedidos {
	int cont;
	tPedido listaP[MAX_PEDIDOS];
};




bool carga(tListaPedidos& pedidos);
bool operator<(tTiempo const& tiempoIzq, tTiempo const& tiempoDer);
tTiempo operator+(tTiempo const& tiempo, int min);
ostream& operator<< (std::ostream& out, tTiempo const& tiempo);
void muestra(tListaPedidos lp, tArrayRiders lr);
void muestraUno(tListaPedidos lp, int i);
tTiempo suma(const tTiempo& tiempo, int min);

int main() {
	tListaPedidos pedidos;
	tArrayRiders riders;
	if (carga(pedidos)) {
		muestra(pedidos, riders);
	}
	else cout << "error";

	return 0;
}

bool operator<(tTiempo const& tiempoIzq, tTiempo const& tiempoDer) {
	return true;
}

tTiempo operator+(tTiempo const& tiempo, int min) {
	return tiempo;
}
ostream& operator<< (std::ostream& out, tTiempo const& tiempo) {
	return out;
}


bool carga(tListaPedidos& pedidos) {
	ifstream archivo;
	bool apertura = true;
	archivo.open("pedidos.txt");
	if (archivo.is_open()) {
		pedidos.cont = 0;
		int horas;
		tPedido pedido;
		archivo >> horas;
		while (horas != -1) {
			pedido.solicitado.horas = horas;
			archivo >> pedido.solicitado.minutos;
			archivo >> pedido.duracion;
			archivo >> pedido.prioritario;
			pedido.procesado = false;
			tTiempo t = suma(pedido.solicitado, pedido.duracion);
			pedido.iniciado = t;
			pedidos.listaP[pedidos.cont] = pedido;
			pedidos.cont++;
			archivo >> horas;
		}
		archivo.close();
		return true;
	}
	else {
		apertura = false;
	}
}


int siguiente(tListaPedidos lp) {
	int i = 0;
	int noPrior = -1;
	int prior = -1;
	int devuelve;

	while (i < MAX_PEDIDOS && (noPrior != -1 || prior != -1)) {
		if (lp.listaP[i].prioritario && !lp.listaP[i].procesado && prior == -1) prior = i;
		if (!lp.listaP[i].procesado && noPrior == -1) noPrior = i;
		i++;
	}
	if (noPrior < prior)	devuelve = noPrior;
	else	devuelve = prior;

	return devuelve;
}

int eligeRider(tArrayRiders listaR) {
	int i = 0;
	while (!listaR.listaR[i].disponible) {
		i++;
	}
	return i;
}

void planifica(tListaPedidos& lp, tArrayRiders& lr) {
	for (int i = 0; i < lp.cont; i++) {
		if (lp.listaP[i].prioritario) {
			lp.listaP[i].rider = eligeRider(lr);
			lp.listaP[i].procesado = true;
		}
	}
	for (int i = 0; i < lp.cont; i++) {
		if (!lp.listaP[i].prioritario) {
			lp.listaP[i].rider = eligeRider(lr);
			lp.listaP[i].procesado = true;
		}
	}
}


void muestra(const tListaPedidos& listaPedidos, int rider) {
	for (int i = 0; i < listaPedidos.cont; i++) {
		if (listaPedidos.listaP[i].rider == rider) {
			std::cout << std::right << std::setfill(' ') << std::setw(3) << rider + 1 << std::setw(10);
			
			cout << std::setw(9);
			
			cout << std::setw(10);
			cout << '\n';
		}
	}
}

void muestra(const tListaPedidos listaPedidos, const tArrayRiders rider) {
	std::cout << "Rider   Solicitado    Iniciado    Terminado\n";
	for (int i = 0; i < NUM_RIDERS; i++) {
		muestra(listaPedidos, i);
		//He utilizado la funcion setw, la funcion left y al funcion setfill para que las ganancias se muestren con dos digitos en la parte decimal 
		std::cout << "Ganancias: $" << std::setw(4) << std::left << std::setfill('0') << rider.listaR[i].ganancias << '\n';
	}
}



tTiempo suma(const tTiempo& tiempo, int min) {
	int minutosTotales = tiempo.minutos + min;
	tTiempo resultado;
	if (minutosTotales < 60) {
		resultado.horas = tiempo.horas;
		resultado.minutos = minutosTotales;
	}
	else {
		resultado.horas = tiempo.horas + 1;
		resultado.minutos = minutosTotales - 60;
	}
	int horas = minutosTotales / 60;
	int minutos = minutosTotales % 60;

	return resultado;
}
