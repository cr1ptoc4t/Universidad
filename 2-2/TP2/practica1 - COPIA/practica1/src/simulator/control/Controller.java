package simulator.control;

import org.json.JSONArray;
import org.json.JSONObject;
import simulator.Simulator;
import simulator.model.animals.Animal;
import simulator.model.animals.AnimalInfo;
import simulator.model.regions.Region;
import simulator.view.SimpleObjectViewer;
import simulator.model.regionmanager.MapInfo;

import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;


public class Controller {
    Simulator _sim;

    public Controller(Simulator sim) {
        if(sim==null)
            throw new IllegalArgumentException("Argumento inválido");
        this._sim = sim;
    }

    public void load_data(JSONObject data) {
        if (data.has("regions")) {
            JSONArray regions = data.getJSONArray("regions");
            for (int i=0;i<regions.length(); i++) {
                JSONObject region = regions.getJSONObject(i);

                JSONObject spec = region.getJSONObject("spec");
                JSONArray rowRange = region.getJSONArray("row");
                JSONArray colRange = region.getJSONArray("col");

                int rowFrom = rowRange.getInt(0);
                int rowTo = rowRange.getInt(1);

                int colFrom = colRange.getInt(0);
                int colTo = colRange.getInt(1);

                for (int row = rowFrom; row <= rowTo; row++)
                    for (int col = colFrom; col <= colTo; col++)
                        _sim.set_region(row, col, spec);

            }
        }

        JSONArray animalsArray = data.getJSONArray("animals");
        for (int i = 0; i < animalsArray.length(); i++) {
            JSONObject animalObj = animalsArray.getJSONObject(i);
            int N = animalObj.getInt("amount");
            JSONObject spec = animalObj.getJSONObject("spec");

            for (int j = 0; j < N; j++)
                _sim.add_animal(spec);

        }

    }

    public void run(double t, double dt, boolean sv, OutputStream out) {
        SimpleObjectViewer view = null;
        if (sv) {
            MapInfo m = _sim.get_map_info();
            view = new SimpleObjectViewer("[ECOSYSTEM]",
                    m.get_width(), m.get_height(),
                    m.get_cols(), m.get_rows());
            view.update(to_animals_info(_sim.get_animals()), _sim.get_time(), dt);
        }

        JSONObject initial_state =_sim.as_JSON();
        while (_sim.get_time() <= t) {
            _sim.advance(dt);
            if (sv) view.update(to_animals_info(_sim.get_animals()), _sim.get_time(), dt);
        }

        JSONObject states = new JSONObject();
        states.put("in", initial_state);
        states.put("out", _sim.as_JSON());
        PrintStream p = new PrintStream(out);
        p.println(states);

        if (sv) view.close();

    }


    private List<SimpleObjectViewer.ObjInfo> to_animals_info(List<? extends AnimalInfo> animals) {
        List<SimpleObjectViewer.ObjInfo> ol = new ArrayList<>(animals.size());
        for (AnimalInfo a : animals) {
            ol.add(new SimpleObjectViewer.ObjInfo(a.get_genetic_code(),
                    (int) a.get_position().getX(),
                    (int) a.get_position().getY(), (int) Math.round(a.get_age()) + 2));
        }
        return ol;
    }

}
