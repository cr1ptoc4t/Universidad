package tp1.exceptions;

public class Exception {

    Exception(String message, Throwable cause,
              boolean enableSuppression, boolean writableStackTrace){
        super(message, cause, enableSuppression, writeableStackTrace);
    }
    Exception(){
        super();
    }
    public Exception(String message, Throwable cause){
        super();
    }
}
