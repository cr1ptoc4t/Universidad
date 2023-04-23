#pragma once
#include "posicion.h"

const int DIM = 2;
typedef struct
{
	int cont;
	int size;
	tPosicion* arrayPos;
} tListaPosiciones;

void iniciaListaPosiciones(tListaPosiciones& lp);
void destruyeListaPosiciones(tListaPosiciones& lp);
void insertar(tListaPosiciones& lp, const tPosicion& pos);
int dameNumElem(const tListaPosiciones& lp);
tPosicion dameElem(const tListaPosiciones& lp, int i);
void guardarListaBombillas(ofstream& archivo, const tListaPosiciones& lp);
