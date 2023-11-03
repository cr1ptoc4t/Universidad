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
	
	private UCMShip laNave;
	private UCMLaser laser;

	public static Level level;

	private AlienManager alienManager;

	private RegularAlienList regularAliens;
	private DestroyerAlienList destroyerAliens;

	private long seed;
	private int puntos;
	private int vidas;

	private int remainingAliens;
	private int numRegular;
	private int numDestroyer;
	private boolean descent;

	private int ciclos;

	private Ufo ufo;

	public Game(Level level, long seed) {
		//TODO fill your code
		this.level=level;
		this.laNave= new UCMShip();
		this.seed=seed;


		this.alienManager = new AlienManager(this, level);

		regularAliens = alienManager.initializeRegularAliens();
		destroyerAliens = alienManager.initializeDestroyerAliens();
		remainingAliens = alienManager.decideNumAliens();

		ciclos= 0;
		vidas = 3;
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
		} else {
			RegularAlien alien = regularAliens.alienInPosition(position);
			if (alien!=null) {
				str = alien.getSymbol();
			} else {
				DestroyerAlien alienD = destroyerAliens.alienInPosition(position);
				if (alienD != null) {
					str = alienD.getSymbol();
				} else if (laser != null && laser.isInPos(position)) {
					str = laser.getSymbol();
				} else if(ufo !=null && ufo.isInPos(position)){
					str=ufo.getSymbol();
				}

			}
		}

		return str;
	}

	public boolean playerWin() {
		//return false;
		return remainingAliens==0;
	}

	public boolean aliensWin() {
		return vidas==0||regularAliens.alienInLowerBorder()|| destroyerAliens.alienInLowerBorder();
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


		boolean onBorder = regularAliens.onBorder()||destroyerAliens.onBorder();
		regularAliens.automaticMove(onBorder);
		destroyerAliens.automaticMove(onBorder);




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
		automaticMoves();
		computerAction();

	}
	private void computerAction(){	//eventos automaticos


		//	esto tiene que haber una forma más elegante de programarlo
		//	pero esq llevo 6 horas delante de una pantalla y encima estoy
		//	de resaca. PROCRASTINADO
		regularComputerAction();
		destroyerComputerAction();

	}

	private void regularComputerAction(){
		if(laser!=null ) {
			int indice = regularAliens.recibeAtaque(laser);
			if(indice!=-1) {
				laser = null;
				remainingAliens--;
				puntos += 5;
			}
		}
	}

	private void destroyerComputerAction(){
		if(laser!=null){
			int indice =destroyerAliens.recibeAtaque(laser);
			if(indice!=-1){
				laser=null;
				remainingAliens--;
				puntos+=5;
			}
		}
	}



	public String lista(){
		StringBuilder buffer = new StringBuilder();

		buffer.append(regularAliens.lista()).append("\n").append(destroyerAliens.lista());

		return buffer.toString();
		//faltará añadirle el ufo
	}

	public void shockWave(){
		regularAliens.shockWave();
		destroyerAliens.shockWave();
		ciclos++;
	}
}
