#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#define inFile "Tablero.txt";


using namespace std;


const bool MODO_DEBUG = false;

const int TURNOS_POSADA = 1;
const int TURNOS_CARCEL = 2;
const int TURNOS_POZO = 3;

const int CENTINELA = 0;

const int NUM_CASILLAS = 63;

const int CASILLA_INICIAL = 1;
const int CASILLA_META = NUM_CASILLAS;

const int RETROCESO_LABERINTO = 12;
// numero de jugadores actual
const int NUM_JUGADORES = 4;
// maximo numero de jugadores
const int MAX_JUGADORES = 4;
// numero de filas a dibujar
const int NUM_FILAS_A_DIBUJAR = 3;



typedef enum { NORMAL, OCA, PUENTE1, PUENTE2, POZO, POSADA, LABERINTO, DADO1, DADO2, CARCEL, CALAVERA } tCasilla;

typedef tCasilla tTablero[NUM_CASILLAS];

typedef int tJugadores[NUM_JUGADORES];

//-------------------------------------------------------------------------
// Subprogramas para pintar el tablero o mostrar informacion

void pintaTablero(const tTablero tablero, const tJugadores casillasJ);
void pintaNumCasilla(int fila, int casillasPorFila);
void pintaBorde(int casillasPorFila);
void pintaTipoCasilla(const tTablero tablero, int fila, int casillasPorFila);
void pintaJugadores(const tJugadores casillasJ, int fila, int casillasPorFila);
string casillaAstring(tCasilla casilla);
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//
void iniciaTablero(tTablero& tablero);
void efectoTirada(const tTablero tablero, int& casillaJ, int& penalizacionJ);

bool esCasillaPremio(const tTablero tablero, int casilla);
bool cargaTablero(tTablero& tablero);

int saltaACasilla(const tTablero tablero, int casillaActual);
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
void buscaCasillaAvanzando(const tTablero tablero, tCasilla tipo, int& posicion);
void buscaCasillaRetrocediendo(const tTablero tablero, tCasilla tipo, int& posicion);
void iniciaJugadores(tJugadores& casillasJ, tJugadores& penalizacionesJ);
void tirada(const tTablero tablero, int& casillaActual, int& penalizacion);

int partida(const tTablero tablero);
int tirarDadoManual();
int tirarDado();

int quienEmpieza();
void printArray(tTablero array, int longitud);
void printArray(tJugadores array, int longitud);
//---------------------------------------------------------------------------

int main() {
    tTablero tablero;
    tJugadores casillasJ;
    tJugadores penalizacionesJ;
    int ganador;
    srand(time(NULL));

    iniciaTablero(tablero);
    if (!cargaTablero(tablero)) {
        cout << "El fichero no existe" << endl;
    }
    else {
        ganador = partida(tablero);
        cout << endl << "------ GANA EL JUGADOR " << ganador + 1
            << "---------" << endl;
    }

    /*
    printArray(casillasJ, NUM_JUGADORES);
    printArray(penalizacionesJ, NUM_JUGADORES);
    */

    return 0;
}



