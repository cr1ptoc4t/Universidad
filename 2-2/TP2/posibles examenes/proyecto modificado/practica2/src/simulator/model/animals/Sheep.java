package simulator.model.animals;

import simulator.misc.Vector2D;
import simulator.misc.Utils;

import java.util.List;
import java.util.Objects;
import java.util.function.Predicate;

import static simulator.misc.Utils.estabilizar;


public class Sheep extends Animal{
    private Animal _danger_source;
    private SelectionStrategy _danger_strategy;
    final static int MIN_ENERGY = 0;
    final static int MAX_ENERGY = 100;
    final static int MIN_DESIRE = 0;
    final static int MAX_DESIRE = 100;
    final static int MAX_AGE = 8;
    final static double SIGHT_RANGE = 40.0;
    final static double INIT_SPEED = 35;


    public Sheep(SelectionStrategy mate_strategy, SelectionStrategy danger_strategy,
                 Vector2D pos){
        super("SHEEP",  Diet.HERBIVORE , SIGHT_RANGE, INIT_SPEED, mate_strategy, pos);

        this._danger_source=null;
        this._danger_strategy= danger_strategy;
    }

    protected Sheep(Sheep p1, Animal p2){
        super(p1, p2);

        this._danger_source=null;
        this._danger_strategy= p1._danger_strategy;
    }


    private void avanzar(double dt){
        if (get_position().distanceTo(_dest) < 8.0)
            _dest = Vector2D.posAleatoria(_region_mngr.get_width(), _region_mngr.get_height());

        move(get_speed()*dt*Math.exp((get_energy()-100.0)*0.007));

        actualyzeAgeEnergyDesire(dt, -dt*20, dt*40,
                MIN_ENERGY, MAX_ENERGY, MIN_DESIRE, MAX_DESIRE);
    }

    public void update(double dt){
        if(get_state()!= State.DEAD){
            switch (get_state()){
                case NORMAL:
                    updateNormal(dt);
                    break;
                case DANGER:
                    updateDanger(dt);
                    break;
                case MATE:
                    updateMate(dt);
            }

            //3. Si la posición está fuera del mapa, ajustarla y cambiar su estado a NORMAL.
            if(!get_position().esPosValida(_region_mngr)) {
                get_position().ajustaPos(_region_mngr.get_width(), _region_mngr.get_height());
                cambiaEstadoA(State.NORMAL);
            }
            //4. Si _energy es 0.0 o _age es mayor de 8.0, cambia su estado a DEAD.
            if(get_energy()==MIN_ENERGY || get_age()>MAX_AGE)
                cambiaEstadoA(State.DEAD);

            //5. Si su estado no es DEAD, pide comida al gestor de regiones usando get_food(this, dt)
            // y añadela a su _energy (manteniéndolo siempre entre 0.0 y 100.0)
            if(get_state()!=State.DEAD){
                _energy += _region_mngr.get_food(this, dt);
                _energy = estabilizar(_energy, MIN_ENERGY, MAX_ENERGY);
            }
        }
    }
    public SelectionStrategy getDangerStrategy(){
        return _danger_strategy;
    }

    private void updateMate(double dt){
        if (_mate_target != null && (_mate_target.get_state() == State.DEAD || !isInVisualRange(_mate_target)))
                _mate_target = null;

        if (_mate_target == null)
            _mate_target = searchAnimalBySelectionStrategy(_mate_strategy, this.get_diet());

        if (_mate_target == null){
            avanzar(dt);
        } else {
            _dest = _mate_target.get_position();
            move(2.0*get_speed()*dt*Math.exp((get_energy()-100.0)*0.007));
            actualyzeAgeEnergyDesire(dt, -dt*20.0*1.2, 40*dt,
                    MIN_ENERGY, MAX_ENERGY, MIN_DESIRE, MAX_DESIRE);

            if (get_position().distanceTo(_mate_target.get_position()) < 8.0)
                emparejarse();
        }



        if (_danger_source == null)
            _danger_source = searchAnimalBySelectionStrategy(_danger_strategy, Diet.CARNIVORE);

        if(_danger_source!=null) cambiaEstadoA(State.DANGER);
        else if(_desire<65)      cambiaEstadoA(State.NORMAL);
    }


    private void emparejarse(){
        _desire = 0.0;
        _mate_target._desire = 0.0;

        if (!is_pregnant()&& !_mate_target.is_pregnant() && Utils._rand.nextDouble() < 0.9)
                _baby = new Sheep(this, _mate_target);

        _mate_target = null;
    }



    private void updateDanger(double dt){
        if(_danger_source!=null&&_state==State.DEAD)
            _danger_source=null;

        if(_danger_source==null)
            avanzar(dt);
        else{
            _dest = _pos.plus(_pos.minus(_danger_source.get_position()).direction());
            move(2.0*get_speed()*dt*Math.exp((get_energy()-100.0)*0.007));
            actualyzeAgeEnergyDesire(dt, -dt*20.0*1.2, dt*40.0,
                    MIN_ENERGY, MAX_ENERGY, MIN_DESIRE, MAX_DESIRE);
        }

        if(_danger_source==null || !isInVisualRange(_danger_source))
            _danger_source = searchAnimalBySelectionStrategy(_danger_strategy, Diet.CARNIVORE);


        if(_danger_source==null) {
            if (_desire < 65.0) cambiaEstadoA(State.NORMAL);
            else                cambiaEstadoA(State.MATE);
        }
    }
    private void cambiaEstadoA(State st){
        switch(st){
            case MATE:
                _danger_source=null;
                break;
            case DANGER:
                _mate_target=null;
                break;
            case NORMAL:
                _mate_target=null;
                _danger_source = null;
        }
        _state=st;
    }

    private void updateNormal(double dt){
        avanzar(dt);

        if (_danger_source == null)
            _danger_source = searchAnimalBySelectionStrategy(_danger_strategy, Diet.CARNIVORE);

        if (_danger_source==null && _desire > 65.0)     cambiaEstadoA(State.MATE);
        else if(_danger_source!=null)                   cambiaEstadoA(State.DANGER);
    }
}

