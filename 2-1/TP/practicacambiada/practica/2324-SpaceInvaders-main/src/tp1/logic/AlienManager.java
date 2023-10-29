package tp1.logic;

//import tp1.logic.gameobjects.DestroyerAlien;
import tp1.logic.gameobjects.RegularAlien;
//import tp1.logic.lists.DestroyerAlienList;
import tp1.logic.gameobjects.UCMLaser;
import tp1.logic.lists.DestroyerAlienList;
import tp1.logic.lists.RegularAlienList;
import tp1.view.Messages;

/**
 * 
 * Manages alien initialization and
 * used by aliens to coordinate movement
 *
 */
public class AlienManager {

	private final int ALIENS_INI =8;
	private Level level;
	private Game game;
	private int remainingAliens;
	private boolean squadInFinalRow;
	private int shipsOnBorder;
	private boolean onBorder;

	private Move dir;

	private static RegularAlienList regularAliens;
	private DestroyerAlienList destroyerAliens;

	public AlienManager(Game game, Level level) {
		this.level = level;
		this.game = game;
		//this.regularAliens= initializeRegularAliens();
		//this.remainingAliens= regularAliens.getNum() + destroyerAliens.getNum();
		//this.onBorder =onBorder();
		this.dir= Move.LEFT;
	}
		
	// INITIALIZER METHODS

	/**
	 * Inicializa todo
	 *
	 */

	public void initialize(){
		regularAliens= initializeRegularAliens();
		//initializeDestroyerAliens();
		this.remainingAliens= regularAliens.getNum(); //+ destroyerAliens.getNum();
	}
	
	/**
	 * Initializes the list of regular aliens
	 * @return the initial list of regular aliens according to the current level
	 */
	protected RegularAlienList initializeRegularAliens() {
		//TODO fill your code
		//remainingAliens = 3;

		RegularAlienList lista = new RegularAlienList(level,ALIENS_INI);
		lista.initializeAlienList();

		return lista;
	}

	/**
	 * Initializes the list of destroyer aliens
	 * @return the initial list of destroyer aliens according to the current level
	 */
    protected  DestroyerAlienList initializeDestroyerAliens() {
		//		TODO fill your code

		return new DestroyerAlienList(2);
	}




	// CONTROL METHODS



	public void shipOnBorder() {
		if(!onBorder) {
			onBorder = true;
			shipsOnBorder = remainingAliens;
		}
	}

	public boolean onBorder() {
		// TODO Auto-generated method stub
		//return aliens.onBorder();
		return false;
	}


	public void automaticMove(){
		regularAutomaticMove();
		destroyerAutomaticMove();
	}
	public boolean regularAlienIsInPosition(Position pos){
		return regularAliens.anAlienInPosition(pos)!=-1; //esto ns si es un poco 1 mierda porque vamos alien por alien a preguntarle la pos
	}

	public int getRemainingAliens(){
		return remainingAliens;
	}
	private void regularAutomaticMove(){

		if(regularAliens.onBorder() /*|| destroyerAliens.onBorder() */ ){
			Move dirOpuesta = dir.opuesto();

			//bajar
			dir=Move.DOWN;
			regularAliens.performGroupMovement(dir);
			//destroyerAliens.performGroupMovement(dir);

			dir=dirOpuesta;

		}

		regularAliens.performGroupMovement(dir);
		//destroyerAliens.performGroupMovement();

	}
	private void destroyerAutomaticMove(){
		/*
		if(destroyerAliens.onBorder() /*|| destroyerAliens.onBorder() * ){
			Move dirOpuesta = dir.opuesto();

			//bajar
			dir=Move.DOWN;
			destroyerAliens.performGroupMovement(dir);
			//destroyerAliens.performGroupMovement(dir);

			dir=dirOpuesta;

		}
		*/
		/*
		if(aliens[0].isInBorderLeft()){
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

		 */
	}
	public static String getSymbol(String type, Position pos){
		String str=" ";
		if(type=="regular"){
			//lo de la posicion es una guarrada pero esq ahora mismo ns como debugear
			//hay q hacer que saque los puntos que tocan
			str= " "+Messages.REGULAR_ALIEN_SYMBOL +"[" + regularAliens.vidaEnPos(pos) +"]";

		} else if (type=="destroyer"){
			str = Messages.DESTROYER_ALIEN_SYMBOL;
		}
		return str;
	}

	public void eliminaAlien(int i){
		regularAliens.eliminar(i);
		remainingAliens--;
	}

	public void recibeAtaque(UCMLaser laser){
		int i= regularAliens.recibeAtaque(laser);

		if(i!=-1) {
			//remainingAliens--;
			laser.die();
		}
		//if(i!=-1&&lista[i].puntos==0) {
		//	eliminaAlien(i);
		//}

		//destroyerAliens.recibeAtaque();
	}
}
