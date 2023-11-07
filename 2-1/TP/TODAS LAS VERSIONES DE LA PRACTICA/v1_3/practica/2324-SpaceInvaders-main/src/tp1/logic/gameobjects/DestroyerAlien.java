package tp1.logic.gameobjects;

import tp1.logic.AlienManager;
import tp1.logic.Level;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;
import tp1.logic.Game;

public class DestroyerAlien {
    private final Move dir;

    private final Position pos;
    private int lifes;
    private final Level level;

    //TODO fill your code


    public static final int damage=1;
    public static final int endurance = 1;

    public static final int value = 10;

    private Bomb bomba;
    private final Game game;

    public DestroyerAlien(Game game, Position pos, Level level) {
        //alienManager = new AlienManager();
        this.game =game;
        this.pos = pos;
        this.dir = direccion();
        this.level=level;
        this.lifes=endurance;

        // random 0-1 -> si este random<frequency -> hay bomba
    }

    private void leaveBomb(){
        Position copia =new Position(this.pos);
        bomba = new Bomb(this, copia);

        bomba.movimientoAutomatico();

    }

    public void performMovement(Move dir) {

        pos.actualiza(dir);

    }

    public void performBombMov(){
        if(bomba!=null)
            bomba.movimientoAutomatico();
    }

    public boolean receiveAttack(UCMLaser laser) {
        //TODO fill your code
        lifes--;
        laser=null;
        return lifes==0;
    }
    /**
     * @return muere
     */
    public boolean isInPosition(Position position){
        return position.equals(pos);
    }

    public boolean isInBorderLeft(){
        return pos.isInBorderLeft() ;
    }

    public boolean isInBorderRight(){
        return pos.isInBorderRight();
    }




    private Move direccion(){
        Move dir;
        if(level==Level.EASY){
            dir= Move.LEFT;
        } else{
            dir=Move.LLEFT;
        }
        return dir;
    }
    public boolean shockWave(){
        lifes--;
        return lifes==0;
    }

    public int vida(){
        return lifes;
    }
    public String getSymbol(){
        return Messages.DESTROYER_ALIEN_SYMBOL+"["+lifes+"]";
    }
    public boolean isInLowerBorder(){
        return pos.isInBorderDown();
    }

    public void shoot(double frequency){
        if(canGenerateRandomBomb(frequency) && (bomba==null|| !bomba.posicionValida() )){
            leaveBomb();
        }
    }


    // este método evalua si se puede generar la bomba
    // SOLO por temas aleatoriedad y frecuencia
    private boolean canGenerateRandomBomb(double frequency){

        //el random siempre saca el mismo numero, que es 0,72...

        return game.rnd.nextDouble() < frequency;
    }

    public boolean bombaEnPos(Position pos){
        if (bomba ==null)
            return false;
        return bomba.isInPos(pos);
    }

}
