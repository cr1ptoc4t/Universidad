package tp1.logic;

import tp1.control.InitialConfiguration;
import tp1.logic.gameobjects.*;
import tp1.view.Messages;

import java.util.List;

public class AlienManager  {
	
	private Game game;
	private boolean ufoEnabled=false;
	private boolean onBorder =false;
	public AlienManager(Game game){
		this.game=game;
	}

	private Move dir;
	private Move direccionOp;
	private boolean bajado;

	public  GameObjectContainer initialize(InitialConfiguration conf) {

		GameObjectContainer container = new GameObjectContainer();
		initializeOvni(container);
		Level level = game.getLevel();
		bajado=false;
		dir=Move.LEFT;
		if(conf.equals(InitialConfiguration.NONE)) {
			initializeRegularAliens(container, level, conf);
			initializeDestroyerAliens(container, level, conf);
			//container.add(new ExplosiveAlien(game,new Position(3,4),this));
		} else
			conf.initContainer(container, game, this);

		return container;
	}

	public AlienShip spawn(String type, int x, int y){
		return ShipFactory.spawnAlienShip(type,game,new Position(x, y),this);
	}


	public void initializeOvni(GameObjectContainer container) {

		if(canGenerateRandomUfo() && !ufoEnabled) {
			container.add(new Ufo(game));
			ufoEnabled=true;
		}
	}


	private void initializeRegularAliens (GameObjectContainer container, Level level, InitialConfiguration conf) {

		int nReg = game.getLevel().getNumRegularAliens();

		if(game.getLevel().equals(Level.EASY))
			for(int i=0; i<nReg;i++)
				container.add(ShipFactory.spawnAlienShip("R", game, new Position(i+3,1), this));

		else
			for(int row=0; row<nReg/4;row++)
				for(int col=0; col<nReg/2; col++)
					container.add(ShipFactory.spawnAlienShip("R", game, new Position(col+3,row+2), this));

	}

	private void initializeDestroyerAliens(GameObjectContainer container, Level level, InitialConfiguration conf) {

		int num = level.getNumDestroyerAliens();
		if (level.equals(Level.EASY))
			for (int i = 0; i < num; i++) {
				container.add(ShipFactory.spawnAlienShip("D", game, new Position(i + 4, 2), this));
			}
		else if (level.equals(Level.HARD))
			for (int i = 0; i < num; i++)
				container.add(ShipFactory.spawnAlienShip("D", game, new Position(i + 4, 4), this));

		else
			for (int i = 0; i < num; i++)
				container.add(ShipFactory.spawnAlienShip("D", game, new Position(i + 3, 4), this));



	}

	//TODO fill with your code
	private boolean canGenerateRandomUfo(){
		return game.rnd.nextDouble() < game.getLevel().getUfoFrequency();
	}





	public void disenableUfo(){
		ufoEnabled=false;
	}

	public boolean onBorder(){
		return onBorder;
	}


	public void setOnBorder(){
		this.onBorder=true;
	}
	public void setOnBorderFalse(){
		this.onBorder=false;
	}

	public String lista(){
		String buffer = UCMShip.lista() + "\n" +
				RegularAlien.lista() + "\n"+
				DestroyerAlien.lista() + "\n" +
				Ufo.lista() + "\n"+
				ExplosiveAlien.lista();

		return buffer;


	}

}
