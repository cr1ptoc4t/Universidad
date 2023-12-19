package tp1.exceptions;

import tp1.view.Messages;

public class NoShockWaveException extends GameModelException{
    @Override
    public void showException() {

    }
    protected String getMessage(){
        return Messages.NO_SHOCKWAVE_EXCEPTION;
    }
}
