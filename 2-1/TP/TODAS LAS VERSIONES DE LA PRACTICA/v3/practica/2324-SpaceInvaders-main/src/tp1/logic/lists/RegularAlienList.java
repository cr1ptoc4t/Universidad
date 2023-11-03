package tp1.logic.lists;
import tp1.logic.*;
import tp1.logic.gameobjects.RegularAlien;
import tp1.logic.gameobjects.UCMLaser;
import tp1.view.Messages;
import tp1.logic.Level;

/**
 * Container of regular aliens, implemented as an array with a counter
 * It is in charge of forwarding petitions from the game to each regular alien
 * 
 */
public class RegularAlienList {


	private RegularAlien[] objects;
	private int num;

	private Move dir=Move.LEFT;
	private Move direccionOp;
	private Level level;
	private boolean descent;
	private Game game;
	private int nCiclos;
	private int wait;
	public RegularAlienList(Game game,Level level, int num){
		this.game =game;
		this.level = level;
		this.num=num;
		objects = new RegularAlien[num];
		wait=waitUntil();
	}

	public void addAlien(RegularAlien alien){
		objects[num++]=alien;
	}
	public void initializeAlienList(){


		// TODO: esto es una cerdada

		if(num==4) {
			for (int i=0; i < num;i++){
				objects[i] = new RegularAlien(game, new Position(i+3, 2), level);
			}
		} else if(num==8) {
			int num2 = 0;
			for (int row = 0; row <  num/4 ; row++) {
				for (int col = 0; col <  num/ 2; col++) {
					objects[num2] = new RegularAlien(game, new Position(col+3, row+2), level);
					num2++;
				}
			}



		}

		/*
		if(num==4)
			for(int i=0;i<4;i++){
				objects[num2] = new RegularAlien(new Position(i, 2), level);
				num2++;
			}
		 */

		/*
		for(int row=1;row<2;row++){ //ROWS
			for(int col=4;col<7;col++){//cols
				objects[num2] = new RegularAlien(new Position(col, row), level);
				num2++;
			}
		}

		 */
	}

	/**
	 * @returns un alien del array esta en posicion -> indice
	 * @else -> -1
	 */

	private int indiceEnPos(Position pos){
		int i= 0;

		while(i<num && !objects[i].isInPosition(pos))
			i++;

		if(i==num) i=-1;

		return i;
	}

	public RegularAlien alienInPosition(Position pos){
		int i = indiceEnPos(pos);

		if(i==-1) return null;

		return objects[i];
	}

	public void automaticMove(boolean onBorder){
		//tema bordes!!
		if(num>0 && nCiclos%wait==0) {
			if (onBorder && descent == false) {
				direccionOp = dir.opuesto();
				dir = Move.DOWN;
				descent = true;
			} else if (descent) {
				dir = direccionOp;
				descent = false;
			}

			performGroupMovement();
		}
		nCiclos++;
	}

	private int waitUntil(){
		int ret=1;

		switch(level){
			case EASY:
				ret=3;
				break;
			case HARD:
				ret=2;
				break;
		}

		return ret;
	}

	private void performGroupMovement(){
		for(int i=0; i<num;i++){
			objects[i].performMovement(dir);
		}
	}

	public boolean onBorder() {
		boolean b=false;
		if(num>0)
			b=objects[0].isInBorderLeft() || objects[num-1].isInBorderRight();

		return b;
	}

	public void eliminar(int indice){
		if(indice!=-1) {
			for (int i = indice; i < num - 1; i++)
				objects[i] = objects[i + 1];
			num--;
		}
	}

	public int recibeAtaque(UCMLaser laser){
		int i=0;

		while (i<num && !objects[i].receiveAttack(laser))
			i++;

		if (i==num) i=-1;
		else {
			eliminar(i);
		}

		return i;
	}


	public String lista(){
		StringBuilder buffer = new StringBuilder();

		buffer.append("\n")
				.append(Messages.REGULAR_ALIEN_DESCRIPTION)
				.append(": points: '").append(RegularAlien.value)
				.append("', damage: '").append(RegularAlien.damage)
				.append("', endurance: '").append(RegularAlien.endurance).append("'");

		return buffer.toString();
	}

	public void shockWave(){
		int n_aux = num;
		int i =0;

		while(i<n_aux){
			if(objects[i].shockWave()){
				eliminar(i);
				// aqui no incrementamos porque cada valor pasa una casilla para la izquierda
				// en vez de mover el indice se mueven las casillas
			} else {
				i++;
			}

		}


		//aqui habria que chequear que elementos tienen 0 de vida y eliminarlos

	}

	public boolean alienInLowerBorder(){
		int i=0;
		while(i<num &&!objects[i].isInLowerBorder()) i++;
		return i!=num;
	}

}
