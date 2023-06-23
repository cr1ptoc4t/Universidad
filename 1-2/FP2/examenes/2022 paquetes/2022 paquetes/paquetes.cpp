#include "paquetes.h"

bool cargarPaquetes(tListaPaquetes& listaPaquetes)
{
	return false;
}

void mostrarPaquetes(const tListaPaquetes& listaPaquetes)
{
}

void mostrarPaquete(const tPaquete& paq)
{
}

int getCodigo(const tListaPaquetes& p, int i)
{
	return p.array_paquetes[i]->cp;
}

int getCont(const tListaPaquetes& p)
{
	return p.cont;
}

void recogerPaquete(tListaPaquetes& lpaquetes)
{
}

void liberarPaquetes(tListaPaquetes& listaPaquetes)
{
}

string getId(const tListaPaquetes& lp, int i)
{
	return lp.array_paquetes[i]->id;
}

int buscarPaquete(const tListaPaquetes lp, string id)
{
	return 0;
}

void eliminarElemento(tListaPaquetes& lp, int indice)
{
}

void setCargado(tListaPaquetes& lp, int i)
{
	lp.array_paquetes[i]->cargado = true;
}

int getCodigoPostalPaquete(const tListaPaquetes& lp, int i)
{
	return lp.array_paquetes[i]->cp;
}
