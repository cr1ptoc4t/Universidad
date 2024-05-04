package simulator.model.animals;

import java.util.List;

public interface SelectionStrategy {
    Animal select(Animal a, List<Animal> as);

}