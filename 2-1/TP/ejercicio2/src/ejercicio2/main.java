package ejercicio2;
//package Vector;
public class main {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Vector v = new Vector(1);
		int random;
		
		for(int i=0;i<10;i++) {
			random = (int)(Math.random()*10+1);
		
			if(i==v.vector.length) {
				v.ampliar();
			}
			
			v.introducirElemento(random, i);
		}
		
		
		//	Muestra por pantalla los elementos del vector
		for(int i=0; i<v.vector.length;i++) {
			System.out.print(v.vector[i] + ", ");
		}
	}
}
