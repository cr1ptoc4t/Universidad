package ejercicio2;

public class Vector {
	int vector[];
	
	//constructor
	public Vector(int longitud){
		vector = new int [longitud];
	}
	
	public void introducirElemento(int elem, int pos) {
		vector[pos]=elem;
	}
	
	public void ampliar() {
		//creamos un nuevo vector el doble de largo
		int [] vector2 = new int [vector.length*2];
		
		//metemos informacion del vector 1 en el vector 2;
		for(int i=0;i<vector.length;i++) {
			vector2[i]=vector[i];
		}
		
		//vector2 pasa a ser vector
		vector=vector2;
	}
}
