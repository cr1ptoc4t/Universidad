package tp1.logic;


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
		//TODO fill your code
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
		//TODO fill your code
		Random random = getRandom();
		return random; 
	}

	public Level getLevel() {
		return level;
	}
	
	public void mueveNave(String dir) {
		//laNave.mueve(new Position(col, row));
		if(dir.equals("left")) {
			laNave.mueve(new Position(0,0));
		} else if(dir.equals("right")) {
			
		} else if(dir.equals("lleft")) {

		} else if(dir.equals("rright")) {
		}
		ciclo++;
	}
	public void reset() {
		
	}

}
