import java.io.Serializable;
import java.util.List;

public class CalculadoraModel implements Observable<Observer> {

    List<Observer> observerList;

    int resultado;

    public CalculadoraModel() {

    }


    @Override
    public void addObserver(Observer observer) {
        observerList.add(observer);
    }

    @Override
    public void removeObserver(Observer observer) {
        observerList.remove(observer);
    }
}
