package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;

/**
 * 
 * Class that represents the laser fired by {@link UCMShip}
 *
 */
public class UCMLaser {
	
	//TODO fill your code
	private Move dir;
	private Game game; //para luego eliminar laser o sumar puntos al matar
	private Position pos;
	private int vida;

	public UCMLaser(Position pos) {
		this.dir = Move.UP;
		this.pos=pos;
		vida=1;
	}


	/**
	 *  Method called when the laser disappears from the board
	 */
	public void onDelete() {

	}

	/**
	 *  Implements the automatic movement of the laser	
	 */
	public void automaticMove () {
		performMovement(dir);
		if(isOut())
			die();
	}

	
	// PERFORM ATTACK METHODS

	
	
	public void die() {
		//TODO fill your code
		//dir=null;
	}

	private boolean isOut() {
		return !pos.esPosicionValida();
	}

	private void performMovement(Move dir) {
		pos.actualiza(dir);
	}

	/**
	 * Method that implements the attack by the laser to a regular alien.
	 * It checks whether both objects are alive and in the same position.
	 * If so call the "actual" attack method {link weaponAttack}.
	 * @param other the regular alien possibly under attack
	 * @return <code>true</code> if the alien has been attacked by the laser.
	 */


	public boolean performAttack(RegularAlien other) {
		boolean b = false;
		if(vida>0 && other.isInPosition(pos)){
			weaponAttack(other);
			b=true;
			vida--;
		}

		return b;
	}


	/*
	 * Method that implements the attack by the laser to a destroyer alien.
	 * It checks whether both objects are alive and in the same position.
	 * If so call the "actual" attack method {@link weaponAttack}.
	 * @param other the destroyer alien possibly under attack
	 * @return <code>true</code> if the alien has been attacked by the laser.
	 */


	public boolean performAttack(DestroyerAlien other) {
		boolean b = false;
		if(vida>0 && other.isInPosition(pos)){
			weaponAttack(other);
			b=true;
			vida--;
		}

		return b;
	}

	//TODO fill your code


	//ACTUAL ATTACK METHODS
	

	/**
	 * 
	 * @param other regular alien under attack by the laser
	 * @return always returns <code>true</code>
	 */
	private boolean weaponAttack(RegularAlien other) {
		return other.receiveAttack(this);
	}

	private boolean weaponAttack(DestroyerAlien other) {
		return other.receiveAttack(this);
	}

	//TODO fill your code


	// RECEIVE ATTACK METHODS
	
	
	/**
	 * Method to implement the effect of bomb attack on a laser
	 * param weapon the received bomb
	 * @return always returns <code>true</code>
	 */
	/*
	public boolean receiveAttack(Bomb weapon) {
		receiveDamage(weapon.getDamage());
		return true;
	}
	*/

	public boolean isInPos (Position pos){
		return this.pos.equals(pos);
	}

	public String getSymbol(){
		return Messages.LASER_SYMBOL;
	}

	public boolean dentroMapa(){
		return pos.esPosicionValida();
	}
}
