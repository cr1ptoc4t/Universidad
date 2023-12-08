package tp1.logic;

import tp1.logic.gameobjects.DestroyerAlien;
import tp1.logic.gameobjects.RegularAlien;
import tp1.logic.gameobjects.Ufo;
public class AlienManager  {
	
	private Game game;
	//private int remainingAliens;
	private boolean ufoEnabled=false;

	private boolean onBorder =false;


	public AlienManager(Game game){
		this.game=game;
	}


	public  GameObjectContainer initialize() {

		GameObjectContainer container = new GameObjectContainer();
		initializeOvni(container);
		Level level =game.getLevel();
		initializeRegularAliens(container, level);
		initializeDestroyerAliens(container, level);
		//remainingAliens = game.getLevel().getNumRegularAliens() +
		//		game.getLevel().getNumDestroyerAliens();

		return container;
	}
	
	public void initializeOvni(GameObjectContainer container) {

		if(canGenerateRandomUfo() && !ufoEnabled) {
			container.add(new Ufo(game));
			ufoEnabled=true;
		}
	}


	private void initializeRegularAliens (GameObjectContainer container, Level level) {
		int nReg = game.getLevel().getNumRegularAliens();

		if(game.getLevel().equals(Level.EASY))
			for(int i=0; i<nReg;i++)
				container.add(new RegularAlien(game,  new Position(i+3, 2),this));

		else
			for(int row=0; row<nReg/4;row++)
				for(int col=0; col<nReg/2; col++)
					container.add(new RegularAlien(game,new Position(col+3, row+2), this));

	}

	private void initializeDestroyerAliens(GameObjectContainer container, Level level) {

		int num = level.getNumDestroyerAliens();
		if(level.equals(Level.EASY))
			for(int i=0; i<num;i++)
				container.add(new DestroyerAlien(game, new Position(i+4, 3), this ));

		else if (level.equals(Level.HARD))
			for(int i=0; i<num;i++)
				container.add(new DestroyerAlien(game, new Position(i+4, 4), this ));

			else
			for(int i=0; i<num;i++)
				container.add(new DestroyerAlien(game, new Position(i+3, 4), this ));

	}

	//TODO fill with your code
	private boolean canGenerateRandomUfo(){
		return game.rnd.nextDouble() < game.getLevel().getUfoFrequency();
	}


	public boolean someoneOnLowerBorder() {
		return false;
	}

	public void disenableUfo(){
		ufoEnabled=false;
	}

	public boolean onBorder(){
		return onBorder;
	}

	public boolean bajar(){
		if(onBorder()){
			onBorder=false;
			return true;
		}
		return false;
	}

	public void setOnBorder(){
		this.onBorder=true;
	}
}
