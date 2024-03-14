package simulator.model.regions;

import simulator.misc.Utils;
import simulator.model.animals.Animal;
import simulator.model.animals.Diet;

import java.util.Random;

public class DynamicSupplyRegion extends Region {

    double _food;
    double _factor;

    public DynamicSupplyRegion(double initialFood, double growFactor){
        _food=initialFood;
        _factor=growFactor;
    }
    @Override
    public void update(double dt) {
        if (Utils._rand.nextDouble() <= 0.5)
            this._food += _food*_factor*dt;

    }

    @Override
    public double get_food(Animal a, double dt) {
        double food = 0;

        if(a.get_diet()!= Diet.CARNIVORE) {
            food = Math.min(_food, 60.0 * Math.exp(-Math.max(0, animalList.size() - 5.0) * 2.0) * dt);
            this._food -= food;
        }

        return food;
    }
}
