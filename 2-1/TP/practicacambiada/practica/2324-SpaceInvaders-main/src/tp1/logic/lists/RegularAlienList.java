package tp1.logic.lists;
import tp1.logic.*;
import tp1.logic.gameobjects.RegularAlien;
import tp1.logic.gameobjects.UCMLaser;
import tp1.view.Messages;

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
	private boolean descent;
	//TODO fill your code
	public RegularAlienList(Level level, int num) {
		this.num = num;
		objects = new RegularAlien[num];

	}
	public int getNum(){
		return num;
	}

	public void initializeAlienList(){
		int num2 = 0;
		//esto hay que cambiarlo para que dependa de la constante ALIENS_INI

		for(int row=2;row<4;row++){ //ROWS
			for(int col=3;col<7;col++){//cols
				objects[num2] = new RegularAlien(new Position(col, row), level);
				num2++;
			}
		}


		/*
		for(int col=0;col<num;col++){//cols
			objects[num2] = new RegularAlien(new Position(col, 2), level);
			num2++;
		}
		*/

	}

	/**
	 * @returns un alien del array esta en posicion -> indice
	 * @else -> -1
	 */
	//esto es una cerdada
	public int indiceEnPos(Position pos){
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
/*
		for(int i=num-2; i>indice;i--){
			objects[i]=objects[i+1];
		}


 */
		if(indice!=-1)
			for(int i=indice;i<num-1;i++)
				objects[i]=objects[i+1];

		num--;
	}

	public int recibeAtaque(UCMLaser laser){
		int i=0;

		while (i<num && !objects[i].receiveAttack(laser))
			i++;

		if (i==num) i=-1;
		else if(laser==null){
			eliminar(i);
		}

		return i;
	}


	public String getSymbol(Position pos){
		//esto es otra cerdada
		return  " "+ Messages.REGULAR_ALIEN_SYMBOL +"[" + objects[indiceEnPos(pos)].vida() +"]";
	}

	public String lista(){
		StringBuilder buffer = new StringBuilder();

		for(int i=0;i<num;i++){
			buffer.append("\n").
					append(Messages.alienDescription(Messages.REGULAR_ALIEN_DESCRIPTION, objects[i].vida(), 0, 2));
		}


		return buffer.toString();
	}

	public void shockWave(){
		for(int i=0;i<num;i++){
			//eliminar 1 punto de vida al objects[i]


			if(objects[i].vida()==0){
				eliminar(i);
			}
		}

	}

}
