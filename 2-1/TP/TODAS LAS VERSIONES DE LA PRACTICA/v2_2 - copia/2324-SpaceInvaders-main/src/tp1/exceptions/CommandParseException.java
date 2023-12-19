package tp1.exceptions;

import tp1.view.GamePrinter;
import tp1.view.Messages;

public class CommandParseException extends GameModelException{


    public CommandParseException(String str) {

    }

    protected String getMessage(){
        return Messages.COMMAND_PARSE_EXCEPTION;
    }

    @Override
    public void showException() {
        GamePrinter.show(getMessage());
    }
}
