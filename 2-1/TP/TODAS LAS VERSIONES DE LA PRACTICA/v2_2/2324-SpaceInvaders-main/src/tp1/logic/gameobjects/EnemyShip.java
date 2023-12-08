package tp1.logic.gameobjects;

import tp1.logic.*;

public class EnemyShip extends Ship{
    private Move dir ;
    public EnemyShip(GameWorld game, Position pos, int life){
        super(game, pos, life);
        dir= Move.NONE;
    }



    @Override
    public boolean isOnPosition(Position pos) {
        // TODO fill with your code
        return this.pos.equals(pos);
    }

    public void automaticMove(Move dir) {
        pos.actualiza(dir);
    }



}
