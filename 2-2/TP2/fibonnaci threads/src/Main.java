public class Main {
    public static void main(String[] args) throws InterruptedException {
        MiFuncion fact = new Factorial(5);
        MiFuncion fib = new Fib(5);

        fact.start();
        fib.start();

        fact.join();
        fib.join();
        System.out.println(fact.getRes());
    }
}