public abstract class MiFuncion extends Thread{

    protected int resultado;

    public abstract void apply();

    public void run(){
        apply();
    }

    public String getRes() {
        return resultado +"";
    }
}
