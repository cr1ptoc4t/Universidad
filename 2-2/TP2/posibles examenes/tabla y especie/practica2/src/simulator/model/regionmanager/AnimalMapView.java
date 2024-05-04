package simulator.model.regionmanager;

import simulator.model.animals.Animal;
import simulator.model.regionmanager.MapInfo;
import simulator.model.regions.FoodSupplier;

import java.util.List;
import java.util.function.Predicate;

public interface AnimalMapView extends MapInfo, FoodSupplier {
    public List<Animal> get_animals_in_range(Animal e, Predicate<Animal> filter);
}
