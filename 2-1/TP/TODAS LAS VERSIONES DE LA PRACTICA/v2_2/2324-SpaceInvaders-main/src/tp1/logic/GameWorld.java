package tp1.logic;

import tp1.logic.gameobjects.GameObject;

public interface GameWorld {

    public void update();
    public void addObject(GameObject object);
    public void updatePlayer(Move move);

    }
