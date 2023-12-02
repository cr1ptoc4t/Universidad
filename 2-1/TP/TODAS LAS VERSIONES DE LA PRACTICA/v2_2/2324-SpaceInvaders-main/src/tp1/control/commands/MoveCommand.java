package tp1.control.commands;

import tp1.control.ExecutionResult;
import tp1.logic.Game;
import tp1.logic.Move;
import tp1.view.Messages;

import static tp1.logic.Move.stringAMov;

public class MoveCommand extends Command {

	private Move move;

	public MoveCommand() {
		super("move");
	}

	protected MoveCommand(Move move) {
		super("move");
		this.move = move;
	}

	@Override
	protected String getName() {
		return Messages.COMMAND_MOVE_NAME;
	}

	@Override
	protected String getShortcut() {
		return Messages.COMMAND_MOVE_SHORTCUT;
	}

	@Override
	protected String getDetails() {
		return Messages.COMMAND_MOVE_DETAILS;
	}

	@Override
	protected String getHelp() {
		return Messages.COMMAND_MOVE_HELP;
	}

	@Override
	public ExecutionResult execute(Game game) {
		//TODO fill with your code
		game.updatePlayer(move);
		//aqui siempre lo saca como si fuera bien pero no sé como hay q hacerlo
		return new ExecutionResult(true);
	}


	@Override
	public Command parse(String[] commandWords) {
	    return new MoveCommand(stringAMov(commandWords[1]));
	}


}
