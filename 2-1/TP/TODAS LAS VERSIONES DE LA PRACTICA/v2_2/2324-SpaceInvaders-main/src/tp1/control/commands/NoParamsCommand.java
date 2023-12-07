package tp1.control.commands;

import tp1.control.ExecutionResult;
import tp1.logic.Game;
import tp1.logic.Move;

public abstract class NoParamsCommand extends Command {


	public NoParamsCommand(String commandName) {
		super(commandName);
	}

	@Override
	public Command parse(String[] commandWords) {
		//TODO fill with your code

		Command command;

		if(commandWords[0].equals("s")||commandWords[0].equals("shoot"))
			command = new ShootCommand();
		else if (commandWords[0].equals("m")||commandWords[0].equals("move"))
			command = new MoveCommand(Move.stringAMov(commandWords[1]));
		else
			command = new NoneCommand();

		return command;
	}

	protected boolean matchCommand(String cw) {
		// comprueba si una acción
		// introducida por teclado se corresponde con la del comando
		return false;
	}
	public ExecutionResult execute(Game game){
		return new ExecutionResult(true);
	}
}
