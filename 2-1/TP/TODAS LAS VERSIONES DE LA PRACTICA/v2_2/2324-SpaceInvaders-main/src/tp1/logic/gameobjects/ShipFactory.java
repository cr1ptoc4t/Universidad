package tp1.logic.gameobjects;

import tp1.logic.AlienManager;
import tp1.logic.Game;
import tp1.logic.GameWorld;
import tp1.logic.Position;

import java.util.Arrays;
import java.util.List;

public class ShipFactory {

    private Game game;

    private static final List<AlienShip> AVAILABLE_ALIEN_SHIPS = Arrays.asList(
            new RegularAlien(),
            new DestroyerAlien()
    );

    public ShipFactory(){

    }

    public static AlienShip spawnAlienShip(String input, GameWorld game, Position pos, AlienManager am) {

        // Este método recorrerá la lista preguntando si el símbolo de cada nave coincide
        // con el determinado por input.
        // Si es así, se solicita a la nave una copia,
        // inicializada con el resto de argumentos (game, pos y am).
        // Para ello añadiremos en AlienShip un método



        return null;
    }

}
