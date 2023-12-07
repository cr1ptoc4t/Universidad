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


	//TODO: EL INSTANCEOF NO SE PUEDE!!!!!!

	public Laser getLaser() {
		for (GameObject object : objects) {
			if (object instanceof Laser) {
				return (Laser) object;
			}
		}
		return null;
	}

	public void shockWave(){
		int i=0;
		while(i<objects.size()){
			objects.get(i).computerAction();
			if(objects.get(i).isAlive())
				i++;
		}
	}

	public Ufo getUfo() {
		for (GameObject object : objects) {
			if (object instanceof Ufo) {
				return (Ufo) object;
			}
		}
		return null;
	}

	public void automaticMoves() {

		for (int i=0;i<objects.size();i++) {
			GameObject object = objects.get(i);
			object.automaticMove();
			//TODO fill with your code
		}


	}

	private boolean bomb(GameObject object){
		Bomb bomba=null;
		if(object instanceof DestroyerAlien){
			bomba = ((DestroyerAlien) object).leaveBomb();
			if(bomba!=null)
				this.objects.add(bomba);
		}
		return bomba!=null;
	}

	public void computerActions(Game game) {
		int i=0;

		while(i<this.objects.size()){

			int j=i+1;
			while(j<this.objects.size())
				if(collision(i,j)) {
					collide(objects.get(i), objects.get(j));
					//j--;
				}
				else
					j++;


			GameObject object= objects.get(i);

			if(object.dies()) {
				game.objectDies(object);
				remove(object);
			}
			else if(!object.posicionValida() || game.playerBombCollision((object)))
				remove(object);
			else if(!bomb(object))
				i++;

		}
	}






	private void collide(GameObject obj1, GameObject obj2){
		//obj1.computerAction();
		//obj2.computerAction();

		//ojo que esto es un boolean lo podemos usar para borrar tbn

		if(obj2.performAttack(obj1)){
			objects.remove(obj2);
		}
			//objects.remove(obj1);

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
