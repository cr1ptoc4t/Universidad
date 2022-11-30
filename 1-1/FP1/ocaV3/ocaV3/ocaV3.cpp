#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#define inFile "Tablero.txt";

using namespace std;

//-------------------------------------------------------------------------
//constantes
const bool MODO_DEBUG = true;

const int TURNOS_POSADA = 1;
const int TURNOS_CARCEL = 2;
const int TURNOS_POZO = 3;

const int CENTINELA = 0;

const int NUM_CASILLAS = 63;

const int CASILLA_INICIAL = 1;
const int CASILLA_META = NUM_CASILLAS;
const int MAX_PARTIDAS = 10;

const int RETROCESO_LABERINTO = 12;
// numero de jugadores actual
const int NUM_JUGADORES = 2;
// maximo numero de jugadores
const int MAX_JUGADORES = 4;
// numero de filas a dibujar
const int NUM_FILAS_A_DIBUJAR = 3;
//-------------------------------------------------------------------------


//-------------------------------------------------------------------------
// 
typedef enum { NORMAL, OCA, PUENTE1, PUENTE2, POZO, POSADA, LABERINTO, DADO1, DADO2, CARCEL, CALAVERA } tCasilla;

typedef tCasilla tTablero[NUM_CASILLAS];

typedef int tJugadores[NUM_JUGADORES];

struct tEstadoJugador {
    int posicion;
    int penalizacion;
};

typedef tEstadoJugador tEstadoJugadores[NUM_JUGADORES];

struct tEstadoPartida {
    tEstadoJugadores estadoJ;
    tTablero tablero;
};

typedef tEstadoPartida tArrayPartidas;

struct tListaPartidas {
    int cont;
    tArrayPartidas arrayPartidas;
};

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
// Subprogramas que inician el juego
void iniciaTablero(tTablero& tablero);
bool cargaTablero(tTablero& tablero);
void iniciaJugadores(tEstadoJugadores& jugadores);
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Subprogramas para el funcionamiento interno del juego
void buscaCasillaAvanzando(const tTablero tablero, tCasilla tipo, int& posicion);
void buscaCasillaRetrocediendo(const tTablero tablero, tCasilla tipo, int& posicion);
void tirada(const tTablero tablero, tEstadoJugador& estadoJug);
void efectoTirada(const tTablero tablero, tEstadoJugador& estadoJug);

int saltaACasilla(const tTablero tablero, int casillaActual);
int partida(tEstadoPartida& estado);
int tirarDadoManual();
int tirarDado();
int quienEmpieza();

bool esCasillaPremio(const tTablero tablero, int casilla);
//---------------------------------------------------------------------------



int main() {
    tTablero tablero;
    int ganador;

    srand(time(NULL));

    iniciaTablero(tablero);
    if (!cargaTablero(tablero)) {
        cout << "El fichero no existe" << endl;
    } else {
        ganador = partida(tablero);
        cout << endl << "------------ GANA EL JUGADOR " << ganador
            << " ------------" << endl;
    }
    return 0;
}



