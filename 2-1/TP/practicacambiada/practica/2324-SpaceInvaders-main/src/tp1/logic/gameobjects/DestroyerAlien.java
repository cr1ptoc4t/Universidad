package tp1.logic.gameobjects;

import tp1.logic.AlienManager;
import tp1.logic.Move;
import tp1.logic.Position;

public class DestroyerAlien {
    private int cyclesToMove;
    private int speed;
    private Move dir;
    private AlienManager alienManager;

    private Position pos;
    private int lifes;
    public DestroyerAlien(int x, int y){
        this.pos=new Position(x,y);
        this.lifes=3;
    }
}
