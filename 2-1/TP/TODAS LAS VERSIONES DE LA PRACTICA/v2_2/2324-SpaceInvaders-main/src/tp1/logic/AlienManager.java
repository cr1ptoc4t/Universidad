package tp1.logic;

import tp1.logic.gameobjects.RegularAlien;

public class AlienManager  {
	
	private Game game;
	private int remainingAliens;
	
	//TODO fill with your code

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
		//container.add(new Ufo(game));
	}
	
	private void initializeRegularAliens (GameObjectContainer container) {

		//TODO fill with your code
		//		container.add(new RegularAlien(....));
	}
	
	private void initializeDestroyerAliens(GameObjectContainer container) {
		//TODO fill with your code
	}

	//TODO fill with your code


}
