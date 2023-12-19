package tp1.control.commands;

import tp1.control.ExecutionResult;
import tp1.exceptions.CommandParseException;
import tp1.logic.Game;
import tp1.logic.Move;
import tp1.view.Messages;

public abstract class NoParamsCommand extends Command {


	public NoParamsCommand(String commandName) {
		super(commandName);
	}


	protected boolean matchCommand(String cw) {
		// comprueba si una acción
		// introducida por teclado se corresponde con la del comando
		return cw.equals(commandName);
	}

	public Command parse(String[] commandWords) throws CommandParseException {
		if (matchCommandName(commandWords[0])) {
			if(commandWords.length == 1) {

			}
 		else {
				throw new CommandParseException(Messages.COMMAND_INCORRECT_PARAMETER_NUMBER);
			}
		}

        return null;
    }
}
