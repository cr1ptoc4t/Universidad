package simulator;

import org.json.JSONArray;
import org.json.JSONObject;
import simulator.factories.Factory;
import simulator.misc.Vector2D;
import simulator.model.EcoSysObserver;
import simulator.model.Observable;
import simulator.model.animals.*;
import simulator.model.regionmanager.MapInfo;
import simulator.model.regionmanager.RegionManager;
import simulator.model.regions.DefaultRegion;
import simulator.model.regions.Region;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Observer;


public class Simulator implements Observable<EcoSysObserver> {
    private int height;
    private int width;
    private int rows;
    private int cols;
    private double _time;
    private List<Animal> _animals;
    private RegionManager _region_manager;
    private List<EcoSysObserver> _observers;

    private Factory<Animal> _animals_factory;
    private Factory<Region> _regions_factory;


    public Simulator(int cols, int rows, int width, int height,
                     Factory<Animal> animals_factory, Factory<Region> regions_factory){
        if(cols<0 || rows<0 || width<0 || height<0 || animals_factory==null || regions_factory== null)
            throw new IllegalArgumentException();


        this.cols = cols;
        this.rows = rows;
        this.width= width;
        this.height=height;

        this._animals_factory =animals_factory;
        this._regions_factory =regions_factory;

        _region_manager = new RegionManager(cols, rows, width, height);

        _time =0.0;
        _animals = new ArrayList<>();
        _observers= new ArrayList<>();
    }


    public int getHeight(){
        return height;
    }

    public int getWidth(){
        return width;
    }

    private void set_region(int row, int col, Region r){
        _region_manager.set_region(row, col, r);
    }

    public void set_region(int row, int col, JSONObject r_json){
        Region r = this._regions_factory.create_instance(r_json);
        set_region(row, col, r);
        notify_on_region_set(row, col, r);
    }

    public void add_animal(Animal a){
        _animals.add(a);
        _region_manager.register_animal(a);
        notify_on_animal_added(a);
    }
    public void remove_animal(Animal a){
        _region_manager.unregister_animal(a);
        _animals.remove(a);
    }

    public void add_animal(JSONObject a_json){
        add_animal(_animals_factory.create_instance(a_json));
    }
    public MapInfo get_map_info(){
        return _region_manager;
    }
    public List<? extends AnimalInfo> get_animals(){
        return new ArrayList<>(_animals);
    }
    public double get_time(){
        return _time;
    }

    public void advance(double dt){
        _time+=dt;
        int i=0;


        while(_animals.size()>i){
            if(_animals.get(i).get_state()==State.DEAD) {
                remove_animal(_animals.get(i));
            } else i++;
        }


        for(Animal animal : _animals){
            animal.update(dt);
            _region_manager.update_animal_region(animal);
        }

        _region_manager.update_all_regions(dt);

        ArrayList <Animal> newAnimals = new ArrayList<>();

        for (Animal animal : _animals) {
            if (animal.is_pregnant()) {
                newAnimals.add(animal.deliver_baby());
            }
        }

        for (Animal a: newAnimals) {
            add_animal(a);
        }

        notify_on_advance(dt);
    }

    public JSONObject as_JSON() {
        JSONObject jo = new JSONObject();
        jo.put("time", this._time);
        jo.put("state", _region_manager.as_JSON());
        return jo;
    }

    public void reset(int cols, int rows, int width, int height){
        this.cols = cols;
        this.rows = rows;
        this.width= width;
        this.height=height;

        _region_manager = new RegionManager(cols, rows, width, height);

        _time =0.0;
        _animals.clear();

        notify_on_reset();
    }

    @Override
    public void addObserver(EcoSysObserver o) {
        _observers.add(o);
        notify_on_register(o);
    }

    @Override
    public void removeObserver(EcoSysObserver o) {
        _observers.remove(o);
    }
    private void notify_on_advance(double dt) {
        List<AnimalInfo> animals = new ArrayList<>(_animals);

        for(EcoSysObserver o : _observers) {
            o.onAvanced(_time, _region_manager, animals, dt);
        }
    }

    private void notify_on_register(EcoSysObserver o) {
        List<AnimalInfo> animals = new ArrayList<>(_animals);
        o.onRegister(_time, get_map_info(), animals);
    }
    private void notify_on_reset() {
        List<AnimalInfo> animals = new ArrayList<>(_animals);
        for(EcoSysObserver o : _observers) {
            o.onReset(_time, _region_manager, animals);
        }
    }

    private void notify_on_animal_added(AnimalInfo a) {
        List<AnimalInfo> animals = new ArrayList<>(_animals);
        for(EcoSysObserver o : _observers) {
            o.onAnimalAdded(_time, get_map_info(), animals, a);
        }
    }

    private void notify_on_region_set(int row, int col, Region r) {
        List<AnimalInfo> animals = new ArrayList<>(_animals);
        for(EcoSysObserver o : _observers) {
            o.onRegionSet(row, col, get_map_info(), r);
        }
    }
}
