package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;

public class Bomb extends EnemyWeapon {

    public Bomb(Game game, Position pos) {
        super(game, pos);
    }

    public void automaticMove(){
        pos.actualiza(Move.DOWN);
    }

    public String toString(){
        return Messages.BOMB_SYMBOL;
    }

    public boolean isOnPosition(Position pos) {
        return this.pos.equals(pos);
    }
}
