package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.GameWorld;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;

public class SuperLaser extends Laser{
    public SuperLaser(GameWorld game, Position pos) {
        super(game, pos);
    }

    public void onDelete() {
        //le dice a la nave que puede crear otro laseer
        game.laserAFalse();
        life=0;
    }

    public void automaticMove() {
        pos.actualiza(Move.UP);
        if(!pos.esPosicionValida()||game.puedeCrearSuperLaser()){
            onDelete();
        }
    }

    @Override
    public String toString() {
        return Messages.SUPERLASER_SYMBOL;
    }

    @Override
    protected int getDamage() {
        return 2;
    }

}
