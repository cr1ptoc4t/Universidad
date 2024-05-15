package simulator.factories;

import org.json.JSONObject;
import simulator.model.regions.DynamicSupplyRegion;
import simulator.model.regions.NewRegion;

public class NewRegionBuilder extends Builder{

    public NewRegionBuilder(){
        super("new","other food supply");
    }

    @Override
    protected Object create_instance(JSONObject data) {

        return new NewRegion();
    }

    @Override
    protected void fill_in_data(JSONObject o) {
        if(!o.has("factor"))
            o.put("factor", "food increase factor (optional, default 2.0)");

    }
}
