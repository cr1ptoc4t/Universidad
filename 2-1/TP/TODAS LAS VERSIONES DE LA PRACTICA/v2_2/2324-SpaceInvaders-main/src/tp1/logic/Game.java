package tp1.logic;

import tp1.logic.gameobjects.*;

import java.util.Random;
// Declarar que Game implementa las interfaces
//public class Game implements GameModel, GameStatus, GameWorld {

//}
	// Y sustituir Game donde proceda por la interfaz adecuada
//	public abstract ExecutionResult execute(GameModel game);

public class Game implements GameStatus, GameModel, GameWorld {
	public static final int DIM_X = 9;
	public static final int DIM_Y = 8;
	
	private GameObjectContainer container;
	private UCMShip player;
	private AlienManager alienManager;
	private int currentCycle;
	private GameWorld gameWorld;
	private Level level;

	public Random rnd;

	private final long seed;

	private int remainingAliens;


	private int points;

	public Game (Level level, long seed){
		//TODO fill with your code
		this.level= level;
		this.seed=seed;
		this.rnd= getRandom();
		points =0;
		alienManager = new AlienManager(this);

		initGame();

	}
		
	private void initGame () {	
		//TODO fill with your code
		this.container = alienManager.initialize();
		this.remainingAliens= level.getNumDestroyerAliens()+level.getNumRegularAliens();
 		this.player = new UCMShip(this, new Position(DIM_X / 2, DIM_Y - 1));
		container.add(player);
	}

	//CONTROL METHODS
	
	public boolean isFinished() {
		// TODO fill with your code
		return playerWin()||aliensWin();
	}

	@Override
	public boolean move(Move move) {
		return false;
	}



	@Override
	public boolean shootLaser() {

		Laser laser = player.creaLaser();
		if(laser!=null) {
			addObject(laser);
			return true;
		}
		return false;
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
		this.container.automaticMoves();
		this.container.computerActions(this);
		this.alienManager.initializeOvni(container);
	}

	//CALLBACK METHODS
	
	public void addObject(GameObject object) {
	    this.container.add(object);
	}

	public String positionToString(int col, int row) {
 		return container.toString(col,row);
	}

	public void puedeCrearLaser(){
		player.puedeCrearLaser();
	}
	

	@Override
	public String infoToString() {
		// TODO fill with your code
		return null;
	}

	@Override
	public String stateToString() {

		String buffer = "Life: " + player.getLifes() +
				"\n" + "Points: " +
				points + "\n";

		return buffer;
	}

	@Override
	public boolean playerWin() {
		// TODO fill with your code
		return remainingAliens==0;
	}

	@Override
	public boolean aliensWin() {
		// TODO fill with your code
		return player.getLifes()<=0||alienManager.someoneOnLowerBorder();
		//return false;
	}



	@Override
	public int getCycle() {
		return currentCycle;
	}

	@Override
	public int getRemainingAliens() {
		return remainingAliens;
	}

	private Random getRandom() {
		return new Random(seed);
	}


	public void updatePlayer(Move move){
		player.mueve(move);
	}

	public Level getLevel(){
		return level;
	}



	public void objectDies(GameObject object) {
		int puntos = object.getPoints();
		if (puntos > 0) {
			points += object.getPoints();
			if(puntos!=25)
				remainingAliens--;
		}
	}
	public void leaveBomb(){

	}


	public boolean playerBombCollision(GameObject object){
				//arreglar esto
		return object instanceof Bomb && player.recibeAtaque((Bomb) object);
	}

	public void shockWave(){
		this.container.shockWave();
	}
}
