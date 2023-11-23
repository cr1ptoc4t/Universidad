package tp1.logic.gameobjects;

import tp1.logic.GameWorld;
import tp1.logic.Position;

public class AlienShip extends EnemyShip{

    public AlienShip(GameWorld gameWorld, Position pos, int life, Move dir){
        super(gameWorld,pos, life, dir);
    }


}
