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
		remainingAliens+=game.getLevel().getNumRegularAliens() +game.getLevel().getNumDestroyerAliens();

		
		//TODO fill with your code
		
		
		return container;
	}
	
	public void initializeOvni(GameObjectContainer container) {
		if(canGenerateRandomUfo() /*o el ufo esta en !posicionvalida*/)
			container.add(new Ufo(game));
	}

	private void initializeRegularAliens (GameObjectContainer container) {
		int nReg = game.getLevel().getNumRegularAliens();

		if(game.getLevel().equals(Level.EASY))
			for(int i=0; i<nReg;i++)
				container.add(new RegularAlien(game, new Position(i+3, 2)));

		else
			for(int row=0; row<nReg/4;row++)
				for(int col=0; col<nReg/2; col++)
					container.add(new RegularAlien(game, new Position(col+3, row+2)));

	}

	/*
	public void inicializa() {
        if (level == Level.EASY){
            //empieza en 3,3
            num = 2;
            for (int i =0; i < num; i++) {
                objects[i] = new DestroyerAlien(game,new Position(i+4, 3), level);
            }
        } else if(level== Level.HARD){
            num = 2;
            for (int i =0; i < num; i++) {
                objects[i] = new DestroyerAlien(game,new Position(i+4, 4), level);
            }
        } else if (level == Level.INSANE) {
            num = 4;
            for (int i =0; i < num; i++) {
                objects[i] = new DestroyerAlien(game, new Position(i+3, 4), level);
            }
        }
    }

	 */
	
	private void initializeDestroyerAliens(GameObjectContainer container) {
		if(game.getLevel().equals(Level.EASY))
			for(int i=0; i<game.getLevel().getNumDestroyerAliens();i++)
				container.add(new DestroyerAlien(game, new Position(i+4, 3), this ));
		else if (game.getLevel().equals(Level.HARD))
			for(int i=0; i<game.getLevel().getNumDestroyerAliens();i++)
				container.add(new DestroyerAlien(game, new Position(i+4, 4), this ));
		else
			for(int i=0; i<game.getLevel().getNumDestroyerAliens();i++)
				container.add(new DestroyerAlien(game, new Position(i+3, 4), this ));

	}

	//TODO fill with your code
	private boolean canGenerateRandomUfo(){
		return game.rnd.nextDouble() < game.getLevel().getUfoFrequency();
	}
	public boolean someoneOnLowerBorder(){
		int i=0;
		//while(i<)
		//mirar si hay algun alien en la ultima fila
		//busqueda
		return false;
	}
}
