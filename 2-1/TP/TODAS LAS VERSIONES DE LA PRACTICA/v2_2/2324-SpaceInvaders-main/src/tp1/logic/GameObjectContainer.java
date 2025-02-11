package tp1.logic;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import tp1.logic.gameobjects.*;

import javax.print.attribute.standard.JobKOctets;

public class GameObjectContainer {

    private List<GameObject> objects;


    public GameObjectContainer() {
        objects = new ArrayList<>();
    }

    public void add(GameObject object) {
        objects.add(object);
    }

    public void remove(GameObject object) {
        objects.remove(object);


    }


    public void shockWave(Game game) {
        int i = 0;
        while (i < objects.size()) {
            objects.get(i).receiveAttack(new ShockWave(game));
            i++;
        }

        eliminarMuertos(game);

    }


    public void automaticMoves() {

        for (int i = 0; i < objects.size(); i++) {
            GameObject object = objects.get(i);
            object.automaticMove();
            //TODO fill with your code
        }

    }


    public void computerActions(Game game) {

        //colisiones y restamos vidas
        for (int i = 0; i < this.objects.size(); i++) {
            int j = i + 1;

            while (j < this.objects.size()) {
                if (collision(i, j)) {
                    collide(objects.get(i), objects.get(j));
                }
                j++;
            }
        }

        actualizarLista(game);

    }


    //eliminamos elementos que están fuera y que no tienen vida
    private void actualizarLista(Game game) {
        int i = 0;

        while (i < this.objects.size()) {

            GameObject object = objects.get(i);
            object.computerAction();

            if (object.dies()) {
                game.objectDies(object);
                remove(object);
            } else if (!object.posicionValida())
                remove(object);
            else
                i++;
        }
    }

    private void eliminarMuertos(Game game) {
        int i = 0;

        while (i < this.objects.size()) {

            GameObject object = objects.get(i);
            if (object.dies()) {
                game.objectDies(object);
                remove(object);
            } else if (!object.posicionValida())
                remove(object);
            else
                i++;
        }
    }


    private void collide(GameItem obj1, GameItem obj2) {
        obj1.performAttack(obj2);
        obj2.performAttack(obj1);
    }

    private boolean collision(int i, int j) {
        return objects.get(i).equalPosition(objects.get(j));
    }

    public String toString(int col, int row) {
        Position aux = new Position(col, row);
        int i = 0;

        while (i < objects.size() && !objects.get(i).isOnPosition(aux))
            i++;


        if (i != objects.size())
            return objects.get(i).toString();

        else return "";
    }


    public void explodeAlien(GameWorld game, GameObject e) {
        int i = 0;
        int acum = 0;

        while (i < objects.size() && acum < 8) {
            GameObject obj = objects.get(i);
            if (e.anexoA(obj)) {
                obj.receiveAttack(new EnemyWeapon(game, null, null));
                acum++;
            }
            i++;
        }

    }

    public void clear(){
        objects.clear();
    }


}
