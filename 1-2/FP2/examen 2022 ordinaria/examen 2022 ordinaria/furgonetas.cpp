#include "furgonetas.h"
string paquetesAsignados(tFurgoneta furgoneta);


void cargarPaquete(tFurgoneta& furgoneta, tPaquete& paquete);
int buscarFurgonetaAux(tListaFurgonetas lf, int codigo, int ini, int fin);


bool cargarCodigos(tListaFurgonetas& listaFurgonetas)
{
	ifstream fich;
	bool ok = true;

	fich.open("codigos.txt");
	if (!fich.is_open())
		ok = false;
	else
	{
		for (int i = 0; i < NUM_FURGONETAS; i++)
		{
			fich >> listaFurgonetas.listaFurgonetas[i].cp;
			listaFurgonetas.listaFurgonetas[i].listaCargados.array_nombres = new string[MAX_IDS]; //inic array din
			listaFurgonetas.listaFurgonetas[i].listaCargados.cont = 0;
		}
		fich.close();
	}
	return ok;
}

void mostrarFurgonetas(const tListaFurgonetas listaFurgonetas)
{
	for (int i = 0; i < listaFurgonetas.cont;i++) {
		cout << "Furgoneta " << i << " reparte en " << listaFurgonetas.listaFurgonetas[i].cp << paquetesAsignados(listaFurgonetas.listaFurgonetas[i])<<endl;
	}
}

void cargarPaquetes(tListaFurgonetas listaFurgonetas, tListaPaquetes& listaPaquetes)
{
	int furgoneta;
	for (int i = 0; i < listaPaquetes.cont;i++) {
		furgoneta = buscarFurgoneta(listaFurgonetas, listaPaquetes.array_paquetes[i]->codigo_postal);
		if(furgoneta!=-1)
		cargarPaquete(listaFurgonetas.listaFurgonetas[furgoneta], *listaPaquetes.array_paquetes[i]);
	}
}

void cargarPaquete(tFurgoneta& furgoneta, tPaquete& paquete) {
	//furgoneta.listaCargados.array_nombres[furgoneta.listaCargados.cont] = new tPaquete(paquete);
	furgoneta.listaCargados.cont++;
	furgoneta.listaCargados.array_nombres[furgoneta.listaCargados.cont] = paquete.id;
	paquete.cargado = true;
}


string paquetesAsignados(tFurgoneta furgoneta) {
	string str = "sin paquetes asignados"; 
	if (furgoneta.listaCargados.cont!=0) {
		str = "Paquetes asignados: ";
		for (int i = 0; i < furgoneta.listaCargados.cont; i++) {
			str += furgoneta.listaCargados.array_nombres[i] + " ";
		}
	}

	return str;
}

int buscarFurgoneta(const tListaFurgonetas listaFurgonetas, int codigo) {
	return buscarFurgonetaAux(listaFurgonetas, codigo, 0, listaFurgonetas.cont);
}

int getNumCargados(tListaFurgonetas lf, int pos)
{
	return lf.listaFurgonetas[pos].listaCargados.cont;
}

void setCargado(tListaPaquetes& lp, int i)
{
	lp.array_paquetes[i]->cargado = true;
}

string getIdPaquete(tListaPaquetes lp, int i)
{
	return lp.array_paquetes[i]->id;
}

void setIdPaquete(tListaFurgonetas& lf, int pos, string id_paquete)
{
	//lf.listaFurgonetas[pos].cp = id_paquete;
}



int buscarFurgonetaAux(tListaFurgonetas lf, int codigo, int ini, int fin) {
	int pos = -1;
	if (ini<=fin) {
		int mitad = (ini + fin) / 2;
		if (codigo == lf.listaFurgonetas[mitad].cp) {
			pos = mitad;
		}
		else if (codigo< lf.listaFurgonetas[mitad].cp) {
			pos = buscarFurgonetaAux(lf, codigo, ini, mitad-1);
		}
		else {
			pos = buscarFurgonetaAux(lf, codigo, mitad-1, fin);
		}
	}
	return pos;
}

