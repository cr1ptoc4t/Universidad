/*
NOMBRE Y APELLIDOS:

USUARIO DomJudge ASIGNADO:

*/

#include "yoMeVacuno.h"


/*
 DETERMINACION DE LA COMPLEJIDAD

*/
YoMeVacuno::YoMeVacuno(tAnio anio, tNumVacunas n) :_n(n), _anio(anio) {}


/*
 DETERMINACION DE LA COMPLEJIDAD

*/
void YoMeVacuno::fija_Anio_NumVacunas(tAnio anio, tNumVacunas n) {
	_n += n;
	_anio = anio;
}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
void YoMeVacuno::registra_centro(tIdCentro id, tDireccion dir) {
	if (_centros.contiene(id))
		throw ECentroDuplicado();


	_centros.inserta(id, dir);
	Cola <tIdCiudadano> c;
	_lista_espera.inserta(id, c);
	centros_ord.inserta(id, 1);
}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
void YoMeVacuno::registra_ciudadano(tIdCiudadano id, tAnio anio) {
	if (_ciudadanos.contiene(id))
		throw ECiudadanoDuplicado();

	_ciudadanos.inserta(id, anio);
}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
void YoMeVacuno::pide_cita(tIdCiudadano id) {
	if (!_ciudadanos.contiene(id))
		throw ECiudadanoInexistente();
	else if (_ciudadanos.valorPara(id) != _anio)
		throw EAnioErroneo();
	else if (_ciud_cita_pedida.contiene(id) || _ciudadanos_cita.contiene(id))
		throw EExisteCita();
	else {
		_peticiones.pon(id);
		_ciud_cita_pedida.inserta(id, 1);
	}
}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
bool YoMeVacuno::en_espera() {
	return !_peticiones.esVacia();
}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
Lista<Asignacion> YoMeVacuno::atiende_solicitudes() {
	if (_centros.esVacio())
		throw EErrorDeAtencion();
	if (_peticiones.esVacia() || _n == 0)
		return Lista<Asignacion>();


	_itcentros = _centros.cbegin();

	Lista<Asignacion> asignaciones;

	while (!_peticiones.esVacia() && _n>0) {

		tIdCiudadano beneficiado = _peticiones.primero();
		_peticiones.quita();

		Asignacion a;
		a.ponCiudadano(beneficiado);
		a.ponCentro(_itcentros.clave());
		a.ponDireccion(_itcentros.valor());
		
		asignaciones.pon_final(a);

		//_ciudadanos_cita.inserta(beneficiado, _itcentros.clave());

		_lista_espera.busca(_itcentros.clave()).valor().pon(beneficiado);

		_itcentros.next();

		if (_itcentros == _centros.cend())
			_itcentros = _centros.cbegin();


		_ciud_cita_pedida.borra(beneficiado);

		_n--;
	}

	return asignaciones;
}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
bool YoMeVacuno::administra_vacuna(tIdCentro idCentro) {
	if (!_centros.contiene(idCentro))
		throw ECentroInexistente();
	
	Diccionario <tIdCentro, Cola<tIdCiudadano>>::Iterator t 
		= _lista_espera.busca(idCentro);
	
	if (t.valor().esVacia())
		return false;
	
	tIdCiudadano c = t.valor().primero();
	_ciudadanos.borra(c);
	_ciudadanos_cita.borra(c);
	t.valor().quita();

	_ciudadanos.borra(c);

	return true;
}
