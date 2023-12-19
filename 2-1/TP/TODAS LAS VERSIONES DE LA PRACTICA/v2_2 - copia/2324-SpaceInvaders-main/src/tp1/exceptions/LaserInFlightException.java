package tp1.exceptions;

import tp1.view.Messages;

public class LaserInFlightException extends GameModelException{
    @Override
    public void showException() {

    }
    protected String getMessage(){
        return Messages.LASER_IN_FLIGHT_EXCEPTION;
    }
}
