package tp1.logic.gameobjects;

import tp1.logic.*;
import tp1.view.Messages;

public class DestroyerAlien extends AlienShip {


   // private Position pos;
    private int dano;

    private boolean shooted=false;
    private final int points= 15;

    public DestroyerAlien(Game game, Position pos, AlienManager alienManager) {
        // TODO fill with your code
        //super(game, pos, 0);
        super(game, pos, 1, Move.LEFT);
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

    public void automaticMove() {
        // TODO Auto-generated method stub
        //pos.actualiza(dir);
        //ojo con los bordes!!!
        //super.automaticMove(dir);
    }

    public String toString(){
        return Messages.DESTROYER_ALIEN_SYMBOL+"["+ life+"]";
    }

    public void computerAction() {
        if(canRandomShoot()&&!shooted) {

            game.leaveBomb(new Bomb(game, new Position(this.pos), this));
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
