package tp1.logic;

//import tp1.logic.gameobjects.DestroyerAlien;
import tp1.logic.gameobjects.RegularAlien;
//import tp1.logic.lists.DestroyerAlienList;
import tp1.logic.lists.RegularAlienList;
import tp1.view.Messages;

/**
 * 
 * Manages alien initialization and
 * used by aliens to coordinate movement
 *
 */
public class AlienManager {
	
	private Level level;
	private Game game;
	private int remainingAliens;
	private boolean squadInFinalRow;
	private int shipsOnBorder;
	private boolean onBorder;
	//private regularAlienList listaAliensRegulares;
	//private destroyerAlienList listaAliensDestroyers;
	private boolean descender;
	private Move dir;

	public RegularAlienList aliens;


	public AlienManager(Game game, Level level) {
		this.level = level;
		this.game = game;
		this.aliens= initializeRegularAliens();
		this.remainingAliens= aliens.getNum(); //+ destroyers.getCont();
		this.onBorder =onBorder();
		this.descender= false;
		this.dir= Move.LEFT;
	}
		
	// INITIALIZER METHODS
	
	/**
	 * Initializes the list of regular aliens
	 * @return the initial list of regular aliens according to the current level
	 */
	protected RegularAlienList initializeRegularAliens() {
		//TODO fill your code

		remainingAliens = 3;

		RegularAlienList lista = new RegularAlienList(remainingAliens);
		lista.initializeAlienList(1);

		return lista;
	}

	/**
	 * Initializes the list of destroyer aliens
	 * @return the initial list of destroyer aliens according to the current level
	 */
//	protected  DestroyerAlienList initializeDestroyerAliens() {
//		//TODO fill your code
//	}

	
	// CONTROL METHODS
		
	public void shipOnBorder() {
		if(!onBorder) {
			onBorder = true;
			shipsOnBorder = remainingAliens;
		}
	}

	public boolean onBorder() {
		// TODO Auto-generated method stub
		return aliens.onBorder();
	}


	public void automaticMove(){
		aliens.automaticMove();
		//destroyers.automaticMove();

	}
	public boolean regularAlienisInPosition(Position pos){
		return aliens.anAlienInPosition(pos);
	}

	public int getRemainingAliens(){
		return remainingAliens;
	}
	private void actualizaAliens(){
	}

	public String simbolosAliens(int i){
		return "vida";
	}
	public void eliminaAlien(int i){

		aliens.eliminaAlien(i);
	}

	public String getSymbol(){
		return Messages.REGULAR_ALIEN_SYMBOL;
	}
}
