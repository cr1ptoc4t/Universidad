package tp1.control;
import tp1.view.Messages;
public class CommandGenerator {

    public CommandGenerator(){

    }

    private static final List <Command> AVAILABLE_COMMANDS = Arrays.asList(
            new MoveCommand(),
            new ListCommand(),
            new ResetCommand(),
            new HelpCommand()
    );

    public static Command parse(String[] commandWords);

    public static String commandHelp();

    public class HelpCommand extends NoParamsCommand {
        @Override
        protected String getName() {
            return Messages.COMMAND_HELP_NAME;
        }
        @Override
        protected String getShortcut() {
            return Messages.COMMAND_HELP_SHORTCUT;
        }
        @Override
        public String getDetails() {
            return Messages.COMMAND_HELP_DETAILS;
        }

        // ...
    }

}