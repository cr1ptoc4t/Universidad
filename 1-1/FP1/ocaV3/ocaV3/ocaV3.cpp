//TO DO LIST 
// 1. MAIN ENTERO -- CASI TERMINADO ME FALTA POQUISIMO
// 2. CAMBIAR PARTIDA   -- HECHO
// 3. CAMBIAR PINTAR JUGADORES PARA QUE NO QUEDE DESTABULADO --- HECHO
// 4. MÉTODO ELIMINAR PARTIDA -- HECHO
// 5. METODO INSERTAR NUEVA PARTIDA -- HECHO
// 6. EN CASILLA 63 DIBUJAR GANADOR 
// 7. GUARDAR PARTIDAS
// 8. CARGAR PARTIDA -- SOLO CARGA LA PRIMERA -- ARREGLADO
//


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

const int NUM_FILAS_A_DIBUJAR = 3;
//-------------------------------------------------------------------------


//-------------------------------------------------------------------------
// tipos definidos
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
    int turno;
};

typedef tEstadoPartida tArrayPartidas[MAX_PARTIDAS];

struct tListaPartidas {
    int cont;
    tArrayPartidas arrayPartidas;
};
//-------------------------------------------------------------------------



//-------------------------------------------------------------------------
// Subprogramas para pintar el tablero o mostrar informacion

void pintaTablero(const tEstadoPartida& partida);
void pintaNumCasilla(int fila, int casillasPorFila);
void pintaBorde(int casillasPorFila);
void pintaTipoCasilla(const tTablero tablero, int fila, int casillasPorFila);
void pintaJugadores(const tEstadoJugadores casillasJ, int fila, int casillasPorFila);
string casillaAstring(tCasilla casilla);
string casillaAstringSinAbreviar(tCasilla casilla);
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Subprogramas que inician el juego
void iniciaTablero(tTablero& tablero);
//bool cargaTablero(tTablero& tablero);
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



void cargaTablero(tTablero& tablero, ifstream& archivo);
void cargaJugadores(tEstadoJugadores& jugadores, ifstream& archivo);
void eliminarPartida(tListaPartidas& partidas, int indice);
void guardaTablero(const tTablero tablero, ofstream& archivo);
void guardaJugadores(const tEstadoJugadores jugadores, ofstream& archivo);
bool cargaPartidas(tListaPartidas& partidas);
bool insertaNuevaPartida(tListaPartidas& partidas, const tEstadoPartida& partidaOca);
void guardaPartidas(const tListaPartidas& partidas);


void imprimeArray(const tTablero tablero);
void imprimeArray(const tEstadoPartida estado);



int main() {
    int ganador, partidaActual;
    char opcion, opcion2;
    tEstadoPartida estado{};
    tListaPartidas listaPartidas{};
    ifstream archivo;
    string nombre;
    bool exit = false;

    srand(time(NULL));

    iniciaTablero(listaPartidas.arrayPartidas[1].tablero);
    iniciaJugadores(listaPartidas.arrayPartidas[1].estadoJ);

    if(cargaPartidas(listaPartidas)){

        partidaActual = listaPartidas.cont;

        cout << "Quieres jugar una partida nueva o existente? (n/e) ";
        cin >> opcion;
        if (opcion=='n') {
            insertaNuevaPartida(listaPartidas, listaPartidas.arrayPartidas[partidaActual]);
        }
        else if (opcion == 'e') {
            cout << "Tienes " << listaPartidas.cont << " empezadas, a que partida quieres jugar? ";
            cin >> partidaActual;
        }
        //cout<< "introduce el nombre del archivo en el que estan los tableros: ";
        //cin>>nombreArchivo;
        archivo.open("partidas.txt");

        while (!exit){
            
            listaPartidas.arrayPartidas[partidaActual-1].turno = quienEmpieza() + 1;
            cout << "/////////////////////////////////////////// PARTIDA N."<< partidaActual << " ///////////////////////////////////////////" << endl;

            ganador = partida(listaPartidas.arrayPartidas[partidaActual - 1]);
            if (ganador > 0 /* && ganador < NUM_JUGADORES*/) { //porque si decides salir del juego se marca ganador= -1
                cout << endl << "------------ GANA EL JUGADOR " << ganador << " ------------" << endl;
                eliminarPartida(listaPartidas, partidaActual - 1);
                
            }
            else if (ganador == -1) {
                //ACTUALIZAR PARTIDA EN ARCHIVO
                guardaPartidas(listaPartidas);
            }

            cout << "Quieres jugar otra partida? (s/n) ";
            cin >> opcion2;
            if (opcion2=='n') {
                exit = true;
                cout << "Nos vemos pronto!!";
            } else if (opcion2=='s') {
                partidaActual++;
            }
        }
        

        }

    return 0;
}


