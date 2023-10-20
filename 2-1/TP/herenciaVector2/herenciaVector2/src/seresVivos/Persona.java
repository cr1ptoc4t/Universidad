package seresVivos;
import propiedades.Ordenable;
import seresVivos.*;

public class Persona extends SerVivo{
    // Variable estática como contador de objetos realizados con el constructor sin parámentros
    private static int numID = 0;
    /**
     * Construye una persona con el nombre indicado, la fecha de nacimiento
     * y el sueldo por mes.
     * @param nombre Nombre de la persona
     * @param fechaNac Fecha de nacimiento
     * @param sueldo sueldo al mes
     */
    public Persona(String nombre, Fecha fechaNac, double sueldo) {
        super(nombre, fechaNac, sueldo);
    }

    // Constructor sin parametros con contador de desconocidos
    /**
     * Construye una persona con el nombre "Desconocido" y el número de desconocido,
     * la fecha de nacimiento el día numID+1 de mes 1 y de año 1000
     * y el sueldo por mes será 0.0.
     */
    public Persona() {
        this("Desconido"+Persona.numID,
             new Fecha(1,1,1000),
             0.0);
        
        super.fechaNac.suma(Persona.numID);
        Persona.numID++;
    }



	public boolean esMenor(Persona p1, Persona p2) {
		return p1.edad()<p2.edad();
	}
	
	
}
