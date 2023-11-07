package tp1.view;

import tp1.logic.Level;

/**
 * String literals used in the game.
 * 
 */
public class Messages {

	public static final String VERSION = "1.0";

	public static final String GAME_NAME = "Space Invaders";

	public static final String USAGE = "Usage: %s <level> [<seed>]".formatted(GAME_NAME);

	public static final String USAGE_LEVEL_PARAM = "\t<level>: %s".formatted(Level.all(", "));

	public static final String USAGE_SEED_PARAM = "\t<seed>: %s".formatted(Messages.SEED_NOT_A_NUMBER);

	public static final String WELCOME = String.format("%s %s%n", GAME_NAME, VERSION);

	public static final String ALLOWED_LEVELS = "Level must be one of: %s".formatted(Level.all(", "));

	public static final String SEED_NOT_A_NUMBER = "The seed must be a number";

	public static final String SEED_NOT_A_NUMBER_ERROR = String.format("%s: %%s", SEED_NOT_A_NUMBER);

	public static final String CONFIGURED_LEVEL = "Level: %s";

	public static final String CONFIGURED_SEED = "Random generator initialized with seed: %d";

	public static final String PROMPT = "Command > ";

	public static final String DEBUG = "%n[DEBUG] Executing: %s%n";

	public static final String ERROR = "[ERROR] Error: %s%n";

	public static final String LINE_SEPARATOR = System.lineSeparator();

	/* @formatter:off */
	public static final String[] HELP_LINES = new String[] { "Available commands:",
			"[m]ove <left|lleft|right|rright>: moves the UCMShip to the indicated direction",
			"[s]hoot: player shoots a laser",
			"shock[W]ave: player releases a shock wave",
			"[l]ist: print the list of current ships",
			"[r]eset: start a new game",
			"[h]elp: print this help message",
			"[e]xit: end the execution of the game",
			"[n]one | \"\": skips cycle"};
	/* @formatter:on */

	public static final String HELP = String.join(System.lineSeparator(), HELP_LINES);

	public static final String UNKNOWN_COMMAND = "Unknown command";

	public static final String COMMAND_PARAMETERS_MISSING = "Missing parameters";

	public static final String COMMAND_INCORRECT_PARAMETER_NUMBER = "Incorrect parameter number";

	public static final String INVALID_POSITION = "Invalid position (%s, %s)";

	public static final String INVALID_GAME_OBJECT = String.format("Invalid object%n");

	public static final String INVALID_COMMAND = "Invalid command";

	public static final String NUMBER_OF_CYCLES = "Number of cycles:";

	public static final String REMAINING_ALIENS = "Remaining aliens:";

	public static final String GAME_OVER = "Game over";

	public static final String PLAYER_QUITS = "Player leaves the game";

	public static final String ALIENS_WIN = "Aliens win!";

	public static final String PLAYER_WINS = "Player wins!";

	public static final String AVAILABLE_SHIPS = "Available ships:";

	public static final String UNEXPECTED_RUNTIME_ERROR = "Oops!";
	
	public static final String SCORE = "Score:";

	public static final String LASER_ERROR = "Laser cannot be shot";

	public static final String SHOCKWAVE_ERROR = "ShockWave cannot be shot";
	
	public static final String MOVEMENT_ERROR = "Movement cannot be performed";
	
	public static final String DIRECTION_ERROR = "Wrong direction: ";

	//
	// Game Objects
	//
	public static final String GAME_OBJECT_STATUS = "%2s[%02d]";

	public static final String ALIEN_DESCRIPTION = "%s: points='%d', damage='%d', endurance='%d'";

	public static final String UCM_DESCRIPTION = "%s: damage='%d', endurance='%d'";

	public static final String SHOCKWAVE_SYMBOL = "W";

	public static final String BOMB_SYMBOL = "*";

	public static final String LASER_SYMBOL = "oo";

	public static final String UCMSHIP_SYMBOL = "^__^";

	public static final String UCMSHIP_DEAD_SYMBOL = "^xx^";

	public static final String UCMSHIP_DESCRIPTION = "[U]CM Ship";

	public static final String REGULAR_ALIEN_SYMBOL = "R";

	public static final String REGULAR_ALIEN_DESCRIPTION = "[R]egular Alien";

	public static final String DESTROYER_ALIEN_SYMBOL = "D";

	public static final String DESTROYER_ALIEN_DESCRIPTION = "[D]estroyer Alien";

	public static final String UFO_SYMBOL = "U";

	public static final String UFO_DESCRIPTION = "U[f]o";


	/**
	 * Formats an debug message.
	 * 
	 * @param message debug message
	 * 
	 * @return the formated debug message;
	 */
	public static final String debug(String message) {
		return Messages.DEBUG.formatted(message);
	}

	/**
	 * Formats an error message.
	 * 
	 * @param message Error message
	 * 
	 * @return the formated error message;
	 */
	public static final String error(String message) {
		return Messages.ERROR.formatted(message);
	}

	public static final String status(String icon, int lives) {
		return Messages.GAME_OBJECT_STATUS.formatted(icon, lives);
	}

	public static final String alienDescription(String alienNameAndShortcut, int points, int damage, int endurance) {
		return Messages.ALIEN_DESCRIPTION.formatted(alienNameAndShortcut, points, damage, endurance);
	}

	public static final String ucmShipDescription(String ucmShipDescription, int damage, int endurance) {
		return Messages.UCM_DESCRIPTION.formatted(ucmShipDescription, damage, endurance);
	}

}
