package simulator.model.animals;

import java.util.Objects;

public enum Diet {
    HERBIVORE, CARNIVORE;
    private Diet(){

    }

    public static Diet castDiet(String str){
        Diet d = Diet.HERBIVORE;
        if (Objects.equals(str, "CARNIVORE")){ d = Diet.CARNIVORE; }
        return d;
    }
}