int partida(tEstadoPartida& estado) {

    bool finPartida = false;
    int gana = 1;
    
    pintaTablero(estado);
    
    cout << "empieza el jugador " << estado.turno << endl;

    while (!finPartida) {
        //ralentiza el juego cuando no está en modo depuracion
        if (!MODO_DEBUG) {
            cout << endl;
            system("pause");
            cout << endl;
        }
    
        //decide si el jugador tirará en función de la penalizacion
        if (estado.estadoJ[estado.turno-1].penalizacion <= 0) {
            tirada(estado.tablero, estado.estadoJ[estado.turno - 1]);
        }
        else {
            estado.estadoJ[estado.turno - 1].penalizacion--;
            cout << "jugador " << estado.turno << ", te quedan " << estado.estadoJ[estado.turno - 1].penalizacion + 1 << " turnos sin jugar" << endl;
        }

        //ganador
        if (estado.estadoJ[estado.turno - 1].posicion >= CASILLA_META - 1) {
            finPartida = true;
            gana = estado.turno;
        }

        pintaTablero(estado);

        //CAMBIO DE JUGADOR
        if (estado.estadoJ[estado.turno - 1].posicion < CASILLA_META && !esCasillaPremio(estado.tablero, estado.estadoJ[estado.turno - 1].posicion)) {
            estado.turno = 1+ (estado.turno) % NUM_JUGADORES;

            cout << endl;
            cout << "/////////////////////////////////////////// CAMBIO DE JUGADOR ///////////////////////////////////////////" << endl;
            cout << "Turno del jugador: " << estado.turno<< endl;
            
            /* COMENTADO POR COMODIDAD --- SE TIENE QUE DESCOMENTAR
            char opcion;
            cout << "Quieres salir del juego? s/n" << endl;
            cin >> opcion;

            if (opcion == 's') {
                finPartida = true;
                gana = -1;
            }
            */
        }
        
        
    }
    return gana;
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

void pintaTablero(const tEstadoPartida& partida) {
    int casillasPorFila = CASILLA_META / NUM_FILAS_A_DIBUJAR;
    cout << endl;

    for (int fila = 0; fila < NUM_FILAS_A_DIBUJAR; fila++) {
        pintaBorde(casillasPorFila);
        pintaNumCasilla(fila, casillasPorFila);
        pintaTipoCasilla(partida.tablero, fila, casillasPorFila);
        pintaJugadores(partida.estadoJ, fila, casillasPorFila);
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


void pintaJugadores(const tEstadoJugadores casillasJ, int fila, int casillasPorFila) {
    int casilla;

    int blancos = MAX_JUGADORES - NUM_JUGADORES;
    string b = "";
    for (int i = 0; i < blancos; i++) b = b + " ";
    cout << "|";
    for (int i = 1; i <= casillasPorFila; i++) {
        casilla = i - 1 + fila * casillasPorFila;
        for (int jug = 0; jug < NUM_JUGADORES; jug++) {
            if (casillasJ[jug].posicion == casilla)
                cout << jug + 1;
            else
                cout << " ";
        }
        cout << b;
        cout << "|";
    }
    cout << endl;

}



//inicia el valor de las casillas a normal
void iniciaTablero(tTablero& tablero) {
    for (int i = 0; i <= NUM_CASILLAS - 2; i++) tablero[i] = NORMAL;

    tablero[CASILLA_META - 1] = OCA;
}

bool esCasillaPremio(const tTablero tablero, int casilla) {
    return (tablero[casilla] == OCA) || (tablero[casilla] == PUENTE1) || (tablero[casilla] == PUENTE2)
        || (tablero[casilla] == DADO1) || (tablero[casilla] == DADO2);
}


// NO FINALIZADO -- SIN TESTEAR
void efectoTirada(const tTablero tablero, tEstadoJugador& estadoJug) {
    int casillaAnterior = estadoJug.posicion;

    cout << "Casilla actual: " << estadoJug.posicion + 1 << " ---- " << casillaAstring(tablero[estadoJug.posicion]) << endl;
    if ((tablero[estadoJug.posicion] == OCA) || (tablero[estadoJug.posicion] == PUENTE1) || (tablero[estadoJug.posicion] == PUENTE2)
        || (tablero[estadoJug.posicion] == DADO1) || (tablero[estadoJug.posicion] == DADO2)) {
        estadoJug.posicion = saltaACasilla(tablero, estadoJug.posicion);
        if (estadoJug.posicion != CASILLA_META) { cout << "VUELVES A TIRAR" << endl; }

    }
    else if (tablero[estadoJug.posicion] == POSADA) {
        cout << "PIERDES " << TURNOS_POSADA << " TURNOS" << endl;
        estadoJug.penalizacion += TURNOS_POSADA;
    }
    else if (tablero[estadoJug.posicion] == CARCEL) {
        cout << "PIERDES " << TURNOS_CARCEL << " TURNOS" << endl;
        estadoJug.penalizacion += TURNOS_CARCEL;

    }
    else if (tablero[estadoJug.posicion] == POZO) {
        cout << "PIERDES " << TURNOS_POZO << " TURNOS" << endl;
        estadoJug.penalizacion += TURNOS_POZO;

    }
    else if (tablero[estadoJug.posicion] == CALAVERA) {
        estadoJug.posicion = saltaACasilla(tablero, estadoJug.posicion);
        cout << "Retrocedes al inicio" << endl;

    }
    else if (tablero[estadoJug.posicion] == LABERINTO) {
        estadoJug.posicion = saltaACasilla(tablero, estadoJug.posicion);
        cout << "Retrocedes doce casillas"<< endl;
    }

    if (casillaAnterior != estadoJug.posicion) {
        
        if (estadoJug.posicion > NUM_CASILLAS) { estadoJug.posicion = NUM_CASILLAS-2; }
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
    if (tipo == PUENTE1)    tipo = PUENTE2;
    else if (tipo == DADO1) tipo = DADO2;
    while (tablero[posicion] != tipo && posicion <=NUM_CASILLAS-1) {
        posicion++;
    }
}

void buscaCasillaRetrocediendo(const tTablero tablero, tCasilla tipo, int& posicion) {
    posicion--;
    if (tipo == PUENTE2) tipo = PUENTE1;
    else if (tipo == DADO2) tipo = DADO1;

    while (tablero[posicion] != tipo && posicion != 0) {
        posicion--;
    }
}

void iniciaJugadores(tEstadoJugadores& jugadores) {
    for (int i = 0; i < NUM_JUGADORES; i++) {
        jugadores[i].posicion = 0;
        jugadores[i].penalizacion = 0;
    }
}

void tirada(const tTablero tablero, tEstadoJugador& estadoJug) {
    int dado;
    if (MODO_DEBUG) dado = tirarDadoManual();
    else {
        dado = tirarDado();
        cout << "Dado: " << dado << endl;
    }
    if(estadoJug.posicion + dado>=NUM_CASILLAS){
        estadoJug.posicion = NUM_CASILLAS-1;
    }else    estadoJug.posicion += dado;

    if (estadoJug.posicion < CASILLA_META) {
        cout << "Avanzas a la casilla " << estadoJug.posicion + 1 << endl;
        efectoTirada(tablero, estadoJug);
    }
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
int quienEmpieza() { return  rand() % NUM_JUGADORES; }


void imprimeArray(const tTablero tablero) {
    for (int i = 0; i < NUM_CASILLAS; i++) {
        cout << tablero[i] << " - ";
    }
}

void imprimeArray(const tEstadoPartida estado) {
    for (int i = 0; i < NUM_JUGADORES; i++) {
        cout << estado.estadoJ[i].penalizacion << " - ";
    }
}

void imprimeArray(const tListaPartidas listaPartidas) {
    for (int i = 0; i < listaPartidas.cont;i++) {
        cout << "Partida " << i + 1 << ":" << endl;
        for (int j = 0; j < NUM_JUGADORES; j++){
            cout << listaPartidas.arrayPartidas[i].estadoJ[j].posicion << " - ";
        }
        cout<<endl;
    }
}


//TERMINADO- SIN TESTEAR
bool cargaPartidas(tListaPartidas& partidas) {
    string nombreFichero;
    ifstream fichero;
    bool cargado = false;

    //cout << "introduce el nombre del fichero de texto:";
    //cin >> nombreFichero;
    
    //fichero.open(nombreFichero);
    
    fichero.open("partidas.txt");

    if (fichero.is_open()) {
        
        fichero >> partidas.cont;

        for (int i = 0; i <partidas.cont;i++) {
            cargaTablero(partidas.arrayPartidas[i].tablero, fichero);
            fichero>>partidas.arrayPartidas[i].turno;
            for (int j = 0; j < NUM_JUGADORES - 1; j++) {
                cargaJugadores(partidas.arrayPartidas[i].estadoJ, fichero);
            }
        }
        fichero.close();
        //imprimeArray(partidas);


        cargado = true;

    } else cout << "No se ha podido abrir el fichero " << nombreFichero << endl;
    
    return cargado;
}

//ESTE MÉTODO FUNCIONA -- NO TOCAR
void cargaTablero(tTablero& tablero, ifstream& archivo) {
    string casillaESP;
    int x; char aux;
    if (archivo.is_open()) {
        archivo >> x;

        while (x != 0) {
            archivo.get(aux);
            getline(archivo, casillaESP);

            if (casillaESP == "OCA") {
                tablero[x - 1] = OCA;
            }
            else if (casillaESP == "PUENTE1") {
                tablero[x - 1] = PUENTE1;
            }
            else if (casillaESP == "PUENTE2") {
                tablero[x - 1] = PUENTE2;
            }
            else if (casillaESP == "DADO1") {
                tablero[x - 1] = DADO1;
            }
            else if (casillaESP == "DADO2") {
                tablero[x - 1] = DADO2;
            }
            else if (casillaESP == "NORMAL") {
                tablero[x - 1] = NORMAL;
            }
            else if (casillaESP == "POZO") {
                tablero[x - 1] = POZO;
            }
            else if (casillaESP == "LABERINTO") {
                tablero[x - 1] = LABERINTO;
            }
            else if (casillaESP == "CARCEL") {
                tablero[x - 1] = CARCEL;
            }
            else if (casillaESP == "CALAVERA") {
                tablero[x - 1] = CALAVERA;
            }
            else if (casillaESP == "POSADA") {
                tablero[x - 1] = POSADA;
            }
            archivo >> x;
        }
        //imprimeArray(tablero);
    }
    else cout << "error!";
    
}



void cargaJugadores(tEstadoJugadores& jugadores, ifstream& archivo) {
    
    for (int i = 0; i < NUM_JUGADORES;i++) {
        archivo >> jugadores[i].posicion;
        jugadores[i].posicion--;
        archivo >> jugadores[i].penalizacion;
    }
}


void eliminarPartida(tListaPartidas& partidas, int indice) {
    
    if (indice < partidas.cont) { // el elemento existe

        for (int j = partidas.cont - 1; j > indice; j--) { //puede que en indice haya que poner indice -1
            partidas.arrayPartidas[j - 1] = partidas.arrayPartidas[j];
        }
        partidas.cont--;
    }
}


bool insertaNuevaPartida(tListaPartidas& partidas, const tEstadoPartida& partidaOca) {

    bool insertado = false;
    if (partidas.cont<=MAX_PARTIDAS) {

        //INSERTAR PARTIDA

        insertado = true;
        partidas.cont++;
    }
    else cout << "tienes demasiadas partidas" << endl;

    return insertado;
}


void guardaPartidas(const tListaPartidas& partidas) {

    ofstream archivoGuardar;

    string nombre;

    cout << "Dónde quieres guardar los datos? ";
    cin >> nombre;
    archivoGuardar.open(nombre);
    if (archivoGuardar.is_open()) {
        archivoGuardar << partidas.cont << endl;
        for (int i = 0; i < partidas.cont ;i++) {// esto no se si esta bien
            guardaTablero(partidas.arrayPartidas[i].tablero, archivoGuardar);
            archivoGuardar << partidas.arrayPartidas[i].turno << endl;
            guardaJugadores(partidas.arrayPartidas[i].estadoJ, archivoGuardar);
        }
        archivoGuardar.close();
    } else {
        cout << "Error al abrir el archivo" << endl;
        //terminar programa
        exit(0); //no se si esto funciona del todo
    }
}

void guardaTablero(const tTablero tablero, ofstream& archivo){
    for (int i = 0; i < NUM_CASILLAS-1;i++) {
        if(esCasillaPremio(tablero, i)){
            archivo << i + 1 << " "  << casillaAstringSinAbreviar(tablero[i]) << endl;
        }
    }
    archivo << 0<<endl;
}

void guardaJugadores(const tEstadoJugadores jugadores, ofstream& archivo) {
    for (int i = 0; i < NUM_JUGADORES - 1;i++)
        archivo << jugadores[i].posicion << " " << jugadores[i].penalizacion<<endl;  
}


string casillaAstringSinAbreviar(tCasilla casilla) {
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
        cadena = "PUENTE";
        break;
    case PUENTE2:
        cadena = "PUENTE";
        break;
    case POSADA:
        cadena = "POSADA";
        break;
    case CALAVERA:
        cadena = "MUERTE";
        break;
    case LABERINTO:
        cadena = "LABERINTO";
        break;
    case POZO:
        cadena = "POZO";
        break;
    case CARCEL:
        cadena = "CARCEL";
        break;
    }
    return cadena;
}