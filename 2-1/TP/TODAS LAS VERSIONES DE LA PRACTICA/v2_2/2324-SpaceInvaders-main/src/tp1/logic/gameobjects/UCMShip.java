package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.GameWorld;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;

public class UCMShip extends Ship {

	//TODO fill with your code
	//private Game game;
//	private Position pos;

	private int vida=3;
	private Move dir;
	//private Game game;
	private Weapon laser;
	private boolean shooted=false;

	public UCMShip(Game game, Position pos) {
		super(game, pos, 3);

		this.dir=Move.NONE;
		this.laser =null;
	}

	
	//TODO fill with your code
	public String toString(){
		String symbol=Messages.UCMSHIP_SYMBOL;
		if(vida<=0){
			symbol="#──#";
		}
		return symbol;
	}

	public boolean estaEnPos(Position position){
		return this.pos.equals(position);
	}

	public void mueve(Move movimiento) {

		//nueva variable para mover
		Position posicionActualizada = new Position(pos);

		//actualizar
		posicionActualizada.actualiza(movimiento);

		//si no esta fuera del mapa
		if(posicionActualizada.esPosicionValida()) {
			//copiar al original
			pos=posicionActualizada;
		} else {
			System.out.println(Messages.INVALID_POSITION);
		}

	}

	public boolean recibeAtaque(EnemyWeapon weapon){
		if(weapon.equalPosition(this))
			vida--;
		return vida<=0;
	}

	public void puedeCrearLaser(){
		shooted=false;
	}

	public Laser creaLaser(){
		if(!shooted) {
			shooted=true;
			Position copia = new Position(pos);
			copia.actualiza(Move.UP);
			return new Laser(game, copia);
		}
		return null;
	}

	public int getLifes(){
		return life;
	}
}

