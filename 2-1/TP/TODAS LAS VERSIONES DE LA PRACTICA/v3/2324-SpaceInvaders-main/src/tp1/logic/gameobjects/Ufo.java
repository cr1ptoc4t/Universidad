package tp1.logic.gameobjects;

import tp1.logic.Move;
import tp1.logic.Position;
import tp1.logic.Game;
import tp1.view.Messages;

public class Ufo extends EnemyShip {
    public final int UFO_X=8;
    public final int UFO_Y=0;

    private static final int UFO_POINTS = 25;
    //private int life  =1;

    public Ufo(Game game){
        super(game, new Position(8, 0), 1);

    }

    public String toString(){
        return Messages.UFO_SYMBOL+"["+ life+"]";
    }

    @Override
    public void automaticMove() {
        pos.actualiza(Move.LEFT);
        //dies();
    }

    public boolean dies(){
        if(!posicionValida()||!isAlive()){
            game.disenableUfo();
            return true;
        }
        return false;
    }
    public int getPoints(){
        return UFO_POINTS;
    }

    public static String lista(){

        String buffer = Messages.UFO_DESCRIPTION +
                ": points= '" + UFO_POINTS +
                "', damage= '" + 1+
                "', endurance= '" + 1 + "'";

        return buffer;

    }
}

