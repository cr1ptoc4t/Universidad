/**
  NOMBRE Y APELLIDOS DE LOS/AS AUTORES/AS DEL CONTROL:
  CATALINA FULLANA MORA
  ALAI MIRANDA BLANCO LASCURAIN


  (Si alguno de los miembros no ha participado, no debe aparecer)
*/

#ifndef _GESTION_ADMISIONES_H
#define _GESTION_ADMISIONES_H

#include <string>
#include "DiccionarioHash.h"
#include "lista.h"
using namespace std;


/**
Tipo que representa el c�digo de los
pacientes
*/
typedef unsigned int CodigoPaciente;

/**
Tipo que representa el grado de gravedad de un
paciente.
*/
typedef enum { LEVE, NORMAL, GRAVE } Gravedad;


/**
RECUERDA QUE PUEDES DEFINIR AQUI TODAS LAS CLASES
Y TIPOS ADICIONALES QUE CONSIDERES OPORTUNO
*/


/**
Excepci�n que debe levantarse cuando trata de darse de alta
un paciente con un c�digo duplicado
*/
class EPacienteDuplicado {};

/**
Excepci�n que debe levantarse cuando trata de consultarse los
datos de un paciente a trav�s de un c�digo que no existe.
*/
class EPacienteNoExiste {};

/**
Excepci�n que debe levantarse cuando trata de consultarse la informaci�n
del siguiente paciente a atender, pero no hay pacientes en el sistema.
*/
class ENoHayPacientes {};

/**
Clase que implementa el TAD
*/
class GestionAdmisiones {
public:
	/**
	  Constructora: crea un sistema de gesti�n de admisiones vac�o
	*/
	GestionAdmisiones();
	/**
	  A�ade un paciente al sistema.
	  Levanta la excepci�n EPacienteDuplicado si ya hay un paciente esperando con el
	  mismo codigo
	  @param codigo El c�digo del paciente
	  @param nombre El nombre del paciente
	  @param edad La edad del paciente
	  @param sintomas Los sintomas del paciente
	  @param gravedad El nivel de gravedad del paciente
	*/
	void an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas, Gravedad gravedad);
	/**
	  Recupera los datos de un paciente, dado su c�digo.
	  Levanta la excepci�n EPacienteNoExiste si el c�digo no se corresponde con el
	  de ning�n paciente en espera
	  @param codigo El c�digo del paciente
	  @param nombre El nombre del paciente
	  @param edad La edad del paciente
	  @param sintomas Los sintomas del paciente
	*/
	void info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const;
	/**
	  Recupera el c�digo y el nivel de gravedad del siguiente paciente que va a ser atendido.
	  Levanta la excepci�n ENoHayPacientes en caso de que no haya pacientes en espera.
	  @param codigo El c�digo del paciente
	  @param gravedad El nivel de gravedad del paciente
	*/
	void siguiente(CodigoPaciente& codigo, Gravedad& gravedad) const;
	/**
	  Determina si hay pacientes en espera
	  @return true si hay pacientes, false en otro caso.
	*/
	bool hay_pacientes() const;
	/**
	  Elimina del sistema todo el rasto de un paciente, dado su c�digo.
	  Si el c�digo no existe, la operaci�n no tiene efecto.
	  @param codigo El codigo del paciente a eliminar.
	*/
	void elimina(CodigoPaciente codigo);


	class tPaciente {
	public:
		CodigoPaciente _codigo;
		string _nombre;
		unsigned int _edad;
		string _sintomas;
		Gravedad _g;
		 Lista<CodigoPaciente>::Iterator _pos;

		tPaciente(CodigoPaciente c, string nombre, unsigned int edad, string sintomas, Gravedad g,Lista<CodigoPaciente>::Iterator pos) {
			_codigo = c;
			_nombre = nombre;
			_edad = edad;
			_sintomas = sintomas;
			_g = g;
			_pos = pos;
		}
	private:
	};
private:
	Gravedad gravedad_paciente(string gravedad)const;
	string gravedad_a_string(Gravedad gravedad)const;
	DiccionarioHash <CodigoPaciente, tPaciente> _pacientes;
	DiccionarioHash <string, Lista<CodigoPaciente>> _gravedad;
};

#endif