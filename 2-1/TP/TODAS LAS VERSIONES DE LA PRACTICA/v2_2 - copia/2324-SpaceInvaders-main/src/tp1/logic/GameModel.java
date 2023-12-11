package tp1.logic;


import tp1.control.InitialConfiguration;

public interface GameModel {
    public boolean isFinished();
    public String infoToString();

    public boolean shootLaser();
    public void reset(InitialConfiguration conf);
    public void exit();

    public void updatePlayer(Move move);

    public void update();

    public void shockWave();


    public boolean shootSuperLaser();

    public String lista();
}
