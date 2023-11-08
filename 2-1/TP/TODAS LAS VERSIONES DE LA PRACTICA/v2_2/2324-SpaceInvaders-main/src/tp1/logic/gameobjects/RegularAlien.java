package tp1.logic.gameobjects;

import tp1.logic.AlienManager;
import tp1.logic.Game;
import tp1.logic.Position;

public class RegularAlien extends GameObject {

	public RegularAlien(Game game, Position pos, AlienManager alienManager) {
		// TODO fill with your code
		super(game, pos, 0);
	}

	@Override
	public boolean isOnPosition(Position pos) {
		// TODO fill with your code
		return false;
	}

	@Override
	protected String getSymbol() {
		// TODO fill with your code
		return null;
	}

	@Override
	protected int getDamage() {
		// TODO fill with your code
		return 0;
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

	@Override
	public void automaticMove() {
		// TODO Auto-generated method stub

	}

}
