package tp1.logic;


import tp1.control.InitialConfiguration;

//ESTA SE USA PARA CONTROLLER
public interface GameModel {
    public boolean isFinished();
    public String infoToString();
    public boolean move(Move move);
    public boolean shootLaser();
    public void reset(InitialConfiguration conf);
    public void exit();

    public void updatePlayer(Move move);

    public void update();

    public void shockWave();

    public void superLaser();

    public boolean shootSuperLaser();

    String lista();
}
