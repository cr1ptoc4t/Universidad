package tp1.exceptions;

import tp1.view.Messages;

public class IllegalArgumentException extends GameModelException{

    @Override
    public void showException() {

    }
    protected String getMessage(){
        return Messages.ILLEGAL_ARGUMENT_EXCEPTION;
    }
}
