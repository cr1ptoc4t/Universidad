/**
  NOMBRE Y APELLIDOS DE LOS/AS AUTORES/AS DEL CONTROL:
  CATALINA FULLANA MORA
  ALAI MIRANDA BLANCO LASCURAIN

  (Si alguno de los miembros no ha participado, no debe aparecer)
*/

#include "GestionAdmisiones.h"



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

	_gravedad.inserta(gravedad_a_string(gravedad), Lista<CodigoPaciente>());

	DiccionarioHash <string, Lista<CodigoPaciente>>::Iterator it = _gravedad.busca(gravedad_a_string(gravedad));
	it.valor().pon_ppio(codigo);

	tPaciente p(codigo, nombre, edad, sintomas, gravedad, it.valor().begin());
	

	_pacientes.inserta(codigo, p);

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
 O(3logn)
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo, Gravedad& gravedad) const {
	if (_gravedad.esVacio())
		throw ENoHayPacientes();
	
	DiccionarioHash <string, Lista<CodigoPaciente>>::ConstIterator grav = _gravedad.cbusca("GRAVE");
	string gravedad_aux;
	
	if (grav != _gravedad.cend() && !grav.valor().esVacia()){
		codigo = grav.valor().primero();
		gravedad_aux = grav.clave();
	}
	else {
		grav = _gravedad.cbusca("NORMAL");
		if (grav != _gravedad.cend() && !grav.valor().esVacia()) {
			codigo = grav.valor().primero();
			gravedad_aux = grav.clave();
		}
		else {
			grav = _gravedad.cbusca("LEVE");
			if (grav != _gravedad.cend() && !grav.valor().esVacia()) {
				codigo = grav.valor().primero();
				gravedad_aux = grav.clave();
			}
			else {
				throw ENoHayPacientes();
			}
		}
	}

	gravedad = gravedad_paciente(gravedad_aux);
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
 O(n)
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
	DiccionarioHash <CodigoPaciente, tPaciente>:: Iterator  it = _pacientes.busca(codigo);
	if (it != _pacientes.end()) {
		DiccionarioHash <string, Lista<CodigoPaciente>>:: Iterator grav =
			_gravedad.busca(gravedad_a_string(it.valor()._g));

		if (grav != _gravedad.end()) {
			grav.valor().eliminar(it.valor()._pos);
			_pacientes.borra(codigo);
		}
	}
}


//O(1)
Gravedad GestionAdmisiones::gravedad_paciente(string gravedad) const
{
	if (gravedad == "LEVE") return LEVE;
	else if (gravedad == "NORMAL") return NORMAL;
	else return GRAVE;
}

//O(1)
string GestionAdmisiones::gravedad_a_string(Gravedad gravedad) const{
	if (gravedad == LEVE) return "LEVE";
	else if (gravedad == NORMAL) return "NORMAL";
	else return "GRAVE";
}
