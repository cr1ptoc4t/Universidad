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
	private final Level level;
	private final Game game;
	private final int remainingAliens;
	private boolean squadInFinalRow;

	private final boolean descent;
	private final Move dir;


	int numRegular,numDestroyer;

	public AlienManager(Game game, Level level) {
		this.level = level;
		this.game = game;
		descent = false;
		this.dir= Move.LEFT;
		remainingAliens=decideNumAliens();
	}



	/**
	 * Initializes the list of regular aliens
	 * @return the initial list of regular aliens according to the current level
	 */
	protected RegularAlienList initializeRegularAliens() {
		//TODO fill your code
		//remainingAliens = numDestroyer+numRegular;
		RegularAlienList lista = new RegularAlienList(game,level,numRegular);
		lista.initializeAlienList();

		return lista;
	}

	/**
	 * Initializes the list of destroyer aliens
	 * @return the initial list of destroyer aliens according to the current level
	 */
	protected DestroyerAlienList initializeDestroyerAliens() {
		//		TODO fill your code
		DestroyerAlienList lista = new DestroyerAlienList(game, numDestroyer, level);
		lista.inicializa();
		return lista;
	}



	public int decideNumAliens(){
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
		return numRegular + numDestroyer;
	}
}
