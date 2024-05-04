package simulator.factories;

import org.json.JSONObject;
import simulator.misc.Vector2D;
import simulator.model.SelectFirst;
import simulator.model.regions.DefaultRegion;

public class DefaultRegionBuilder extends Builder {

    public DefaultRegionBuilder(){
        super("default","Infinite food supply");
    }

    @Override
    protected DefaultRegion create_instance(JSONObject data) {
        return new DefaultRegion();
    }

    protected void fill_in_data(JSONObject o) {

    }

}
