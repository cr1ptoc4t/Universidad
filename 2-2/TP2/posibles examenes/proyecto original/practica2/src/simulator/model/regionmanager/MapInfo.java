package simulator.model.regionmanager;

import simulator.model.JSONable;
import simulator.model.animals.AnimalInfo;
import simulator.view.SpecieData;

import java.util.Iterator;

public interface MapInfo extends JSONable, Iterable<MapInfo.RegionData>  {
    Iterator<AnimalInfo> animalInfoIterator();          //  Añadido

    public record RegionData(int row, int col, RegionInfo r) {

    }

    public int get_cols();
    public int get_rows();
    public int get_width();
    public int get_height();
    public int get_region_width();
    public int get_region_height();

}
