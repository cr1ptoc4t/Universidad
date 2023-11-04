package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.Position;
import tp1.logic.Move;
import tp1.logic.gameobjects.DestroyerAlien;
import tp1.view.Messages;

public class Bomb {
    private Position pos;
    private Move dir;
    private int vida;

    private DestroyerAlien alien;


    public Bomb(DestroyerAlien alien, Position pos){
        this.alien = alien;
        this.pos=pos;
        this.dir=Move.DOWN;
    }




    public static String getSymbol(){
        return Messages.BOMB_SYMBOL;
    }

    public boolean isInPos(Position pos){
        return this.pos.equals(pos);
    }



}
