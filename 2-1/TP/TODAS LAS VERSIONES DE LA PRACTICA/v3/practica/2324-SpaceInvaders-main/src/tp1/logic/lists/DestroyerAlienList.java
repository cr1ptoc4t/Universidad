package tp1.logic.lists;

import tp1.logic.*;
import tp1.logic.gameobjects.DestroyerAlien;
import tp1.logic.gameobjects.UCMLaser;
import tp1.view.Messages;

public class DestroyerAlienList {
    private DestroyerAlien[] objects;
    private int num;
    private boolean descent;
    private Level level;
    private AlienManager alienManager;
    private Move dir=Move.LEFT;
    private Move direccionOp;

    public DestroyerAlienList(int num, Level level){
        this.num= num;
        this.level = level;
        objects = new DestroyerAlien[num];
        descent=false;
    }

    public int getNum(){
        return num;
    }

    public boolean onBorder(){
        return objects[0].isInBorderLeft()|| objects[num-1].isInBorderRight();
    }

    private void performGroupMovement(){
        for(int i=0; i<num;i++){
            objects[i].performMovement(dir);
        }
    }
    public void automaticMove(){
        if(num>0) {
            if (onBorder() && descent == false) {
                direccionOp = dir.opuesto();
                dir = Move.DOWN;
                descent = true;
            } else if (descent) {
                dir = direccionOp;
                descent = false;
            }
            //performGroupMovement();
        }
    }


    public int indiceEnPos(Position pos){
        int i= 0;

        while(i<num && !objects[i].isInPosition(pos))
            i++;

        if(i==num) i=-1;

        return i;
    }

    public void inicializa() {
        if (level == Level.EASY || level == Level.HARD){
            num = 2;
            for (int i =0; i < num; i++) {
                objects[i] = new DestroyerAlien(new Position(i+4, 3), level);
            }
        }
        else if (level == Level.INSANE) {
            num = 4;
            for (int i =0; i < num; i++) {
                objects[i] = new DestroyerAlien(new Position(i+4, 4), level);
            }
        }

    }

    public String lista(){

        return "";
    }

    public int recibeAtaque(UCMLaser laser){
        int i=0;

        while (i<num && !objects[i].receiveAttack(laser))
            i++;

        if (i==num) i=-1;   //si ningun elemento para eliminar
        else {
            eliminar(i);
        }

        return i;
    }
    public String getSymbol(Position pos){
        return Messages.DESTROYER_ALIEN_SYMBOL+"[1]";
    }
    public void shockWave(){
        for(int i=0;i<num;i++){
            //eliminar 1 punto de vida al objects[i]
            objects[i].shockWave();
            if(objects[i].vida()==0){
                //eliminar(i);
            }
        }

    }


    public void eliminar(int indice){
        if(indice!=-1) {
            for (int i = indice; i < num - 1; i++)
                objects[i] = objects[i + 1];
            num--;
        }
    }
}
