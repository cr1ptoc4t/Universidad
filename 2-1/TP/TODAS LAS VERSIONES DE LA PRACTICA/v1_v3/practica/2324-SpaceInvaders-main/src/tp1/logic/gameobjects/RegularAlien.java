package tp1.logic.gameobjects;

import tp1.logic.*;
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
	private final Move dir;
	private AlienManager alienManager;
	
	private final Position pos;
	private int life;
	private final Level level;


	public static final int damage=0;
	public static final int endurance = 2;
	public static final int value = 5;
	
	//TODO fill your code
	public RegularAlien(Game game, Position pos, Level level) {
		//alienManager = new AlienManager();
		this.pos = pos;
		this.dir = direccion(level);
		this.life= endurance;
		this.level=level;

	}

	public void performMovement(Move dir) {
		pos.actualiza(dir);
	}

	private boolean isInBorderVertical() {
		//TODO fill your code
		return pos.isInBorderLeft()||isInBorderRight();
	}



	//si performattack
	//actualizas var

	public boolean receiveAttack(UCMLaser laser) {

		life--;
		laser=null;
		return life==0;
	}
	/**
	 * @return muere
	 */
	public boolean isInPosition(Position position){
		return position.equals(pos);
	}

	public boolean isInBorderLeft(){
		return pos.isInBorderLeft() ;
	}

	public boolean isInBorderRight(){
		return pos.isInBorderRight();
	}

	public boolean isInLowerBorder(){
		return pos.isInBorderDown();
	}

	private Move direccion(Level level){
		Move dir;
		if(level==Level.EASY){
			dir= Move.LEFT;
		} else{
			dir=Move.LLEFT;
		}
		return dir;
	}
	public int vida(){
		return life;
	}
	public boolean shockWave(){
		life--;
		return life==0;
	}
	//@returns : esta vivo?

	public String getSymbol(){
		return Messages.REGULAR_ALIEN_SYMBOL+"["+life+"]";
	}

}