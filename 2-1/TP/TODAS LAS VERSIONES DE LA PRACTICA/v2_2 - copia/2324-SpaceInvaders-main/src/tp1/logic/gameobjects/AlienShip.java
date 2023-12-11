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
		waitUntil=game.getLevel().getNumCyclesToMoveOneCell();
		ciclos=1;
    }

    public AlienShip(){
        super();
    }

    public void automaticMove(){
        if(ciclos==0){
            pos.actualiza(dir);
            ciclos=waitUntil;

        }else if(alienManager.onBorder()){
            pos.actualiza(Move.DOWN);
            bajado=true;
            dir=dir.opuesto();
            alienManager.decreaseAliensOnBorder();
        }else
            ciclos--;

        if(pos.enBordeInferior()) {
            game.gananAliens();
        }

    }

    private boolean onBorder(){
        return this.pos.onBorderLateral();
    }

    public void computerAction() {
        if(pos.enBordeInferior()){
            game.gananAliens();
        }
        if(onBorder()&&!bajado) {
            alienManager.setOnBorder();

        }
    }

    protected abstract AlienShip copy(GameWorld game, Position pos, AlienManager am);

    public boolean matchSymbol(String input){
        return  input.equals(getSymbol());
    }
}
