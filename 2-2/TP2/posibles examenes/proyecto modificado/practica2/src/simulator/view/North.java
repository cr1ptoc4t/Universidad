package simulator.view;

import simulator.control.Controller;
import simulator.model.EcoSysObserver;
import simulator.model.animals.AnimalInfo;
import simulator.model.regionmanager.MapInfo;
import simulator.model.regionmanager.RegionInfo;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class North implements EcoSysObserver {
    private Controller _ctrl;
    private Map<AnimalInfo, Double> _pos_anterior;
    private Map<Integer, Integer> _iterations;
    private int iteracion = 0;

    public North(Controller ctrl) {
        _ctrl = ctrl;
        _iterations = new HashMap<>();
        _ctrl.addObserver(this);
    }


    public void print() {
        for (Map.Entry e : _iterations.entrySet()) {
            System.out.println("Iteration: " + e.getKey() + " num animals:" + e.getValue());
        }
    }

    @Override
    public void onRegister(double time, MapInfo map, List<AnimalInfo> animals) {
        _pos_anterior = new HashMap<>();
        //_iterations = new HashMap<>();
        for (AnimalInfo a : animals) {
            _pos_anterior.put(a, a.get_position().getY());
        }
    }

    @Override
    public void onReset(double time, MapInfo map, List<AnimalInfo> animals) {

    }

    @Override
    public void onAnimalAdded(double time, MapInfo map, List<AnimalInfo> animals, AnimalInfo a) {

    }

    @Override
    public void onRegionSet(int row, int col, MapInfo map, RegionInfo r) {

    }

    @Override
    public void onAvanced(double time, MapInfo map, List<AnimalInfo> animals, double dt) {

        int n = 0;
        for (AnimalInfo a : animals) {
            if (_pos_anterior.containsKey(a) && _pos_anterior.get(a) < a.get_position().getX()) {
                n++;
            }
        }

        _pos_anterior = new HashMap<>();
        for (AnimalInfo a : animals) {
            _pos_anterior.put(a, a.get_position().getY());
        }

        _iterations.put(iteracion++, n);
    }
}
