#ifndef paquetes_h
#define paquetes_h

#include <string>
using namespace std;

const int MAX_PAQUETES = 50;

struct tPaquete
{
	string id;
	int codigo_postal;
	bool cargado = false;
};

typedef tPaquete* tArrayPaquetes[MAX_PAQUETES];

struct tListaPaquetes
{
	tArrayPaquetes array_paquetes;
	int cont;
};

bool cargarPaquetes(tListaPaquetes& listaPaquetes);
void mostrarPaquetes(const tListaPaquetes& listaPaquetes);
void recogerPaquete(tListaPaquetes& listaPaquetes);
void liberarPaquetes(tListaPaquetes& listaPaquetes);
int getNumPaquetes(const tListaPaquetes& listaPaquetes);
int getCodigoPostalPaquete(const tListaPaquetes& listaPaquetes, int i);
string getIdPaquete(const tListaPaquetes& listaPaquetes, int i);
void setCargado(tListaPaquetes& listaPaquetes, int pos);


#endif