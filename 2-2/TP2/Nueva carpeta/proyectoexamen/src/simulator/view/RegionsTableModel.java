package simulator.view;

import simulator.control.Controller;
import simulator.model.EcoSysObserver;
import simulator.model.animals.AnimalInfo;
import simulator.model.animals.Diet;
import simulator.model.regionmanager.MapInfo;
import simulator.model.regionmanager.MapInfo.RegionData;
import simulator.model.regionmanager.RegionInfo;

import javax.swing.table.AbstractTableModel;
import java.util.*;

class RegionsTableModel extends AbstractTableModel implements EcoSysObserver {
    private Controller _ctrl;
    private List<TableRegion> _regions;
    List<String> _headers;

    RegionsTableModel(Controller ctrl) {
        _regions = new LinkedList<>();
        initHeaders();
        this._ctrl = ctrl;
        _ctrl.addObserver(this);
    }


    public String getColumnName(int indx) {
        return _headers.get(indx);
    }


    private void initHeaders() {
        _headers = new ArrayList<>();
        _headers.add("Row");
        _headers.add("Col");
        _headers.add("Desc");
        for (Diet d : Diet.values())
            _headers.add(d.toString());
    }

    @Override
    public int getRowCount() {
        return _regions.size();
    }

    @Override
    public int getColumnCount() {
        return _headers.size();
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        return (_regions.get(rowIndex)).getValueAt(columnIndex);
    }


    @Override
    public void onRegister(double time, MapInfo map, List<AnimalInfo> animals) {
        register_aux(map);
    }

    @Override
    public void onReset(double time, MapInfo map, List<AnimalInfo> animals) {
        _regions.clear();
        register_aux(map);
    }

    @Override
    public void onAnimalAdded(double time, MapInfo map, List<AnimalInfo> animals, AnimalInfo a) {
        int animal_col = (int) a.get_position().getX() / map.get_region_width();
        int animal_row = (int) a.get_position().getY() / map.get_region_height();

        int indice = animal_row * map.get_cols() + animal_col;
        _regions.get(indice).addAnimal(a);

        fireTableDataChanged();
    }

    @Override
    public void onRegionSet(int row, int col, MapInfo map, RegionInfo r) {
        int indice = row * map.get_cols() + col;
        _regions.get(indice).update(r);
        fireTableDataChanged();
    }

    @Override
    public void onAvanced(double time, MapInfo map, List<AnimalInfo> animals, double dt) {
        _regions = new ArrayList<>();
        register_aux(map);
        fireTableDataChanged();
    }

    private void register_aux(MapInfo map) {

        Iterator<RegionData> regionData = map.iterator();

        while (regionData.hasNext()) {
            RegionData rd = regionData.next();
            _regions.add(new TableRegion(rd.row(), rd.col(), rd.r()));
        }

        fireTableDataChanged();
    }
}