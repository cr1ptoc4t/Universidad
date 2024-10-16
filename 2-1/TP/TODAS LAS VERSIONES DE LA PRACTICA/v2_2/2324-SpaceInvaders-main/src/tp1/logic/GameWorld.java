package tp1.logic;

import tp1.logic.gameobjects.Bomb;
import tp1.logic.gameobjects.DestroyerAlien;
import tp1.logic.gameobjects.ExplosiveAlien;
import tp1.logic.gameobjects.GameObject;

import java.util.Random;

public interface GameWorld {

    public Random rnd = new Random();
    //PARA GAMEOBJECT
    public void update();
    public void addObject(GameObject object);
    public void updatePlayer(Move move);

    public void leaveBomb( Bomb bomb);
    public void disenableUfo();
    //public Random rnd;

    public void enableBomb(DestroyerAlien alien);
    public void died(GameObject object);

    public Level getLevel();

    public void laserAFalse();

    public boolean puedeCrearLaser();


    boolean puedeCrearSuperLaser();

    Level getlevel();

    void explodeAlien(ExplosiveAlien explosiveAlien);

    public int getCycle();

    public void gananAliens();
}
