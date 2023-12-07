package tp1.logic.gameobjects;

import tp1.logic.Move;
import tp1.logic.Position;
import tp1.logic.Game;

public class EnemyWeapon extends Weapon{

	//TODO fill with your code
	//protected Position pos;
    protected Game game;
    protected Move dir;

    public EnemyWeapon(Game game, Position pos, Move dir){
        // game, pos,life, damage, armor, move.down
        super(game, pos, dir);
        this.dir=dir;
    }


    public void automaticMove(){
        pos.actualiza(dir);
    }
    public boolean isInPos(Position pos){
        return this.pos.equals(pos);
    }


    public boolean performAttack(GameItem other) {
        other.receiveAttack(this);
        return other.isOnPosition(this.pos);
    }
}
