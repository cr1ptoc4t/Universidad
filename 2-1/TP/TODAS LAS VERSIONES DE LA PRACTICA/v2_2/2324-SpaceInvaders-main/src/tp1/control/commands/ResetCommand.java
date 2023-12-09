package tp1.control.commands;

import tp1.control.ExecutionResult;
import tp1.control.InitialConfiguration;
import tp1.logic.Game;
import tp1.logic.GameModel;
import tp1.logic.Move;
import tp1.view.BoardPrinter;
import tp1.view.Messages;

import static tp1.logic.Move.stringAMov;

public class ResetCommand extends Command {

    private InitialConfiguration conf;
    public ResetCommand(){
        super("reset");
    }

    protected ResetCommand(InitialConfiguration conf){
        super("reset");
        this.conf=conf;
    }

    @Override
    protected String getName() {
        return Messages.COMMAND_RESET_NAME;
    }

    @Override
    protected String getShortcut() {
        return Messages.COMMAND_RESET_SHORTCUT;
    }

    @Override
    protected String getDetails() {
        return Messages.COMMAND_RESET_DETAILS;
    }

    @Override
    protected String getHelp() {
        return Messages.COMMAND_RESET_HELP;
    }

    @Override
    public ExecutionResult execute(GameModel game) {
        game.reset(conf);
        return new ExecutionResult(true);
    }


    public Command parse(String[] commandWords) {
        String str="none";
        if(commandWords.length!=1)
            str= commandWords[1];

        return new ResetCommand(InitialConfiguration.valueOfIgnoreCase(str));
    }

}
