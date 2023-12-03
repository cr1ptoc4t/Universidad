package tp1.logic.gameobjects;

import tp1.logic.AlienManager;
import tp1.logic.Game;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;

public class RegularAlien extends AlienShip {

	Move dir = Move.LEFT;


	public RegularAlien(Game game, Position pos) {
		// TODO fill with your code
		super(game, pos, 2, Move.LEFT);

	}


	@Override
	public boolean isOnPosition(Position pos) {
		// TODO fill with your code
		return this.pos.equals(pos);
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
		return life;
	}

	@Override
	public void onDelete() {
		// TODO Auto-generated method stub

	}

	@Override
	public void automaticMove() {
		// TODO Auto-generated method stub
		//pos.actualiza(dir);
		//ojo con los bordes!!!
	}

	public String toString(){
		return Messages.REGULAR_ALIEN_SYMBOL+"["+ life+"]";
	}

}
