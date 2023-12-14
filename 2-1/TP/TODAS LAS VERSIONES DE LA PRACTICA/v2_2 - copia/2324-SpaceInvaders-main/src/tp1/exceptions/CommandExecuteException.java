package tp1.exceptions;

import tp1.view.GamePrinter;
import tp1.view.Messages;

public class CommandExecuteException extends GameModelException{


    protected String getMessage(){
        return Messages.COMMAND_EXECUTE_EXCEPTION;
    }
    @Override
    public void showException() {
        GamePrinter.show(getMessage());
    }
}
