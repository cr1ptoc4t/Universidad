#pragma once
#include <fstream>
#include "partida.h"

using namespace std;
const int MAX_PARTIDAS = 20;
typedef tPartida* tPtrPartida;
typedef struct
{
	int nElem;
	tPtrPartida datos[MAX_PARTIDAS];
}tListaPartidas;

tPtrPartida dameElem(const tListaPartidas& listaPartidas, int pos);

int buscaPos(const tListaPartidas& listaPartidas, int nivel);
int dameNumElem(const tListaPartidas& listaPartidas);

void iniciaListaPartidas(tListaPartidas& listaPartidas);
void cargarListaPartidas(ifstream& archivo, tListaPartidas& listaPartidas);
void insertarOrd(tListaPartidas& listaPartidas, const tPartida& partida);
void actualizaBombillas(tPartida& partida);
void eliminarPartida(tListaPartidas& listaPartidas, const tPartida& partida);
void guardarListaPartidas(ofstream& archivo, const tListaPartidas& listaPartidas);
void destruyeListaPartidas(tListaPartidas& listaPartidas);