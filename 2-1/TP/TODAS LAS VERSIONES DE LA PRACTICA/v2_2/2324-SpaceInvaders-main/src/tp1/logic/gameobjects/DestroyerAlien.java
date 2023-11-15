package tp1.logic.gameobjects;

import tp1.logic.AlienManager;
import tp1.logic.Game;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;

public class DestroyerAlien extends GameObject {

    Move dir = Move.LEFT;

    public DestroyerAlien(Game game, Position pos, AlienManager alienManager) {
        // TODO fill with your code
        super(game, pos, 0);
    }

    @Override
    public boolean isOnPosition(Position pos) {
        // TODO fill with your code
        return this.pos.equals(pos);
    }

    @Override
    protected String getSymbol() {
        // TODO fill with your code
        return Messages.DESTROYER_ALIEN_SYMBOL +"["+life+"]";
    }

    @Override
    protected int getDamage() {
        // TODO fill with your code
        return 0;
    }

    @Override
    protected int getArmour() {
        // TODO Auto-generated method stub
        return 0;
    }

    @Override
    public void onDelete() {
        // TODO Auto-generated method stub

    }

    @Override
    public void automaticMove() {
        // TODO Auto-generated method stub
        pos.actualiza(dir);
        //ojo con los bordes!!!
    }

}
