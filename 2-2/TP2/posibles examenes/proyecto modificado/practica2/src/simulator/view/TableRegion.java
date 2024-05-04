package simulator.view;

import simulator.model.animals.AnimalInfo;
import simulator.model.animals.Diet;
import simulator.model.regionmanager.RegionInfo;
import simulator.model.regions.Region;

import java.util.HashMap;
import java.util.Map;

public class TableRegion {
    private int _row;
    private int _col;
    private RegionInfo _desc;
    private Map <Diet, Integer> _diet_values;

    public TableRegion(int row, int col, RegionInfo desc) {
        this._row = row;
        this._col = col;
        this._desc = desc;

        initMap();
    }

    public Object getValueAt(int columnIndex) {
        Object o;
        switch (columnIndex) {
            case 0:
                o = _row;
                break;
            case 1:
                o = _col;
                break;
            case 2:
                o = _desc;
                break;
            default:
                o = _diet_values.get(Diet.values()[columnIndex-3]);
        }
        return o;
    }

    private void initMap(){
        this._diet_values = new HashMap<>();
        for(Diet d: Diet.values())
            _diet_values.put(d,0);

        for(AnimalInfo a: _desc.getAnimalsInfo()){
            Diet d = a.get_diet();
            int freq = _diet_values.get(d);
            _diet_values.put(d, freq+1);
        }
    }

    public int get_col() {
        return _col;
    }
    public int get_row() {
        return _row;
    }

    public void addAnimal(AnimalInfo a) {
        Integer freq = _diet_values.get(a.get_diet());
        _diet_values.put(a.get_diet(), freq+1);
    }

    public void update(RegionInfo r){
        _desc = r;
    }
}
