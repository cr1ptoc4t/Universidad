/*
package tp1.logic;

import tp1.logic.Move;
import java.util.Random;
import tp1.logic.gameobjects.*;
import tp1.logic.lists.DestroyerAlienList;
import tp1.logic.lists.RegularAlienList;
import tp1.view.Messages;

import static tp1.util.MyStringUtils.repeat;
import tp1.logic.Game;
import tp1.util.MyStringUtils;

public class Game {


	public static final int DIM_X = 9;
	public static final int DIM_Y = 8;
	
	private final UCMShip laNave;
	private UCMLaser laser;

	public static Level level;

	private final AlienManager alienManager;
	private final RegularAlienList regularAliens;
	private final DestroyerAlienList destroyerAliens;

	private final long seed;
	private int puntos;
	private int vidas;

	private int remainingAliens;

	private int ciclos;
	private boolean shockWave = false;

	private final Ufo ufo;

	public Random rnd;


	public Game(Level level, long seed) {
		//TODO fill your code
		Game.level =level;
		this.laNave= new UCMShip();
		this.seed=seed;
		this.ufo=new Ufo(this);
		this.rnd =getRandom();


		this.alienManager = new AlienManager(this, level);

		regularAliens = alienManager.initializeRegularAliens();
		destroyerAliens = alienManager.initializeDestroyerAliens();
		remainingAliens = alienManager.decideNumAliens();

		ciclos= 0;
		vidas = 3;
	}

	public String stateToString() {

		String buffer = "Life: " + vidas +
				"\n" + "Points: " +
				puntos + "\n";

		return buffer;
	}

	public int getCycle() {
		return ciclos;
	}

	public int getRemainingAliens() {
		return remainingAliens;
	}

	public String positionToString(int col, int row) {
		String str = "";
		Position position = new Position(col,row);
		
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

		return str;
	}

	public boolean playerWin() {
		return remainingAliens==0;
	}

	public boolean aliensWin() {
		return vidas==0||regularAliens.alienInLowerBorder()|| destroyerAliens.alienInLowerBorder();
	}

	public void enableLaser() {
		if(laser==null ||(!laser.dentroMapa()))
			this.laser = laNave.creaLaser();

		ciclos++;
	}

	public Random getRandom() {
		return new Random(seed);
	}

	public Level getLevel() {
		return level;
	}
	
	public void mueveNave(Move direction) {
		laNave.mueve(direction);
		ciclos++;
	}
	public void reset() {
		// regenerar todos los aliens con todas las vidas
		// cambiar a posición inicial los aliens
		ciclos=0;
	}

	public void pasaCiclo(){
		ciclos++;
	}

	private void automaticMoves(){
		
		boolean onBorder = regularAliens.onBorder()||destroyerAliens.onBorder();
		regularAliens.automaticMove(onBorder);
		destroyerAliens.automaticMove(onBorder);

		//si ovni distinto de null, actualiza posicion
		if(ufo!=null && ufo.isEnabled())
			ufo.movimientoAutomatico();

		if(laser!=null) {
			laser.automaticMove();
		}
		
	}

	public void update(){

		automaticMoves();
		computerAction();

	}
	
	private void computerAction(){	//eventos automaticos
		
		regularComputerAction();
		destroyerComputerAction();
		ufoComputerAction();
		
		destroyerAliens.shoot();
		if(destroyerAliens.bombaAtaca(laNave)) vidas--;
		
	}

	private void ufoComputerAction(){
		
		if(ufo.isEnabled()){
			if(laser!=null&&ufo.receiveAttack(laser)) {
				laser=null;
				actualizaPoints("ufo");
				ufo.onDelete();
				shockWave=true;
			}
			
		}else {
			ufo.computerAction();
		}
	}

	private void regularComputerAction(){
		if(laser!=null) {
			int indice = regularAliens.recibeAtaque(laser);
			if (indice != -1) {
				laser = null;
			}
		}
	}

	private void destroyerComputerAction(){

		if(laser!=null) {
			int indice = destroyerAliens.recibeAtaque(laser);
			if (indice != -1) {
				laser = null;
			}
		}
	}

	public String lista(){
		StringBuilder buffer = new StringBuilder();

		buffer.append(regularAliens.lista())
			  .append("\n").append(destroyerAliens.lista()).append(ufo.lista());

		return buffer.toString();
	}

	public void doShockWave() {
		if (shockWave){
			regularAliens.shockWave();
			destroyerAliens.shockWave();
			shockWave=false;
		} else{
			System.out.println("aún no puedes");
		}
		ciclos++;
	}

	public void actualizaRemainingAliens(){
		
		remainingAliens--;
	}
	
	
	public void actualizaPoints(String type){
		switch (type){
			case "regular":
				puntos+=RegularAlien.value;
				break;
			case "destroyer":
				puntos+=DestroyerAlien.value;
				break;
			case "ufo":
				puntos+=Ufo.value;
				shockWave= true;
		}

	}
}
*/
package tp1.logic;

import tp1.logic.gameobjects.GameObject;
import tp1.logic.gameobjects.UCMShip;


public class Game implements GameStatus {

	//TODO fill with your code

	public static final int DIM_X = 9;
	public static final int DIM_Y = 8;

	private GameObjectContainer container;
	private UCMShip player;
	private AlienManager alienManager;
	private int currentCycle;

	//TODO fill with your code

	public Game (Level level, long seed){
		//TODO fill with your code
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
		String str = "";
		Position position = new Position(col,row);

		if(player.estaEnPos(position)){
			str = player.getSymbol();

		} else {
			/*
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



	//@Override
	public String infoToString () {
		// TODO fill with your code
		return null;
	}

	//@Override
	public String stateToString () {

			/*
			String buffer = "Life: " + vidas +
					"\n" + "Points: " +
					puntos + "\n";

			return buffer;
*/
			return " ";
	}

	//@Override
	public boolean playerWin () {
		// TODO fill with your code
		return getRemainingAliens() == 0;
	}

	//@Override
	public boolean aliensWin() {
		// TODO fill with your code
			return vidas==0||regularAliens.alienInLowerBorder()|| destroyerAliens.alienInLowerBorder();
	}

	//@Override
	public int getCycle() {
		// TODO fill with your code
		return currentCycle;
	}

	//@Override
	public int getRemainingAliens() {
		// TODO fill with your code
		return 0;
	}

}