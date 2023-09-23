package ex1;

public class Fecha {
	
	private int dia;
	private int mes;
	private int anyo;
	
	
	//constructor
	public Fecha(int dia, int mes, int anyo) {
		this.dia=dia;
		this.mes=mes;
		this.anyo=anyo;
	}
	
	
	//provisional, numdias<31
	public void suma(int numdias) {
		//cuantos dias tiene el mes
		/*
		int diasMes= 30;
		if(mes%2==1 && mes<=7 || mes%2==0 && mes>=8) { //1, 3, 5, 7,8,10,12
			diasMes++;
		} else if(mes==2) {	//si es en febrero
			diasMes=28;
			if(anyo%4==0) {
				diasMes=29;
			}
		}
		*/
		
		while(numdias>0) {
			int diasMes= numDiasMes();
			
			if(numdias>=diasMes) {
				numdias-=diasMes;
				
			}else {
				dias += numdias;
			}
			
		//	numdias= numdias%diasMes;
		}
		
		//this.mes += (this.dia + numdias) /diasMes;
		//this.dia = (this.dia + numdias) % diasMes;
					
	}
	public void sumaMes(int numMeses) {
		suma(numMeses*31);
	}
	
	public void escribe() {
		System.out.println(dia+"/"+mes+"/"+anyo);
	}
	
	private int numDiasMes() {
		int diasMes= 30;
		if(mes%2==1 && mes<=7 || mes%2==0 && mes>=8) { //1, 3, 5, 7,8,10,12
			diasMes++;
		} else if(mes==2) {	//si es en febrero
			diasMes=28;
			if(anyo%4==0) {
				diasMes=29;
			}
		}
		return diasMes;
	}
}
