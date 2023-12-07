package tp1.logic;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import tp1.logic.gameobjects.GameObject;
import tp1.logic.gameobjects.UCMShip;
import tp1.logic.gameobjects.UCMWeapon;
import tp1.logic.gameobjects.Ufo;

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


	public UCMWeapon getLaser() {
		for (GameObject object : objects) {
			if (object instanceof UCMWeapon) {
				return (UCMWeapon) object;
			}
		}
		return null;  // Si no se encuentra ningún Laser
	}
	public Ufo getUfo() {
		for (GameObject object : objects) {
			if (object instanceof Ufo) {
				return (Ufo) object;
			}
		}
		return null;  // Si no se encuentra ningún Laser
	}

	public void automaticMoves() {

		for (int i=0;i<objects.size();i++) {
			GameObject object = objects.get(i);
			object.automaticMove();
			//TODO fill with your code
		}

		// hacer los shoots
		//if(canShoot()){}

	}
	private boolean canShoot(){
		return false;
	}

	public void computerActions(Game game) {
		//COLISIONES VAN AQUI
		int i=0;

		GameObject obj1, obj2;
		while(i<this.objects.size()){

			for(int j =i+1;j<this.objects.size();j++){
				if(collision(i,j))
					collide(objects.get(i), objects.get(j));
			}

			GameObject object= objects.get(i);

			if(object.diesByUser()) {
				game.objectDies(object);
				remove(object);
			}
			else if(object.diesNaturally())
				remove(object);
			else
				i++;

		}
	}
	private void collide(GameObject obj1, GameObject obj2){
		obj1.computerAction();
		obj2.computerAction();
	}

	private boolean collision(int i, int j){
		return objects.get(i).equalPosition(objects.get(j));
	}

	public String toString(int col, int row){
		int i=0;
		while(i<objects.size()&&
				!objects.get(i).isOnPosition((new Position(col, row)))){
			i++;
		}
		if (i!=objects.size())
			return objects.get(i).toString();
		else return "";
	}




}
