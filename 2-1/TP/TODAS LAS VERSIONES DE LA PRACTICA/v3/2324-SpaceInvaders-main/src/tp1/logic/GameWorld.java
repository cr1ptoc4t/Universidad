package tp1.logic;

import tp1.logic.gameobjects.Bomb;
import tp1.logic.gameobjects.DestroyerAlien;
import tp1.logic.gameobjects.ExplosiveAlien;
import tp1.logic.gameobjects.GameObject;

import java.util.Random;

public interface GameWorld {

    public Random rnd = new Random();

    public Level getLevel();

    public int getCycle();

    public boolean puedeCrearLaser();
    public boolean puedeCrearSuperLaser();

    public void update();
    public void addObject(GameObject object);
    public void updatePlayer(Move move);
    public void leaveBomb( Bomb bomb);
    public void disenableUfo();
    public void enableBomb(DestroyerAlien alien);
    public void died(GameObject object);
    public void laserAFalse();
    public void explodeAlien(ExplosiveAlien explosiveAlien);
    public void gananAliens();

}