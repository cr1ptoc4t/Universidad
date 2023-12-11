package tp1.logic;

import tp1.control.InitialConfiguration;
import tp1.logic.gameobjects.*;
import tp1.view.GamePrinter;
import tp1.view.Messages;

import java.util.Objects;
import java.util.Random;


public class Game implements GameStatus, GameModel, GameWorld {
	public static final int DIM_X = 9;
	public static final int DIM_Y = 8;

	
	private GameObjectContainer container;
	private UCMShip player;
	private AlienManager alienManager;
	private Level level;

	private boolean alienOnBorder=false;
	private boolean exit=false;
	private boolean shockWave;


	private final long seed;

	private int remainingAliens;
	private int currentCycle;
	private int points;



	private InitialConfiguration conf;
	public static final int DIM_X_UCM_SHIP = 4;
	public static final int DIM_Y_UCM_SHIP = 7;


	public Game (Level level, long seed){
		//TODO fill with your code
		this.level= level;
		this.seed=seed;

		conf=InitialConfiguration.NONE;
		alienManager = new AlienManager(this);
		initGame(conf);
	}
		
	private void initGame (InitialConfiguration conf) {
		points = 0;
		this.container = alienManager.initialize(conf);
		this.remainingAliens = getNumAliens(conf);
 		this.player = new UCMShip(this, new Position(DIM_X_UCM_SHIP,DIM_Y_UCM_SHIP));
		container.add(player);

		shockWave=false;
	}


	private int getNumAliens(InitialConfiguration conf){
		int num=0;

        if (InitialConfiguration.NONE.equals(conf))
			num = level.getNumDestroyerAliens() + level.getNumRegularAliens();
        else
            num = InitialConfiguration.values().length;

		return num;
	}


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

		String buffer = "Life: " + player.getLifes() + "\nPoints: " + points + "\nShockWave: "+ toString(shockWave) +"\n";

		return buffer;
	}

	@Override
	public boolean playerWin() {
		return remainingAliens==0;
	}

	@Override
	public boolean aliensWin() {
		return player.getLifes()<=0||alienOnBorder;
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
	public boolean shootLaser() {

		Laser laser = player.creaLaser();
		if(laser!=null) {
			addObject(laser);
		}
		return laser!=null;
	}

	public boolean shootSuperLaser(){
		SuperLaser sl = player.creaSuperLaser();

		if(points>=5&&sl != null) {
			addObject(sl);
			points-=5;
		}
		return sl!=null;
	}


	public void reset(InitialConfiguration conf) {
		this.container.clear();
		this.initGame(conf);
	}

	public void exit() {
		exit=true;
	}

	public void gananAliens(){
		alienOnBorder=true;
	}

	public Level getLevel(){
		return level;
	}


	public void objectDies(GameObject object) {
		int puntos = object.getPoints();
		if(puntos==25 && object.posicionValida()) {
			points += puntos;
			shockWave = true;
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
			GamePrinter.show(Messages.SHOCKWAVE_ERROR);
		}
	}



	public boolean puedeCrearSuperLaser(){
		return points >5 && !player.getShooted();
	}


	public String toString(boolean shockWave){
		String str="OFF";
		if(shockWave)
			str= "ON";

		return str;
	}

	public void explodeAlien(ExplosiveAlien alien){
		container.explodeAlien(this, alien);
	}

}
