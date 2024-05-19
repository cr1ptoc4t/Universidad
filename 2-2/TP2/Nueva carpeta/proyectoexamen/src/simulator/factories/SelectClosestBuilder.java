package simulator.factories;

import org.json.JSONObject;
import simulator.model.SelectClosest;

public class SelectClosestBuilder extends Builder{
    public SelectClosestBuilder() {
        super("closest", "Animal");
    }

    @Override
    protected SelectClosest create_instance(JSONObject data) {
        return new SelectClosest();
    }
}
