package tp1.logic;


//ESTA SE USA PARA CONTROLLER
public interface GameModel {
    public boolean isFinished();

    public boolean move(Move move);
    public boolean shootLaser();
    public void reset();
    public void exit();

    public void updatePlayer(Move move);

    public void update();

    public void shockWave();

    public void superLaser();

    public boolean shootSuperLaser();
}
