package tp1.control.commands;

import tp1.control.ExecutionResult;
import tp1.logic.Game;
import tp1.logic.GameModel;
import tp1.view.BoardPrinter;
import tp1.view.Messages;

import static tp1.logic.Move.stringAMov;

public class HelpCommand extends NoParamsCommand {
	BoardPrinter printer;

	public HelpCommand(){
		super("help");
	}
	@Override
	protected String getName() {
		return Messages.COMMAND_HELP_NAME;
	}

	@Override
	protected String getShortcut() {
		return Messages.COMMAND_HELP_SHORTCUT;
	}

	@Override
	protected String getDetails() {
		return Messages.COMMAND_HELP_DETAILS;
	}

	@Override
	protected String getHelp() {
		return Messages.COMMAND_HELP_HELP;
	}

	@Override
	public ExecutionResult execute(GameModel game) {
		printer.show(Messages.HELP_AVAILABLE_COMMANDS);
		printer.show(CommandGenerator.commandHelp());
		return new ExecutionResult(false);
	}


	public Command parse(String[] commandWords) {
		return new HelpCommand();
	}

}
