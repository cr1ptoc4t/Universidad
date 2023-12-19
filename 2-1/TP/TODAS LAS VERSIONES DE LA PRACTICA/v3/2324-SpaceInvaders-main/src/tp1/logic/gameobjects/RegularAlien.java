package tp1.logic.gameobjects;

import tp1.logic.*;
import tp1.view.Messages;

public class RegularAlien extends AlienShip {
	private final static int points=10;

	public RegularAlien(GameWorld game, Position pos, AlienManager alienManager) {
		super(game, pos, 2, Move.LEFT, alienManager);

	}

	public RegularAlien() {
		super();
	}


	@Override
	protected String getSymbol() {
		// TODO fill with your code
		return Messages.REGULAR_ALIEN_SYMBOL;
	}

	@Override
	protected int getDamage() {
		// TODO fill with your code
		return 1;
	}

	@Override
	protected int getArmour() {
		// TODO Auto-generated method stub
		return 1;
	}

	@Override
	public void onDelete() {
		// TODO Auto-generated method stub

	}


	@Override
	public int getPoints(){
		return points;
	}


	public String toString(){
		return Messages.REGULAR_ALIEN_SYMBOL+"[0"+ life+"]";
	}

	protected AlienShip copy(GameWorld game, Position pos, AlienManager am){
		return new RegularAlien(game, pos, am);
	}


	public static String lista(){

		String buffer = Messages.REGULAR_ALIEN_DESCRIPTION +
				": points= '" + points +
				"', damage= '" + 1+
				"', endurance= '" + 1 + "'";

		return buffer;

	}
}
