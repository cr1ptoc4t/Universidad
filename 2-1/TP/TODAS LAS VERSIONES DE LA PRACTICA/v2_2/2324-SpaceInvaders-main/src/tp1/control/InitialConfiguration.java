package tp1.control;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import tp1.logic.*;
import tp1.logic.gameobjects.AlienShip;
import tp1.logic.gameobjects.ShipFactory;

public enum InitialConfiguration {

    NONE,
    CONF_1(Arrays.asList(
            "R 2 3", "R 3 3", "R 4 3", "R 5 3"
    )),
    CONF_2(Arrays.asList(
            "R 2 3", "R 3 3", "D 4 3", "R 5 3"
    )),
    CONF_3(Arrays.asList(
            "R 2 2", "R 3 2", "R 4 2", "R 5 2",
            "R 2 3", "E 3 3", "R 4 3", "R 5 3",
            "R 2 4", "R 3 4", "D 4 4", "R 5 4"

    ));

    private List<String> descriptions;

    private InitialConfiguration() {}

    private InitialConfiguration(List<String> descriptions) {
        this.descriptions = descriptions;
    }

    public List<String> getShipDescription(){
        return Collections.unmodifiableList(descriptions);
    }

    public static InitialConfiguration valueOfIgnoreCase(String param) {
        for (InitialConfiguration conf : InitialConfiguration.values())
            if (conf.name().equalsIgnoreCase(param)) return conf;
        return null;
    }

    public static String all(String separator) {
        StringBuilder sb = new StringBuilder();
        for (InitialConfiguration conf : InitialConfiguration.values())
            sb.append(conf.name() + separator);
        String allLevels = sb.toString();
        return allLevels.substring(0, allLevels.length()-separator.length());
    }



    public static int getNumAliens(InitialConfiguration conf){
        return 0;
        //return this.values().length;
        /*

        int num=0;

        switch (conf) {
            case CONF_1:
                num=CONF_1.values().length;
                break;
            case CONF_2:
                num=4;
                break;
            case CONF_3:
                num=12;
        }
        return num;

         */
    }


    public AlienShip spawn(Game game, String type, int x, int y, AlienManager am){
        return ShipFactory.spawnAlienShip(type,game,new Position(x, y),am);
    }

    public void initContainer(GameObjectContainer container, Game game, AlienManager am){
        for(int i=0; i<getShipDescription().size();i++){
            String descripcion=getShipDescription().get(i);
            String type= String.valueOf(getShipDescription().get(i).charAt(0));
            int x=  descripcion.charAt(2) -'0';
            int y=   descripcion.charAt(4) -'0';
            container.add(spawn(game, type, x, y, am));
        }
    }


}