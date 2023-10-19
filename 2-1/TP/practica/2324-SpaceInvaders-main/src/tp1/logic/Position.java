package tp1.logic;

import java.util.Objects;
/**
 * 
 * Immutable class to encapsulate and manipulate positions in the game board
 * 
 */
public class Position {

	private int col;
	private int row;
	
	public Position(int col, int row) {
		this.col = col;
		this.row = row;
	}
	//TODO fill your code
	
	private int getCol() {
		return col;
	}
	
	private int getRow() {
		return row;
	}
	
	@Override
	public int hashCode() {
		return Objects.hash(col, row);
	}
	@Override
	public boolean equals(Object obj) {
		boolean b;
		if (this == obj)
			b=true;
		if (obj == null || getClass() != obj.getClass())
			b=false;
		else {
			Position other = (Position) obj;		 //conversion explicita
			b = col == other.col && row == other.row;
		}
		return b;
	}
	
	public boolean esPosicionValida() {
		return Game.DIM_X>getCol() && getCol()>0 && getRow()>0 && getRow()<Game.DIM_Y;
	}
	
	public void actualiza(Move mov) {
		col = col + mov.getX(); 
		row = row + mov.getY();
	}
}
