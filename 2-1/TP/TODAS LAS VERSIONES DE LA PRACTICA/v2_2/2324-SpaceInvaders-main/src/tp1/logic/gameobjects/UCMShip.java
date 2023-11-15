package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;

public class UCMShip {

	//TODO fill with your code
	private Game game;
	private Position pos;

	private int vida=3;
	Move dir;

	public UCMShip(Game game, Position position) {
		//TODO fill with your code
		this.game=game;
		this.pos =position;
		this.dir=Move.NONE;
	}
	
	//TODO fill with your code


	public String getSymbol(){
		String symbol=Messages.UCMSHIP_SYMBOL;
		if(vida<0){
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
		if(weapon.isInPos(this.pos)){
			vida--;
		}
		return weapon.isInPos(this.pos);
	}

	public UCMWeapon creaLaser(){
		Position copia = new Position(pos);
		return new UCMWeapon(game, copia);
	}
}

