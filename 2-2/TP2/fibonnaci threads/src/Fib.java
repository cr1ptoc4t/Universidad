public class Fib extends MiFuncion {

    private int n;

    public Fib(int n) {
        this.n = n;
    }

    @Override
    public void apply() {
        int a = 0, b = 1;
        int c;
        for (int i = 0; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }

        this.resultado = b;
    }
}
