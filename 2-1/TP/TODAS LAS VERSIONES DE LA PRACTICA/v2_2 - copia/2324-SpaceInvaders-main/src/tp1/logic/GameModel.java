package tp1.logic;


import tp1.control.InitialConfiguration;
import tp1.exceptions.LaserInFlightException;
import tp1.exceptions.NotEnoughtPointsException;

public interface GameModel {
    public boolean isFinished();
    public String infoToString();

    public boolean shootLaser();
    public void reset(InitialConfiguration conf);
    public void exit();

    public void updatePlayer(Move move);

    public void update();

    public void shockWave();


    public void shootSuperLaser() throws LaserInFlightException, NotEnoughtPointsException;

    public String lista();
}
