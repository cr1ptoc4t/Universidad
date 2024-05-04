package simulator.factories;

import org.json.JSONObject;

import java.util.List;

public interface Factory<T> {
    public T create_instance(JSONObject info);
    public List<JSONObject> get_info();
}