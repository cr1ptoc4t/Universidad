package tp1.logic.lists;
import tp1.logic.*;
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

	private Level level;

	//TODO fill your code
	public RegularAlienList(Level level, int num) {
		this.num = num;
		objects = new RegularAlien[num];

	}

	public int getNum(){
		return num;
	}

	public void initializeAlienList(){
		int num = 0;
		//esto hay que cambiarlo para que dependa de la constante ALIENS_INI
		for(int row=2;row<4;row++){ //ROWS
			for(int col=3;col<7;col++){//cols
				objects[num] = new RegularAlien(col, row, level);
				num++;
			}

		}

		/*
		for(int i=0; i<2;i++)
		for(int j=0;j<num;j++){
			objects[i]= new RegularAlien(columna, row, level);

		}
		*/

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

	public void eliminar(int indice){

		for(int i=num-1; i>indice;i--){
			objects[i-1]=objects[i];
		}

		num--;
	}

	public int recibeAtaque(UCMLaser laser){
		int i=0;

		while (i<num &&laser!=null&& !objects[i].receiveAttack(laser))
			i++;

		if (i==num) i=-1;
		else if(laser==null){
			eliminar(i);
		}
		return i;
	}
	public int vidaEnPos(Position pos){
		int i=0;
		while(i<num && !objects[i].isInPosition(pos))i++;

		if(i==num) return 0;
		return objects[i].vida();
	}

}
