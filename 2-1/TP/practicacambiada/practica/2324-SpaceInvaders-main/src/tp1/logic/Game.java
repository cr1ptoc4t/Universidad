package tp1.logic;

import tp1.logic.Move;
import java.util.Random;
import tp1.logic.gameobjects.*;
import tp1.view.Messages;

import static tp1.util.MyStringUtils.repeat;
import tp1.logic.Game;
import tp1.util.MyStringUtils;

// TODO implementar

public class Game {

	public static final int DIM_X = 9;
	public static final int DIM_Y = 8;
	
	private UCMShip laNave;
	private UCMLaser laser;

	public static Level level;

	private AlienManager alienManager;

	private long seed;
	private int puntos;
	private int vidas;
	private static final int ALIENS_INI = 3; //USAR ESTO!!!!!!!!!!!!!
	private int remainingAliens;
	private int ciclos;


	public Game(Level level, long seed) {
		//TODO fill your code
		this.level=level;
		this.laNave= new UCMShip();
		this.seed=seed;
		createAlienManager();
		ciclos =0;
	}

	private void createAlienManager(){
		this.alienManager = new AlienManager(this, level);
		alienManager.initialize();
		this.remainingAliens=alienManager.ALIENS_INI;
	}

	public String stateToString() {

		StringBuilder buffer = new StringBuilder();

		buffer.append("Life: ").append(vidas)
				.append("\n").append("Points: ")
				.append(puntos).append("\n");

		return buffer.toString();
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
		} else if(alienManager.regularAlienIsInPosition(position)){
			str=alienManager.getSymbol("regular", new Position(col, row));

		} else if(laser!=null && laser.isInPos(position)){
			str = laser.getSymbol();
		}

		return str;
	}

	public boolean playerWin() {
		return remainingAliens==0;
	}

	public boolean aliensWin() {
		//return vidas==0;
		return false;
	}

	public void enableLaser() {

		if(laser==null ||( laser!=null	&& !laser.dentroMapa()))
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

	public void movimientosAutomaticos(){

		if(laser!=null) {
			laser.automaticMove();
		}
		alienManager.automaticMove();

	}

	public void eventosAutomaticos(){

		if(laser!=null && alienManager.recibeAtaque(laser)) {
			laser = null;
			remainingAliens--;
			puntos+=5;
		}


		/*

		int indice = regularAlienIsInPosition(laser.pos);
		if(indice!=-1){
			alienManager.eliminaAlien(indice);
		}
		*/
	}

	public boolean laserMata(){
		//return laser.pos.equals(algunodelosaliens.pos);
		return false;
	}

	public String lista(){
		//faltará añadirle el ufo
		return alienManager.lista();
	}

	public void shockWave(){
		alienManager.shockWave();
		ciclos++;
	}

}
