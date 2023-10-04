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
		this.row=row;
	}
	//TODO fill your code
	public int getX() {
		return col;
	}
	
	public int getY() {
		return row;
	}
	
	public void setX(int x) {
		col=x;
	}
	
	public void setY(int y) {
		row=y;
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
}
