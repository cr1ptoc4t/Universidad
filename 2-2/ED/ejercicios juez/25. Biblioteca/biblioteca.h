#pragma once
/**
  NOMBRE Y APELLIDOS:
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#ifndef _biblioteca_H
#define _biblioteca_H


#include "lista.h"
#include <string>
using namespace std;

// clases para las excepciones
class ELibroExistente {};  // excepción asociada a "annadir_libro"
class ESocioExistente {}; // excepción asociada a "annadir_socio"
class EPrestamoNoAdmitido {};  // excepción asociada a "prestar"
class ELibroInexistente {};  // excepción asociada a "primeroEnEspera"
class ESinEsperas {};  // excepción asociada a "primeroEnEspera"
class ESocioInexistente {};  // excepción asociada a "prestados"
class EDevolucionNoAdmitida {};  // excepción asociada a "devolver"

typedef unsigned int tSignatura;  // tipo para la signatura del libro
typedef unsigned int tCodigo;  // tipo para el código de identificación del socio
typedef unsigned int tNumEjemplares; // tipo para el nº ejemplares que hay de un libro
typedef string tNombre; // tipo para el nombre del socio
typedef string tFecha; // tipo para la fecha de los préstamos

//clase para la operación "primeroEnEspera"
class Codigo_y_Nombre {
public:
    tCodigo id;
    tNombre n;
};

// clase para la operación "prestados"
class Signatura_y_Fecha {
public:
    tSignatura signatura;
    tFecha fecha;
};



class Biblioteca {
public:
    Biblioteca();
    void annadir_libro(tSignatura signatura, tNumEjemplares num_ejemplares);
    void annadir_socio(tCodigo id, tNombre nombre);
    unsigned int prestar(tSignatura signatura, tCodigo id, tFecha fecha);
    Codigo_y_Nombre primeroEnEspera(tSignatura signatura) const;
    Lista<Signatura_y_Fecha>prestados(tCodigo id) const;
    bool devolver(tSignatura signatura, tCodigo id, tFecha fecha);
private:

};

#endif