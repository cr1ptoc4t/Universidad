package tp1.exceptions;

public class IllegalArgumentException extends Exception{
    public IllegalArgumentException() { super(); }
    public IllegalArgumentException(String message){ super(message); }
    public IllegalArgumentException(String message, Throwable cause){
        super(message, cause);
    }
    public IllegalArgumentException(Throwable cause){ super(cause); }

    IllegalArgumentException(String message, Throwable cause,
                          boolean enableSuppression, boolean writableStackTrace){
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
