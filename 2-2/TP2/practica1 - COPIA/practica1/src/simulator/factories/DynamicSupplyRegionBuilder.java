package simulator.factories;

import org.json.JSONArray;
import org.json.JSONObject;
import simulator.misc.Vector2D;
import simulator.model.SelectFirst;
import simulator.model.animals.SelectionStrategy;
import simulator.model.regions.DynamicSupplyRegion;

public class DynamicSupplyRegionBuilder extends Builder{

    public DynamicSupplyRegionBuilder(){
        super("default","Region");
    }
    @Override
    protected Object create_instance(JSONObject data) {
        JSONObject jo = data.getJSONObject("data");
        Double factor;
        if(jo.has("factor"))
             factor = jo.getDouble("factor");
        else factor= 2.0;

        Double food = jo.getDouble("food");

        return new DynamicSupplyRegion(factor, food);
    }

    @Override
    protected void fill_in_data(JSONObject o) {
        if(!o.has("factor"))
            o.put("factor", 2.0);

        if(!o.has("danger_strategy"))
            o.put("danger_strategy", 1000.0);

    }
}
