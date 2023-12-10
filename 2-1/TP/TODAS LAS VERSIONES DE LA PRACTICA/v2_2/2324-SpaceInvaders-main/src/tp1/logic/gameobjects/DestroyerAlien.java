package tp1.logic.gameobjects;

import tp1.logic.*;
import tp1.view.Messages;

public class DestroyerAlien extends AlienShip {

    private int dano;

    private boolean shooted=false;
    private final static int points= 15;

    public DestroyerAlien(GameWorld game, Position pos, AlienManager alienManager) {
        super(game, pos, 1, Move.LEFT, alienManager);
        dano=1;
    }

    public DestroyerAlien() {
        super();
    }


    @Override
    protected String getSymbol() {
        // TODO fill with your code
        return Messages.DESTROYER_ALIEN_SYMBOL;
    }

    @Override
    protected int getDamage() {
        // TODO fill with your code
        return dano;
    }

    @Override
    protected int getArmour() {
        // TODO Auto-generated method stub
        return 1;
    }



    public String toString(){
        return Messages.DESTROYER_ALIEN_SYMBOL+"["+ life+"]";
    }

    public void computerAction() {

        if(canRandomShoot()&&!shooted) {
            game.leaveBomb(new Bomb(game, new Position(this.pos), this));
            shooted=true;
        }
        super.computerAction();
        //if(this.pos.onBorderLateral()){
          //  alienManager.setOnBorder();
        //}

    }

    @Override
    protected AlienShip copy(GameWorld game, Position pos, AlienManager am) {
        return new DestroyerAlien(game, pos, am);
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

    public static String lista(){

        String buffer = Messages.DESTROYER_ALIEN_DESCRIPTION +
                ": points= '" + points +
                "', damage= '" + 1+
                "', endurance= '" + 1 + "'";

        return buffer;

    }


}
