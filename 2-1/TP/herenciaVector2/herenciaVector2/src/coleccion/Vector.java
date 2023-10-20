package coleccion;

public class Vector<T> {
    private int nElem;
    private Object[] datos;
    
    public Vector(int capI) {
        this.nElem = 0;
        this.datos =  new Object[capI];
    }
    public T dameElemEnPos(int pos) {
        T elElem = null;
        if (esPosValida(pos)) elElem = (T) this.datos[pos];
        return elElem;
    }
    public boolean esPosValida(int pos) {
        return 0<= pos && pos < this.nElem;
    }
    public void anyadirAlFinal(T elem) {
        if (estaLleno()) duplicar(); 
        
        this.datos[this.nElem] = elem;
        this.nElem++;
    }
    private void duplicar() {
        Object[] elVAux = new Object[capacidad()*2];
        int nAux = 0;

        for(Object elem: this.datos) { // for Each
            elVAux[nAux] = elem;
            nAux++;
        }
        this.datos = elVAux;
    }
    
    public int numeroElementos() {
        return this.nElem;
    }
    private boolean estaLleno() {
        return numeroElementos() == capacidad();
    }
    private int capacidad() {
        return this.datos.length;
    }
    /*
     * Se explica en clase la diferencia entre:
     * String: inmutable, para procesos iterativos tarda mucho
     * StringBuilder: mutable y no sincronizado, el más rápido si no se porgrama para varias hebras
     * StringBuffer: mutable y sincronizada, rápido y seguro ante varias hebras
     */
    @Override
    public String toString() {
        StringBuilder elStr= new StringBuilder();
        elStr.append('[');
        
        for(int i = 0; i< this.nElem; i++) {
            elStr.append(this.datos[i].toString());
            elStr.append(',');
        }
        if (elStr.length() > 1) elStr.replace(elStr.length()-1, elStr.length(), "]");
        else elStr.append(']');
        
        return elStr.toString();
    }
    
    public void ponElementoEnPos(T elem, int pos) {
    	for (int i=numeroElementos(); i>pos;i--) {
    		datos[i+1]=datos[i];
    	}
    	this.datos[pos]= elem;
    }

}
