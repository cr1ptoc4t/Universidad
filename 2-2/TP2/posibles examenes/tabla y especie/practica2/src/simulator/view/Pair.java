package simulator.view;

public class Pair {
    private Double x;
    private int y;
    public Pair(Double x, int y) {
        this.x = x;
        this.y = y;
    }

    public Double getX() {
        return x;
    }
    public void setX(Double x) {
        this.x = x;
    }
    public int getY() {
        return y;
    }
    public void setY(int y) {
        this.y = y;
    }
}
