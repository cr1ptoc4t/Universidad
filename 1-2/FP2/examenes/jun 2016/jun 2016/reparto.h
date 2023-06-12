    #ifndef REPARTO_H
#define REPARTO_H
#include <string>
#include <fstream>
using namespace std;

const int N = 10;
typedef struct {
	string lista[N];
	int contador;
} tReparto;

/*
carga un reparto. El fichero ya viene abierto.
El reparto viene dado por un numero entero n seguido de n strings con los nombres
de los actores.
*/
void cargar(ifstream &fichero, tReparto &reparto);

/*
Indica si el nombre de un actor aparece en el reparto. El par�metro 
pos es la posicion desde la que buscar.
*/
bool aparece(const tReparto &reparto, string nombre, int pos);

#endif
    