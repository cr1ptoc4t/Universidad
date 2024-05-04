/*
NOMBRE Y APELLIDOS:

USUARIO DomJudge ASIGNADO:

*/

#ifndef _yomevacuno_H
#define _yomevacuno_H

#include "lista.h"
#include "Cola.h"
#include "DiccionarioHash.h"
#include "Diccionario.h"
#include <string>
using namespace std;

class ECentroDuplicado {};  // excepción asociada a registra_centro
class ECiudadanoDuplicado {}; // excepción asociada a registra_ciudadano
class ECiudadanoInexistente {};  // excepción asociada a pide_cita
class EAnioErroneo {};  // excepción asociada a pide_cita
class EExisteCita {};  // excepción asociada a pide_cita
class EErrorDeAtencion {};  // excepción asociada a atiende_solicitudes
class ECentroInexistente {};  // excepción asociada a administra_vacuna

typedef unsigned int tIdCentro;  // tipo para el identificador del centro
typedef string tDireccion; // tipo para la dirección del centro
typedef unsigned int tIdCiudadano; // tipo para el identificador del ciudadano
typedef unsigned int tNumVacunas; // tipo para el nº de vacunas disponibles
typedef unsigned int tAnio; // tipo para el año de nacimiento

// clase para la asignación de centro a ciudadano que ha pedido cita  
class Asignacion {
public:
    void ponCiudadano(tIdCiudadano id) { _ciudadano = id; }
    void ponCentro(tIdCentro id) { _centro = id; }
    void ponDireccion(tDireccion dir) { _direccion = dir; }
    const tIdCiudadano& dameCiudadano() const { return _ciudadano; }
    const tIdCentro& dameCentro() const { return _centro; }
    const tDireccion& dameDireccion() const { return _direccion; }
private:
    tIdCiudadano  _ciudadano;
    tIdCentro _centro;
    tDireccion _direccion;
};


class YoMeVacuno {
public:
    YoMeVacuno(tAnio anio, tNumVacunas n);
    void registra_centro(tIdCentro id, tDireccion dir);
    void registra_ciudadano(tIdCiudadano id, tAnio anio);
    void fija_Anio_NumVacunas(tAnio anio, tNumVacunas n);
    void pide_cita(tIdCiudadano id);
    bool en_espera();
    Lista<Asignacion> atiende_solicitudes();
    bool administra_vacuna(tIdCentro idCentro);
private:
    tAnio _anio;
    tNumVacunas _n;

    Diccionario <tIdCentro, tDireccion> _centros;
    Diccionario<tIdCentro, int> centros_ord;

    DiccionarioHash <tIdCiudadano, tAnio> _ciudadanos;
    
    Cola <tIdCiudadano> _peticiones;
    Diccionario <tIdCentro, Cola<tIdCiudadano>> _lista_espera;
    DiccionarioHash <tIdCiudadano, tIdCentro> _ciudadanos_cita;
    DiccionarioHash<tIdCiudadano, bool> _ciud_cita_pedida;
    Diccionario <tIdCentro, tDireccion>::ConstIterator _itcentros;
};

#endif