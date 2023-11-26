package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.Position;
import tp1.logic.Move;

public class Weapon extends GameObject{

    private Game game;
    private Position pos;
    private int life;

    public Weapon(Game game, Position pos, Move dir, int dano){
        super(game, pos, 1); //no se porque un 1
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
