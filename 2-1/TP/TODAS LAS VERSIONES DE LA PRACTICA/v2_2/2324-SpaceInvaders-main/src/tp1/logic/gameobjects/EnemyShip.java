package tp1.logic.gameobjects;

import tp1.logic.GameWorld;
import tp1.logic.Position;
import tp1.logic.Move;
import tp1.logic.Game;

public class EnemyShip extends Ship{
    private Move dir ;
    public EnemyShip(Game game, Position pos, int life){
        super(game, pos, life);
        dir= Move.NONE;
    }

}
