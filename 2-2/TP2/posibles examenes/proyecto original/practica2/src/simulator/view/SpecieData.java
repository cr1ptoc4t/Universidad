package simulator.view;

import simulator.model.animals.AnimalInfo;
import simulator.model.animals.State;
import simulator.model.regionmanager.RegionInfo;
import simulator.model.regions.Region;

import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class SpecieData {
    private String _genetic_code;

    private  Map<State, Integer> _animals_state;

    public SpecieData(String geneticCode,  Map<State, Integer> _animals_state) {
        this._genetic_code = geneticCode;
        this._animals_state = _animals_state;
    }

    public Object getValueAt(int col) {
        Object ret;
        if (col == 0)
            ret = _genetic_code;
        else
            ret = _animals_state.get(State.values()[col - 1]);

        return ret;
    }

    public Map<State, Integer> getMap(){
        return _animals_state;
    }

    public void actualiza_frecuencia(State estado){
        Integer frequency = _animals_state.get(estado);
        _animals_state.put(estado, frequency + 1);
    }
}
