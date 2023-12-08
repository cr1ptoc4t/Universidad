package tp1.logic.gameobjects;

import tp1.logic.*;
import tp1.view.Messages;

public class RegularAlien extends AlienShip {

	Move dir = Move.LEFT;

	private final int points=10;

	public RegularAlien(Game game, Level level, Position pos, AlienManager alienManager) {
		// TODO fill with your code
		super(game, level, pos, 2, Move.LEFT, alienManager);

	}

	@Override
	protected String getSymbol() {
		// TODO fill with your code
		return Messages.REGULAR_ALIEN_SYMBOL +"["+life+"]";
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
		return Messages.REGULAR_ALIEN_SYMBOL+"["+ life+"]";
	}

}