string casillaAstring(tCasilla casilla) {
    string cadena = " ";
    switch (casilla) {
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
    for (int i = 1; i < blancos; i++) b = b + " ";
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


//inicia el valor de las casillas a normal;
void iniciaTablero(tTablero& tablero) {
    for (int i = 0; i <= NUM_CASILLAS - 1; i++) {
        tablero[i] = NORMAL;

        if (i == CASILLA_META - 1) { tablero[i] = OCA; }
    }
}

// lee el fichero de las casillas especiales.
//almacena las casillas en el array Ttablero.
bool cargaTablero(tTablero& tablero) {
    bool aperturaCorrecta=false;
    int i;
    int contador = 0;
    char aux;
    string nombreF, casillaESP;
    ifstream fichero;
   // cout << "Introduce el nombre del fichero que contiene el tablero: ";
   // cin >> nombreF;
    fichero.open("tablero.txt"); //Cambiar esto por la introduccion de texto
    if (fichero.is_open()) {
        aperturaCorrecta = true;
        fichero >> i;
        while (i != 0) {
            fichero.get(aux);
            getline(fichero, casillaESP);
            if (casillaESP == "OCA") {
                tablero[i - 1] = OCA;
            }
            else if (casillaESP == "PUENTE1") {
                tablero[i - 1] = PUENTE1;
            }
            else if (casillaESP == "PUENTE2") {
                tablero[i - 1] = PUENTE2;
            }
            else if (casillaESP == "DADO1") {
                tablero[i - 1] = DADO1;
            }
            else if (casillaESP == "DADO2") {
                tablero[i - 1] = DADO2;
            }
            else if (casillaESP == "NORMAL") {
                tablero[i - 1] = NORMAL;
            }
            else if (casillaESP == "POZO") {
                tablero[i - 1] = POZO;
            }
            else if (casillaESP == "LABERINTO") {
                tablero[i - 1] = LABERINTO;
            }
            else if (casillaESP == "CARCEL") {
                tablero[i - 1] = CARCEL;
            }
            else if (casillaESP == "CALAVERA") {
                tablero[i - 1] = CALAVERA;
            }
            fichero >> i;
        }
    }
    else cout << "error";
    fichero.close();
    return aperturaCorrecta;
}

bool esCasillaPremio(const tTablero tablero, int casilla) {
    bool premio=false;
    if ((tablero[casilla] == OCA) || (tablero[casilla] == PUENTE1) || (tablero[casilla] == PUENTE2) || (tablero[casilla] == DADO1) || (tablero[casilla] == DADO2)) {
        premio = true;
    }
    return premio;
}

void efectoTirada(const tTablero tablero, int& casillaJ, int& penalizacionJ) {
    //si hay salto --> actualizar casilla actual y penalizacion
    //si casilla actual hay salto --> saltaACasilla()

    /*
    * switch(){
    * case DADO2:
       casillaActual = saltaACasilla(tablero, casillaActual);
        …


        if (!esMeta(casillaActual)) {cout << "Y VUELVES A TIRAR" << endl; }
        break;
        case POSADA:
        cout << "HAS CAIDO EN LA POSADA." << endl;
        cout << "PIERDES " << TURNOS_POSADA << " TURNOS" << endl;
        penalizacion = TURNOS_POSADA;
        break;
    */
}



int saltaACasilla(const tTablero tablero, int casillaActual) {

    if (tablero[casillaActual - 1] == OCA) {
        buscaCasillaAvanzando(tablero, OCA, casillaActual);
    } else if (tablero[casillaActual - 1] == PUENTE1) {
        buscaCasillaAvanzando(tablero, PUENTE2, casillaActual);
    } else if(tablero[casillaActual - 1] == DADO1) {
        buscaCasillaAvanzando(tablero, DADO2, casillaActual);
    } else if  (tablero[casillaActual - 1] == PUENTE2) {
        buscaCasillaRetrocediendo(tablero, PUENTE1, casillaActual);
    }else if (tablero[casillaActual - 1] == DADO2) {
        buscaCasillaRetrocediendo(tablero, DADO1, casillaActual);
    }
    return casillaActual;
}

void buscaCasillaAvanzando(const tTablero tablero, tCasilla tipo, int& posicion) {
    while (tablero[posicion]!= tipo && posicion<CASILLA_META) {
        posicion++;
    }
}

void buscaCasillaRetrocediendo(const tTablero tablero, tCasilla tipo, int& posicion) {
    while (tablero[posicion] != tipo && posicion !=0) {
        posicion--;
    }
}

void iniciaJugadores(tJugadores& casillasJ, tJugadores& penalizacionesJ) {
    for (int i = 0; i < NUM_JUGADORES ;i++) {
        casillasJ[i] = 0;
        penalizacionesJ[i] = 0;
    }
}

void tirada(const tTablero tablero, int& casillaActual, int& penalizacion) {
    int dado;
    if(MODO_DEBUG){
        dado= tirarDadoManual();
    } else { dado = tirarDado(); }
    casillaActual += dado;
    if(casillaActual<63&&esCasillaPremio(tablero, casillaActual)){
        efectoTirada(tablero, casillaActual, casillaActual);
    }
}

int partida(const tTablero tablero) {
    tJugadores casillasJug, penalizacionesJug;
    
    bool finPartida = false;
    int gana = 1;
    
    iniciaJugadores(casillasJug, penalizacionesJug);
    pintaTablero(tablero, casillasJug);

    int empieza = quienEmpieza();
    cout << "empieza el jugador " << empieza<<endl;

    int turno = empieza;

    while (!finPartida) {
        pintaTablero(tablero, casillasJug);
        if (penalizacionesJug[turno-1]<=0){
            cout << "le toca al jugador: " << turno << endl;
            tirada(tablero, casillasJug[turno-1], penalizacionesJug[turno-1] );
        } else {
            penalizacionesJug[turno-1]--;
            cout <<"jugador "<<turno <<", te quedan " << penalizacionesJug[turno-1] << " turnos sin jugar" << endl;
        }

        //ganador
        if (casillasJug[turno - 1] >= CASILLA_META) {
            finPartida = true;
            gana = turno;
            pintaTablero(tablero, casillasJug);
        }

        //CAMBIO DE JUGADOR
        if (casillasJug[turno-1]<CASILLA_META && !esCasillaPremio(tablero, casillasJug[turno-1])) {
            if (turno<MAX_JUGADORES) turno++;
            else turno = 1;
        }
    }

    // cout<< "has ganado el jugador "<< jugador<<endl;

    
    return gana;
}

int tirarDadoManual() {
    int a = 0;
    cout << endl;
    cout << "Introduce valor del dado:";
    cin >> a;
    while (a > 6 || a < 1) {
        cout << "ERROR: el numero debe pertenecer al intervalo [1,6]." << endl;
        cout << "Elige otro numero:";
        cin >> a;
    }
    return a;
}


int tirarDado() { return rand() % 6 + 1; }

int quienEmpieza() { return 1 + rand() % NUM_JUGADORES; }

void printArray(tTablero array, int longitud) {
    for (int i = 0; i < longitud; i++) {
        cout << array[i] << " | ";
    }
}


void printArray(tJugadores array, int longitud) {
    for (int i = 0; i < longitud; i++) {
        cout << array[i] << " | ";
    }
}