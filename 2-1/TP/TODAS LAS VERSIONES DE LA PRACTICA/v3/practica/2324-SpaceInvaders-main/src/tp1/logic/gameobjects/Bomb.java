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
        this.vida =1;
    }




    public static String getSymbol(){
        return Messages.BOMB_SYMBOL;
    }

    public boolean isInPos(Position pos){
        return this.pos.equals(pos);
    }

    public void movimientoAutomatico(){
        pos.actualiza(dir);
    }


    public boolean posicionValida(){
        return pos.esPosicionValida();
    }

    public int getDamage(){
        return 1;
    }
}
