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
	private int ciclo;
	//TODO fill your code
	public Game(Level level, long seed) {
		//TODO fill your code
		this.level=level;
		this.laNave= new UCMShip();
		this.alien = new RegularAlien();
		ciclo =0;
	}

	public String stateToString() {
		//TODO fill your code
		return null;
	}

	public int getCycle() {
		return ciclo;
	}

	public int getRemainingAliens() {
		//TODO fill your code
		return remainingAliens;
	}
	
	public String positionToString(int col, int row) {
		//TODO fill your code
		String str = "";
		if(laNave.estaEnPos(new Position(col,row))){
			str = laNave.getSymbol();
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
			// eliminar alien
			// remainingAliens--;
		
	}

	public Random getRandom() {
		return getRandom();
	}

	public Level getLevel() {
		return level;
	}
	
	public void mueveNave(Move movimiento) {
		laNave.mueve(movimiento);
		ciclo++;
	}
	public void reset() {
		
	}

}
