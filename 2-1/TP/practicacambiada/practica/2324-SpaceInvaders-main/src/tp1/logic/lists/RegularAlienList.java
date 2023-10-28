package tp1.logic.lists;
import tp1.logic.AlienManager;
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

	//private Move dir=Move.LEFT;

	private AlienManager alienManager;


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

	/**
	 * @returns un alien del array esta en posicion -> indice
	 * @else -> -1
	 */
	public int anAlienInPosition(Position pos){
		int i= 0;

		while(i<num && !objects[i].isInPosition(pos))
			i++;

		if(i==num) i=-1;

		return i;
	}


	public void performGroupMovement(Move dir){
		for(int i=0; i<num;i++){
			objects[i].performMovement(dir);
		}
	}
	public boolean onBorder() {
		return objects[0].isInBorderLeft() || objects[num-1].isInBorderRight();
	}
}
