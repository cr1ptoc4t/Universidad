package tp1.logic.gameobjects;

import tp1.logic.GameWorld;
import tp1.logic.Position;
import tp1.logic.Move;

public class EnemyShip extends Ship{
    private Move dir ;
    public EnemyShip(GameWorld gameWorld, Position pos, int life){
        super(gameWorld, pos, life);
        dir= Move.NONE;
    }

}
