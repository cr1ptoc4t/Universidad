package simulator.factories;

import org.json.JSONArray;
import org.json.JSONObject;
import simulator.misc.Vector2D;
import simulator.model.SelectFirst;
import simulator.model.animals.SelectionStrategy;
import simulator.model.regions.DynamicSupplyRegion;

public class DynamicSupplyRegionBuilder extends Builder{

    public DynamicSupplyRegionBuilder(){
        super("dynamic","Dynamic food supply");
    }

    @Override
    protected Object create_instance(JSONObject data) {
        double factor;
        if(data.has("factor"))
             factor = data.getDouble("factor");
        else
            factor= 2.0;

        double food;
        if(data.has("food"))
            food = data.getDouble("food");
        else
            food= 100;

        return new DynamicSupplyRegion(factor, food);
    }

    @Override
    protected void fill_in_data(JSONObject o) {
        if(!o.has("factor"))
            o.put("factor", "food increase factor (optional, default 2.0)");

        if(!o.has("food"))
            o.put("food", "initial amount of food (optional, default 100.0)");
    }
}
