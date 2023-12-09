package tp1.logic.gameobjects;

import tp1.logic.*;
import tp1.view.Messages;

public abstract class AlienShip extends EnemyShip{
    private Move dir;
    private boolean bajado=false;
    private AlienManager alienManager;
    private int waitUntil;
    public AlienShip(GameWorld game, Position pos, int life, Move dir, AlienManager alienManager){
        super(game, pos, life);
        this.alienManager= alienManager;
        this.dir=dir;

        waitUntil=game.getlevel().getNumCyclesToMoveOneCell();
    }

    public AlienShip(){
        super();
    }



    public void automaticMove(){

        //TODO: ESTO HAY QUE DESCOMENTARLO ESQ SIN QUE SE MUEVAN VA MEJOR PARA ENCONTRAR FALLOS
        //if(game.getCycle()%waitUntil==0) {
        if(false){
            if (this.alienManager.bajar() && !bajado) {
                this.pos.actualiza(Move.DOWN);
                dir = dir.opuesto();
                bajado = true;
            } else {
                this.pos.actualiza(dir);
                bajado = false;
            }


        }
    }

    private boolean onBorder(){
        return this.pos.onBorderLateral();
    }

    public void computerAction() {
        if(onBorder()){
            alienManager.setOnBorder();
        }
    }

    protected abstract AlienShip copy(GameWorld game, Position pos, AlienManager am);


    public boolean matchSymbol(String input){
        return  input.equals(getSymbol());
    }
}
