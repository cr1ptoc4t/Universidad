package simulator.model.regions;

import simulator.model.animals.Animal;

public interface FoodSupplier {
    double get_food(Animal a, double dt);
}