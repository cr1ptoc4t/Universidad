package simulator.model.regions;

import org.json.JSONArray;
import org.json.JSONObject;
import simulator.model.Entity;
import simulator.model.animals.Animal;
import simulator.model.animals.Diet;
import simulator.model.animals.Sheep;

import java.util.ArrayList;
import java.util.List;

public abstract class Region implements Entity, FoodSupplier, RegionInfo {

    protected List <Animal> animalList;
    //solo una constructora
    public Region() {
        this.animalList = new ArrayList<>();
    }

    public final void add_animal(Animal a) {
        animalList.add(a);
    }

    public final void remove_animal(Animal a){
        animalList.remove(a);
    }

    public final List<Animal> getAnimals(){
        return animalList;
    }

    public JSONObject as_JSON(){
        JSONObject jo = new JSONObject();
        JSONArray animals = new JSONArray();

        for (Animal a: animalList)
            animals.put(a.as_JSON());

        jo.put("animals", animals);

        return jo;
    }
    protected List <Animal> filtraPorDieta(Diet diet){
        List <Animal> animals = new ArrayList<>();
        for (Animal a:animalList)
            if(a.get_diet().equals(diet))
                animals.add(a);

        return animals;
    }

}
