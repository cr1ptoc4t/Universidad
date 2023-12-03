package tp1.logic;

import tp1.logic.gameobjects.GameObject;
import tp1.logic.gameobjects.UCMShip;
import tp1.logic.gameobjects.UCMWeapon;

import java.util.Random;
// Declarar que Game implementa las interfaces
//public class Game implements GameModel, GameStatus, GameWorld {

//}
	// Y sustituir Game donde proceda por la interfaz adecuada
//	public abstract ExecutionResult execute(GameModel game);

public class Game implements GameStatus, GameModel, GameWorld {

	//TODO fill with your code

	public static final int DIM_X = 9;
	public static final int DIM_Y = 8;
	
	private GameObjectContainer container;
	private UCMShip player;
	private AlienManager alienManager;
	private int currentCycle;
	private GameWorld gameWorld;
	private Level level;
	private boolean shooted;
	
	//TODO fill with your code
	public Random rnd;

	private long seed;

	private int remainingAliens;

	//esto esta mal tiene que ir en el contenedor pero me la pela
	private UCMWeapon laser;

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
		container.add(player);
		this.shooted = false;
	}

	//CONTROL METHODS
	
	public boolean isFinished() {
		// TODO fill with your code
		return false;
	}

	@Override
	public boolean move(Move move) {
		return false;
	}

	@Override
	public boolean shootLaser() {
		// aqui tiene que haber una forma de solo crear uno, cuando no se usa
		// ponerlo a null y sobreescribir ese objeto cuando se use
		// porque aqui solo podemos crear 1 y cuando esta fuera del mapa
		// ya no puedes crear mas

		if(!shooted){
			addObject(player.creaLaser());
			shooted= true;
		}

		return shooted;
	}

	@Override
	public void reset() {
		this.initGame();
	}

	public void exit() {
		// TODO fill with your code
		//comprobar quien ha ganado y tal
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
		return container.toString(col,row);
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


	public void updatePlayer(Move move){
		player.mueve(move);

		//aqui habria que mirar si aun tiene vidas o algo??
	}

	public Level getLevel(){
		return level;
	}

}
