package tp1.view;

import tp1.logic.Game;
import tp1.logic.GameModel;
import tp1.logic.GameStatus;

public abstract class GamePrinter {
	
	protected GameStatus game;
	//protected Game game;
	
	//public GamePrinter(GameStatus game) {
	//	this.game = game;
	//}
	public GamePrinter(GameStatus game) {
		this.game= game;
	}

	public abstract String endMessage();


	//esto lo recomendó en clase
	public static void show(String str){
		System.out.println(str);
	}

}