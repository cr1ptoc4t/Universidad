package seresVivos;
/**
 * Documentación de la clase Fecha
 */

/**
 * @author Albertoe
 * Segunda documentación
 *
 */
public class Fecha {
	// Atributos siempre privados, se deberían documentar
	private int dia;
	private int mes;
	private int anyo;
	
	/**
	 * Devuelve el dia segigiiñññññ
	 */
	@Override
	public String toString() {
	    return dia+"/"+mes+"/"+anyo;
	}
	
    /**
     *  Constructor
     * @param d días de la fecha
     * @param m mes de la fecha
     * @param a año de la fecha
     */
    public Fecha(int dia, int mes, int anyo) {
        this.dia = dia;
        this.mes = mes;
        this.anyo = anyo;
    }
	/**
	 * Falta cicndioeosonn
	 */
    public Fecha() {
        this(31, 12, 2023);
    }
    public Fecha(Fecha otra) {
        this(otra.dia, otra.mes, otra.anyo);
    }
	
	/**
	 * Método que incrementa la fecha en numDias
	 * @param numDias días a incrementar la fecha, solo se admiten valores positivos
	 */
	public void suma(int numDias) {
		int dia = this.dia + numDias;
		int mes = this.mes;
		int anyo = this.anyo;
		int diasMes = numDiasMes(mes, anyo);
		while (dia > diasMes) {
			dia -= diasMes;
			mes++;
			if (mes > 12) {
				mes = 1;
				anyo++;
			}
			diasMes = numDiasMes(mes, anyo);
	
		}
		this.dia = dia;
		this.mes = mes;
		this.anyo = anyo;
	}

	/**
	 * Muestra la fecha por la consola. 
	 * Este tipo de procedimientos NO se implentan en Java.
	 * 
	 * En Java se suele implementar un toString()
	 */
	public void escribe() {
		System.out.println(this.dia + "/" + this.mes + "/" + this.anyo);
	}
	
	
	/**
	 * Suele ser recomendable documentar todos los métodos aunque sean privados
	 * @param anyo Aquí se indica el contenido del atributo y sus posibles restricciones
	 * @return Se suele indicar lo que devuelve
	 */
	private boolean esBisiesto(int anyo) {
		return anyo % 4 == 0 && (anyo % 100 != 0 || anyo % 400 == 0);
	}

	/**
	 * Vaya falta por hacer, pues está mal!
	 * @param mes
	 * @param anyo
	 * @return
	 */
	private int numDiasMes(int mes, int anyo) {
		int numDias = 31;

		if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8
				|| mes == 10 || mes == 12)
			numDias = 31;
		else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
			numDias = 30;
		else if (esBisiesto(anyo))
			numDias = 29;
		else
			numDias = 28;

		return numDias;
	}
	int getDia(){
		return dia;
	}
}
