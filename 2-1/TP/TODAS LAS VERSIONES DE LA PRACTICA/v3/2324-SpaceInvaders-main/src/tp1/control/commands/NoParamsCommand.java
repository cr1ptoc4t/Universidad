package tp1.control.commands;

import tp1.control.ExecutionResult;
import tp1.logic.Game;
import tp1.logic.Move;

public abstract class NoParamsCommand extends Command {


	public NoParamsCommand(String commandName) {
		super(commandName);
	}


	protected boolean matchCommand(String cw) {
		// comprueba si una acción
		// introducida por teclado se corresponde con la del comando
		return cw.equals(commandName);
	}
}
