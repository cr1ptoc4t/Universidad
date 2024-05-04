package simulator.factories;

import org.json.JSONObject;

import java.util.*;

public class BuilderBasedFactory<T> implements Factory<T> {
    private Map<String, Builder<T>> _builders;
    private List<JSONObject> _builders_info;

    public BuilderBasedFactory() {

        _builders = new HashMap<>();
        _builders_info = new LinkedList<>();
    }

    public BuilderBasedFactory(List<Builder<T>> builders) {
        this();

        for (Builder b : builders) {
            add_builder(b);
        }
    }

    public void add_builder(Builder<T> b) {
        _builders.put(b.get_type_tag(), b);
        _builders_info.add(b.get_info());
    }

    @Override
    public T create_instance(JSONObject info) {
        if (info == null) {
            throw new IllegalArgumentException("’info’ cannot be null");
        }

        T instance = null;
        String type = info.getString("type");
        Builder<T> builder = _builders.get(type);

        if (builder != null)
            instance = builder.create_instance(info.has("data") ? info.getJSONObject("data") : new JSONObject());

        if (instance == null)
            throw new IllegalArgumentException("Unrecognized ‘info’:" + info.toString());

        return instance;
    }

    @Override
    public List<JSONObject> get_info() {
        return Collections.unmodifiableList(_builders_info);
    }
}
