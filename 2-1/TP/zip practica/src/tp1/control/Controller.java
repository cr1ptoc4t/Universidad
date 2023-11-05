package tp1.control;

import static tp1.view.Messages.debug;

import java.nio.Buffer;
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

	private final Game game;
	private final Scanner scanner;
	private final GamePrinter printer;

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

		printGame();

		do{

			comando = prompt();
			ejecutarComando(comando);

			game.update();

			printGame();


		}while(!esComandoExit(comando)&&!game.aliensWin()&&!game.playerWin());

		System.out.println(printer.endMessage());
	}


	private boolean esComandoExit(String[] comando){
		return comando[0].equals("exit") || comando[0].equals("e");
	}

	private void ejecutarComando(String[] comando){
	
		
		if(comando[0].equals("move") || comando[0].equals("m")) {
			game.mueveNave(Move.stringAMov(comando[1]));
				
		} else if(comando[0].equals("shoot")||comando[0].equals("s")){
			game.enableLaser();

		}
		else if(comando[0].equals("help") || comando[0].equals("h")) {
			System.out.println(Messages.HELP);
		}
		else if (comando[0].equals("reset") || comando[0].equals("r")) {
			game.reset();
		}else if(comando[0].equals("l")|| comando[0].equals("list")) {
			System.out.println(list());
		}else if(comando[0].equals("n")||comando[0].equals("none")){
			game.pasaCiclo();
		} else if (comando[0].equals("w")||comando[0].equals("shockwave")) {
			game.doShockWave();
		} else{
			System.out.println(Messages.INVALID_COMMAND);
			game.pasaCiclo();
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
	private String list() {

		/* @formatter:off */
		String buffer=Messages.ucmShipDescription(Messages.UCMSHIP_DESCRIPTION,3, 2)+
 game.lista();
		//if(hay aliens)
		//for cada alien
		//buffer.append("\n").append(Messages.alienDescription(Messages.REGULAR_ALIEN_DESCRIPTION, 5, 0, 2));
		//if hay destroyer aliens
		// for
		//buffer.append(NEW_LINE).....
		//if hay ufo
		// buffer.append......


		return buffer;
	}

}
