package tp1.control.commands;

import tp1.control.ExecutionResult;
import tp1.exceptions.CommandParseException;
import tp1.exceptions.IllegalArgumentException;
import tp1.logic.Game;
import tp1.logic.GameModel;
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
	public ExecutionResult execute(GameModel game) {
		//TODO fill with your code
		game.updatePlayer(move);
		//aqui siempre lo saca como si fuera bien pero no sé como hay q hacerlo
		return new ExecutionResult(true);
	}


	@Override
	public Command parse(String[] commandWords) throws CommandParseException {
		String direction=commandWords[1];
		try{
			//todo: esto esta separado para debuggear. hay que juntarlo en 1 linea return
			Move mov = stringAMov(commandWords[1]);
			MoveCommand moveCom = new MoveCommand(mov);

			return moveCom;
		} catch (IllegalArgumentException e) {
			throw new CommandParseException(Messages.DIRECTION_ERROR + direction);
		}
	}



}
