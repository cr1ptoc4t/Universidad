package tp1.logic;

import java.util.ArrayList;
import java.util.List;

import tp1.logic.gameobjects.GameObject;
import tp1.logic.gameobjects.UCMShip;

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

	public void automaticMoves() {

		for (int i=0;i<objects.size();i++) {
				GameObject object = objects.get(i);
				object.automaticMove();
			//TODO fill with your code
		}

		//si ufo!=null -> moverlo para la izq

		//


	}

	public void computerActions() {

		//COLISIONES VAN AQUI
	}

	public String toString(int col, int row){
		int i=0;
		while(i<objects.size()&&!objects.get(i).isOnPosition(new Position(col, row))){
			i++;
		}
		if (i!=objects.size())
			return objects.get(i).toString();
		else return "";
	}
}
