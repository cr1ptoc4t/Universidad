package tp1.logic.gameobjects;
import tp1.logic.Game;
import tp1.logic.Position;
import tp1.logic.Move;

public class Bomb {
    Position pos;
    Move dir;

    public Bomb(Position pos){
        this.pos=pos;
        this.dir=Move.DOWN;
    }



}
