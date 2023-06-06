#include "paquetes.h"

bool cargarPaquetes(tListaPaquetes& listaPaquetes)
{
	ifstream archivo;
	bool abierto = false;
	archivo.open("paquete.txt");
	if(archivo.is_open()){
		tPaquete paq;
		paq.cargado = false;
		int num;
		archivo >> num;
		for (int i = 0; i < num; i++) {
			archivo >>paq.id >> paq.cp;

			listaPaquetes.lp[i] = new tPaquete(paq);
			listaPaquetes.cont++;
		}
		archivo.close();
		abierto = true;
	}
	return abierto;
}

void mostrarPaquetes(const tListaPaquetes& listaPaquetes)
{
	for (int i = 0; i < listaPaquetes.cont; i++)
		mostrarPaquete(*listaPaquetes.lp[i]);
}
void mostrarPaquete(const tPaquete& paquete)
{
	cout << paquete.id << " va a " << paquete.cp << " - cargado: ";
	if (paquete.cargado) cout << "SI" << endl;
	else cout << "NO" << endl;
}
int getCodigo(const tListaPaquetes& p, int i) {
	return p.lp[i]->cp;
}
int getCont(const tListaPaquetes& p) {
	return p.cont;
}

void recogerPaquete(tListaPaquetes& lpaquetes) {
	string id;
	cout << "id?";
	cin >> id;
	//bscarPaquete con ese identidicador
	int indice=buscarPaquete(lpaquetes, id);
	
	if (indice != -1 && !lpaquetes.lp[indice]->cargado)
		eliminarElemento(lpaquetes, indice);
		//eliminar de la lista de paquetes
}

void liberarPaquetes(tListaPaquetes& listaPaquetes)
{
	delete[]listaPaquetes.lp;
	listaPaquetes.cont = 0;
}

int buscarPaquete(const tListaPaquetes lp, string id) {
	int i = 0;
	while (getId(lp, i) != id && i < lp.cont)
		i++;
	
	if (lp.cont == i)
		i = -1;


	return i;
}

string getId(const tListaPaquetes& lp, int i) {
	return lp.lp[i]->id;
}

void eliminarElemento(tListaPaquetes& lp, int indice) {
	delete lp.lp[indice];
	for (int i = indice; i < lp.cont - 1; i++)
		lp.lp[i] = lp.lp[i + 1];
	lp.cont--;
}

void setCargado(tListaPaquetes& lp, int i)
{
	lp.lp[i]->cargado = true;
}

int getCodigoPostalPaquete(const tListaPaquetes& lp, int i) {
	return lp.lp[i]->cp;
}
