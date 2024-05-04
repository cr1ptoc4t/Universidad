package simulator.factories;

import org.json.JSONObject;
import simulator.model.SelectFirst;

public class SelectFirstBuilder extends Builder{
    public SelectFirstBuilder(){
        super("first", "Animal");
    }
    @Override
    protected Object create_instance(JSONObject data) {
        return new SelectFirst();
    }
}
