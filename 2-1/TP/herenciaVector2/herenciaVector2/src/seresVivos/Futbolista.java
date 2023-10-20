package seresVivos;

public class Futbolista extends SerVivo{
    private double primas;
    private String equipo;
    
    public Futbolista(String nombreCompleto,
                   Fecha fechaNac,
                   double sueldoMes, 
                   String equipo) {
            
            super(nombreCompleto,fechaNac,sueldoMes);
            this.equipo = equipo;
            this.primas = 0.0;
        }
        @Override
        public double sueldoAnual() {
            double sueldoAux = super.sueldoAnual();
            return sueldoAux*14/12 +primas;
        }

        public void contratarPublicidad(double dinero) {
            this.primas += dinero;
        }

}
