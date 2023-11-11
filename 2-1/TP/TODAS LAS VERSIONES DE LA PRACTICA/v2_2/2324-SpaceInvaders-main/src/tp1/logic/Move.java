package tp1.logic;

public enum Move {
    LEFT(-1,0), LLEFT(-2,0), RIGHT(1,0), RRIGHT(2,0), DOWN(0,1), UP(0,-1), NONE(0,0);
    private int x;
    private int y;

    Move(int x, int y){
        this.x = x;
        this.y =y;
    }

    public int getX(){
        return x;
    }

    public int getY(){
        return y;
    }

    public static Move stringAMov(String str){
        Move ret = NONE;

        switch(str){
            case "left":
                ret=LEFT;
                break;
            case "right":
                ret=RIGHT;
                break;
            case "lleft":
                ret = LLEFT;
                break;
            case "rright":
                ret =RRIGHT;
                break;
            case "up":
                ret = UP;
                break;
            case "down":
                ret= DOWN;
        }

        return ret;
    }


    public Move opuesto(){
        Move ret = NONE;

        switch(this){
            case RIGHT:
                ret=LEFT;
                break;
            case LEFT:
                ret=RIGHT;
                break;
            case RRIGHT:
                ret = LLEFT;
                break;
            case LLEFT:
                ret =RRIGHT;
                break;
            case DOWN:
                ret = UP;
                break;
            case UP:
                ret= DOWN;
        }

        return ret;
    }



}