package tp1.logic.gameobjects;

import tp1.logic.AlienManager;
import tp1.logic.Level;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;
import tp1.logic.Game;

public class DestroyerAlien {
    private int cyclesToMove;
    private int speed;
    private Move dir;
    private AlienManager alienManager;

    private Position pos;
    private int lifes;

    private int points;
    private Level level;

    //TODO fill your code



    public DestroyerAlien(Position pos, Level level) {
        //alienManager = new AlienManager();
        this.pos = pos;
        this.dir = direccion(level);
        this.level=level;
        this.points=1;
    }

    public void leaveBomb(){
        Bomb bomb = new Bomb(this.pos);
    }

    public void performMovement(Move dir) {
        pos.actualiza(dir);
    }

    private boolean isInBorderVertical() {
        //TODO fill your code
        return pos.isInBorderLeft()||isInBorderRight();
    }

    public boolean receiveAttack(UCMLaser laser) {
        //TODO fill your code

        return laser!=null && laser.isInPos(pos);
    }
    /**
     * @return muere
     */
    public boolean isInPosition(Position position){
        return position.equals(pos);
    }

    public boolean isInCol(int col){
        return pos.isInCol(col);
    }

    public boolean isInBorderLeft(){
        return pos.isInBorderLeft() ;
    }

    public boolean isInBorderRight(){
        return pos.isInBorderRight();
    }


    private Move direccion(Level level){
        Move dir;
        if(level==Level.EASY){
            dir= Move.LEFT;
        } else{
            dir=Move.LLEFT;
        }
        return dir;
    }
    public int vida(){
        return points;
    }

    public void shockWave(){
        points--;
    }

    public String getSymbol(){
        return Messages.DESTROYER_ALIEN_SYMBOL+"["+points+"]";
    }
    public boolean isInLowerBorder(){
        return pos.isInBorderDown();
    }
}
