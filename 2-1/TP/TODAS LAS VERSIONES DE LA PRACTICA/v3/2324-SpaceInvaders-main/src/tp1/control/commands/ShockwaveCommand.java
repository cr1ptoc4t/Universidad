package tp1.control.commands;

import tp1.control.ExecutionResult;
import tp1.logic.Game;
import tp1.logic.GameModel;
import tp1.view.Messages;

import static tp1.logic.Move.stringAMov;

public class ShockwaveCommand extends NoParamsCommand{


    public ShockwaveCommand(){
        super("shockwave");
    }
    @Override
    protected String getName() {
        return Messages.COMMAND_SHOCKWAVE_NAME;
    }

    @Override
    protected String getShortcut() {
        return Messages.COMMAND_SHOCKWAVE_SHORTCUT;
    }

    @Override
    protected String getDetails() {
        return Messages.COMMAND_SHOCKWAVE_DETAILS;
    }

    @Override
    protected String getHelp() {
        return Messages.COMMAND_SHOCKWAVE_HELP;
    }



    @Override
    public ExecutionResult execute(GameModel game) {
        game.shockWave();
        return new ExecutionResult(true);
    }

    @Override
    public Command parse(String[] commandWords) {
        return new ShockwaveCommand();
    }
}
