package tp1.logic;
public interface GameModel { // Definir las interfaces
    public boolean isFinished();
    // PLAYER ACTIONS
    public boolean move(Move move);
    public boolean shootLaser();
    public void reset();
// …
}
