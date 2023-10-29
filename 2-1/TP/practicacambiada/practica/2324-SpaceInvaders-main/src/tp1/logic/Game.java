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

	private int puntos;
	private int vidas;
	private static final int ALIENS_INI = 3; //USAR ESTO!!!!!!!!!!!!!
	private int remainingAliens;
	private int ciclos;
	//TODO fill your code
	public Game(Level level, long seed) {
		//TODO fill your code
		this.level=level;
		this.laNave= new UCMShip();
		this.alienManager = new AlienManager(this, level);
		alienManager.initialize();
		this.laser = laser;
		//this.laser = new UCMLaser(new Position(1,0));

		//este alien.getRemaining hay q cambiarlo por la constante
		this.remainingAliens=alienManager.getRemainingAliens();
		ciclos =0;
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
		//TODO fill your code
		return false;
	}

	public boolean aliensWin() {
		//TODO fill your code
		return false;
	}

	public void enableLaser() {
		//falta pasarle posicion nave
		if(laser==null ||( laser!=null	&& !laser.dentroMapa()))
			this.laser = new UCMLaser(new Position(4,7));	//	la posicion tiene que ser la de la nave
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

		if(laser!=null) {
			laser.automaticMove();
		}
		alienManager.automaticMove();

	}
	public void eventosAutomaticos(){
		if(laser!=null)
			alienManager.recibeAtaque(laser);
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



}
