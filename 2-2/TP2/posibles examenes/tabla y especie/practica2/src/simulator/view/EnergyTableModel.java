package simulator.view;

import simulator.control.Controller;
import simulator.model.EcoSysObserver;
import simulator.model.animals.AnimalInfo;
import simulator.model.animals.State;
import simulator.model.regionmanager.MapInfo;
import simulator.model.regionmanager.RegionInfo;

import javax.swing.table.AbstractTableModel;
import java.util.*;

import static java.lang.Math.floor;

public class EnergyTableModel  extends AbstractTableModel implements EcoSysObserver {
    private List<String> _headers;
    private Controller _ctrl;
    List<EnergyData> _content;

    private final int MAX_ENERGY=100;
    private final int increment=10;
    public EnergyTableModel(Controller _ctrl){
        this._ctrl = _ctrl;
        fillHeaders();
        _content= new ArrayList<>();
        _ctrl.addObserver(this);
    }

    private void fillHeaders() {
        _headers = new ArrayList<>();
        _headers.add("type");
        for(double i=0; i<=MAX_ENERGY; i+=increment){
            _headers.add(i+"");
        }
    }

    @Override
    public int getRowCount() {
        return _content.size();
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
        return _content.get(rowIndex).getValueAt(columnIndex);
    }

    @Override
    public void onRegister(double time, MapInfo map, List<AnimalInfo> animals) {

        Map<String, Map<Double, Integer>> _map = new HashMap<>();


        for(AnimalInfo a:animals){

            if(!_map.containsKey(a.get_genetic_code())){
                _map.put(a.get_genetic_code(), newInternMap());
            }

            Map<Double, Integer> mapa_interno = _map.get(a.get_genetic_code());
            double energy = ((int)a.get_energy()/10) *10;
            //System.out.println(energy);

            int freq = mapa_interno.get(energy);
            mapa_interno.put(energy, freq+1);
            _map.put(a.get_genetic_code(), mapa_interno);
        }

        for (Map.Entry<String, Map<Double, Integer>> key : _map.entrySet()) {
            _content.add(new EnergyData(key.getKey(), key.getValue()));
        }
    }


    private Map<Double, Integer> newInternMap() {
        Map<Double, Integer> mapaInterno = new HashMap<>();
        for(double i=0; i<=MAX_ENERGY; i+=increment)
            mapaInterno.put(i, 0);

        return mapaInterno;
    }

    @Override
    public void onReset(double time, MapInfo map, List<AnimalInfo> animals) {
        _content.clear();
        onRegister(time, map, animals);
    }

    @Override
    public void onAnimalAdded(double time, MapInfo map, List<AnimalInfo> animals, AnimalInfo a) {

    }

    @Override
    public void onRegionSet(int row, int col, MapInfo map, RegionInfo r) {

    }

    @Override
    public void onAvanced(double time, MapInfo map, List<AnimalInfo> animals, double dt) {
        _content.clear();
        onRegister(time, map, animals);
        fireTableDataChanged();
    }


}
