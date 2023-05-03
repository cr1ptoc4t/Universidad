#pragma once
#include "jugadoras.h"
#include <iostream>
using namespace std;


typedef struct {
	string nombre;
	int puntos;
	int presupuesto;
	tJugadoras* jugadoras;
	int num_jugadoras;
}tEquipo;