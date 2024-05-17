package simulator.view;

import simulator.control.Controller;
import simulator.model.EcoSysObserver;
import simulator.model.animals.AnimalInfo;
import simulator.model.animals.Diet;
import simulator.model.regionmanager.MapInfo;
import simulator.model.regionmanager.RegionInfo;

import java.lang.reflect.Array;
import java.util.*;

public class Counter implements EcoSysObserver {
    private Controller _ctrl;
    private Map<Integer, Integer> _map;
    private int num_cols;

    public Counter(Controller ctrl) {
        _ctrl = ctrl;
        _ctrl.addObserver(this);
        _map = new HashMap<>();
    }


    public void showMessage() {
        for (Map.Entry<Integer, Integer> entry : _map.entrySet()) {
            int num_region = entry.getKey();
            int x = num_region % num_cols;
            int y = (int)((num_region-1) / num_cols);
            Integer value = entry.getValue();
            System.out.println("Region: " + x + " " + y + ", Value: " + value);
        }
    }


    @Override
    public void onRegister(double time, MapInfo map, List<AnimalInfo> animals) {
        num_cols = map.get_cols();
    }

    @Override
    public void onReset(double time, MapInfo map, List<AnimalInfo> animals) {
        num_cols = map.get_cols();
        _map = new HashMap<>();
    }

    @Override
    public void onAnimalAdded(double time, MapInfo map, List<AnimalInfo> animals, AnimalInfo a) {

    }

    @Override
    public void onRegionSet(int row, int col, MapInfo map, RegionInfo r) {

    }

    @Override
    public void onAvanced(double time, MapInfo map, List<AnimalInfo> animals, double dt) {
        Map<Integer, Integer> mapa1 = new HashMap<>();

        for (AnimalInfo a : animals) {
            if (a.get_diet() == Diet.CARNIVORE) {
                int fila = (int) (a.get_position().getX() / map.get_region_width());
                int columna = (int) (a.get_position().getY() / map.get_region_height());

                int num_region = fila * num_cols + (columna + 1);

                if (!mapa1.containsKey(num_region))
                    mapa1.put(num_region, 1);
                else
                    mapa1.put(num_region, mapa1.get(num_region) + 1);
            }
        }

        for (Map.Entry<Integer, Integer> entry : mapa1.entrySet()) {
            int num_region = entry.getKey();
            int numero_carnivoros = entry.getValue();

            if (numero_carnivoros >= 3) {
                if (!_map.containsKey(num_region))
                    _map.put(num_region, numero_carnivoros);
                else
                    _map.put(num_region, mapa1.get(num_region) + 1);
            }
        }
    }
}
