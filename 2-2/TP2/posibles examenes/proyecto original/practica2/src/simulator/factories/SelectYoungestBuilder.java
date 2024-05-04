package simulator.factories;

import org.json.JSONObject;
import simulator.model.SelectYoungest;

public class SelectYoungestBuilder extends Builder{

    public SelectYoungestBuilder(){
        super("youngest","Animal");
    }
    @Override
    protected SelectYoungest create_instance(JSONObject data) {
        return new SelectYoungest();
    }
}
