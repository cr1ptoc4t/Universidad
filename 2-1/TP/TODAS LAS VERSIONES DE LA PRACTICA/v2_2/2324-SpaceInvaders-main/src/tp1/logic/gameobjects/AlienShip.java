package tp1.logic.gameobjects;

import tp1.logic.GameWorld;
import tp1.logic.Position;
import tp1.logic.Game;
import tp1.logic.Move;

public class AlienShip extends EnemyShip{
    private Move dir;
    public AlienShip(Game game, Position pos, int life, Move dir){
        super(game, pos, life);
        this.dir=dir;
    }




}
