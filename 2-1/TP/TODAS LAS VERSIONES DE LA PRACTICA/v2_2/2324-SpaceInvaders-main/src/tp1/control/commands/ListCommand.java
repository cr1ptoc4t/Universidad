package tp1.control.commands;

import tp1.control.ExecutionResult;
import tp1.logic.Game;
import tp1.logic.GameModel;
import tp1.view.BoardPrinter;
import tp1.view.Messages;

import static tp1.logic.Move.stringAMov;

public class ListCommand extends NoParamsCommand {
    BoardPrinter printer;

    public ListCommand(){
        super("list");
    }
    @Override
    protected String getName() {
        return Messages.COMMAND_LIST_NAME;
    }

    @Override
    protected String getShortcut() {
        return Messages.COMMAND_LIST_SHORTCUT;
    }

    @Override
    protected String getDetails() {
        return Messages.COMMAND_LIST_DETAILS;
    }

    @Override
    protected String getHelp() {
        return Messages.COMMAND_LIST_HELP;
    }

    @Override
    public ExecutionResult execute(GameModel game) {
        printer.show(game.lista());
        return new ExecutionResult(false);
    }


    public Command parse(String[] commandWords) {
        return new ListCommand();
    }

}
