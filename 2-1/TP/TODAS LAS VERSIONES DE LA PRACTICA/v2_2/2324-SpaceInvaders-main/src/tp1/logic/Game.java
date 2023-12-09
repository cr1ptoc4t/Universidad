package tp1.logic;

import tp1.logic.gameobjects.*;
import tp1.view.GamePrinter;
import tp1.view.Messages;

import java.util.Random;


public class Game implements GameStatus, GameModel, GameWorld {
	public static final int DIM_X = 9;
	public static final int DIM_Y = 8;
	
	private GameObjectContainer container;
	private UCMShip player;
	private AlienManager alienManager;
	private int currentCycle;
	private GameWorld gameWorld;
	private Level level;


	private boolean exit=false;


	private final long seed;

	private int remainingAliens;
	private int waitUntil;

	private boolean shockWave;

	private int points;
	private GamePrinter printer;

	public Game (Level level, long seed){
		//TODO fill with your code
		this.level= level;
		this.seed=seed;
		//this.rnd= getRandom();

		alienManager = new AlienManager(this);
		initGame();

	}
		
	private void initGame () {	
		//TODO fill with your code
		points = 0;
		this.container = alienManager.initialize();
		this.remainingAliens = level.getNumDestroyerAliens()+level.getNumRegularAliens();
 		this.player = new UCMShip(this, new Position(DIM_X / 2, DIM_Y - 1));
		container.add(player);

		shockWave=false;
	}

	//CONTROL METHODS
	




	//CALLBACK METHODS
	//GAMEWORLD

	public void update() {
		this.currentCycle++;


		this.container.computerActions(this);
		this.container.automaticMoves();
		this.alienManager.initializeOvni(container);
	}

	public void addObject(GameObject object) {
		this.container.add(object);
	}

	public void updatePlayer(Move move){
		player.mueve(move);
	}

	public void leaveBomb( Bomb bomb){
		container.add(bomb);
	}

	public void disenableUfo(){
		alienManager.disenableUfo();
	}


	public void enableBomb(DestroyerAlien alien) {
		alien.enableBomb();
	}




	public void died(GameObject object) {
		container.remove(object);
	}


	public boolean puedeCrearLaser(){
		return !player.getShooted();
	}

	@Override
	public void superLaserAFalse() {

	}

	public void laserAFalse(){
		player.setLaserAFalse();
	}

	//GAMESTATUS
	public String positionToString(int col, int row) {
		return container.toString(col,row);
	}

	@Override
	public String infoToString() {
		// TODO fill with your code
		return null;
	}

	public String lista(){
		StringBuilder buffer = new StringBuilder();

		buffer.append(alienManager.lista());

		return buffer.toString();
	}


	@Override
	public String stateToString() {

		String buffer = "Life: " + player.getLifes() +
				"\nPoints: " + points + "\nShockWave: "+ toString(shockWave) +"\n";

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


	//GAMEMODEL


	public boolean isFinished() {
		// TODO fill with your code
		return playerWin()||aliensWin()||exit;
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

	public boolean shootSuperLaser(){
		if(points>5) {
			SuperLaser sl = player.creaSuperLaser();
			if (sl != null) {
				addObject(sl);
				points-=5;
				return true;
			}
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
		exit=true;
	}
	private Random getRandom() {
		return new Random(seed);
	}


	public Level getLevel(){
		return level;
	}


	public void objectDies(GameObject object) {
		int puntos = object.getPoints();
		if(puntos==25 && object.posicionValida()) {
			points += puntos;
			shockWave = true;
			//printer.show("YOU CAN USE SHOCKWAVE NOW");
		} else if(puntos>0 && !(puntos==25 && !object.posicionValida())) {
			points += puntos;
			remainingAliens--;
		}
	}


	public void shockWave(){
		if(shockWave) {
			this.container.shockWave(this);
			shockWave=false;
		} else{
			printer.show(Messages.SHOCKWAVE_ERROR);
		}
	}

	@Override
	public void superLaser() {

	}


	public boolean puedeCrearSuperLaser(){
		return points >5 && !player.getShooted();
	}

	@Override
	public Level getlevel() {
		return this.level;
	}

	public String toString(boolean shockWave){
		String str="OFF";
		if(shockWave)
			str= "ON";

		return str;
	}

}
