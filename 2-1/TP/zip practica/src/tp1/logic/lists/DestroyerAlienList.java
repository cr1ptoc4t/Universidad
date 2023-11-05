package tp1.logic.lists;

import tp1.logic.*;
import tp1.logic.gameobjects.DestroyerAlien;
import tp1.logic.gameobjects.RegularAlien;
import tp1.logic.gameobjects.UCMLaser;
import tp1.logic.gameobjects.UCMShip;
import tp1.view.Messages;

public class DestroyerAlienList {
    private final DestroyerAlien[] objects;
    private int num;
    private boolean descent;
    private final Level level;

    private Move dir=Move.LEFT;
    private Move direccionOp;
    private int nCiclos;
    private final int wait;
    private final double frequency;
    private final Game game;
    public DestroyerAlienList(Game game,int num, Level level){
        this.game = game;
        this.num= num;
        this.level = level;
        objects = new DestroyerAlien[num];
        descent = false;
        nCiclos = 0;
        wait = waitUntil();
        this.frequency = decideFrecuencia();
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
            if (onBorder && !descent) {
                direccionOp = dir.opuesto();
                dir = Move.DOWN;
                descent = true;
            } else if (descent) {
                dir = direccionOp;
                descent = false;
            }

            performGroupMovement();
        }
        performBombMov();

        nCiclos++;
    }

    private void performBombMov(){
        for(int i=0; i<num;i++)
            objects[i].performBombMov();
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

    public DestroyerAlien bombInPosition(Position pos){
        int i= indiceEnPos(pos);

        if(i==-1) return null;

        return objects[i];
    }


    //esto deberia poderse hacer más limpio
    public void inicializa() {
        if (level == Level.EASY){
            //empieza en 3,3
            num = 2;
            for (int i =0; i < num; i++) {
                objects[i] = new DestroyerAlien(game,new Position(i+4, 3), level);
            }
        } else if(level== Level.HARD){
            num = 2;
            for (int i =0; i < num; i++) {
                objects[i] = new DestroyerAlien(game,new Position(i+4, 4), level);
            }
        } else if (level == Level.INSANE) {
            //empieza en 3,4
            num = 4;
            for (int i =0; i < num; i++) {
                objects[i] = new DestroyerAlien(game, new Position(i+3, 4), level);
            }
        }

    }

    public String lista(){

        String buffer = Messages.DESTROYER_ALIEN_DESCRIPTION +
                ": points: '" + DestroyerAlien.value +
                "', damage: '" + DestroyerAlien.damage +
                "', endurance: '" + DestroyerAlien.endurance + "'";

        return buffer;
    }

    public int recibeAtaque(UCMLaser laser){
        int i=0;

        //while (i<num && !objects[i].receiveAttack(laser))
        while (i<num && !laser.performAttack(objects[i]))
            i++;

        if (i==num) i=-1;
        else {
            eliminar(i);
        }

        return i;
    }

    public void shockWave(){
        int n_aux = num;
        int i =0;

        while(i<n_aux){
            if(objects[i].shockWave()){
                eliminar(i);
                // aqui no incrementamos porque cada valor pasa una casilla para la izquierda
                // en vez de mover el indice se mueven las casillas
            } else {
                i++;
            }

        }


        //aqui habria que chequear que elementos tienen 0 de vida y eliminarlos

    }


    public void eliminar(int indice){
        if(indice!=-1 && objects[indice].vida()==0) {
            for (int i = indice; i < num - 1; i++)
                objects[i] = objects[i + 1];
            num--;

            game.actualizaPoints("destroyer");
            game.actualizaRemainingAliens();

        }
    }



    public boolean alienInLowerBorder(){
        int i=0;
        while(i<num &&!objects[i].isInLowerBorder()) i++;
        return i!=num;
    }

    public void shoot(){
        for(int i=0; i<num;i++){
            objects[i].shoot(frequency);
        }
    }

    private double decideFrecuencia(){
        double ret = 0.1;

        switch (level) {
            case HARD:
                ret=0.3;
                break;
            case INSANE:
                ret=0.5;
        }
        return ret;
    }

    public boolean hayBomba(Position pos){
        int i=0;
        while (i<num &&!objects[i].bombaEnPos(pos))
            i++;

        return i!=num;
    }

    public boolean bombaAtaca(UCMShip laNave){
        int i=0;
        while (i<num && !laNave.recibeAtaque(this.objects[i]))
            i++;

        return i!=num;
    }

}
