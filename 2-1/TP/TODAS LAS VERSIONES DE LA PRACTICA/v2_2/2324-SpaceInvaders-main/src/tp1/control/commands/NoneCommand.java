package tp1.control.commands;

import tp1.control.ExecutionResult;
import tp1.logic.Game;
import tp1.logic.GameModel;
import tp1.view.Messages;

public class NoneCommand extends NoParamsCommand{



    public NoneCommand(){
        super("none");
    }

    @Override
    protected String getName() {
        return Messages.COMMAND_NONE_NAME;
    }

    @Override
    protected String getShortcut() {
        return Messages.COMMAND_NONE_SHORTCUT;
    }

    @Override
    protected String getDetails() {
        return Messages.COMMAND_NONE_DETAILS;
    }

    @Override
    protected String getHelp() {
        return Messages.COMMAND_NONE_HELP;
    }

    @Override
    public ExecutionResult execute(GameModel game) {
        return new ExecutionResult(true);
    }
    public Command parse(String[] commandWords) {
        return new NoneCommand();
    }

}
