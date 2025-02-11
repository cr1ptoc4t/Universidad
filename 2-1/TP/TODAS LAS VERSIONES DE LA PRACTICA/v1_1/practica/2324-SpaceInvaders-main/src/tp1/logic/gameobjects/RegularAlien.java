package tp1.logic.gameobjects;

import tp1.logic.AlienManager;
import tp1.logic.Game;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;

/**
 * 
 * Class representing a regular alien
 *
 *
 */
public class RegularAlien {

	//TODO fill your code
	private int cyclesToMove;
	private int speed;
	private Move dir;
	private AlienManager alienManager;
	
	private Position pos;
	private int lifes;
	
	//TODO fill your code
	public RegularAlien(int x, int y) {
		//alienManager = new AlienManager();
		this.pos = new Position(x,y);
		this.dir = Move.LEFT;
		this.lifes= 3;
	}
	/**
	 *  Implements the automatic movement of the regular alien	
	 */
	public void automaticMove() {
		if(isInBorderVertical()) {
			performMovement(Move.DOWN);
			if(dir==Move.LEFT) {		dir = Move.RIGHT;	}
			else if (dir==Move.RIGHT){	dir = Move.LEFT;	}

		}
		performMovement(dir);
		// TODO ESTO HAY QUE CAMBIARLO PORQUE NOS OCUPA UN CICLO Y DEBERIAN SER DOS
	}

	private void descent() {
		performMovement(Move.DOWN);
	}

	public void performMovement(Move dir) {
		pos.actualiza(dir);
	}

	private boolean isInBorderVertical() {
		//TODO fill your code
		return pos.estaEnBordeVertical();
	}

	public boolean receiveAttack(UCMLaser laser) {
		//TODO fill your code

		return false;
	}
	/**
	 * @return muere
	 */
	public boolean isInPosition(Position position){
		return position.equals(pos);
	}

	public String getSymbol(){
		return Messages.REGULAR_ALIEN_SYMBOL;
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


	//ESTE GET?????????????
	public int getLifes(){
		return lifes;
	}

}