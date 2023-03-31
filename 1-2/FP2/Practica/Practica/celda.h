#pragma once

typedef enum { PARED, BOMBILLA, LIBRE }tTipo;

typedef struct {
	tTipo tipo;
	int numBombillas;
}tCelda;

char celdaToChar(const tCelda& celda);
tCelda charToCelda(char c);

bool esPared(const tCelda& c);
bool esParedRestringida(const tCelda& c);
bool esBombilla(const tCelda& c);
bool estaApagada(const tCelda& c);
bool estaIluminada(const tCelda& c);
bool estaLibre(const tCelda& c);

void apagaCelda( tCelda& c);
void actualizaIluminacionCelda( tCelda& c, bool iluminar);
void ponBombilla( tCelda& c);

int numParedRestringida(const tCelda& c);
