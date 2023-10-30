package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.Move;
import tp1.logic.Position;


public class Ufo {

	//TODO fill your code

	private boolean enabled;
	private Game game;

	private Position pos;
	//TODO fill your code

	public Ufo(Game game,Position pos){
		this.game=game;
		this.pos=pos;
	}

	public void computerAction() {
		if(!enabled && canGenerateRandomUfo()) {
			enable();
		}
	}
	
	private void enable() {
		//TODO fill your code
		enabled=true;
		
	}

	public void onDelete() {
		//TODO fill your code
	}

	/**
	 * Checks if the game should generate an ufo.
	 * 
	 * @return <code>true</code> if an ufo should be generated.
	 */
	private boolean canGenerateRandomUfo(){
		return game.getRandom().nextDouble() < game.getLevel().getUfoFrequency();
	}
	
}
