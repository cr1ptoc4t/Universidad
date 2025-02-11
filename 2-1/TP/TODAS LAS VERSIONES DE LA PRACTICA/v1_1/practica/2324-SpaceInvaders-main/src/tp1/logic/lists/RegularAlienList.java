package tp1.logic.lists;

import tp1.logic.Game;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.logic.gameobjects.RegularAlien;
import tp1.logic.gameobjects.UCMLaser;

/**
 * Container of regular aliens, implemented as an array with a counter
 * It is in charge of forwarding petitions from the game to each regular alien
 * 
 */
public class RegularAlienList {

	private RegularAlien[] objects;
	private int num;

	private Move dir=Move.LEFT;
	
	//TODO fill your code
	public RegularAlienList(int num) {
		this.num = num;
		objects = new RegularAlien[num];
	}

	public int getNum(){
		return num;
	}

	public void initializeAlienList(int row){
		int columna= Game.DIM_X/2 - num/2;
		for(int i=0;i<num;i++){
			objects[i]= new RegularAlien(columna, row);
			columna++;
		}
	}

	// @returns si un alien del array esta en posicion -> true
	// @else -> false
	public boolean anAlienInPosition(Position pos){
		int i= 0;

		while(i<num && !objects[i].isInPosition(pos))
			i++;

		return i!=num;
	}

	public void automaticMove(){
		if(objects[0].isInBorderLeft()){
			dir=Move.DOWN;
			performGroupMovement();
			dir= Move.RIGHT;
			//this.automaticMove(Move.DOWN);
		}else if(objects[num-1].isInBorderRight()){
			dir=Move.DOWN;
			performGroupMovement();
			dir=Move.LEFT;
		}
		performGroupMovement();
	}

	private void performGroupMovement(){
		for(int i=0; i<num;i++){
			objects[i].performMovement(dir);
		}
	}
	public boolean onBorder() {
		return objects[0].isInBorderLeft() || objects[num-1].isInBorderRight();
	}
	public void eliminaAlien(int i){
		objects[i]=null;
		num--;

		//acordarse de hacer lo de los bordes
		//if(i==0)
	}
}
