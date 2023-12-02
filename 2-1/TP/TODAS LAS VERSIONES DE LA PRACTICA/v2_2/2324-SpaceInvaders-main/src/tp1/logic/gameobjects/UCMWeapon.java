package tp1.logic.gameobjects;

import tp1.logic.Move;
import tp1.logic.Position;
import tp1.logic.Game;
import tp1.view.Messages;

public class UCMWeapon extends Weapon {

	//TODO fill with your code

    public UCMWeapon(Game game, Position pos){
        // Game game, Position pos, Move dir, int dano
        super(game, pos, Move.NONE, 1);
    }
    @Override
    protected String getSymbol() {
        return Messages.LASER_SYMBOL;
    }
    public String toString() {
        return Messages.LASER_SYMBOL;
    }

    @Override
    protected int getDamage() {
        return 0;
    }

    @Override
    protected int getArmour() {
        return 0;
    }

    @Override
    public void onDelete() {

    }

    @Override
    public void automaticMove() {
        pos.actualiza(Move.UP);
    }
}
