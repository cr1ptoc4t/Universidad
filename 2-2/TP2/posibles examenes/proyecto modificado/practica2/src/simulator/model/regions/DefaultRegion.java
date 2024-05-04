package simulator.model.regions;

import simulator.model.animals.Animal;
import simulator.model.animals.AnimalInfo;
import simulator.model.animals.Diet;

import java.util.List;

public class DefaultRegion extends Region {

    @Override
    public void update(double dt) {
    }

    @Override
    public double get_food(Animal a, double dt) {
        double food=0;
        if(a.get_diet()!= Diet.CARNIVORE) {
            List<AnimalInfo> _lista_herbivoros = filtraPorDieta(Diet.HERBIVORE);
            food = 60.0 * Math.exp(-Math.max(0, _lista_herbivoros.size() -5.0) * 2.0) * dt;
        }
        return food;
    }

    public String toString(){
        return "Default region";
    }
}
