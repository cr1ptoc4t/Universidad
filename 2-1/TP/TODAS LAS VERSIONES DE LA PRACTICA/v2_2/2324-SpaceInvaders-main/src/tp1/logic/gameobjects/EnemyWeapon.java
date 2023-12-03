package tp1.logic.gameobjects;

import tp1.logic.Position;
import tp1.logic.Game;

public class EnemyWeapon {

	//TODO fill with your code
	protected Position pos;
    protected Game game;
    public EnemyWeapon(Game game, Position pos){
        this.game=game;
        this.pos=pos;
    }


    public boolean isInPos(Position pos){
        return this.pos.equals(pos);
    }
}
