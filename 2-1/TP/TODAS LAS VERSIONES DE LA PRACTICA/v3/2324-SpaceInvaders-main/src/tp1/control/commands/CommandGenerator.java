package tp1.control.commands;

import java.util.Arrays;
import java.util.List;

import tp1.exceptions.CommandParseException;
import tp1.logic.Move;
import tp1.view.GamePrinter;
import tp1.view.Messages;

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

	public static Command parse(String[] commandWords) throws CommandParseException {
		try {
			if (commandWords.length > 0) {
				for (Command c : availableCommands) {
					if (c.matchCommandName(commandWords[0])) {
						return c.parse(commandWords);
					}
				}
			}
		} catch (CommandParseException e) {//throw new CommandParseException(Messages.UNKNOWN_COMMAND);

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
