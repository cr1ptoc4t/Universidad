package tp1.control;

import static tp1.view.Messages.debug;

import java.util.Scanner;

import tp1.control.commands.Command;
import tp1.control.commands.CommandGenerator;
import tp1.logic.Game;
import tp1.view.BoardPrinter;
import tp1.view.GamePrinter;
import tp1.view.Messages;

/**
 * Accepts user input and coordinates the game execution logic.
 */
public class Controller {

	private Game game;
	private Scanner scanner;
	private GamePrinter printer;

	public Controller(Game game, Scanner scanner) {
		this.game = game;
		this.scanner = scanner;
		printer = new BoardPrinter(game);
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

	public void run() {

		printGame();

		while (!game.isFinished()) {
			String[] parameters = prompt();

			Command command = CommandGenerator.parse(parameters);

			if (command != null) {
				ExecutionResult result = command.execute(game);
				if (result.success()) {
					if (result.draw())
						printGame();
				} 
				else
					System.out.println(result.errorMessage());
			} else {
				System.out.println(Messages.UNKNOWN_COMMAND);
			}
		}

		printEndMessage();
	}
	
	/**
	 * Draws/prints the game
	 */
	private void printGame() {
		System.out.println(printer);
	}

	/**
	 * Prints the final message once the game is finished.
	 */
	public void printEndMessage() {
		System.out.println(printer.endMessage());
	}

}
