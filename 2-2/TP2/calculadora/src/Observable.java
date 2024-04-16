public interface Observable<T>{
    public void addObserver(T t);
    public void removeObserver(T t);
}