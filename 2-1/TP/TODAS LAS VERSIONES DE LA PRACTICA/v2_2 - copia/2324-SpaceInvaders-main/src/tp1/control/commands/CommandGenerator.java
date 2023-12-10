package tp1.control.commands;

import java.util.Arrays;
import java.util.List;

import tp1.logic.Move;
import tp1.view.GamePrinter;

public class CommandGenerator {

	
	private static GamePrinter printer;
	private static final List<Command> availableCommands = Arrays.asList(
			new MoveCommand(),
			new ShootCommand(),
			new ShockwaveCommand(),
			new ListCommand(),
			new ResetCommand(),
			new HelpCommand(),
			new ExitCommand(),
			new NoneCommand(),
			new SuperLaserCommand()
		//TODO fill with your code
	);

	public static Command parse(String[] commandWords) {		

		if(commandWords.length>0) {
			for (Command c : availableCommands) {  //commands es la lista de comandos que tenemos
				//if(c.commandName(commandWords)){
				//if (c.parse(commandWords) != null) {
				if(c.matchCommandName(commandWords[0])){
					return c.parse(commandWords);
				}
			}
		}
		return null;
	}
		
	public static String commandHelp() {
		StringBuilder commands = new StringBuilder();	
		for (Command c: availableCommands) {
			printer.show( c.getDetails() +": "+ c.getHelp()+".");

		}
		return commands.toString();
	}



}
