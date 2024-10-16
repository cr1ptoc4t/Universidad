package tp1.logic;

//import tp1.logic.gameobjects.DestroyerAlien;
import tp1.logic.gameobjects.DestroyerAlien;
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

	public final int ALIENS_INI =8;
	private Level level;
	private Game game;
	private int remainingAliens;
	private boolean squadInFinalRow;
	private int shipsOnBorder;
	private boolean onBorder;

	private boolean descent;
	private Move dir;
	private Move direccionOp; //esto no está bien

	int numRegular,numDestroyer;
	private static RegularAlienList regularAliens;
	private DestroyerAlienList destroyerAliens;

	public AlienManager(Game game, Level level) {
		this.level = level;
		this.game = game;
		descent=false;
		this.dir= Move.LEFT;
		decideNumAliens();
	}

	private void decideNumAliens(){
		switch (level){
			case EASY:
			{

				numRegular=4;
				numDestroyer=2;
				break;
			}
			case HARD:
			{
				numRegular=8;
				numDestroyer=2;
				break;
			}
			case INSANE:
			{
				numRegular = 8;
				numDestroyer = 4;
			}
		}
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

		RegularAlienList lista = new RegularAlienList(numRegular);
		lista.initializeAlienList();

		return lista;
	}

	/**
	 * Initializes the list of destroyer aliens
	 * @return the initial list of destroyer aliens according to the current level
	 */
    protected  DestroyerAlienList initializeDestroyerAliens() {
		//		TODO fill your code
		DestroyerAlienList lista = new DestroyerAlienList(game, numDestroyer, level);
		lista.inicializa();
		return lista;
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
		return regularAliens.indiceEnPos(pos)!=-1;	//	esto ns si es un poco 1 mierda porque
													//	vamos alien por alien a preguntarle la posición
	}

	public int getRemainingAliens(){
		return remainingAliens;
	}


	//esro no deberia ir aqui
	private void regularAutomaticMove(){
		if(regularAliens.onBorder() && descent==false){
			direccionOp = dir.opuesto();
			dir = Move.DOWN;
			descent=true;
		} else if(descent){
			dir = direccionOp;
			descent=false;
		}

		regularAliens.performGroupMovement(dir);
		//destroyerAliens.performGroupMovement();
	}

	//esto tampoco deberia ir aqui
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
			//lo de la posición es una guarrada, pero esq ahora mismo ns como hacerlo y necesito ver
			//hay que hacer que saque los puntos que tocan
			str=regularAliens.getSymbol(pos);
		} else if (type=="destroyer"){
			str = Messages.DESTROYER_ALIEN_SYMBOL;
		}
		return str;
	}

	public void eliminaAlien(int i){
		regularAliens.eliminar(i);
		remainingAliens--;
	}

	//esto tamp
	public boolean recibeAtaque(UCMLaser laser){
		int i= regularAliens.recibeAtaque(laser);

		if(i!=-1) {
			eliminaAlien(i);
		}
		//if(i!=-1&&lista[i].puntos==0) {
		//	eliminaAlien(i);
		//}

		//destroyerAliens.recibeAtaque();

		return i!=-1;
	}


	public String lista(){
		StringBuilder buffer = new StringBuilder();

		buffer.append(regularAliens.lista());//.append("\n").append(destroyerAliens.lista());

		return buffer.toString();
	}


	public void shockWave(){
		regularAliens.shockWave();

		//check puntos
			//si algún alien tiene 0 puntos -> eliminar del array

		//listaDestroyers.shockwave();
	}

}
