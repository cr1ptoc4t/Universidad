package simulator.view;

import simulator.control.Controller;
import simulator.model.EcoSysObserver;
import simulator.model.animals.AnimalInfo;
import simulator.model.regionmanager.MapInfo;
import simulator.model.regionmanager.RegionInfo;

import javax.swing.table.AbstractTableModel;
import javax.swing.table.TableModel;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class VelocityTableModel extends AbstractTableModel implements EcoSysObserver {
    List<VelocityData> _velocity;
    List<String> _headers;
    public VelocityTableModel(Controller ctrl) {
        _velocity = new ArrayList<>();
        initHeaders();
        ctrl.addObserver(this);

    }

    private void initHeaders() {
        _headers = new ArrayList<>();
        _headers.add("Type");
        _headers.add("Value");
    }


    @Override
    public int getRowCount() {
        return _velocity.size();
    }

    @Override
    public int getColumnCount() {
        return _headers.size();
    }
    public String getColumnName(int col) {
        return _headers.get(col);
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        return _velocity.get(rowIndex).getValueAt(columnIndex);
    }
/*
    Pair<Integer, String> pair = new Pair<>(1, "One");
    Integer key = pair.getKey();
    String value = pair.getValue();


 */
    @Override
    public void onRegister(double time, MapInfo map, List<AnimalInfo> animals) {
        //en el par -> velocidad media - num muestras
        Map<String, Pair> _map = new HashMap<>();
        for (AnimalInfo animal : animals) {
            if(!_map.containsKey(animal.get_genetic_code()))
                _map.put(animal.get_genetic_code(), new Pair(animal.get_speed(),1));
            else {
                Pair pair = _map.get(animal.get_genetic_code());
                pair.setX(pair.getX()+animal.get_speed());
                pair.setY(pair.getY()+1);
                _map.put(animal.get_genetic_code(), pair);
            }
        }

        for(Map.Entry<String, Pair> key: _map.entrySet()){
            _velocity.add(new VelocityData(key.getKey(), key.getValue().getX()/ key.getValue().getY()));
        }

    }

    @Override
    public void onReset(double time, MapInfo map, List<AnimalInfo> animals) {
        _velocity.clear();
        onRegister(time, map, animals);
    }

    @Override
    public void onAnimalAdded(double time, MapInfo map, List<AnimalInfo> animals, AnimalInfo a) {
        _velocity.clear();
        onRegister(time, map, animals);
    }

    @Override
    public void onRegionSet(int row, int col, MapInfo map, RegionInfo r) {

    }

    @Override
    public void onAvanced(double time, MapInfo map, List<AnimalInfo> animals, double dt) {
        _velocity.clear();
        onRegister(time, map, animals);
    }

}
