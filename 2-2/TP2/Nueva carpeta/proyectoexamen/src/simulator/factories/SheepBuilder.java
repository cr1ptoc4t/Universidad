package simulator.factories;

import org.json.JSONArray;
import org.json.JSONObject;
import simulator.misc.Vector2D;
import simulator.model.SelectClosest;
import simulator.model.SelectFirst;
import simulator.model.animals.Animal;
import simulator.model.animals.SelectionStrategy;
import simulator.model.animals.Sheep;

import javax.swing.text.Position;
import java.util.List;

public class SheepBuilder extends Builder {
    Factory<SelectionStrategy>  _sel;

    public SheepBuilder(Factory<SelectionStrategy> sel) {
        super("sheep", "Animal");

        if(sel==null)   throw new IllegalArgumentException("Argumento inválido");

        _sel = sel;
    }

    @Override
    public Sheep create_instance(JSONObject data) {
        Vector2D posicion;
        SelectionStrategy mateStrategy, dangerStrategy;

        if (data.has("mate_strategy")) {
            JSONObject mate_st = data.getJSONObject("mate_strategy");
            mateStrategy = _sel.create_instance(mate_st);
        } else mateStrategy = new SelectFirst();

        if (data.has("danger_strategy")) {
            JSONObject danger_st = data.getJSONObject("danger_strategy");
            dangerStrategy = _sel.create_instance(danger_st);
        } else dangerStrategy = new SelectFirst();

        if (data.has("pos")) {
            JSONObject pos = data.getJSONObject("pos");

            JSONArray posX = pos.getJSONArray("x_range");
            JSONArray posY = pos.getJSONArray("y_range");

            posicion = Vector2D.posInRange(posX.getDouble(0), posX.getDouble(1),
                    posY.getDouble(0), posY.getDouble(1));

        } else posicion = null;

        return new Sheep(mateStrategy, dangerStrategy, posicion);
    }

    @Override
    protected void fill_in_data(JSONObject o) {
        if(!o.has("mate_strategy"))
            o.put("mate_strategy", new SelectFirst());

        if(!o.has("danger_strategy"))
            o.put("danger_strategy", new SelectFirst());

        if(!o.has("pos")){
            Vector2D range = new Vector2D(100.0, 200.0);
            JSONObject jRange = new JSONObject();
            jRange.put("x_range", range);
            jRange.put("y_range", range);
            o.put("pos", jRange);
        }
    }
}
