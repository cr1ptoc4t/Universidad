package tp1.logic.gameobjects;

import tp1.logic.Position;
import tp1.logic.Game;

public class Ufo extends EnemyShip {
    public final int UFO_X=8;
    public final int UFO_Y=0;

    private Position posIni;
    public Ufo(Game game){
        super(game, new Position(8, 0), 1);
    }

}

