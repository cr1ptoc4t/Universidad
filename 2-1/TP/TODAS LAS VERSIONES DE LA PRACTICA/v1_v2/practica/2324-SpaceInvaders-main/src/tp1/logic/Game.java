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

// TODO implementar

public class Game {

	public static final int DIM_X = 9;
	public static final int DIM_Y = 8;
	
	private UCMShip laNave;
	private UCMLaser laser;

	public static Level level;

	private AlienManager alienManager;

	private RegularAlienList regularAliens;
	private DestroyerAlienList destroyerAliens;

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
		vidas=3;
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
		//return vidas==0||fila de los aliens==fila de la ucm ship		;
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

	private void automaticMoves(){

		alienManager.automaticMove();

		//trayectoria bombas
			/*
			* Si una bomba de una nave alienígena alcanza a UCMShip,
			* UCMShip sufre un decremento de un punto de daño y la bomba es destruida.
			* Si UCMShip llega a 0 puntos de daño,
			* se utilizará el siguiente String para representar que la nave está destruida: #──#.
			* Si una bomba alcanza al láser de UCMShip, ambos, bomba y láser, son destruidos.
			*
			* */
		//si ovni distinto de null, actualiza posicion

		if(laser!=null) {
			laser.automaticMove();
		}

		/* TODO SOBRE EL LASER:
		Si el láser lanzado por UCMShip alcanza una bomba de una nave alienígena,
			ambos se eliminan del tablero.
		Si el láser de UCMShip alcanza una nave alienígena,
			la nave impactada sufre un decremento de un punto de daño
			y el láser es destruido.
		Si una nave alienígena llega a 0 puntos de daño, desaparece del tablero. -- hecho
		 */



	}

	public void update(){
		//en este orden?? --mirar 1.2 al final
		computerAction();
		automaticMoves();
	}
	private void computerAction(){	//eventos automaticos
		if(laser!=null && alienManager.recibeAtaque(laser)) {
			laser = null;
			remainingAliens--;
			puntos+=5;
		}
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
