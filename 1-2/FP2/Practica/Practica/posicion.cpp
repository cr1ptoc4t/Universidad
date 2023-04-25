#include "posicion.h"
#include <iostream>
#include <fstream>
using namespace std;

void iniciaPosicion(tPosicion& pos, int xx, int yy) {
	pos.x = xx;
	pos.y = yy;
}
bool operator==(const tPosicion& p1, const tPosicion& p2) {
	return p1.x == p2.x && p1.y == p2.y;
}
void guardarPosicion(ofstream& archivo, const tPosicion& p) {
	archivo << p.x << " " << p.y<<endl;
}


int dameX(const tPosicion& pos) {
	return pos.x;
}
int dameY(const tPosicion& pos) {
	return pos.y;
}