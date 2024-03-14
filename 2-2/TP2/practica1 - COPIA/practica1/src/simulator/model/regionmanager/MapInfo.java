package simulator.model.regionmanager;

import simulator.model.JSONable;

public interface MapInfo extends JSONable {
    public int get_cols();
    public int get_rows();
    public int get_width();
    public int get_height();
    public int get_region_width();
    public int get_region_height();
}
