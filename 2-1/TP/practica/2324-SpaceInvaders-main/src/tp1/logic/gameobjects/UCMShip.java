import tp1.logic.*;
import tp1.view.Messages;
public class UCMShip{
	private Position pos;

	public UCMShip(){
		this.pos = new Position(Game.DIM_X/2, Game.DIM_Y/2);
	}

	public String getSymbol(){
		return Messages.UCMSHIP_SYMBOL;
	}

	public boolean estaEnPos(Position position){
		return this.pos == position; 
	}

}