package tp1.control.commands;

import java.util.Arrays;
import java.util.List;

import tp1.logic.Move;

public class CommandGenerator {

	

	private Move move;
	public void MoveCommand () {}
	
	protected void MoveCommand (Move move) {
		this.move = move;
	}
	
	private static final List<Command> availableCommands = Arrays.asList(
		new HelpCommand(),
		new MoveCommand(),
		new ExitCommand()
		//TODO fill with your code
	);

	public static Command parse(String[] commandWords) {		
		//Command command = null;
		//for (Command c: availableCommands) {
			
		//}
		//return command;
		
		for(Command c : availableCommands){  //comands es la lista de comandos que tenemos
			//if(c.commandName(commandWords[0])){
			//	return c.parse(commandWords);
			//}

		}
		return null;
	}
		
	public static String commandHelp() {
		StringBuilder commands = new StringBuilder();	
		for (Command c: availableCommands) {
			//TODO fill with your code
		}
		return commands.toString();
	}

}
