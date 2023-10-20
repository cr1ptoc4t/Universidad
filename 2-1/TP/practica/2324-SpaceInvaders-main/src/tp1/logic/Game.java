package tp1.logic;

import tp1.logic.Move;
import java.util.Random;
import tp1.logic.gameobjects.*;

// TODO implementar

public class Game {

	public static final int DIM_X = 9;
	public static final int DIM_Y = 8;
	
	private UCMShip laNave;
	private RegularAlien alien;
	public static Level level;
	
	
	
	private static final int ALIENS_INI =30;
	private int remainingAliens;
	private int ciclos;
	//TODO fill your code
	public Game(Level level, long seed) {
		//TODO fill your code
		this.level=level;
		this.laNave= new UCMShip();
		this.alien = new RegularAlien(DIM_X/2, DIM_Y/3);
		ciclos =0;
	}


	//que hace esto??????
	public String stateToString() {
		//TODO fill your code
		return null;
	}

	public int getCycle() {
		return ciclos;
	}

	public int getRemainingAliens() {
		//TODO fill your code
		return remainingAliens;
	}
	
	public String positionToString(int col, int row) {
		//TODO fill your code
		String str = "";
		Position position = new Position(col,row);

		if(laNave.estaEnPos(position)){
			str = laNave.getSymbol();
		} else if(alien.isInPosition(position)) {
			str = alien.getSymbol();
		}

		return str;
	}

	public boolean playerWin() {
		//TODO fill your code
		return false;
	}

	public boolean aliensWin() {
		//TODO fill your code
		return false;
	}

	public void enableLaser() {
		//TODO fill your code
		//disparar

		// si hay un alien en la misma columna:
		//if(alien.pos.equals(/*laNave.pos*/)){

		//	remainingAliens--;
		//}
			// eliminar alien
			// remainingAliens--;
		
	}

	public Random getRandom() {
		return getRandom();
	}

	public Level getLevel() {
		return level;
	}
	
	public void mueveNave(Move direccion) {
		laNave.mueve(direccion);
		ciclos++;
	}
	public void reset() {
		ciclos=0;
	}

	public void pasaCiclo(){
		ciclos++;
	}
}
