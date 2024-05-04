package simulator.model;

import org.json.JSONObject;

public interface JSONable {
    default public JSONObject as_JSON(){
        return new JSONObject();
    }
}
