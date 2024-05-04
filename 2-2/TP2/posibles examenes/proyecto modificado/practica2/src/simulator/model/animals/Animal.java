package simulator.model.animals;


import org.json.JSONObject;
import simulator.misc.Utils;
import simulator.misc.Vector2D;
import simulator.model.Entity;
import simulator.model.regionmanager.AnimalMapView;
import simulator.model.regionmanager.RegionManager;

import java.util.List;

import static simulator.misc.Utils.estabilizar;

public class Animal implements Entity, AnimalInfo {
    private String _genetic_code;
    private Diet _diet;
    protected State _state;
    protected Vector2D _pos;
    protected Vector2D _dest;
    protected double _energy;
    private double _speed;
    protected double _age;
    protected double _desire;
    private double _sight_range;
    protected Animal _mate_target;
    protected Animal _baby;
    protected RegionManager _region_mngr;
    protected SelectionStrategy _mate_strategy;


    protected Animal(String genetic_code, Diet diet, double sight_range, double init_speed,
                     SelectionStrategy mate_strategy, Vector2D pos){
        if(genetic_code==null || sight_range<=0 || init_speed<=0 || mate_strategy==null)
            throw new IllegalArgumentException("Argumento inválido");
        else {
            this._genetic_code = genetic_code;
            this._diet = diet;
            this._sight_range = sight_range;
            this._mate_strategy = mate_strategy;
            this._age = 0.0;
            this._pos = pos;
            this._state=State.NORMAL;
            _region_mngr=null;
            this._speed = Utils.get_randomized_parameter(init_speed, 0.1);
            this._energy=100;
            this._desire =0.0;
            this._dest=null;
            this._mate_target=null;
            this._baby=null;
        }
    }

    protected Animal(Animal p1, Animal p2){
        if(p1==null||p2==null)   throw new IllegalArgumentException("Argumento inválido");

        this._dest = null;
        this._baby = null;
        this._mate_target = null;
        this._region_mngr = null;
        this._state = State.NORMAL;
        this._desire = 0.0;
        this._genetic_code = p1._genetic_code;
        this._diet = p1._diet;
        this._energy = (p1._energy + p2._energy)/2;
        this._pos = p1.get_position().plus(Vector2D.get_random_vector(-1,1).scale(60.0*(Utils._rand.nextGaussian()+1)));
        this._sight_range = Utils.get_randomized_parameter((p1.get_sight_range()+p2.get_sight_range())/2, 0.2);
        this._speed = Utils.get_randomized_parameter((p1.get_speed()+p2.get_speed())/2, 0.2);
        this._age = 0.0;
        this._mate_strategy = p2._mate_strategy;

    }

    @Override
    public void update(double dt) {

    }

    @Override
    public State get_state() {
        return this._state;
    }

    @Override
    public Vector2D get_position() {
        return this._pos;
    }

    @Override
    public String get_genetic_code() {
        return this._genetic_code;
    }

    @Override
    public Diet get_diet() {
        return this._diet;
    }

    @Override
    public double get_speed() {
        return this._speed;
    }

    @Override
    public double get_sight_range() {
        return this._sight_range;
    }

    @Override
    public double get_energy() {
        return this._energy;
    }

    @Override
    public double get_age() {
        return this._age;
    }

    @Override
    public Vector2D get_destination() {
        return this._dest;
    }

    public Animal get_baby(){
        return _baby;
    }
    public boolean is_pregnant() {
        return _baby != null;
    }
    public boolean is_dead(){return _state == State.DEAD;}


    public void init(RegionManager reg_mngr){

        this._region_mngr = reg_mngr;

        if( _pos == null)
            this._pos = Vector2D.posAleatoria(reg_mngr.get_width()-1, reg_mngr.get_height()-1);
        else
            this._pos.ajustaPos(reg_mngr.get_width(), reg_mngr.get_height());

        _dest = Vector2D.posAleatoria(reg_mngr.get_width(), reg_mngr.get_height());
    }

    public Animal deliver_baby() {
        Animal baby = _baby;
        _baby = null;
        return baby;
    }

    protected void move(double speed){
        this._pos = _pos.plus(_dest.minus(_pos).direction().scale(speed));
    }

    public JSONObject as_JSON() {
        JSONObject jo = new JSONObject();

        jo.put("pos", this._pos);
        jo.put("gcode", this._genetic_code);
        jo.put("diet", this._diet);
        jo.put("state", this._state);

        return jo;
    }

    public boolean isYoungerThan(Animal b) {
        return this._age < b._age;
    }
    protected void actualyzeAgeEnergyDesire(double sumToAge, double sumToEnergy, double sumToDesire,
                                            int min_energy, int max_energy, int min_desire, int max_desire){
        _age +=sumToAge;

        _energy += sumToEnergy;
        _energy = estabilizar(_energy, min_energy, max_energy);

        _desire+=sumToDesire;
        _desire = estabilizar(_desire, min_desire, max_desire);
    }

    public boolean isInVisualRange(Animal b){
        return _sight_range>=_pos.distanceTo(b._pos);
    }
    public boolean isInVisualRange(AnimalInfo b){
        return _sight_range>=_pos.distanceTo(b.get_position());
    }

    public Animal searchAnimalBySelectionStrategy(SelectionStrategy ss, Diet diet){
        List<Animal> list =_region_mngr.get_animals_in_range(this,
                animal -> animal.get_diet().equals(diet));
        return ss.select(this, list);
    }
    public static boolean isCloser(Animal a, Animal b, Animal closest){
        return  b._pos.distanceTo(a._pos) < closest._pos.distanceTo(a._pos);
    }
}
