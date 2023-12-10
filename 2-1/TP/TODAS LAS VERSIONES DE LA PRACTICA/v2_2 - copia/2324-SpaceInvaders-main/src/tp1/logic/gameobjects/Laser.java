package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.GameWorld;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;

public class Laser extends UCMWeapon{


    public Laser(GameWorld game, Position pos) {
        super(game, pos);
    }

    public void onDelete() {
        //le dice a la nave que puede crear otro laseer
        game.laserAFalse();
        life=0;
    }

    public void automaticMove() {
        pos.actualiza(Move.UP);
        if(!pos.esPosicionValida()||game.puedeCrearLaser()){
            onDelete();
        }
    }

    @Override
    public boolean performAttack(GameItem other) {
        onDelete();
        return other.receiveAttack(this);
    }


    public String toString() {
        return Messages.LASER_SYMBOL;
    }

    @Override
    protected int getDamage() {
        return 1;
    }

    @Override
    protected int getArmour() {
        return 1;
    }
}
