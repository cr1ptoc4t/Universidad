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
} tListaPartidas;

void iniciaListaPartidas(tListaPartidas& listaPartidas);
void cargarListaPartidas(ifstream& archivo, tListaPartidas& listaPartidas);
void insertarOrd(tListaPartidas& listaPartidas, const tPartida& partida);
int buscaPos(const tListaPartidas& listaPartidas, int nivel);
tPtrPartida dameElem(const tListaPartidas& listaPartidas, int pos);
int dameNumElem(const tListaPartidas& listaPartidas);
void eliminarPartida(tListaPartidas& listaPartidas, const tPartida& partida);
void guardarListaPartidas(ofstream& archivo, const tListaPartidas& listaPartidas);
void destruyeListaPartidas(tListaPartidas& listaPartidas);