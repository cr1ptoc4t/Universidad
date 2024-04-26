/*
NOMBRE Y APELLIDOS: CATALINA FULLANA MORA
DNI: 41618813Z
*/


#include "GestionComandas.h"
#include "DiccionarioHash.h"
#include "Cola.h"

DiccionarioHash<tProducto, double> _carta;

typedef Lista<tProducto> tComanda;
Cola<tComanda> _comandas;


DiccionarioHash<tServicio, tComanda> _servicios;


/*
  COMPLEJIDAD: Determina justificadamente la complejidad de esta operación

*/
GestionComandas::GestionComandas() {
	// A IMPLEMENTAR
};

/*
  COMPLEJIDAD: Determina justificadamente la complejidad de esta operación
  O(1). un insertar en un diccionario es cte
*/
void GestionComandas::registra_producto(const tProducto& producto, unsigned int precio) {
	// A IMPLEMENTAR
	_carta.inserta(producto, precio);
}

/*
  COMPLEJIDAD: Determina justificadamente la complejidad de esta operación

*/
void GestionComandas::registra_servicio(const tServicio& servicio) {
	// A IMPLEMENTAR
	if (_servicios.contiene(servicio)) {
		throw EServicioYaExiste();
	}
	else {
		Lista<tProducto> cuenta;
		_servicios.inserta(servicio, cuenta);
	}
}

/*
  COMPLEJIDAD: Determina justificadamente la complejidad de esta operación

*/
void GestionComandas::registra_comanda(const tServicio& servicio, const Lista<tProducto>& productos) {
	// A IMPLEMENTAR
	_servicios.inserta(servicio, productos);
}

/*
  COMPLEJIDAD: Determina justificadamente la complejidad de esta operación

*/
void GestionComandas::atiende_comanda() {
	// A IMPLEMENTAR
	if (_comandas.esVacia())
		throw ENoHayComandas();
	else {
		tComanda c = _comandas.primero();

		//c.atender!!!!!!!!

		_comandas.quita();
	}
}

/*
  COMPLEJIDAD: Determina justificadamente la complejidad de esta operación

*/
Cuenta GestionComandas::cierra_servicio(const tServicio& servicio) {
	if (!_servicios.contiene(servicio)|| !_servicios.valorPara(servicio).esVacia()) {
		throw ECierreServicio();
	}else{
		
		//lista nombre producto - unidades
		Lista<ApunteCuenta> cuenta = _servicios.valorPara(servicio);
		//cantidad a pagar
		double pagar = 0;

		Lista<ApunteCuenta>::Iterator it = cuenta.begin();
		while (it != cuenta.end()) {
			double precio_producto = _carta.valorPara(it.elem().producto);
			
			pagar += precio_producto* it.elem().unidades;
			it.next();
		}

		Cuenta c(cuenta, 0);

		//eliminsr informacion servicio

		
		return c;
	}
}

/*
class Cuenta {
public:
	Cuenta(const Lista<ApunteCuenta>& apuntes, unsigned int precio) :
		apuntes(apuntes), precio(precio) {}
	Lista<ApunteCuenta> apuntes;     // Apuntes que conforman la cuenta
	unsigned int precio;             // Cantidad de dinero total a pagar    
};
*/
