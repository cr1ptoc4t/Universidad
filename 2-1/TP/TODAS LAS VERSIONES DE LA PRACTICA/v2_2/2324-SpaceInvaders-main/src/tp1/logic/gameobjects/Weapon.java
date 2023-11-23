package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.Position;

public class Weapon extends GameObject{

    private Game game;
    private Position pos;
    private int life;
    public Weapon(){
        super(game, pos, life);
    }

    @Override
    public boolean isOnPosition(Position pos) {
        return false;
    }

    @Override
    protected String getSymbol() {
        return null;
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

    }

}
