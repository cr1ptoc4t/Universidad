package simulator.model;

import simulator.model.animals.Animal;
import simulator.model.animals.SelectionStrategy;

import java.util.List;

public class SelectFirst implements SelectionStrategy {
    @Override
    public Animal select(Animal a, List<Animal> as) {
        if(as.isEmpty())
            return null;

        return as.get(0);
    }
}
