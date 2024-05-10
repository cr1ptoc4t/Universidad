/**
  NOMBRE Y APELLIDOS DE LOS/AS AUTORES/AS DEL CONTROL:


  (Si alguno de los miembros no ha participado, no debe aparecer)
*/

#include "GestionAdmisiones.h"
#include "Cola.h"


/**
Debes completar la implementación de las operaciones de GestionAdmisiones,
y justificar la complejidad de los mismos.
*/


/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
GestionAdmisiones::GestionAdmisiones() {
	// A IMPLEMENTAR

}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 o(1);
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas, Gravedad gravedad) {
	if (_pacientes.contiene(codigo))
		throw EPacienteDuplicado();

	tPaciente p(codigo, nombre, edad, sintomas, gravedad);

	_pacientes.inserta(codigo, p);
	//añadir a lista _gravedad

}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 O(logn)
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {

	DiccionarioHash <CodigoPaciente, tPaciente>:: ConstIterator i = _pacientes.cbusca(codigo);

	if (i == _pacientes.cend())
		throw EPacienteNoExiste();

	nombre = i.valor()._nombre;
	edad = i.valor()._edad;
	sintomas = i.valor()._sintomas;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 O(n)
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo, Gravedad& gravedad) const {
	DiccionarioHash<CodigoPaciente, tPaciente>::ConstIterator i = _pacientes.cbegin();

	if (_pacientes.esVacio()||i==_pacientes.cend())
		throw ENoHayPacientes();

	while (i!=_pacientes.cend()&&i.valor()._g!=GRAVE) {
		i.next();
	}

	if (i == _pacientes.cend()) {
		i = _pacientes.cbegin();
		while (i != _pacientes.cend() && i.valor()._g != NORMAL) {
			i.next();
		}
		if (i == _pacientes.cend()){
			i = _pacientes.cbegin();
			while (i != _pacientes.cend() && i.valor()._g != LEVE) {
				i.next();
			}
		}
	}

	codigo = i.valor()._codigo;
	gravedad = i.valor()._g;

}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 O(1)
*/
bool GestionAdmisiones::hay_pacientes() const {
	return !_pacientes.esVacio();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
	_pacientes.borra(codigo);
}

