package tp1.logic.gameobjects;
import tp1.logic.*;
import tp1.view.Messages;

public class UCMShip{
	
	private Position pos;
	private boolean onBorder;
	int life;
	public UCMShip(){
		this.pos = new Position(Game.DIM_X/2, Game.DIM_Y/2);
		this.life=100;
	}

	public String getSymbol(){
		String symbol=Messages.UCMSHIP_SYMBOL;
		if(life<0){
			symbol=Messages.UCMSHIP_DEAD_SYMBOL;
		}
		return symbol;
	}

	public boolean estaEnPos(Position position){
		return this.pos.equals(position); 
	}
	
	public void mueve(Move movimiento) {
		
		//nueva variable para mover
		Position posicionActualizada = pos;
		
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
	
	private boolean onBorder0() {
		return pos.equals(new Position(0, Game.DIM_Y/2));
	}
	private boolean onBorderX() {
		return pos.equals(new Position(Game.DIM_X-1, Game.DIM_Y/2)) ;
	}

	void recibeAtaque(){
		life-=10;
	}
}
