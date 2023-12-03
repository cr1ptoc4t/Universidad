package tp1.control.commands;

import tp1.control.ExecutionResult;
import tp1.logic.Game;
import tp1.view.Messages;

public class NoneCommand extends NoParamsCommand{



    public NoneCommand(){
        super("none");
    }

    @Override
    public ExecutionResult execute(Game game) {
        //game.exit();
        return new ExecutionResult(true);
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

}
