package tp1.logic.gameobjects;

import tp1.logic.GameWorld;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.logic.Game;
import tp1.view.Messages;

public class UCMWeapon extends Weapon {

	//TODO fill with your code

    public UCMWeapon(GameWorld game, Position pos){
        // Game game, Position pos, Move dir, int dano
        super(game, pos, Move.NONE);

    }


    @Override
    public void onDelete() {

    }


    public boolean performAttack(GameItem other) {
        other.receiveAttack(this);
        life--;
        return life<=0;
    }
}
