using namespace std;
#include <iostream>
#include <fstream>
#include <string>


const int MAX_PAQUETES = 50;


struct tPaquete {
	string id;
	int cp;
	bool cargado;
};

typedef tPaquete* tArrayPaquetes[MAX_PAQUETES];

struct tListaPaquetes
{
	tArrayPaquetes array_paquetes;
	int cont;
};

bool cargarPaquetes(tListaPaquetes& listaPaquetes);
void mostrarPaquetes(const tListaPaquetes& listaPaquetes);
void mostrarPaquete(const tPaquete& paq);
int getCodigo(const tListaPaquetes& p, int i);
int getCont(const tListaPaquetes& p);

void recogerPaquete(tListaPaquetes& lpaquetes);
void liberarPaquetes(tListaPaquetes& listaPaquetes);
string getId(const tListaPaquetes& lp, int i);
int buscarPaquete(const tListaPaquetes lp, string id);
void eliminarElemento(tListaPaquetes& lp, int indice);
void setCargado(tListaPaquetes& lp, int i);
int getCodigoPostalPaquete(const tListaPaquetes& lp, int i);
