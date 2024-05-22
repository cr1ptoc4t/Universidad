package simulator.model.regions;

import simulator.misc.Utils;
import simulator.model.animals.Animal;
import simulator.model.animals.AnimalInfo;
import simulator.model.animals.Diet;

import java.util.List;

public class DryRegion extends Region {
    private double r1, r2, n, m;
    private boolean dry;
    private double time, rand_time;

    public DryRegion(double r1, double r2, double n, double m) {
        this.r1 = r1;
        this.r2 = r2;
        this.n = n;
        this.m = m;
        rand_time = Utils.get_randomized_parameter(0, this.m);
    }

    @Override
    public void update(double dt) {
        if (time < n) {
            dry = false;
        } else if (!dry&&time >= n) {
            dry = true;
            r1 = r1 * r2;
        } else if(dry&&time==rand_time+n){
            time = 0;
            dry= false;
        }
        time += dt;

        System.out.println("time? " + time + " dry? " + dry);
    }

    @Override
    public double get_food(Animal a, double dt) {
        double food = 0;
        if (a.get_diet() != Diet.CARNIVORE) {
            List<AnimalInfo> _lista_herbivoros = filtraPorDieta(Diet.HERBIVORE);
            food = 60.0 * Math.exp(-Math.max(0, _lista_herbivoros.size() - 5.0) * 2.0) * dt;
        }

        if (dry) {
            food *= r1;
        }

        return food;
    }

    public String toString() {
        return "Dry region";
    }
}
