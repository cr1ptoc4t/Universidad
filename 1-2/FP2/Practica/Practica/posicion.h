#pragma once
#include <fstream>
using namespace std;
typedef struct {
	int x;
	int y;
}tPosicion;

void iniciaPosicion(tPosicion& pos, int xx, int yy);
void guardarPosicion(ofstream& archivo, const tPosicion& p);

bool operator==(const tPosicion& p1, const tPosicion& p2);

int dameX(const tPosicion& pos);
int dameY(const tPosicion& pos);