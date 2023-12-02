package tp1.logic.gameobjects;


import tp1.logic.GameWorld;
import tp1.logic.Position;
import tp1.logic.Game;
import tp1.logic.Move;

public class Ship extends GameObject {
    private Move dir;

    public Ship(Game game, Position pos, int life){
        super(game, pos, life);
        dir= Move.NONE;
    }



    @Override
    public boolean isOnPosition(Position pos) {
        return this.pos.equals(pos);
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


    protected String getSymbol(){
        return "";
    }
    @Override
    public void automaticMove() {

    }

}
