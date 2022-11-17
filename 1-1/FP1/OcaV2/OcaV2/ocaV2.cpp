#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;


const int MODO_DEBUG = true;

const int TURNOS_POSADA = 1;
const int TURNOS_CARCEL = 2;
const int TURNOS_POZO = 3;

const int CENTINELA = 0;

const int CASILLA_INICIAL = 1;
const int CASILLA_META = 63;

const int RETROCESO_LABERINTO = 12;
// n?mero de jugadores actual
const int NUM_JUGADORES = 2;
// m?ximo n?mero de jugadores
const int MAX_JUGADORES = 4;
// n?mero de filas a dibujar
const int NUM_FILAS_A_DIBUJAR = 3;

typedef enum { NORMAL, OCA, PUENTE1, PUENTE2, POZO, POSADA, LABERINTO, DADO1, DADO2, CARCEL, CALAVERA } tCasilla;

typedef tCasilla tTablero[CASILLA_META];

typedef int tJugadores[NUM_JUGADORES];

//-------------------------------------------------------------------------
// Subprogramas para pintar el tablero o mostrar informaci?n

void pintaTablero(const tTablero tablero, const tJugadores casillasJ);
void pintaNumCasilla(int fila, int casillasPorFila);
void pintaBorde(int casillasPorFila);
void pintaTipoCasilla(const tTablero tablero, int fila, int casillasPorFila);
void pintaJugadores(const tJugadores casillasJ, int fila, int casillasPorFila);
string casillaAstring(tCasilla casilla);
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//
void iniciaTablero(tTablero tablero);
void efectoTirada(const tTablero tablero, int& casillaJ, int& penalizacionJ);

bool esCasillaPremio(const tTablero tablero, int casilla);
bool cargaTablero(tTablero tablero);

int saltaACasilla(const tTablero tablero, int casillaActual);
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
void buscaCasillaAvanzado(const tTablero tablero, tCasilla tipo, int& posicion);
void buscaCasillaRetrocediendo(const tTablero tablero, tCasilla tipo, int& posicion);
void iniciaJugadores(tJugadores casillasJ, tJugadores penalizacionesJ);
void tirada(const tTablero tablero, int& casillaActual, int& penalizacion);

int partida(const tTablero tablero);
//---------------------------------------------------------------------------



int main() {


    return 0;
}



string casillaAstring(tCasilla casilla) {
    string cadena;
    switch (casilla) {
    case NORMAL:
        cadena = " ";
        break;
    case OCA:
        cadena = "OCA";
        break;
    case DADO1:
    case DADO2:
        cadena = "DADO";
        break;
    case PUENTE1:
    case PUENTE2:
        cadena = "PNTE";
        break;
    case POSADA:
        cadena = "PSDA";
        break;
    case CALAVERA:
        cadena = "MUER";
        break;
    case LABERINTO:
        cadena = "LBRN";
        break;
    case POZO:
        cadena = "POZO";
        break;
    case CARCEL:
        cadena = "CRCL";
        break;
    }
    return cadena;
}

void pintaTablero(const tTablero tablero, const tJugadores casillasJ) {


    int casillasPorFila = CASILLA_META / NUM_FILAS_A_DIBUJAR;
    cout << endl;
    for (int fila = 0; fila < NUM_FILAS_A_DIBUJAR; fila++) {
        pintaBorde(casillasPorFila);
        pintaNumCasilla(fila, casillasPorFila);
        pintaTipoCasilla(tablero, fila, casillasPorFila);
        pintaJugadores(casillasJ, fila, casillasPorFila);
    }
    pintaBorde(casillasPorFila);
    cout << endl;
}


void pintaBorde(int casillasPorFila) {

    for (int i = 1; i <= casillasPorFila; i++)
        cout << "|====";

    cout << "|" << endl;

}


void pintaNumCasilla(int fila, int casillasPorFila) {

    for (int i = 1; i <= casillasPorFila; i++)
        cout << "| " << setw(2) << setfill('0') << i + fila * casillasPorFila << " ";

    cout << "|" << endl;

}


void pintaTipoCasilla(const tTablero tablero, int fila, int casillasPorFila) {

    for (int i = 1; i <= casillasPorFila; i++)
        cout << "|" << setw(4) << setfill(' ') << casillaAstring(tablero[i - 1 + fila * casillasPorFila]);

    cout << "|" << endl;

}

void pintaJugadores(const tJugadores casillasJ, int fila, int casillasPorFila) {
    int casilla;

    int blancos = MAX_JUGADORES - NUM_JUGADORES;
    string b = "";
    for (int i = 0; i < blancos; i++) b = b + " ";
    cout << "|";
    for (int i = 1; i <= casillasPorFila; i++) {
        casilla = i - 1 + fila * casillasPorFila;
        for (int jug = 0; jug < NUM_JUGADORES; jug++) {
            if (casillasJ[jug] == casilla)
                cout << jug + 1;
            else
                cout << " ";
        }
        cout << b;
        cout << "|";
    }
    cout << endl;

}


bool cargaTablero(tTablero tablero) {
    bool aperturaCorrecta = false;
    string nombreFichero = "";
    fstream archivo;

    cout << "Como se llama el fichero de texto? " << endl;
    cin >> nombreFichero;

    archivo.open(nombreFichero);
    if (archivo.is_open()) {
        aperturaCorrecta = false;
        //actualizar las posiciones correspondientes del tablero;
    }
    return aperturaCorrecta;
}
void iniciaTablero(tTablero tablero) {

}

bool esCasillaPremio(const tTablero tablero, int casilla) {
    bool premio = false;
    /*if (tablero[casilla] == esOca(casilla) || tablero[casilla] == esPuente(casilla) || tablero[casilla] == esDadps(casilla)) {
        premio = true;
    }*/
    return premio;
}

void efectoTirada(const tTablero tablero, int& casillaJ, int& penalizacionJ) {

}

int saltaACasilla(const tTablero tablero, int casillaActual) {

}

void buscaCasillaAvanzado(const tTablero tablero, tCasilla tipo, int& posicion) {

}

void buscaCasillaRetrocediendo(const tTablero tablero, tCasilla tipo, int& posicion){

}

void iniciaJugadores(tJugadores casillasJ, tJugadores penalizacionesJ) {

}

void tirada(const tTablero tablero, int& casillaActual, int& penalizacion){
}

int partida(const tTablero tablero) {

}

void pintaTablero(const tTablero tablero, const tJugadores casillasJ) {

}