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
    private Map<int[], Integer> _map;

    public Counter(Controller ctrl) {
        _ctrl = ctrl;
        _ctrl.addObserver(this);
        _map = new HashMap<>();
    }


    public void showMessage() {
        for (Map.Entry<int[], Integer> entry : _map.entrySet()) {
            int[] key = entry.getKey();
            Integer value = entry.getValue();
            System.out.println("Region: " + key[0] + " " + key[1] + ", Value: " + value);
        }
    }


    @Override
    public void onRegister(double time, MapInfo map, List<AnimalInfo> animals) {

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
        Map<int[], Integer> mapa1 = new HashMap<>();

        for (AnimalInfo a : animals) {
            if (a.get_diet() == Diet.CARNIVORE) {
                int[] ar = {(int) (a.get_position().getX() / map.get_region_width()),
                        (int) (a.get_position().getY() / map.get_region_height())};

                boolean found = false;
                for (int[] key : mapa1.keySet()) {
                    if (Arrays.equals(key, ar)) {
                        mapa1.put(key, mapa1.get(key) + 1);
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    mapa1.put(ar, 1);
                }
            }
        }

        for (Map.Entry<int[], Integer> entry : mapa1.entrySet()) {
            int[] key = entry.getKey();
            int value = entry.getValue();

            if (value >= 3) {
                boolean found = false;
                for (int[] existingKey : _map.keySet()) {
                    if (Arrays.equals(existingKey, key)) {
                        _map.put(existingKey, _map.get(existingKey) + 1);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    _map.put(key, 1);
                }
            }
        }
    }
}
