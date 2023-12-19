package tp1.exceptions;

import tp1.view.Messages;

public abstract class GameModelException  extends Exception{


    //creo q esto hay q borrarlo
    public abstract void showException();

    public String getMessage(){
        return Messages.GAME_MODEL_EXCEPTION;
    }

    public GameModelException() { super(); }
    public GameModelException(String message){ super(message); }
    public GameModelException(String message, Throwable cause){
        super(message, cause);
    }
    public GameModelException(Throwable cause){ super(cause); }

    Exception(String message, Throwable cause,
              boolean enableSuppression, boolean writableStackTrace){
        super(message, cause, enableSuppression, writeableStackTrace);
    }
}
