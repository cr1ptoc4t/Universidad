package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.GameWorld;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;

public class Bomb extends EnemyWeapon {

    private DestroyerAlien alien;

    public Bomb(GameWorld game, Position pos, DestroyerAlien alien) {
        super(game, pos, Move.DOWN);
        this.alien = alien;
    }


    public String toString(){
        return Messages.BOMB_SYMBOL;
    }

    public boolean isOnPosition(Position pos) {
        return this.pos.equals(pos);
    }

    public void onDelete(){
        game.enableBomb(alien);
        game.died(this);
    }

    public void automaticMove(){
        pos.actualiza(Move.DOWN);
    }

    public void computerAction(){
        if(!posicionValida()){
            onDelete();
        }
    }

}
