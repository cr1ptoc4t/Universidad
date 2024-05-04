package simulator.model.regionmanager;

import org.json.JSONArray;
import org.json.JSONObject;
import simulator.model.EcoSysObserver;
import simulator.model.animals.Animal;
import simulator.model.animals.AnimalInfo;
import simulator.model.regions.DefaultRegion;
import simulator.model.regions.Region;
import simulator.view.SpecieData;

//import javax.swing.plaf.synth.Region;
import java.util.*;
import java.util.function.Predicate;

public class RegionManager implements AnimalMapView {

    private int _height;
    private int _width;
    private int _rows;
    private int _cols;
    private int _region_height;
    private int _region_width;


    private Region[][] _regions;
    private Map<AnimalInfo, Region> _animal_region;

    //esta solo tiene 1 constructor
    public RegionManager(int cols, int rows, int width, int height) {
        if(cols<0 || rows<0 || width<0 || height<0)
            throw new IllegalArgumentException();

        this._cols = cols;
        this._rows = rows;
        this._width = width;
        this._height = height;

        _region_width = _width / _cols + (width % cols != 0 ? 1 : 0);
        _region_height = _height / _rows + (height % rows != 0 ? 1 : 0);

        _regions = new Region[_rows][_cols];

        initRegions();

        _animal_region = new HashMap<>();
    }

    private void initRegions() {
        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _cols; j++)
                _regions[i][j] = new DefaultRegion();
    }

    @Override
    public List<Animal> get_animals_in_range(Animal e, Predicate<Animal> filter) {
        List<Animal> animalsInRange = new ArrayList<>();

        double x = e.get_position().getX();
        double y = e.get_position().getY();

        double limiteIzquierdo = x - e.get_sight_range();
        double limiteDerecho = x + e.get_sight_range();
        double limiteSuperior = y - e.get_sight_range();
        double limiteInferior = y + e.get_sight_range();

        //  Cuando tenga esos valores compruebo si cada uno de ellos está fuera del rango.
        //  Si esto pasa pongo el que ese salga por la izquierda o por arriba y a ancho-1
        //  (o alto-1) si se sale por la derecha o por abajo.

        //  izq o arriba
        if (limiteIzquierdo < 0)
            limiteIzquierdo = 0;
        if (limiteSuperior < 0)
            limiteSuperior = 0;

        //  der o abajo
        if (limiteDerecho > _width)
            limiteDerecho = _width - 1;
        if (limiteInferior > _height)
            limiteInferior = _height - 1;

        int filaInicio = (int) (limiteSuperior / get_region_height());
        int filaFin = (int) (limiteInferior / get_region_height());
        int columnaInicio = (int) (limiteIzquierdo / get_region_width());
        int columnaFin = (int) (limiteDerecho / get_region_width());

        for (int fila = filaInicio; fila <= filaFin; fila++)
            for (int columna = columnaInicio; columna <= columnaFin; columna++) {
                Region region = _regions[fila][columna];
                for (Animal animal : region.getAnimals())
                    if (e.isInVisualRange(animal) && filter.test(animal) && !e.equals(animal))
                        animalsInRange.add(animal);
            }

        return animalsInRange;
    }

    @Override
    public int get_cols() {
        return this._cols;
    }

    @Override
    public int get_rows() {
        return this._rows;
    }

    @Override
    public int get_width() {
        return this._width;
    }

    @Override
    public int get_height() {
        return this._height;
    }

    @Override
    public int get_region_width() {
        return _region_width;
    }

    @Override
    public int get_region_height() {
        return _region_height;
    }

    public void set_region(int row, int col, Region r) {
        List<AnimalInfo> l = this._regions[row][col].getAnimalsInfo();
        int i = 0;
        //!!
        while (i<l.size()) {
            r.add_animal((Animal) l.get(i));
            this._animal_region.put(l.get(i), r);
            i++;
        }
        this._regions[row][col] = r;

       //notifyOnRegionSet();

    }


    public void register_animal(Animal a) {
        a.init(this);
        int col = get_region_col(a);
        int row = get_region_row(a);

        this._regions[row][col].add_animal(a);
        this._animal_region.put(a, this._regions[row][col]);

    }

    public void unregister_animal(Animal a) {

        this._animal_region.get(a).remove_animal(a);
        this._animal_region.remove(a);
    }

    public void update_animal_region(Animal a) {
        //esto se tiene que hacer con iteradores
        int col = get_region_col(a);
        int row = get_region_row(a);

        if (! this._regions[row][col].equals(this._animal_region.get(a))) {
            _animal_region.get(a).remove_animal(a);
            this._regions[row][col].add_animal(a);
            _animal_region.put(a, _regions[row][col]);

        }
    }

    public double get_food(Animal a, double dt) {
        int col = get_region_col(a);
        int row = get_region_row(a);

        return _regions[row][col].get_food(a, dt);
    }

    public void update_all_regions(double dt) {
        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _cols; j++)
                _regions[i][j].update(dt);
    }

    public JSONObject as_JSON() {
        JSONArray arrayRegiones = new JSONArray();

        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                JSONObject region = new JSONObject();

                region.put("row", i);
                region.put("col", j);
                region.put("data", _regions[i][j].as_JSON());
                arrayRegiones.put(region);
            }
        }
        JSONObject jo= new JSONObject();
        jo.put("Regiones",arrayRegiones);
        return jo;
    }

    private int get_region_col(Animal a) {
        double x = a.get_position().getX();
        return (int)(x / _region_width);
    }

    private int get_region_row(Animal a) {
        double y = a.get_position().getY();
        return (int)(y / _region_height);
    }

    @Override
    public Iterator<RegionData> iterator() {
        Iterator <RegionData> iterador = new Iterator<RegionData>() {
            int i=0;    //rows
            int j=-1;   //cols

            @Override
            public boolean hasNext() {
                return !(_rows-1==i && _cols-1==j);
            }

            @Override
            public RegionData next() {
                if(j==_cols-1) {
                    j = 0;
                    i++;
                } else
                    j++;

                return new RegionData(i, j, _regions[i][j]);
            }
        };

        return iterador;
    }

    public Iterator<AnimalInfo> animalInfoIterator() {
        Iterator <AnimalInfo> iterador = new Iterator<AnimalInfo>() {
            int i=0;

            @Override
            public boolean hasNext() {
                return i<0;
            }

            @Override
            public AnimalInfo next() {

                return null;
            }
        };


        return iterador;
    }




}
