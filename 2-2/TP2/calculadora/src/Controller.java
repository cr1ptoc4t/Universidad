public class Controller {

    private String opAnt;
    private String opSig;
    private String num1, num2;
    private CalculadoraModel m;

    public Controller() {
        m = new CalculadoraModel();
    }

    public void clear() {
        opAnt = "";
        opSig="";
        num1="";
        num2="";
    }

    public double executeOperation(String num1, String num2, String op){
        double n1 = Double.parseDouble(num1);
        double n2 = Double.parseDouble(num2);
        double res = switch (op) {
            case "+" -> n1 + n2;
            case "-" -> n1 - n2;
            case "*" -> n1 * n2;
            case "/" -> n1 / n2;
            default -> 0;
        };

        return res;
    }

    public void addObserver(Observer observer) {
        m.addObserver(observer);
    }

    public void removeObserver(Observer observer) {
        m.removeObserver(observer);
    }
}
