package simulator.view;

import simulator.model.animals.State;

import java.util.Map;

public class EnergyData {
    private String _genetic_code;
    private Map<Integer, Integer> _energy;
    public EnergyData(String genetic_code, Map<Integer, Integer> energy) {
        _genetic_code = genetic_code;
        _energy = energy;
    }

    public Object getValueAt(int columnIndex) {
        if (columnIndex == 0) {
            return _genetic_code;
        }else{
           return _energy.get((columnIndex-1)*10);
        //   return (_energy.get((columnIndex-1)*5.0) == null  ? 0: _energy.get((columnIndex-1)*5.0) );
        }
    }

}
