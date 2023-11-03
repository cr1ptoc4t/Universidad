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
	private Move dir;
	private AlienManager alienManager;
	
	private Position pos;
	private int points;
	private Level level;
	
	//TODO fill your code
	public RegularAlien(Game game, Position pos, Level level) {
		//alienManager = new AlienManager();
		this.pos = pos;
		this.dir = direccion(level);
		this.points= 2;
		this.level=level;
	}

	public void performMovement(Move dir) {
		pos.actualiza(dir);
	}

	private boolean isInBorderVertical() {
		//TODO fill your code
		return pos.isInBorderLeft()||isInBorderRight();
	}



	public boolean receiveAttack(UCMLaser laser) {
		//TODO fill your code
		if(laser!=null && laser.isInPos(pos)){
			points--;
			laser=null;
		}
		//hacer un if para incrementar puntos
		if(points==0){
			//game.puntos+=5;
		}

		//devuelve si deberia morir
		return points==0;
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
		return points;
	}
	public void shockWave(){
		points--;
	}

	public String getSymbol(){
		return Messages.REGULAR_ALIEN_SYMBOL+"["+points+"]";
	}
}