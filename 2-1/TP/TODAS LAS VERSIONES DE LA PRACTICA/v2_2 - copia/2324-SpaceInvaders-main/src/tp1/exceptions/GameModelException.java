package tp1.exceptions;

public abstract class GameModelException  extends Exception{


    public abstract void showException();

    protected abstract String getMessage();
}
