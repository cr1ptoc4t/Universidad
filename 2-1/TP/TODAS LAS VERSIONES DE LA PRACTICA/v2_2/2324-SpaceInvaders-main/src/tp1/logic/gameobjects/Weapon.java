package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.GameWorld;
import tp1.logic.Position;
import tp1.logic.Move;

public class Weapon extends GameObject{

    public Weapon(GameWorld game, Position pos, Move dir){
        super(game, pos, 1);
    }

    @Override
    public boolean isOnPosition(Position pos) {
        return this.pos.equals(pos);
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
    public boolean performAttack(GameItem other) {
        //other.receiveAttack(this);
        return other.isOnPosition(this.pos);
    }



}
