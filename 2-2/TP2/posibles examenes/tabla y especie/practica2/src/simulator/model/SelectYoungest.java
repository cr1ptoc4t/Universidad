package simulator.model;

import simulator.model.animals.Animal;
import simulator.model.animals.SelectionStrategy;

import java.util.List;

public class SelectYoungest implements SelectionStrategy {
    @Override
    public Animal select(Animal a, List<Animal> as) {
        if(as.isEmpty())
            return null;

        Animal youngest = null;
        for(Animal b: as)
            if(youngest==null || b.isYoungerThan(youngest))
                youngest = b;


        return youngest;
    }
}
