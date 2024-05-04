package simulator.model.regions;

import org.json.JSONArray;
import org.json.JSONObject;
import simulator.model.Entity;
import simulator.model.animals.Animal;
import simulator.model.animals.AnimalInfo;
import simulator.model.animals.Diet;
import simulator.model.regionmanager.RegionInfo;

import java.util.ArrayList;
import java.util.List;

public abstract class Region implements Entity, FoodSupplier, RegionInfo {

    protected List <Animal> _animals;
    //solo una constructora
    public Region() {
        this._animals = new ArrayList<>();
    }

    public final void add_animal(Animal a) {
        _animals.add(a);
    }

    public final void remove_animal(AnimalInfo a){
        _animals.remove(a);
    }

    public List<Animal> getAnimals(){
        return _animals;
    }
    public List<AnimalInfo> getAnimalsInfo(){
        return new ArrayList<>(_animals);
    }

    public JSONObject as_JSON(){
        JSONObject jo = new JSONObject();
        JSONArray animals = new JSONArray();

        for (AnimalInfo a: _animals)
            animals.put(a.as_JSON());

        jo.put("animals", animals);

        return jo;
    }
    protected List <AnimalInfo> filtraPorDieta(Diet diet){
        List <AnimalInfo> animals = new ArrayList<>();
        for (AnimalInfo a:_animals)
            if(a.get_diet().equals(diet))
                animals.add(a);

        return animals;
    }

}
