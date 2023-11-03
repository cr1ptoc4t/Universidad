package tp1.logic.lists;

import tp1.logic.*;
import tp1.logic.gameobjects.DestroyerAlien;
import tp1.logic.gameobjects.RegularAlien;
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

    //hay que poner el game aqui??
    //private Game game;
    int nCiclos;
    int wait;
    public DestroyerAlienList(int num, Level level){
        this.num= num;
        this.level = level;
        objects = new DestroyerAlien[num];
        descent = false;
        nCiclos = 0;
        wait = waitUntil();
    }

    public boolean onBorder() {
        boolean b=false;
        if(num>0)
            b=objects[0].isInBorderLeft() || objects[num-1].isInBorderRight();

        return b;
    }

    private void performGroupMovement(){
        for(int i=0; i<num;i++){
            objects[i].performMovement(dir);
        }
    }
    public void automaticMove(boolean onBorder){
        //tema bordes!!
        if(num>0 && nCiclos%wait==0) {
            if (onBorder && descent == false) {
                direccionOp = dir.opuesto();
                dir = Move.DOWN;
                descent = true;
            } else if (descent) {
                dir = direccionOp;
                descent = false;
            }

            performGroupMovement();
        }
        nCiclos++;
    }

    private int waitUntil(){
        int ret=1;

        switch(level){
            case EASY:
                ret=3;
                break;
            case HARD:
                ret=2;
                break;
        }

        return ret;
    }

    private int indiceEnPos(Position pos){
        int i= 0;

        while(i<num && !objects[i].isInPosition(pos))
            i++;

        if(i==num) i=-1;

        return i;
    }

    public DestroyerAlien alienInPosition(Position pos){
        int i= indiceEnPos(pos);

        if(i==-1) return null;

        return objects[i];
    }


    // TODO cambiarlo a solo 1 bucle que dependa de num
    public void inicializa() {
        if (level == Level.EASY){
            //empieza en 3,3
            num = 2;
            for (int i =0; i < num; i++) {
                objects[i] = new DestroyerAlien(new Position(i+4, 3), level);
            }
        } else if(level==level.HARD){
            num = 2;
            for (int i =0; i < num; i++) {
                objects[i] = new DestroyerAlien(new Position(i+4, 4), level);
            }
        } else if (level == Level.INSANE) {
            //empieza en 3,4
            num = 4;
            for (int i =0; i < num; i++) {
                objects[i] = new DestroyerAlien(new Position(i+3, 4), level);
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

    public boolean alienInLowerBorder(){
        int i=0;
        while(i<num &&!objects[i].isInLowerBorder()) i++;
        return i!=num;
    }

}
