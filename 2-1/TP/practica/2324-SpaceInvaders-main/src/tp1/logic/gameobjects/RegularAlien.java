package tp1.logic.gameobjects;

import tp1.logic.AlienManager;
import tp1.logic.Game;
import tp1.logic.Move;
import tp1.logic.Position;

/**
 * 
 * Class representing a regular alien
 *
 */
public class RegularAlien {

	//TODO fill your code
	private int cyclesToMove;
	private int speed;
	private Move dir;
	
	private AlienManager alienManager;
	
	private Position pos;
	
	
	//TODO fill your code
	public RegularAlien() {
		//alienManager = new AlienManager();
		this.pos = new Position(0,0); //esto esta mal
		//this.dir = new Move();
		//
	}
	/**
	 *  Implements the automatic movement of the regular alien	
	 */
	public void automaticMove() {
		//TODO fill your code
		//Move direccion = new Move (-1,0);
		if(isInBorder()) {
			//cambio de movimiento
		}
		//performMovement(direccion);
	}

	private void descent() {
		//TODO fill your code
		//esto no se si está bien puesto que estas creando un objeto encima de otro
		//pos=new Position (pos.getRow()-1, pos.getCol());
	}

	private void performMovement(Move dir) {
		//TODO fill your code
		
	}

	private boolean isInBorder() {
		//TODO fill your code
		//return pos.getCol()==Game.DIM_X || pos.getCol()==0;
		return false;
	}

	public boolean receiveAttack(UCMLaser laser) {
		//TODO fill your code
		
		return false;
	}
	

}