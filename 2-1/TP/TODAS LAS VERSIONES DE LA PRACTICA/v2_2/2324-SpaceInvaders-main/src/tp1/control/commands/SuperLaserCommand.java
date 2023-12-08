package tp1.control.commands;

import tp1.control.ExecutionResult;
import tp1.logic.Game;
import tp1.logic.GameModel;
import tp1.view.Messages;

public class SuperLaserCommand extends NoParamsCommand{
    public SuperLaserCommand(){
        super("super laser");

    }

    @Override
    protected String getName() {
        return Messages.COMMAND_SUPERLASER_NAME;
    }

    @Override
    protected String getShortcut() {
        return Messages.COMMAND_SUPERLASER_SHORTCUT;
    }

    @Override
    protected String getDetails() {
        return Messages.COMMAND_SUPERLASER_DETAILS;
    }

    @Override
    protected String getHelp() {
        return Messages.COMMAND_SUPERLASER_HELP;
    }

    @Override
    public ExecutionResult execute(GameModel game) {
        return null;
    }

    @Override
    public ExecutionResult execute(Game game) {
       //game.superlaser
        return new ExecutionResult(true);
    }

    @Override
    public Command parse(String[] commandWords) {
        return new SuperLaserCommand();
    }

}
