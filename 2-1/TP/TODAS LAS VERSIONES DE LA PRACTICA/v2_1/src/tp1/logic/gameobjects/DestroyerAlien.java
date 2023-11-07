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

    public static final int damage=1;
    public static final int endurance = 1;

    public static final int value = 10;

    private Bomb bomba;
    private final Game game;

    public DestroyerAlien(Game game, Position pos, Level level) {
        this.game =game;
        this.pos = pos;
        this.dir = direccion();
        this.level=level;
        this.lifes=endurance;

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
        return game.rnd.nextDouble() < frequency;
    }

    public boolean bombaEnPos(Position pos){
        if (bomba ==null)
            return false;
        return bomba.isInPos(pos);
    }

}
