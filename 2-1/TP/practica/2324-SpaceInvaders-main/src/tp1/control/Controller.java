package tp1.control;

import static tp1.view.Messages.debug;

import java.util.Scanner;

import tp1.logic.Game;
import tp1.logic.Move;
import tp1.view.GamePrinter;
import tp1.view.Messages;
import tp1.logic.Position;

/**
 *  Accepts user input and coordinates the game execution logic
 */
public class Controller {

	private Game game;
	private Scanner scanner;
	private GamePrinter printer;

	public Controller(Game game, Scanner scanner) {
		this.game = game;
		this.scanner = scanner;
		printer = new GamePrinter(game);
	}

	/**
	 * Show prompt and request command.
	 *
	 * @return the player command as words
	 */
	private String[] prompt() {
		System.out.print(Messages.PROMPT);
		String line = scanner.nextLine();
		String[] words = line.toLowerCase().trim().split("\\s+");

		System.out.println(debug(line));

		return words;
	}

	/**
	 * Runs the game logic
	 */
	public void run() {
		//TODO fill your code
		String[]comando;
		do{
			//printer.showGame();
			printGame();
			comando = prompt();
			ejecutarComando(comando);
		}while(!esComandoExit(comando));

		printer.endMessage();
	}

	private boolean esComandoExit(String[] comando){
		return comando[0].equals("exit") || comando[0].equals("e");
	}

	private void ejecutarComando(String[] comando){
			//llenar esto
	
		if(comando[0].equals("move") || comando[0].equals("m")) {
			Move movimiento = Move.stringAMov(comando[1]);
			game.mueveNave(movimiento);
				
		} else if(comando[0].equals("shoot")||comando[0].equals("s")){
			//performAttack();
		}
		else if(comando[0].equals("help") || comando[0].equals("h")) {
			System.out.print("""
					[m]ove <left|lleft|right|rright>: Moves UCM-Ship to the indicated direction.
					[s]hoot: UCM-Ship launches a laser.
					shock[W]ave: UCM-Ship releases a shock wave.
					[l]ist: Prints the list of available ships.
					[r]eset: Starts a new game.
					[h]elp: Prints this help message.
					[e]xit: Terminates the program.
					[n]one: Skips one cycle.""");
		}
		else if (comando[0].equals("reset") || comando[0].equals("r")) {
			game.reset();
		}
	}
	
	/**
	 * Draw / paint the game
	 */
	private void printGame() {
		
		System.out.println(printer);
	}
	
	/**
	 * Prints the final message once the game is finished
	 */
	public void printEndMessage() {
		System.out.println(printer.endMessage());
	}
	
}
