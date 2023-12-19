package tp1.exceptions;

import tp1.view.Messages;

public class InitializationException extends GameModelException{
    @Override
    public void showException() {

    }
    protected String getMessage(){
        return Messages.INITIALIZATION_EXCEPTION;
    }
}
