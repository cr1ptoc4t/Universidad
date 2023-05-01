//ALBA GALIANO CAMPILLO -- CATALINA FULLANA MORA
#include <iostream>
#include <fstream>
#include "reglasJuego.h"
#include "listaPartidas.h"

using namespace std;


int  elegirPartida(const tListaPartidas& lp);

int main() {
    ifstream archivoEntrada;
    ofstream archivoSalida;
    tListaPartidas lp;
    string archivo;
    int partida, nPasos=0;

    archivoEntrada.open("tableros.txt");
    iniciaListaPartidas(lp);
    cargarListaPartidas(archivoEntrada, lp);
    partida = elegirPartida(lp);

    if (!juega(*lp.datos[partida], nPasos))
        eliminarPartida(lp, *lp.datos[partida]);
    else
        actualizaBombillas(*lp.datos[partida]);
       

    cout << "Elige archivo donde guardar las partidas"<<endl;
    cin >> archivo;
    archivoSalida.open(archivo); 
    guardarListaPartidas(archivoSalida, lp);
    destruyeListaPartidas(lp);
    return 0;

}
int elegirPartida(const tListaPartidas& lp) {
    int nivel, i = 0;
    cout << "Que nivel quieres jugar? ";
    cin >> nivel;

    if (nivel < lp.datos[lp.nElem - 1]->nivel)                  //falta getter
        while (i < lp.nElem && lp.datos[i]->nivel < nivel)
            i++;
    else i = lp.nElem-1;
    
    return i;
}