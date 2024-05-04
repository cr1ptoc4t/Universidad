package simulator.model;

import simulator.model.animals.Animal;
import simulator.model.animals.SelectionStrategy;

import java.util.List;
import simulator.misc.Vector2D;

import static simulator.model.animals.Animal.isCloser;

public class SelectClosest implements SelectionStrategy {

    @Override
    public Animal select(Animal a, List<Animal> as) {

        if(as.isEmpty())
            return null;

        Animal closest = null;
        for(Animal b: as)
            if(closest == null || isCloser(a, b, closest))
                closest = b;


        return closest;
    }
}
