package simulator.view;

import simulator.model.animals.State;

import java.util.Map;

public class EnergyData {
    private String _genetic_code;
    private Map<Double, Integer> _energy;
    public EnergyData(String genetic_code, Map<Double, Integer> energy) {
        _genetic_code = genetic_code;
        _energy = energy;
    }

    public Object getValueAt(int columnIndex) {
        if (columnIndex == 0) {
            return _genetic_code;
        }else{
           return _energy.get((columnIndex-1)*10.0);
        //   return (_energy.get((columnIndex-1)*5.0) == null  ? 0: _energy.get((columnIndex-1)*5.0) );
        }
    }

    public void actualiza_frecuencia(Double d){
        Integer frequency = _energy.get(d);
        _energy.put(d, frequency + 1);
    }
}
