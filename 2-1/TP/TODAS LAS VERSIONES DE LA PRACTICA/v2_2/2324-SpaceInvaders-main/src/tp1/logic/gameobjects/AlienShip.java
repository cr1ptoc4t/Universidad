package tp1.logic.gameobjects;

import tp1.logic.*;
import tp1.view.Messages;

public abstract class AlienShip extends EnemyShip{
    private Move dir;
    private Move direccionOp;
    private boolean bajado=false;
    private AlienManager alienManager;
    private int ciclos;
    private int waitUntil;
    public AlienShip(GameWorld game, Position pos, int life, Move dir, AlienManager alienManager){
        super(game, pos, life);
        this.alienManager= alienManager;
        this.dir=dir;

        waitUntil=game.getlevel().getNumCyclesToMoveOneCell();
        ciclos=0;
    }

    public AlienShip(){
        super();
    }

    public void automaticMove(){

        //if(game.getCycle()%waitUntil==0) {
        //if(false){
               //esto solo se tiene que hacer una vez por ciclo
        //dir=alienManager.calculaDir();
        //cicloAnterior = game.getCycle();
        this.pos.actualiza(Move.DOWN);


        //if(waitUntil==0){
        //    this.pos.actualiza(dir);
        //}else if(alienManager.onBorder()){
        //    dir=dir.opuesto();
        //    this.pos.actualiza(Move.DOWN);
        //} else waitUntil--;


    }

    private boolean onBorder(){
        return this.pos.onBorderLateral();
    }

    public void computerAction() {
        if(pos.enBordeInferior()){
            game.gananAliens();
        }
        if(onBorder()){
            alienManager.setOnBorder();
        }
    }

    protected abstract AlienShip copy(GameWorld game, Position pos, AlienManager am);


    public boolean matchSymbol(String input){
        return  input.equals(getSymbol());
    }
}
