package simulator.model.animals;

import java.util.Objects;

public enum State {
    NORMAL, MATE, HUNGER, DANGER, DEAD;
    private State(){}

    public static State castState(String str){
        State s = State.NORMAL;
        switch (str){
            case "MATE": {
                s = State.MATE;
                break;}
            case "HUNGER": {
                s = State.HUNGER;
                break;}
            case "DANGER": {
                s = State.DANGER;
                break;}
            case "DEAD": {
                s = State.DEAD;}
        }
        return s;
    }
}
