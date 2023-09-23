package ex1;

public class ex1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Fecha miFecha1 = construye(3, 10,2014);
		Fecha miFecha2 = construye(27, 4,1990);
		
		//miFecha1.escribe();
		//miFecha1.suma(3);
		//System.out.print("Avanzando 3 dias a mi fecha 1: " );
		//miFecha1.escribe();
		
		miFecha2.escribe();
		miFecha2.suma(100);
		System.out.print("Avanzando una semana a mi fecha 2: " );
		miFecha2.escribe();

	}
	
	public static Fecha construye(int dia, int mes, int anyo) {
		return new Fecha(dia, mes, anyo);
	}

}
