package tp1.logic;

import tp1.logic.gameobjects.GameObject;
import tp1.logic.gameobjects.UCMShip;
import java.util.Random;
// Declarar que Game implementa las interfaces
//public class Game implements GameModel, GameStatus, GameWorld {

//}
	// Y sustituir Game donde proceda por la interfaz adecuada
//	public abstract ExecutionResult execute(GameModel game);

public class Game implements GameStatus {

	//TODO fill with your code

	public static final int DIM_X = 9;
	public static final int DIM_Y = 8;
	
	private GameObjectContainer container;
	private UCMShip player;
	private AlienManager alienManager;
	private int currentCycle;
	private GameWorld gameWorld;
	private Level level;
	
	//TODO fill with your code
	public Random rnd;

	private long seed;

	private int remainingAliens;

	public Game (Level level, long seed){
		//TODO fill with your code
		this.level= level;
		this.seed=seed;
		this.rnd= getRandom();

		alienManager = new AlienManager(this);

		initGame();

	}
		
	private void initGame () {	
		//TODO fill with your code
		this.container = alienManager.initialize();
		this.player = new UCMShip(this, new Position(DIM_X / 2, DIM_Y - 1));
		//container.add(player);
	}

	//CONTROL METHODS
	
	public boolean isFinished() {
		// TODO fill with your code
		return false;
	}

	public void exit() {
		// TODO fill with your code
	}

	public void update() {
	    this.currentCycle++;
	    this.container.computerActions();
	    this.container.automaticMoves();
	}

	// TODO fill with your code

	//CALLBACK METHODS
	
	public void addObject(GameObject object) {
	    this.container.add(object);
	}

	// TODO fill with your code
	
	//VIEW METHODS
	
	public String positionToString(int col, int row) {
		//return null;
		//return container.toString(new Position(col, row));
		String str = " ";
		Position position = new Position(col,row);
/*
		if(laNave.estaEnPos(position)){
			str = laNave.getSymbol();

		} else {
			RegularAlien alien = regularAliens.alienInPosition(position);
			if (alien != null) {
				str = alien.getSymbol();

			} else {
				DestroyerAlien alienD = destroyerAliens.alienInPosition(position);

				if (alienD != null) {
					str = alienD.getSymbol();

				} else{
					if (destroyerAliens.hayBomba(position)){
						str = Bomb.getSymbol();

					} else if (laser != null && laser.isInPos(position)){
						str = laser.getSymbol();

					} else if (ufo != null && ufo.isInPos(position) && ufo.isEnabled()){
						str = ufo.getSymbol();
					}
				}
			}
		}

 */

		return str;
	}
	
	

	@Override
	public String infoToString() {
		// TODO fill with your code
		return null;
	}

	@Override
	public String stateToString() {
		/*
		String buffer = "Life: " + vidas +
				"\n" + "Points: " +
				puntos + "\n";

		return buffer;

		 */
		return  " ";
	}

	@Override
	public boolean playerWin() {
		// TODO fill with your code
		return remainingAliens==0;
	}

	@Override
	public boolean aliensWin() {
		// TODO fill with your code
		//return vidas==0||regularAliens.alienInLowerBorder()|| destroyerAliens.alienInLowerBorder();
		return false;
	}

	@Override
	public int getCycle() {
		// TODO fill with your code
		return currentCycle;
	}

	@Override
	public int getRemainingAliens() {
		// TODO fill with your code
		return remainingAliens;
	}

	public Random getRandom() {
		return new Random(seed);
	}

}
