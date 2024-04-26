/*
NOMBRE Y APELLIDOS: CATALINA FULLANA MORA
DNI: 41618813Z
*/


#include "lista.h"
#include <string>

using namespace std;


class EServicioYaExiste {};
class ECierreServicio {};
class ERegistroComanda {};
class ENoHayComandas {};


typedef string tProducto;    // Tipo para representar nombres de productos
typedef string tServicio;    // Tipo para representar identificadores de servicios

// Clase para representar apuntes en una cuenta 
class ApunteCuenta {
public:
	ApunteCuenta(const tProducto& producto, unsigned int unidades) :
		producto(producto), unidades(unidades) {};
	tProducto producto;          // Producto
	unsigned int unidades;       // Unidades que se han servido 
};

// Clase para representar la cuenta asociada a un servicio
class Cuenta {
public:
	Cuenta(const Lista<ApunteCuenta>& apuntes, unsigned int precio) :
		apuntes(apuntes), precio(precio) {}
	Lista<ApunteCuenta> apuntes;     // Apuntes que conforman la cuenta
	unsigned int precio;             // Cantidad de dinero total a pagar    
};


class GestionComandas {
public:
	GestionComandas();
	void registra_producto(const tProducto& producto, unsigned int precio);
	void registra_servicio(const tServicio& servicio);
	void registra_comanda(const tServicio& servicio, const Lista<tProducto>& productos);
	void atiende_comanda();
	Cuenta cierra_servicio(const tServicio& servicio);
private:
	// Incluye aquí los detalles de representación que consideres oportuno

};