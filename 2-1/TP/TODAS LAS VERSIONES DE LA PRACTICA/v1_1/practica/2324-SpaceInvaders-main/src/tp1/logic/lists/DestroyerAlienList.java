package tp1.logic.lists;

import tp1.logic.Move;
import tp1.logic.Position;
import tp1.logic.gameobjects.DestroyerAlien;

public class DestroyerAlienList {
    private DestroyerAlien[] objects;
    private int num;

    private Move dir=Move.LEFT;

    public DestroyerAlienList(int num){
        this.num= num;
        //this.initializeList();
    }

    public void initializeList(){
        for(int i=0; i<num;i++){
            objects[i]=new DestroyerAlien(0, i);
        }
    }

}
