package tp1.logic.gameobjects;

import tp1.control.commands.Command;
import tp1.logic.AlienManager;
import tp1.logic.Game;
import tp1.logic.GameWorld;
import tp1.logic.Position;

import java.util.Arrays;
import java.util.List;

public class ShipFactory {

    private GameWorld gw;

    private static final List<AlienShip> AVAILABLE_ALIEN_SHIPS = Arrays.asList(
            new RegularAlien(),
            new DestroyerAlien(),
            new ExplosiveAlien()
    );

    public ShipFactory(GameWorld gw){this.gw=gw;}

    public static AlienShip spawnAlienShip(String input, GameWorld game, Position pos, AlienManager am) {
        for(AlienShip a : AVAILABLE_ALIEN_SHIPS){
            if(a.matchSymbol(input)){
                return a.copy(game, pos, am);
            }
        }

        return null;
    }

}
