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

	//Duplicador de posicion
	public Position (Position posicion2){
		this.col = posicion2.col;
		this.row = posicion2.row;
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
			Position other = (Position) obj;		 //Conversion explicita
			b = col == other.col && row == other.row;
		}
		return b;
	}

	public boolean esPosicionValida() {
		return Game.DIM_X>col && col>=0
				&& row>=0 && row<=Game.DIM_Y;
	}

	public void actualiza(Move mov) {
		col = col + mov.getX();
		row = row + mov.getY();
	}
	public boolean onBorderLateral(){
		return Game.DIM_X-1==col || col==0;
	}

	public boolean annexoA(Position pos){
		return (pos.col-1==col&&pos.row-1==row ) || (pos.col==col&&pos.row-1==row) || (pos.col+1==col&&pos.row-1==row)
				||(pos.col-1==col&&pos.row==row )				|| 					 (pos.col+1==col&&pos.row==row)||
				(pos.col-1==col&&pos.row+1==row )||(pos.col==col&&pos.row+1==row)||(pos.col+1==col&&pos.row+1==row );

	}
}
