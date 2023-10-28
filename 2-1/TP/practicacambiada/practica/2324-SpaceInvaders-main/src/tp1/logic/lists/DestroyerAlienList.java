package tp1.logic.lists;

import tp1.logic.AlienManager;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.logic.gameobjects.DestroyerAlien;

public class DestroyerAlienList {
    private DestroyerAlien[] objects;
    private int num;

    private AlienManager alienManager;
    private Move dir=Move.LEFT;

    public DestroyerAlienList(int num){
        this.num= num;
        this.initializeList();
    }

    private void initializeList(){
        for(int i=0; i<num;i++){
            objects[i]=new DestroyerAlien(0, i);
        }
    }

    public int getNum(){
        return num;
    }

    public boolean onBorder(){
        return false;
    }

    public void performGroupMovement(Move dir){
        for(int i=0; i<num;i++){
            objects[i].performMovement(dir);
        }
    }
}
