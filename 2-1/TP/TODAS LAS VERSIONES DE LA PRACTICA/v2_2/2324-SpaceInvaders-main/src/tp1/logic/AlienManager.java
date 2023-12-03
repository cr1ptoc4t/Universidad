package tp1.logic;

import tp1.logic.gameobjects.DestroyerAlien;
import tp1.logic.gameobjects.RegularAlien;
import tp1.logic.gameobjects.Ufo;
public class AlienManager  {
	
	private Game game;
	private int remainingAliens;
	private Ufo ufo;

	private int nAliensReg = 3;
	//TODO fill with your code
	public AlienManager(Game game){
		this.game=game;
	}


	public  GameObjectContainer initialize() {
		this.remainingAliens = 0;
		GameObjectContainer container = new GameObjectContainer();
		initializeOvni(container);
		initializeRegularAliens(container);
		initializeDestroyerAliens(container);

		
		//TODO fill with your code
		
		
		return container;
	}
	
	private void initializeOvni(GameObjectContainer container) {
		if(canGenerateRandomUfo() /*o el ufo esta en !posicionvalida*/)
			container.add(new Ufo(game));
	}
	
	private void initializeRegularAliens (GameObjectContainer container) {

		for(int i=0; i<game.getLevel().getNumRegularAliens();i++)
			container.add(new RegularAlien(game, new Position(i, 1)));

		remainingAliens+=game.getLevel().getNumRegularAliens();
	}
	
	private void initializeDestroyerAliens(GameObjectContainer container) {
		for(int i=0; i<game.getLevel().getNumDestroyerAliens();i++)
			container.add(new DestroyerAlien(game, new Position(i, 2), this ));
		remainingAliens+=game.getLevel().getNumDestroyerAliens();

	}

	//TODO fill with your code
	private boolean canGenerateRandomUfo(){
		return game.rnd.nextDouble() < game.getLevel().getUfoFrequency();
	}
}
