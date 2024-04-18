public class Factorial extends MiFuncion{

    int n;
    public Factorial(int n){
        this.n = n;
    }

    @Override
    public void apply() {
        int resultado = 1;

        for(int i = 1; i <= n; i++){
            resultado = resultado * i;
        }

        this.resultado = resultado;
    }
}
