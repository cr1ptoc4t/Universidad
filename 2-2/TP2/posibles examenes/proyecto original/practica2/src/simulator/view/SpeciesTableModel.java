package simulator.view;

import simulator.control.Controller;
import simulator.model.EcoSysObserver;
import simulator.model.animals.AnimalInfo;
import simulator.model.animals.State;
import simulator.model.regionmanager.MapInfo;
import simulator.model.regionmanager.RegionInfo;

import javax.swing.table.AbstractTableModel;
import java.util.*;


class SpeciesTableModel extends AbstractTableModel implements EcoSysObserver {
    private List<String> _headers;
    private List<SpecieData> _species;

    private Controller _ctrl;

    SpeciesTableModel(Controller ctrl) {
        _ctrl = ctrl;
        _species = new ArrayList<>();
        initHeaders();
        _ctrl.addObserver(this);
    }


    @Override
    public int getRowCount() {
        return _species.size();
    }

    @Override
    public int getColumnCount() {
        return _headers.size();
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {

        return (_species.get(rowIndex)).getValueAt(columnIndex);
    }

    public String getColumnName(int indx) {
        return _headers.get(indx);
    }

    @Override
    public void onRegister(double time, MapInfo map, List<AnimalInfo> animals) {
        register_aux(animals);
    }

    private Map<State, Integer> newInternMap() {
        Map<State, Integer> mapaInterno = new HashMap<>();
        for (State s : State.values()) {
            mapaInterno.put(s, 0);
        }
        return mapaInterno;
    }

    @Override
    public void onReset(double time, MapInfo map, List<AnimalInfo> animals) {
        _species.clear();
        register_aux(animals);
    }

    @Override
    public void onAnimalAdded(double time, MapInfo map, List<AnimalInfo> animals, AnimalInfo a) {

        //buscamos indice tabla por codigo genetico
        String genetic_code = a.get_genetic_code();
        int i = 0;
        while (i < _species.size() && _species.get(i).getValueAt(0) != genetic_code)
            i++;

        //buscamos el mapa interno del codigo genetico
        Map<State, Integer> mapaInterno;
        if (i == _species.size()) {    // si este codigo genetico aun no ha entrado en la tabla:
            mapaInterno = newInternMap();
            _species.add(new SpecieData(genetic_code, mapaInterno));
        }

        //actualizamos frecuencia mapa interno
        _species.get(i).actualiza_frecuencia(a.get_state());
        fireTableDataChanged();
    }


    @Override
    public void onRegionSet(int row, int col, MapInfo map, RegionInfo r) {

    }

    @Override
    public void onAvanced(double time, MapInfo map, List<AnimalInfo> animals, double dt) {
        _species = new ArrayList<>();
        register_aux(animals);
        fireTableDataChanged();
    }

    private void initHeaders() {
        _headers = new ArrayList<>();
        _headers.add("Species");

        for (State a : State.values()) {
            _headers.add(a.toString());
        }
    }

    private void register_aux(List<AnimalInfo> animals) {
        Map<String, Map<State, Integer>> _species_map = new HashMap<>();    // mapa de animales en funcion de codigo genetico

        for (AnimalInfo animal : animals) {

            Map<State, Integer> mapaInterno = _species_map.get(animal.get_genetic_code());

            // si el codigo genético aun no existe en la tabla/el mapa
            if (mapaInterno == null) {
                //inicializamos el mapa interno
                mapaInterno = newInternMap();

                //metemos mapa interno inicializado en el mapa inicial
                _species_map.put(animal.get_genetic_code(), mapaInterno);
            }

            //sumamos 1 a la "frecuencia" del submapa elegido e inscribimos en el mapa "grande"
            actualiza_frecuencia(mapaInterno, animal.get_state());
            _species_map.put(animal.get_genetic_code(), mapaInterno);
        }

        //recorremos el mapa y vamos inscribiendo en la tabla por codigo genetico y mapa correspondiente
        for (Map.Entry<String, Map<State, Integer>> key : _species_map.entrySet()) {
            _species.add(new SpecieData(key.getKey(), key.getValue()));
        }

        fireTableStructureChanged();
    }

    private void actualiza_frecuencia(Map<State, Integer> mapaInterno, State estado) {
        Integer frequency = mapaInterno.get(estado);
        mapaInterno.put(estado, frequency + 1);
    }

}
