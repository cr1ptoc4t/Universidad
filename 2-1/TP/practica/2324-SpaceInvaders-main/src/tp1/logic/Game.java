package tp1.logic;


import java.util.Random;
import tp1.logic.gameobjects.*;

// TODO implementar

public class Game {

	public static final int DIM_X = 9;
	public static final int DIM_Y = 8;
	
	private UCMShip laNave;
	public static Level level;
	
	//TODO fill your code
	public Game(Level level, long seed) {
		//TODO fill your code
		this.level=level;
		this.laNave= new UCMShip();
	}

	public String stateToString() {
		//TODO fill your code
		return null;
	}

	public int getCycle() {
		//TODO fill your code
		return 0;
	}

	public int getRemainingAliens() {
		//TODO fill your code
		return 0;
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
	}

	public Random getRandom() {
		//TODO fill your code
		return null;
	}

	public Level getLevel() {
		//TODO fill your code
		//return level;
		return null;
	}

}
