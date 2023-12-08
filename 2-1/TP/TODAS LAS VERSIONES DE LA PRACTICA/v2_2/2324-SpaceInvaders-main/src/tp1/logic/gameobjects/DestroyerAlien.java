package tp1.logic.gameobjects;

import tp1.logic.*;
import tp1.view.Messages;

public class DestroyerAlien extends AlienShip {

    private int dano;

    private boolean shooted=false;
    private final int points= 15;

    public DestroyerAlien(Game game, Level level, Position pos, AlienManager alienManager) {
        // TODO fill with your code
        //super(game, pos, 0);
        super(game, level, pos, 1, Move.LEFT, alienManager);
        dano=1;
    }



    @Override
    protected String getSymbol() {
        // TODO fill with your code
        return Messages.DESTROYER_ALIEN_SYMBOL +"["+life+"]";
    }

    @Override
    protected int getDamage() {
        // TODO fill with your code
        return dano;
    }

    @Override
    protected int getArmour() {
        // TODO Auto-generated method stub
        return 0;
    }

    @Override
    public void onDelete() {
        // TODO Auto-generated method stub

    }


    public String toString(){
        return Messages.DESTROYER_ALIEN_SYMBOL+"["+ life+"]";
    }

    public void computerAction() {
        if(canRandomShoot()&&!shooted) {
            Position copia =new Position(this.pos);
            //copia.actualiza(Move.DOWN);
            game.leaveBomb(new Bomb(game, copia, this));
            shooted=true;
        }

    }

    public void enableBomb(){
        shooted =false;
    }
    @Override
    public int getPoints(){
        return points;
    }
    private boolean canRandomShoot(){
        return game.rnd.nextDouble() < game.getLevel().getShootFrequency();
    }
}
