package tp1.view;

import tp1.logic.GameStatus;

public abstract class GamePrinter {
	
	protected GameStatus game;
	
	public GamePrinter(GameStatus game) {
		this.game = game;
	}

	public abstract String endMessage();
	
}