string casillaAstring(tCasilla casilla) {

    string cadena = " ";
    switch (casilla) {
    case OCA:
        cadena = "OCA";
        break;
    case DADO1:
        cadena = "DADO";
        break;
    case DADO2:
        cadena = "DADO";
        break;
    case PUENTE1:
        cadena = "PNTE";
        break;
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
    for (int i = 0; i <= NUM_CASILLAS - 2; i++) tablero[i] = NORMAL;

    tablero[CASILLA_META - 1] = OCA;
}

// lee el fichero de las casillas especiales.
// almacena las casillas en el array Ttablero.
bool cargaTablero(tTablero& tablero) {

    bool aperturaCorrecta = false;
    int i;
    int contador = 0;
    char aux;

    string nombreF, casillaESP;
    ifstream fichero;

    cout << "Introduce el nombre del fichero que contiene el tablero: ";
    cin >> nombreF;
    fichero.open(nombreF);

    if (fichero.is_open()) {

        aperturaCorrecta = true;
        fichero >> i;

        while (i != 0) {
            fichero.get(aux);
            getline(fichero, casillaESP);
             

            //USAR SWITCH >> MÁS LIMPIO
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
            else if (casillaESP == "POSADA") {
                tablero[i - 1] = POSADA;
            }
            fichero >> i;
        }
    }
    else cout << "error";
    fichero.close();

    return aperturaCorrecta;
}

bool esCasillaPremio(const tTablero tablero, int casilla) {
    return (tablero[casilla] == OCA) || (tablero[casilla] == PUENTE1) || (tablero[casilla] == PUENTE2)
        || (tablero[casilla] == DADO1) || (tablero[casilla] == DADO2);
}


// NO FINALIZADO -- SIN TESTEAR
void efectoTirada(const tTablero tablero,tEstadoJugador& estadoJug) {
    int casillaAnterior = estadoJug.posicion;

    cout << "Casilla actual: " << estadoJug.posicion + 1 << " ---- " << casillaAstring(tablero[estadoJug.posicion]) << endl;
    if((tablero[estadoJug.posicion] == OCA) || (tablero[estadoJug.posicion] == PUENTE1) || (tablero[estadoJug.posicion] == PUENTE2)
            || (tablero[estadoJug.posicion] == DADO1) || (tablero[estadoJug.posicion] == DADO2)){
        
        estadoJug.posicion = saltaACasilla(tablero, estadoJug.posicion);
        if (estadoJug.posicion != CASILLA_META) { cout << "VUELVES A TIRAR" << endl; }
    
    } else if (tablero[estadoJug.posicion] == POSADA) {
        cout << "PIERDES " << TURNOS_POSADA << " TURNOS" << endl;
        estadoJug.penalizacion += TURNOS_POSADA;

    } else if (tablero[estadoJug.posicion] == CARCEL) {
        cout << "PIERDES " << TURNOS_CARCEL << " TURNOS" << endl;
        estadoJug.penalizacion += TURNOS_CARCEL;

    } else if (tablero[estadoJug.posicion] == POZO) {
        cout << "PIERDES " << TURNOS_POZO << " TURNOS" << endl;
        estadoJug.penalizacion += TURNOS_POZO;

    } else if (tablero[estadoJug.posicion] == CALAVERA) {
        estadoJug.posicion = saltaACasilla(tablero, estadoJug.posicion);
        cout << "Retrocedes al inicio" << endl;

    } else if (tablero[estadoJug.posicion] == LABERINTO) {
        estadoJug.posicion = saltaACasilla(tablero, estadoJug.posicion);
        cout << "Retrocedes doce casillas: " << estadoJug.posicion << endl;

    }

    if (casillaAnterior != estadoJug.posicion) {
        cout << "Saltas a la casilla: " << estadoJug.posicion + 1 << endl;
    }

}



int saltaACasilla(const tTablero tablero, int casillaActual) {

    if (tablero[casillaActual] == OCA || tablero[casillaActual] == PUENTE1 ||
        tablero[casillaActual] == DADO1) {
        buscaCasillaAvanzando(tablero, tablero[casillaActual], casillaActual);
    }
    else if (tablero[casillaActual] == PUENTE2 || tablero[casillaActual] == DADO2) {
        buscaCasillaRetrocediendo(tablero, tablero[casillaActual], casillaActual);
    }
    else if (tablero[casillaActual] == LABERINTO) casillaActual -= 12;
    else if (tablero[casillaActual] == CALAVERA) casillaActual = 0;

    return casillaActual;
}

void buscaCasillaAvanzando(const tTablero tablero, tCasilla tipo, int& posicion) {
    posicion++;
    while (tablero[posicion] != tipo && posicion < CASILLA_META) {
        posicion++;
    }
}

void buscaCasillaRetrocediendo(const tTablero tablero, tCasilla tipo, int& posicion) {
    posicion--;
    while (tablero[posicion] != tipo && posicion != 0) {
        posicion--;
    }
}

void iniciaJugadores(tEstadoJugadores& jugadores) {
    for (int i = 0; i < NUM_JUGADORES; i++) {
        //no se si esta bien
        jugadores[i].posicion = 0;
        jugadores[i].penalizacion = 0;
    }
}

void tirada(const tTablero tablero,tEstadoJugador& estadoJug) {
    int dado;
    if (MODO_DEBUG) dado = tirarDadoManual();
    else {
        dado = tirarDado();
        cout << "Dado: " << dado << endl;
    }

    estadoJug.posicion += dado;

    if (estadoJug.posicion < CASILLA_META) {
        cout << "Avanzas a la casilla " << estadoJug.posicion + 1 << endl;
        efectoTirada(tablero, estadoJug);
    }
}

int partida(tEstadoPartida& estado) {

    tJugadores casillasJug, penalizacionesJug;

    bool finPartida = false;
    int gana = 1;

    iniciaJugadores(jugadores);
    pintaTablero(estado.tablero, casillasJug);

    int turno = quienEmpieza();
    cout << "empieza el jugador " << turno << endl;

    while (!finPartida) {

        //ralentiza el juego cuando no está en modo depuracion
        if (!MODO_DEBUG) {
            cout << endl;
            system("pause");
            cout << endl;
        }

        //decide si el jugador tirará en función de la penalizacion
        if (penalizacionesJug[turno - 1] <= 0) {
            tirada(estado.tablero, estado[turno - 1].estadoJ.posicion, estado[turno - 1].estadoJ.penalizacion);
        }else {
            penalizacionesJug[turno - 1]--;
            cout << "jugador " << turno << ", te quedan " << penalizacionesJug[turno - 1] + 1 << " turnos sin jugar" << endl;
        }

        //ganador
        if (casillasJug[turno - 1] >= CASILLA_META - 1) {
            finPartida = true;
            gana = turno;
        }

        pintaTablero(estado.tablero, casillasJug);

        //CAMBIO DE JUGADOR
        if (casillasJug[turno - 1] < CASILLA_META && !esCasillaPremio(estado.tablero, casillasJug[turno - 1])) {
            turno = (turno + 1) % MAX_JUGADORES+1;

            cout << endl;
            cout << "/////////////////////////////////////////// CAMBIO DE JUGADOR ///////////////////////////////////////////" << endl;
            cout << "Turno del jugador: " << turno << endl;

        }


    }


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

//decide que jugador empezará el juego
int quienEmpieza() { return 1 + rand() % NUM_JUGADORES; }