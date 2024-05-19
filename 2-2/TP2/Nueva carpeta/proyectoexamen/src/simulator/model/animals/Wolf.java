package simulator.model.animals;

import simulator.misc.Utils;
import simulator.misc.Vector2D;
import simulator.model.regionmanager.RegionManager;

import java.util.List;

import static simulator.misc.Utils._rand;
import static simulator.misc.Utils.estabilizar;
import static simulator.misc.Vector2D.posAleatoria;

public class  Wolf extends Animal{
    private Animal _hunt_target;
    private SelectionStrategy _hunting_strategy;
    final static double SIGHT_RANGE = 50.0;
    final static double INIT_SPEED = 65.0;

    final static int MIN_ENERGY = 0;
    final static int MAX_ENERGY = 100;
    final static int MIN_DESIRE = 0;
    final static int MAX_DESIRE = 100;
    final static int MAX_AGE = 14;



    public Wolf (SelectionStrategy mate_strategy, SelectionStrategy hunting_strategy, Vector2D pos){
        super("WOLF",  Diet.CARNIVORE , SIGHT_RANGE, INIT_SPEED, mate_strategy, pos);
        this._hunting_strategy = hunting_strategy;
    }

    protected Wolf(Wolf p1, Animal p2){
        super(p1, p2);
        this._hunting_strategy = p1._hunting_strategy;
        this._hunt_target = null;
    }

    @Override
    public void update(double dt) {
        if(get_state()!= State.DEAD){
            actualizaSegunEstado(dt);

            //3. Si la posición está fuera del mapa, ajustarla y cambiar su estado a NORMAL.
            if(!_pos.esPosValida(_region_mngr)) {
                _pos.ajustaPos(_region_mngr.get_width(), _region_mngr.get_height());
                cambiaEstadoA(State.NORMAL);
            }
            //4. Si _energy es 0.0 o _age es mayor de 14.0, cambia su estado a DEAD.
            if(get_energy()==MIN_ENERGY || get_age()>MAX_AGE)
                cambiaEstadoA(State.DEAD);

            if(get_state()!=State.DEAD){
                _energy+= _region_mngr.get_food(this, dt);
                _energy= estabilizar(_energy, MIN_ENERGY, MAX_ENERGY);
            }
        }
    }

    private void actualizaSegunEstado(double dt){
        switch (get_state()){
            case NORMAL:
                updateNormal(dt);
                break;
            case HUNGER:
                updateHunger(dt);
                break;
            case MATE:
                updateMate(dt);
        }
    }

    private void cambiaEstadoA(State st){
        switch(st){
            case MATE:
                _hunt_target = null;
                break;
            case HUNGER:
                _mate_target = null;
                break;
            case NORMAL:
                _mate_target = null;
                _hunt_target = null;
        }
        _state=st;
    }


    private void updateNormal(double dt) {
        avanzaNormal(dt);
        if(_energy<50.0)        cambiaEstadoA(State.HUNGER);
        else if(_desire>65)     cambiaEstadoA(State.MATE);
    }

    private void updateHunger(double dt) {

        if(_hunt_target==null||((_hunt_target.get_state()==State.DEAD || !isInVisualRange(_hunt_target))))
            _hunt_target = searchAnimalBySelectionStrategy(_hunting_strategy, Diet.HERBIVORE);

        if(_hunt_target==null)
            avanzaNormal(dt);
        else{
            _dest= _hunt_target.get_position();

            move(3.0*get_speed()*dt*Math.exp((_energy-100.0)*0.007));

            actualyzeAgeEnergyDesire(dt, -18.0*1.2*dt, 30*dt,
                    MIN_ENERGY, MAX_ENERGY, MIN_DESIRE, MAX_DESIRE);

            if(_pos.distanceTo(_hunt_target.get_position())<8.0)
                cazar();
        }

        if(_energy>50.0) {
            if (_desire < 65.0) cambiaEstadoA(State.NORMAL);
            else                cambiaEstadoA(State.MATE);
        }
    }

    private void cazar(){
        _hunt_target._state = State.DEAD;
        _hunt_target = null;
        _energy+=50;
        _energy=estabilizar(_energy, MIN_ENERGY, MAX_ENERGY);
    }

    private void avanzaNormal(double dt){
        if(_pos.distanceTo(_dest)<8.0)
            _dest = Vector2D.posAleatoria(_region_mngr.get_width(), _region_mngr.get_height());

        move(get_speed()*dt*Math.exp((_energy-100.0)*0.007));
        actualyzeAgeEnergyDesire(dt, -18.0*dt, 30*dt,
                MIN_ENERGY, MAX_ENERGY, MIN_DESIRE, MAX_DESIRE);
    }

    private void updateMate(double dt) {
        if (_mate_target != null && (_mate_target.get_state() == State.DEAD || !isInVisualRange(_mate_target)))
            _mate_target = null;

        if (_mate_target == null)
            _mate_target = searchAnimalBySelectionStrategy(_mate_strategy, this.get_diet());

        if (_mate_target == null) {
            avanzaNormal(dt);
        } else {
            _dest = _mate_target._pos;
            move(3.0 * get_speed() * dt * Math.exp((_energy - 100.0) * 0.007));
            actualyzeAgeEnergyDesire(dt, -18 * 1.2 * dt, 30 * dt,
                    MIN_ENERGY, MAX_ENERGY, MIN_DESIRE, MAX_DESIRE);
            if (_pos.distanceTo(_mate_target.get_position()) < 8.0)
                emparejarse(_mate_target);
        }

        if(_energy<50)          cambiaEstadoA(State.HUNGER);
        else if (_desire<65.0)  cambiaEstadoA(State.NORMAL);
    }

    private void emparejarse(Animal animal){
        _desire=0;
        _mate_target._desire=0;

        if(!is_pregnant() &&!_mate_target.is_pregnant() && Utils._rand.nextDouble()<0.9)
            _baby = new Wolf(this, _mate_target);

        _energy -= 10;
        _energy = estabilizar(_energy, MIN_ENERGY, MAX_ENERGY);

        _mate_target=null;
    }
}
