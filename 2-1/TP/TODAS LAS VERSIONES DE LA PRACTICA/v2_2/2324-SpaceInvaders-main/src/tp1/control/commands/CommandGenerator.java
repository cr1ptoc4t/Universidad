package tp1.control.commands;

import java.util.Arrays;
import java.util.List;

import tp1.logic.Move;
import tp1.view.GamePrinter;

public class CommandGenerator {

	
	private static GamePrinter printer;
	private Move move;

	public void MoveCommand () {
	}
	
	protected void MoveCommand (Move move) {
		this.move = move;
	}
	
	private static final List<Command> availableCommands = Arrays.asList(
		new MoveCommand(),
		new HelpCommand(),
		new ExitCommand(),
		new ShootCommand(),
		new ShockwaveCommand()
		//TODO fill with your code
	);

	public static Command parse(String[] commandWords) {		
		//Command command = null;
		//for (Command c: availableCommands) {
			
		//}
		//return command;
		if(commandWords.length>0) {
			for (Command c : availableCommands) {  //commands es la lista de comandos que tenemos
				//if(c.commandName(commandWords)){
				if (c.parse(commandWords) != null) {
					return c.parse(commandWords);
				}
			}
		}
		return null;
	}
		
	public static String commandHelp() {
		StringBuilder commands = new StringBuilder();	
		for (Command c: availableCommands) {
			printer.show(c.getName()+" ("+ c.getDetails() + "): "+ c.getHelp());

		}
		return commands.toString();
	}



}
