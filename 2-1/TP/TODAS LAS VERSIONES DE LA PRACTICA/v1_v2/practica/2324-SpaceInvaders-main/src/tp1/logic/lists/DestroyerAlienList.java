package tp1.logic.lists;

import tp1.logic.*;
import tp1.logic.gameobjects.DestroyerAlien;

public class DestroyerAlienList {
    private DestroyerAlien[] objects;
    private int num;

    private Level level;
    private AlienManager alienManager;
    private Move dir=Move.LEFT;

    public DestroyerAlienList(Game game, int num, Level level){
        this.num= num;
        this.level = level;
        this.initializeList();
    }

    private void initializeList(){
        for(int i=0; i<num;i++){
            objects[i]=new DestroyerAlien(game,new Position(0, i), level);
        }
    }

    public int getNum(){
        return num;
    }

    public boolean onBorder(){
        return objects[0].isInBorderRight()|| objects[num-1].isInBorderLeft();
    }

    public void performGroupMovement(Move dir){
        for(int i=0; i<num;i++){
            objects[i].performMovement(dir);
        }
    }

    public void inicializa(){


    }

    public String lista(){

        return "";
    }

}
