package tp1.logic.gameobjects;
import tp1.logic.*;
import tp1.view.Messages;

public class UCMShip{
	
	private Position pos;
	private boolean onBorder;
	public UCMShip(){
		this.pos = new Position(Game.DIM_X/2, Game.DIM_Y/2);
	}

	public String getSymbol(){
		return Messages.UCMSHIP_SYMBOL;
	}

	public boolean estaEnPos(Position position){
		return this.pos.equals(position); 
	}
	
	public void mueve(Move movimiento) {
		//Move movimiento = new Move(0,0);
		
		//nueva variable ya movida
		Position posicionActualizada= pos;
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
		return pos.equals(new Position(Game.DIM_X, Game.DIM_Y/2)) ;
	}

}