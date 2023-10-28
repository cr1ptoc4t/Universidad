package tp1.logic;

import tp1.logic.Move;
import java.util.Random;
import tp1.logic.gameobjects.*;
import tp1.view.Messages;

// TODO implementar

public class Game {

	public static final int DIM_X = 9;
	public static final int DIM_Y = 8;
	
	private UCMShip laNave;
	private UCMLaser laser;
	//private RegularAlien alien;

	public static Level level;

	private AlienManager alienManager;
	
	
	private static final int ALIENS_INI =30;
	private int remainingAliens;
	private int ciclos;
	//TODO fill your code
	public Game(Level level, long seed) {
		//TODO fill your code
		this.level=level;
		this.laNave= new UCMShip();
		//this.alien = new RegularAlien(DIM_X/2, DIM_Y/3);
		this.alienManager= new AlienManager(this, level);
		this.laser= laser;
		//this.laser = new UCMLaser(new Position(1,0));
		this.remainingAliens=alienManager.getRemainingAliens();
		ciclos =0;
	}


	//que hace esto??????
	public String stateToString() {
		//TODO fill your code
		return null;
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
		} else if(alienManager.regularAlienisInPosition(position)){
			str = " "+alienManager.getSymbol() +"[" + 3 +/*alienManager.getLife()*/ "]"; //
			//str = alienManager.simbolosAliens(0);
		} else if(laser!=null && laser.isInPos(position)){
			str = laser.getSymbol();
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
		//falta pasarle posicion +1(vertical)
		if(laser==null|| !laser.dentroMapa())			//				esto que coño es  ??????????????????????
			this.laser = new UCMLaser(new Position(4,6));	//	esto hay que cambiarlo para que la posicion sea
																	//	la de la nave pero una fila menos)
		ciclos++;
	}

	public Random getRandom() {
		return getRandom();
	}

	public Level getLevel() {
		return level;
	}
	
	public void mueveNave(Move direccion) {
		laNave.mueve(direccion);
		ciclos++;
	}
	public void reset() {
		// regenerar todos los aliens con todas las vidas
		// cambiar a posicion inicial los aliens
		ciclos=0;
	}

	public void pasaCiclo(){
		ciclos++;
	}

	public void movimientosAutomaticos(){

		int indice = laserChoca();
		if(indice!=-1){
			alienManager.eliminaAlien(indice);
		}else if (laser!=null) {
			laser.automaticMove();
		}
		alienManager.automaticMove();

	}

	public boolean laserMata(){
		//return laser.pos.equals(algunodelosaliens.pos);
		return false;
	}


	private int laserChoca(){
		//aqui no se como mirar que laser esta en la misma posicion que alguna nave sin hacer un get

		return -1;
	}

}
