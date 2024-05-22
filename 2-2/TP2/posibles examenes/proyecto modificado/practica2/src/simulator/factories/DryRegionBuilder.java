package simulator.factories;

import org.json.JSONObject;
import simulator.model.regions.DefaultRegion;
import simulator.model.regions.DryRegion;

public class DryRegionBuilder extends Builder {

    public DryRegionBuilder() {
        super("dry", "dry reg");
    }

    @Override
    protected DryRegion create_instance(JSONObject data) {
        //String fase = data.getString("fase");
        return new DryRegion(0.1,0.2,3,4);
    }

    protected void fill_in_data(JSONObject o) {

    }

}