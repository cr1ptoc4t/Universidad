package simulator.factories;

import org.json.JSONObject;

public abstract class Builder<T> {
    private String _type_tag;
    private String _desc;
    public Builder(String type_tag, String desc) {
        if (type_tag == null || desc == null || type_tag.isBlank() || desc.isBlank())
            throw new IllegalArgumentException("Invalid type/desc");
        _type_tag = type_tag;
        _desc = desc;
    }
    public String get_type_tag() {
        return _type_tag;
    }
    public JSONObject get_info() {
        JSONObject info = new JSONObject();
        info.put("type", _type_tag);
        info.put("desc", _desc);
        JSONObject data = new JSONObject();
        fill_in_data(data);
        info.put("data", data);
        return info;
    }
    protected void fill_in_data(JSONObject o) {
    }
    @Override
    public String toString() {
        return _desc;
    }
    protected abstract T create_instance(JSONObject data);

}

