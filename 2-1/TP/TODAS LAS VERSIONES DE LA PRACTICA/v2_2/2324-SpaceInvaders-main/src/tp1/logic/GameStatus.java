package tp1.logic;

public interface GameStatus {
	//PARA GAMEPRINTER

	public String positionToString(int col, int row);

	public String stateToString();

	public boolean playerWin();
	public boolean aliensWin();

	public int getCycle();
	public int getRemainingAliens();

}
