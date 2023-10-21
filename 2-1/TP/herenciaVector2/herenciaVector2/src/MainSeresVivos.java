import seresVivos.*;
import coleccion.Vector;
import propiedades.Ordenable;
import seresVivos.Persona;
public class MainSeresVivos {
    // Prueba de la clase Vector y toString
    public static void main(String[] args) {
        Vector<Persona> miVector = new Vector<Persona>(10);

        miVector.anyadirAlFinal(new Persona());
        miVector.anyadirAlFinal(new Persona());
        
        System.out.println(miVector.toString());
    }
    
    // Prueba de herencia
    public static void main0(String[] args) {
        Persona laPersona = 
                new Persona("Yo",
                            new Fecha(23,2,1976),
                            2345.28);
        
        System.out.println("Yo 1: "+ laPersona.toString());

        Fecha fechaAux = laPersona.fechaNacimiento();
        fechaAux.suma(7);
        System.out.println("Una semana después de tu nacimiento era el día: "+
                           fechaAux);
        
        System.out.println("Yo 2: "+ laPersona.toString());        
    }
    
    public void ordenar(Vector <Ordenable> vect) {
		boolean ordenado= false;
		while(!ordenado) {
			for(int i=0; i<vect.numeroElementos()-1;i++) {
				ordenado= true;
				//if(vect.dameElemEnPos(i).esMenor(dameElemEnPos(i+1))) {
					//swap
				//	SerVivo temp;
					
					//temp = vect.dameElemEnPos(i);
					//vect.ponElementoEnPos(vect.dameElemEnPos(i+1),i);
					//vect.ponElementoEnPos(temp, i+1);
					
					//booleano para hacer más eficiente el código
					ordenado = false;
				//}
					
			}
		}
		
	}
}
