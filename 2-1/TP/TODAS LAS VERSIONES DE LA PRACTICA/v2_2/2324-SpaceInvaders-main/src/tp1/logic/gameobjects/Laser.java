package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.Move;
import tp1.logic.Position;

public class Laser extends UCMWeapon{


    public Laser(Game game, Position pos) {
        super(game, pos);
    }

    public void onDelete() {
        //le dice a la nave que puede crear otro laseer
        game.puedeCrearLaser();
    }

    public void automaticMove() {
        pos.actualiza(Move.UP);
        if(!pos.esPosicionValida()){
            onDelete();
        }
    }

    @Override
    public boolean performAttack(GameItem other) {
        if(other.isOnPosition(this.pos)){
            onDelete();
            other.receiveAttack(this);
            return true;
        }

        return false;
    }
}
