package simulator.model.regionmanager;

import simulator.model.JSONable;
import simulator.model.animals.AnimalInfo;

import java.util.List;

public interface RegionInfo extends JSONable {
    public List<AnimalInfo> getAnimalsInfo();
}
