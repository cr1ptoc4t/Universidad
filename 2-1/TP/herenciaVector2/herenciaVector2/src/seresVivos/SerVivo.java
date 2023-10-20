package seresVivos;

public abstract class SerVivo {
    private String nombreCompleto;
    protected Fecha fechaNac;
    private double sueldoMes;
    
    public SerVivo(String nombreCompleto,
                   Fecha fechaNac,
                   double sueldoMes) {
            
            this.nombreCompleto = nombreCompleto;
            this.fechaNac = fechaNac;
            this.sueldoMes = sueldoMes;
        }
        @Override
        public String toString() {
            return this.nombreCompleto +
                   "["+this.fechaNac.toString()+"]";
        }
        
        public String nombre () {
            return this.nombreCompleto;
        }

        public Fecha fechaNacimiento() {
            //return this.fechaNac; // MAL devuelvo mis tripas
            return new Fecha(this.fechaNac);
        }
        
        public double sueldoAnual() {
            return this.sueldoMes*12;
        }
        public double getSueldoMes() {
            return this.sueldoMes;
        }
        
        public int edad() {
        	return this.edad();
        }


}
