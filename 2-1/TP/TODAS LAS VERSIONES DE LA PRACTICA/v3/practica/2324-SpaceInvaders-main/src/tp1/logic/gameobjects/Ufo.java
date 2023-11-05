package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;


public class Ufo {

	//TODO fill your code
	public final int UFO_X=8;
	public final int UFO_Y=0;

	private boolean enabled;
	private Game game;

	private Position pos;
	//TODO fill your code
	private int points;

	public static final int damage=0;
	public static final int endurance = 1;

	public static final int value = 25;
	private Move mov;

	public Ufo(Game game){
		this.game=game;
		this.pos=new Position(UFO_X,UFO_Y);
		points=1;
		this.mov=Move.LEFT;
		enabled=false;
	}

	public void computerAction() {
		if(!enabled && canGenerateRandomUfo()) {
			enable();
		}
	}

	public boolean isEnabled(){
		return enabled;
	}

	public void movimientoAutomatico(){
		//aqui hay que considerar los bordes
		if(pos.isInBorderRight())
			mov=Move.LEFT;
		else if (pos.isInBorderLeft())
			mov=Move.RIGHT;

		pos.actualiza(mov);
	}
	
	private void enable() {
		enabled=true;

		
	}

	public void onDelete() {
		//TODO fill your code
		enabled=false;
		pos=new Position(UFO_X, UFO_Y);
		mov= Move.LEFT;
	}

	/**
	 * Checks if the game should generate an ufo.
	 * 
	 * @return <code>true</code> if an ufo should be generated.
	 */
	private boolean canGenerateRandomUfo(){
		return game.getRandom().nextDouble() < game.getLevel().getUfoFrequency();
	}

	public boolean isInPos(Position pos){
		return pos.equals(this.pos);
	}

	public String getSymbol(){
		return Messages.UFO_SYMBOL+"["+points+"]";
	}

	public String lista(){

		StringBuilder buffer = new StringBuilder();

		buffer.append("\n")
				.append(Messages.UFO_DESCRIPTION)
				.append(": points: '").append(value)
				.append("', damage: '").append(damage)
				.append("', endurance: '").append(endurance).append("'");

		return buffer.toString();
	}


	public boolean receiveAttack(UCMLaser laser){

		return laser.isInPos(this.pos);
	}



}
